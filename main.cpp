// Long Chau doing doing get order part
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book
{
    // need a class book.
};

class Order
{
private:
    int orderId;
    string dateCreated;
    int userId;
    vector<Book> booksOrdered;
    string status;
    string dueDate;
    string returnDate; // because we dont have a class for date so i just replace it using "string"

public:
    Order() : booksOrdered({}) {}

    // Getter methods
    int getOrderId() const
    {
        return orderId;
    }
    string getDateCreated() const
    {
        return dateCreated;
    }
    int getUserId() const
    {
        return userId;
    }
    const vector<Book> &getBooksOrdered() const
    {
        return booksOrdered;
    }
    string getStatus() const
    {
        return status;
    }
    string getDueDate() const
    {
        return dueDate;
    }
    string getReturnDate() const
    {
        return returnDate;
    }

    // Setter methods
    void setOrderId(int id)
    {
        orderId = id;
    }
    void setDateCreated(const string &d)
    {
        dateCreated = d;
    }
    void setUserId(int id)
    {
        userId = id;
    }
    void setBooksOrdered(const vector<Book> &books)

    {
        booksOrdered = books;
    }
    void setStatus(const string &s)
    {
        status = s;
    }
    void setDueDate(const string &d)
    {
        dueDate = d;
    }
    void setReturnDate(const string &d)
    {
        returnDate = d;
    }
};

//---------------------------------------------------------------------------------------------------------------
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
    const vector<Order> &getOrders() const
    {
        return orders;
    }
};
