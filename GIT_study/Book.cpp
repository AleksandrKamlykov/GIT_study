#include "Book.h"

void Book::setName(string name)
{
	this->name = name;
}

string Book::getName()
{
	return this->name;
}

void Book::setAuthor(string author)
{
	this->author = author;
}

string Book::getAuthor()
{
	return this->author;
}

void Book::setYear(int year)
{
	this->year = year;
}

int Book::getYear()
{
	return this->year;
}

void Book::setISBN(string ISBN)
{
	this->ISBN = ISBN;
}

string Book::getISBN()
{
	return this->ISBN;
}

void Book::setQuantityExem(int quantityExem)
{
	this->quantityExem = quantityExem;
}

int Book::getQuantityExem()
{
	return this->quantityExem;
}

void Book::showData()
{
	cout << "Book name: " << this->getName() << "\nAuthor: " << this->getAuthor() << "\nYear: " << this->getYear() << "\nISBN: " << this->getISBN() << "\n--------------\n";
}
