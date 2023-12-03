#include "Book.h"

Book::Book() : copiesAvailable(0), totalCopies(0) {}


std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string& t) {
    title = t;
}

std::string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const std::string& a) {
    author = a;
}

std::string Book::getISBN() const {
    return isbn;
}

void Book::setISBN(const std::string& isbn) {
    this->isbn = isbn;
}

Date Book::getPublicationDate() const {
    return publicationDate;
}

void Book::setPublicationDate(const Date& d) {
    publicationDate = d;
}

int Book::getCopiesAvailable() const {
    return copiesAvailable;
}

void Book::setCopiesAvailable(int c) {
    copiesAvailable = c;
}

int Book::getTotalCopies() const {
    return totalCopies;
}

void Book::setTotalCopies(int c) {
    totalCopies = c;
}

std::string Book::getLanguage() const {
    return language;
}

void Book::setLanguage(const std::string& l) {
    language = l;
}

std::string Book::getCondition() const {
    return condition;
}

void Book::setCondition(const std::string& cond) {
    condition = cond;
}

int Book::getBookId() const {
    return bookId;
}

void Book::setBookId(int id) {
    bookId = id;
}

std::string Book::getBookStatus() const {
    return bookStatus;
}

void Book::setBookStatus(const std::string& s) {
    bookStatus = s;
}
void Book::checkoutBook() {
    if (copiesAvailable > 0) {
        copiesAvailable--;
} else {
        std::cout << "No copies available for checkout." << std::endl;
    }
}

