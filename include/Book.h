#include <string>
#include "Date.h"

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
    Book();

    std::string getTitle() const;
    void setTitle(const std::string& t);

    std::string getAuthor() const;
    void setAuthor(const std::string& a);

    std::string getISBN() const;
    void setISBN(const std::string& isbn);

    Date getPublicationDate() const;
    void setPublicationDate(const Date& d);

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