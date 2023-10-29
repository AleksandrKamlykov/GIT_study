#pragma once

#include <string>
#include <vector>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;
    std::string catalogFilePath;

public:
    Library(const std::string& catalogFilePath);
    void addBook(Book& book);
    void removeBook(const std::string& isbn);
    std::vector<Book> searchBooks(const std::string& query);
    void saveCatalogToFile();
    void loadCatalogFromFile();
    void displayAllBooks();
};


