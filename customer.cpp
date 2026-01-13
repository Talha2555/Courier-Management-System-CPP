#include "customer.h"
#include "Utils.h"
#include <fstream>
#include <sstream>
#include <vector>

Customer::Customer(string u, string p) : User(u, p, "CUSTOMER") {}

void Customer::menu() {
    int choice;
    do {
        cout << "\n=== CUSTOMER MENU (" << username << ") ===" << endl;
        cout << "1. Place New Order" << endl;
        cout << "2. Track Order" << endl;
        cout << "3. View My History" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: placeOrder(); break;
            case 2: trackOrder(); break;
            case 3: viewMyOrders(); break;
            case 4: cout << "Logging out..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
}

void Customer::placeOrder() {
    string r, c;
    double w;
    cout << "\n--- Place Order ---" << endl;
    cout << "Receiver Name: "; cin >> r;
    cout << "City: "; cin >> c;
    cout << "Weight (kg): "; cin >> w;

    // --- OOP CONCEPT: Template Usage ---
    double cost = calculateCost<double>(w);
    cout << "Calculated Cost: $" << cost << endl;

    // Generate pseudo-random ID
    int id = rand() % 9000 + 1000;
    
    // Save to file
    ofstream file("shipments.csv", ios::app);
    if (!file.is_open()) {
        cout << "[ERROR] Could not save order! Is shipments.csv open in Excel?" << endl;
        return; 
    }
    // Format: ID,Sender(Current User),Receiver,City,Weight,Status
    file << id << "," << username << "," << r << "," << c << "," << w << ",Pending" << endl;
    file.close();

    cout << "Order Placed! Your Tracking ID is: " << id << endl;
}

void Customer::trackOrder() {
    int id;
    cout << "Enter Tracking ID: "; cin >> id;
    
    ifstream file("shipments.csv");
    string line;
    bool found = false;
    while(getline(file, line)) {
        stringstream ss(line);
        string strId, sender, rec, city, weight, status;
        getline(ss, strId, ',');
        
        if(stoi(strId) == id) {
            // Read rest of line
            getline(ss, sender, ',');
            getline(ss, rec, ',');
            getline(ss, city, ',');
            getline(ss, weight, ',');
            getline(ss, status, ',');
            
            cout << "Status: " << status << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "Order not found." << endl;
}

void Customer::viewMyOrders() {
    ifstream file("shipments.csv");
    string line;
    cout << "\n--- My Order History ---" << endl;
    while(getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> row;
        while(getline(ss, segment, ',')) row.push_back(segment);

        // row[1] is Sender. Check if it matches current username
        if(row.size() >= 2 && row[1] == username) {
            cout << "ID: " << row[0] << " | To: " << row[2] << " | Status: " << row[5] << endl;
        }
    }
}
