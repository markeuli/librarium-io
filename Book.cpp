#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
class Date {
private:
    std::tm dateInfo;

public:
    Date() {
        updateCurrentDate();
    }

    // Method to get the current date
    void updateCurrentDate() {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        localtime_s(&dateInfo, &now);
    }

    int getYear() const {
        return dateInfo.tm_year + 1900;
    }

    int getMonth() const {
        return dateInfo.tm_mon + 1; 
    }

    int getDay() const {
        return dateInfo.tm_mday;
    }


    std::string getDateString() const {
        char buffer[11]; 
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &dateInfo);
        return buffer;
    }
};

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    Date publicationDate;
    int copiesAvailable;
    int totalCopies;
    std::string language;
    std::string condition;
    int bookId;
    std::string bookStatus;

public:

    Book() {}

    std::string getTitle() const {
        return title;
    }

    void setTitle(const std::string& t) {
        title = t;
    }

    std::string getAuthor() const {
        return author;
    }

    void setAuthor(const std::string& a) {
        author = a;
    }

    std::string getISBN() const {
        return isbn;
    }

    void setISBN(const std::string& isbn) {
        this->isbn = isbn;
    }

    Date getPublicationDate() const {
        return publicationDate;
    }

    void setPublicationDate(const Date& d) {
        publicationDate = d;
    }

    int getCopiesAvailable() const {
        return copiesAvailable;
    }

    void setCopiesAvailable(int c) {
        copiesAvailable = c;
    }

    int getTotalCopies() const {
        return totalCopies;
    }

    void setTotalCopies(int c) {
        totalCopies = c;
    }

    std::string getLanguage() const {
        return language;
    }

    void setLanguage(const std::string& l) {
        language = l;
    }

    std::string getCondition() const {
        return condition;
    }

    void setCondition(const std::string& cond) {
        condition = cond;
    }

    int getBookId() const {
        return bookId;
    }

    void setBookId(int id) {
        bookId = id;
    }

    std::string getBookStatus() const {
        return bookStatus;
    }

    void setBookStatus(const std::string& s) {
        bookStatus = s;
    }
};

