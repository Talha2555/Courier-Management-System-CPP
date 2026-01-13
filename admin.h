#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "shipment.h"
#include <vector>

// --- OOP CONCEPT: Inheritance ---
class Admin : public User {
public:
    Admin(string u, string p);

    // --- OOP CONCEPT: Function Overriding ---
    void menu() override;

    // Admin specific features
    void addShipment();
    void viewAllShipments();
    void updateStatus();
    
    // --- OOP CONCEPT: Function Overloading ---
    void searchShipment(int id);      // Search by ID
    void searchShipment(string city); // Search by City

private:
    void saveShipmentToFile(const Shipment& s);
};

#endif
