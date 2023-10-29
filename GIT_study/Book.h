#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Book
{
private:
	string name;
	string author;
	int year;
	string ISBN;
	int quantityExem;
public:

	Book(const string& name, const string& author, int year, const string& ISBN, int quantityExem)
		: name(name), author(author), year(year), ISBN(ISBN), quantityExem(quantityExem)
	{
	}
	Book(){}
	void setName(string name);
	string getName();
	void setAuthor(string author);
	string getAuthor();
	void setYear(int year);
	int getYear();
	void setISBN(string ISBN);
	string getISBN();
	void setQuantityExem(int quantityExem);
	int getQuantityExem();
	void showData();
	friend std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << book.name << ";" << book.author << ";" << book.year << ";" << book.ISBN <<";" << book.quantityExem;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Book& book)
	{
		string year ="", quantity ="";

		getline(is,book.name ,';');
		getline(is, book.author, ';');
		getline(is, year, ';');
		getline(is, book.ISBN, ';');


		return is;
	}
};

