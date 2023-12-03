#include <vector>
#include <algorithm>
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

// Edit an existing order based on its ID
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