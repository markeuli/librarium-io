#include <vector>
#include <algorithm>
#include "Order.h"

using namespace std;

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