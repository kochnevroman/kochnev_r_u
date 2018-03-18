#include "hashImageFinder.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	sqlite3 *db;
	sqlite3_open("ImagesHashDB.db", &db);

	dropTable(db);
	createTable(db);
	addImageToDB(db, "zru.017.001.00009_x0587y0699w0061h0057.err.wcc.png");
	addImageToDB(db, "zru.017.001.00010_x0633y0683w0062h0056.err.wcc.png");
	addImageToDB(db, "zru.017.001.00010_x0633y0683w0062h0056.err.wcc.png");
	getAllImagesFromDB(db);

	cout << getHashImageFromDB(db, "zru.017.001.00009_x0587y0699w0061h0057.err.wcc.png");
	
	cout << equalHash(db, "zru.017.001.00009_x0587y0699w0061h0057.err.wcc.png", "zru.001.001.00040_x0465y0715w0057h0061.err.wcc.png") << "\n";
	cout << equalHash(db, "zru.017.001.00009_x0587y0699w0061h0057.err.wcc.png", "zru.017.001.00010_x0633y0683w0062h0056.err.wcc.png") << "\n";

	sqlite3_close(db);
	getchar();
	return 0;
}