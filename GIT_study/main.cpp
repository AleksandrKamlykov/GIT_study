#include <iostream>
#include <string>
using namespace std;

#include "Book.h"
#include "Library.h"

void main() {

	Book clearCode("ClearCode 2", "Martin", 2023, "238y273232983", 10);
	Book clearAgile("ClearAgile 2", "Martin", 2023, "238y273232983", 10);

	Library library("lib.txt");

	library.addBook(clearCode);
	library.addBook(clearAgile);
	library.saveCatalogToFile();
	library.loadCatalogFromFile();
	library.displayAllBooks();

}