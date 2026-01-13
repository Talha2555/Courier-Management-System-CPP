#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include <iostream>
using namespace std;

// --- OOP CONCEPT: Composition (Has-A Relationship) ---
class Date {
public:
    int day, month, year;
    Date() : day(26), month(11), year(2025) {} 
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Shipment {
private:
    int trackingID;
    string sender;
    string receiver;
    string city;
    double weight;
    string status;      
    double profitMargin; 

    // --- OOP CONCEPT: Composition ---
    Date orderDate;

public:
    // --- OOP CONCEPT: Static Member (Declaration) ---
    // Counts how many shipment objects exist in memory
    static int totalShipmentCount;

    // --- OOP CONCEPT: Constructor ---
    Shipment(int id, string s, string r, string c, double w, string st = "Pending") 
    : orderDate(26, 11, 2025) { 
        // --- OOP CONCEPT: "This" Pointer ---
        this->trackingID = id;
        this->sender = s;
        this->receiver = r;
        this->city = c;
        this->weight = w;
        this->status = st;
        this->profitMargin = w * 20.5;
        
        totalShipmentCount++; // Increment static counter
    }

    // --- OOP CONCEPT: Copy Constructor (Deep/Shallow Copy) ---
    Shipment(const Shipment &other) {
        trackingID = other.trackingID;
        sender = other.sender;
        receiver = other.receiver;
        city = other.city;
        weight = other.weight;
        status = other.status;
        profitMargin = other.profitMargin;
        orderDate = other.orderDate;
        
        totalShipmentCount++; // Copying creates a new object, so increment count
    }

    // --- OOP CONCEPT: Destructor ---
    ~Shipment() {
        totalShipmentCount--;
    }

    // Getters
    int getID() const { return trackingID; }
    string getCity() const { return city; }
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getStatus() const { return status; }
    double getWeight() const { return weight; }
    
    // Static Function
    static int getTotalCount() { return totalShipmentCount; }

    void setStatus(string newStatus) { status = newStatus; }

    // Display function (Kept for Admin compatibility)
    void display() const {
        cout << "ID: " << trackingID << " | To: " << receiver 
             << " (" << city << ") | Status: " << status 
             << " | Date: " << orderDate.day << "/" << orderDate.month << endl;
    }

    // --- OOP CONCEPT: Operator Overloading ---
    friend ostream& operator<<(ostream& os, const Shipment& s);
    friend void auditShipment(const Shipment& s);
};

// --- OOP CONCEPT: Operator Overloading Definition (Inline) ---
inline ostream& operator<<(ostream& os, const Shipment& s) {
    os << "[Shipment] ID: " << s.trackingID << " | Status: " << s.status;
    return os;
}

// --- OOP CONCEPT: Friend Function (Inline) ---
inline void auditShipment(const Shipment& s) {
    cout << "\n[ADMIN AUDIT] ID: " << s.trackingID 
         << " | Profit: $" << s.profitMargin 
         << " | Active Objects: " << Shipment::totalShipmentCount << endl;
}

#endif
