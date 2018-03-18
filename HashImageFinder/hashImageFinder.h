#ifndef HASHIMAGEFINDER_HASHIMAGEFINDER_H
#define HASHIMAGEFINDER_HASHIMAGEFINDER_H

#pragma once

#include "sqlite3.h"
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include "xxHash32.h"

IplImage* loadImage(const std::string filename)
{
    return cvLoadImage(filename.c_str());
}

uint32_t calcImageHash(IplImage* image)
{
    static const uint32_t seed = 0;
    XXHash32* x = new XXHash32(seed);
    x->add(image -> imageData, image -> imageSize);
    return x -> hash();
}

static int callback(void *data, int argc, char **argv, char **azColName)
{
    fprintf(stderr, "%s ", (const char*)data);

    for (int i(0); i < argc; i += 1) {
        printf("\t%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

int dropTable(sqlite3* db)
{
    std::string sql = "DROP TABLE ImagesHash";
    char *zErrMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Table dropped successfully\n");
        return 0;
    }
}

int createTable(sqlite3* db)
{
    std::string sql = "CREATE TABLE ImagesHash("  \
		"PATH_TO_IMAGE        CHAR(250)," \
		"HASH_IMAGE         CHAR(100));";
    char *zErrMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Table created successfully\n");
        return 0;
    }
}

int insertImageToDB(sqlite3* db, const std::string filename, const uint32_t hash)
{
    std::string sql = "INSERT INTO ImagesHash" \
		"(PATH_TO_IMAGE, HASH_IMAGE)"  \
		"VALUES('" +
                      filename + "', '" +
                      std::to_string(hash) + "')";

    char *zErrMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Image inserted successfully\n");
        return 0;
    }
}

int addImageToDB(sqlite3* db, const std::string filename)
{
    IplImage* image = loadImage(filename);
    uint32_t hash = calcImageHash(image);
    return insertImageToDB(db, filename, hash);
}

int getAllImagesFromDB(sqlite3* db)
{
    std::string sql = "SELECT * FROM ImagesHash";

    const char* data = "Image in database:\n";
    char *zErrMsg = nullptr;

    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    } else {
        fprintf(stdout, "Select operation is successfull\n");
        return 0;
    }
}

const unsigned char* getHashImageFromDB(sqlite3* db, const std::string filename)
{
    std::string sql = "SELECT HASH_IMAGE FROM ImagesHash WHERE " \
		"PATH_TO_IMAGE = '" + filename + "'";

    sqlite3_stmt* stmt;
    sqlite3_prepare(db, sql.c_str(), -1, &stmt, NULL);

    int rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        return (const unsigned char*)sqlite3_column_text(stmt, 0);
    } else {
        sqlite3_finalize(stmt);
        fprintf(stdout, "Select hash is bad\n");
        return nullptr;
    }
}

const bool equalHash(sqlite3* db, const std::string f1, const std::string f2)
{
    const unsigned char* h1 = getHashImageFromDB(db, f1);
    const unsigned char* h2 = getHashImageFromDB(db, f2);
    return memcmp(h1, h2, sizeof(h1)) == 0;
}

#endif //HASHIMAGEFINDER_HASHIMAGEFINDER_H
