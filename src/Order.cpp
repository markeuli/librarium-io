/* Order.cpp
 * Description: Order class implementation. Holds data pertaining to a specific order.
 *
 * 
 * 
 * Authors: Long Chau
 * Date Created: 12/1/2023 
*/

#include "Order.h"

int Order::getUserId() const {
    return userId;
}

std::string Order::getStatus() const {
    return status;
}

Date Order::getDueDate() const {
    return dueDate;
}

void Order::setOrderId(int id) {
    orderId = id;
}

void Order::setBookId(int id) {
    bookId = id;
}

int Order::getBookId() const {
    return bookId;
}

void Order::setUserId(int id) {
    userId = id;
}

void Order::setStatus(const std::string &s) {
    status = s;
}

void Order::setDueDate(const Date &d) {
    dueDate = d;
}

int Order::getOrderId() const {
    return orderId;
}

