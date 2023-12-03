#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "Date.h"

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    int publicationDate;
    int copiesAvailable;
    int totalCopies;
    std::string language;
    std::string condition;
    int bookId;
    std::string bookStatus;

public:
    Book();
    Book(int id, const std::string& title, const std::string& author, const std::string& isbn, 
        int tc, const std::string& lang = "Unknown", const std::string& cond = "Fair", 
        const std::string& status="Available");

    std::string getTitle() const;
    void setTitle(const std::string& t);

    std::string getAuthor() const;
    void setAuthor(const std::string& a);

    std::string getISBN() const;
    void setISBN(const std::string& isbn);

    int getPublicationDate() const;
    void setPublicationDate(const int& d);

    int getCopiesAvailable() const;
    void setCopiesAvailable(int c);

    int getTotalCopies() const;
    void setTotalCopies(int c);

    std::string getLanguage() const;
    void setLanguage(const std::string& l);

    std::string getCondition() const;
    void setCondition(const std::string& cond);

    int getBookId() const;
    void setBookId(int id);

    std::string getBookStatus() const;
    void setBookStatus(const std::string& s);
};

class ManageBook
{
    private:
        std::vector<Book> books;
    public:
        void addBook();
        void removeBook(int bookId);
        void editBook(int bookID);
        const std::vector<Book> getBooks() const;
        void viewBook(int id);
        void viewAllBooks();
        bool checkOutBook(int bookId);
        bool returnBook(int bookId);
};

#endif