/* Book.cpp
 * Description: Book class implementation. Holds data pertaining to a specific book. One book is hardcoded for ease
 *              of testing and demonstration as there is no persistent database. 
 * 
 * 
 * Authors: Duy Dinh, Mark Ulicnik
 * Date Created: 12/1/2023 
*/

#include "Book.h"

Book::Book() {
    title = "";
    author = "";
    isbn = "";
    publicationDate = 2000;
    copiesAvailable = 0;
    totalCopies = 0;
    language = "";
    condition = "";
    bookId = 0;
    bookStatus = "";
}

Book::Book(int id, const std::string& title, const std::string& author, const std::string& isbn, 
        int tc, const std::string& lang, const std::string& cond, 
        const std::string& status){
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->totalCopies = tc;
    this->copiesAvailable = tc;
    this->language = lang;
    this->condition = cond;
    this->bookId = id;
    this->bookStatus = status;

}

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

int Book::getPublicationDate() const {
    return publicationDate;
}

void Book::setPublicationDate(const int& d) {
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


