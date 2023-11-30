// Long Chau doing doing get order part
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Date {

};

class Book {

};
// Class representing an Order
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
    Order() : booksOrdered({}) {}

    // Getter methods
    int getOrderId() const {
        return orderId;
    }
    Date getDateCreated() const {
        return dateCreated;
    }
    int getUserId() const {
        return userId;
    }
    const vector<Book> &getBooksOrdered() const {
        return booksOrdered;
    }
    string getStatus() const {
        return status;
    }
    Date getDueDate() const {
        return dueDate;
    }
    Date getReturnDate() const {
        return returnDate;
    }

    // Setter methods
    void setOrderId(int id) {
        orderId = id;
    }
    void setDateCreated(const Date &d) {
        dateCreated = d;
    }
    void setUserId(int id) {
        userId = id;
    }
    void setBooksOrdered(const vector<Book> &books) {
        booksOrdered = books;
    }
    void setStatus(const string &s) {
        status = s;
    }
    void setDueDate(const Date &d) {
        dueDate = d;
    }
    void setReturnDate(const Date &d) {
        returnDate = d;
    }
};

//---------------------------------------------------------------------------------------------------------------
// Class managing a collection of orders

class ManageOrder
{
private:
    vector<Order> orders;

public:
    // Add a new order to the list
    void addOrder(const Order &order)
    {
        orders.push_back(order);
    }

    // Remove an order based on its ID
    void removeOrder(int orderId)
    {
        orders.erase(
            remove_if(orders.begin(), orders.end(),
                      [orderId](const Order &o)
                      {
                          return o.getOrderId() == orderId;
                      }),
            orders.end());
    }

    // Edit an existing order based on its ID
    void editOrder(const Order &updatedOrder)
    {
        for (auto &o : orders)
        {
            if (o.getOrderId() == updatedOrder.getOrderId())
            {
                o = updatedOrder;
                return;
            }
        }
    }
    // Getter method to retrieve the list of orders
    const vector<Order> &getOrders() const
    {
        return orders;
    }
};
