#include "Library.h"
#include "Library.h"
#include <iostream>
#include <fstream>
#include <string>


Library::Library(const string& catalogFilePath) : catalogFilePath(catalogFilePath) {
    loadCatalogFromFile();
}

void Library::addBook( Book& book) {
    books.push_back(book);
}

void Library::removeBook(const string& isbn) {
    books.erase(remove_if(books.begin(), books.end(),
        [isbn]( Book& book) { return book.getISBN() == isbn; }), books.end());
}

vector<Book> Library::searchBooks(const string& query) {
    vector<Book> results;
    for ( Book& book : books) {
        if (book.getName().find(query) != string::npos ||
            book.getAuthor().find(query) != string::npos ||
            book.getISBN() == query) {
            results.push_back(book);
        }
    }
    return results;
}

void Library::saveCatalogToFile() {
    ofstream file;
    file.open(catalogFilePath);

    if (file.is_open()) {
        for (const Book& book : books) {
            file << book << endl ;
        }
        file.close();
    }
}

void Library::loadCatalogFromFile() {
    this->books.clear();
    ifstream file(catalogFilePath);
    if (file.is_open()) {
      
        string str;

        while (getline(file,str)) {
            std::stringstream ss(str);

            std::vector<std::string> tokens;
            std::string token;
            char delimiter = ';';

            while (std::getline(ss, token, delimiter)) {
                tokens.push_back(token);
            }
            Book book{ tokens[0],tokens[1],stoi(tokens[2]) ,tokens[3] ,stoi(tokens[4]) };
            this->addBook(book);

        }
        file.close();
    }
}

void Library::displayAllBooks() {
    for (Book& book : books) {
        book.showData();
    }
}
