#include "Order.h"


int Order::getUserId() const {
    return userId;
}

const std::vector<Book>& Order::getBooksOrdered() const {
    return booksOrdered;
}

std::string Order::getStatus() const {
    return status;
}

Date Order::getDueDate() const {
    return dueDate;
}

Date Order::getReturnDate() const {
    return returnDate;
}

// Setter methods
void Order::setOrderId(int id) {
    orderId = id;
}

void Order::setDateCreated(const Date &d) {
    dateCreated = d;
}

void Order::setUserId(int id) {
    userId = id;
}

void Order::setBooksOrdered(const std::vector<Book> &books) {
    booksOrdered = books;
}

void Order::setStatus(const std::string &s) {
    status = s;
}

void Order::setDueDate(const Date &d) {
    dueDate = d;
}

void Order::setReturnDate(const Date &d) {
    returnDate = d;
}

int Order::getOrderId() const {
    return orderId;
}

