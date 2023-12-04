/* ManageOrder.cpp
 * Description: ManageOrder is used to hold and manipulate orders. It has functions to add, remove, edit, and 
 *              view one or multiple orders. It also has functions to order and return books, which are called
 *              to create orders for member actions.
 * 
 * Authors: Long Chau
 * Date Created: 12/1/2023 
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include "Order.h"

using namespace std;


void ManageOrder::addOrder(const Order &order)
{
    orders.push_back(order);
}

// Remove an order based on its ID
void ManageOrder::removeOrder(int orderId)
{
    orders.erase(
        remove_if(orders.begin(), orders.end(),
                    [orderId](const Order &o)
                    {
                        return o.getOrderId() == orderId;
                    }),
        orders.end());
}

// Edit an existing order based on another order
void ManageOrder::editOrder(const Order &updatedOrder)
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

const vector<Order> ManageOrder::getOrders() const
{
    return orders;
}

bool ManageOrder::orderBook(int userId, int bookId, const Date &dueDate) {
    Order order;
    order.setUserId(userId);
    order.setDueDate(dueDate);
    order.setBookId(bookId);
    order.setOrderId(orders.size() + 1);
    order.setStatus("Active");
    addOrder(order);
    return true;
}

void ManageOrder::viewAllOrders() {
    for (auto &o : orders)
    {
        cout << "Order ID: " << o.getOrderId() << endl;
        cout << "User ID: " << o.getUserId() << endl;
        cout << "Book ID: " << o.getBookId() << endl;
        cout << "Due Date: " << o.getDueDate().getDay() << "/" << o.getDueDate().getMonth() << "/" << o.getDueDate().getYear() << endl;
        cout << "Status: " << o.getStatus() << endl;
        cout << endl;
    }
}

void ManageOrder::viewOrdersByUser(int userId){
    for (auto &o : orders)
    {
        if(o.getUserId() == userId){
            cout << "Order ID: " << o.getOrderId() << endl;
            cout << "User ID: " << o.getUserId() << endl;
            cout << "Book ID: " << o.getBookId() << endl;
            cout << "Due Date: " << o.getDueDate().getDay() << "/" << o.getDueDate().getMonth() << "/" << o.getDueDate().getYear() << endl;
            cout << "Status: " << o.getStatus() << endl;
            cout << endl;
        }
    }
}

bool ManageOrder::returnBook(int userId, int orderId){
    for (auto &o : orders)
    {
        if(o.getUserId() == userId && o.getOrderId() == orderId){
            o.setStatus("Returned");
            return true;
        }
    }
    return false;
}