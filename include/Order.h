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
    int userId;
    int bookId;
    string status;
    Date dueDate;

public:
    
    int getUserId() const;
    std::string getStatus() const;
    Date getDueDate() const;
    int getOrderId() const;
    int getBookId() const;

    
    void setOrderId(int id);
    void setUserId(int id);
    void setStatus(const std::string &s);
    void setDueDate(const Date &d);
    void setBookId(int id);
};

class ManageOrder
{
private:
    std::vector<Order> orders;

public:
    void addOrder(const Order &order);
    void removeOrder(int orderId);
    void editOrder(const Order &updatedOrder);
    const std::vector<Order> getOrders() const;
    bool orderBook(int userId, int bookId, const Date &dueDate);
    void viewAllOrders();
    void viewOrdersByUser(int userId);
    bool returnBook(int userId, int bookId);
};

#endif