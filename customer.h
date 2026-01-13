#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Shipment.h"

// --- OOP CONCEPT: Inheritance ---
class Customer : public User {
public:
    Customer(string u, string p);

    // --- OOP CONCEPT: Function Overriding ---
    void menu() override;

    void placeOrder();
    void trackOrder();
    void viewMyOrders();
};

#endif
