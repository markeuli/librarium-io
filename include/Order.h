#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
#include "Book.h"
#include "Date.h"

using namespace std;

class Order {
private:
    int orderId;
    Date dateCreated;
    int userId;
    vector<Book> booksOrdered;
    string status;
    Date dueDate;
    Date returnDate;

public:
    
    int getUserId() const;
    const std::vector<Book>& getBooksOrdered() const;
    std::string getStatus() const;
    Date getDueDate() const;
    Date getReturnDate() const;
    int getOrderId() const;

    
    void setOrderId(int id);
    void setDateCreated(const Date &d);
    void setUserId(int id);
    void setBooksOrdered(const std::vector<Book> &books);
    void setStatus(const std::string &s);
    void setDueDate(const Date &d);
    void setReturnDate(const Date &d);
};

#endif