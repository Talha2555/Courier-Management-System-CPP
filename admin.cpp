#include "Admin.h"
#include "Utils.h" // For template function if needed
#include <fstream>
#include <sstream>

Admin::Admin(string u, string p) : User(u, p, "ADMIN") {}

void Admin::menu() {
    int choice;
    do {
        cout << "\n=== ADMIN DASHBOARD (" << username << ") ===" << endl;
        cout << "1. Add New Shipment" << endl;
        cout << "2. View All Shipments" << endl;
        cout << "3. Update Shipment Status" << endl;
        cout << "4. Search by ID" << endl;
        cout << "5. Search by City" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addShipment(); break;
            case 2: viewAllShipments(); break;
            case 3: updateStatus(); break;
            case 4: {
                int id; cout << "Enter ID: "; cin >> id;
                searchShipment(id);
                break;
            }
            case 5: {
                string city; cout << "Enter City: "; cin >> city;
                searchShipment(city);
                break;
            }
            case 6: cout << "Logging out..." << endl; break;
            default: cout << "Invalid option." << endl;
        }
    } while (choice != 6);
}

void Admin::addShipment() {
    int id;
    string s, r, c;
    double w;

    cout << "\n--- New Shipment ---" << endl;
    cout << "Enter Tracking ID: "; cin >> id;
    cout << "Sender Name: "; cin >> s;
    cout << "Receiver Name: "; cin >> r;
    cout << "Destination City: "; cin >> c;
    
    // --- OOP CONCEPT: Exception Handling ---
    try {
        cout << "Weight (kg): "; cin >> w;
        if (w <= 0) throw "Weight must be positive!";
    }
    catch(const char* msg) {
        cerr << "Error: " << msg << " Setting weight to 1kg default." << endl;
        w = 1.0;
    }

    Shipment newShip(id, s, r, c, w);
    saveShipmentToFile(newShip);
    cout << "Shipment Added Successfully!" << endl;
}

void Admin::saveShipmentToFile(const Shipment& s) {
    ofstream file("shipments.csv", ios::app); // Append mode
    if (file.is_open()) {
        file << s.getID() << "," << s.getSender() << "," << s.getReceiver() 
             << "," << s.getCity() << "," << s.getWeight() << "," << s.getStatus() << endl;
        file.close();
    }
}

void Admin::viewAllShipments() {
    ifstream file("shipments.csv");
    string line;
    cout << "\n--- All Shipments ---" << endl;
    while(getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> data;
        while(getline(ss, segment, ',')) data.push_back(segment);

        if(data.size() >= 6) {
            // Reconstruct object to use Friend Function
            Shipment temp(stoi(data[0]), data[1], data[2], data[3], stod(data[4]), data[5]);
            temp.display();
            // Call Friend Function to show hidden data
            auditShipment(temp); 
        }
    }
    file.close();
}

void Admin::updateStatus() {
    // NOTE: For simple CSV handling, we usually read all to memory, update, then rewrite.
    // For this demo, we will simulate the logic or perform a simple append update.
    // Real implementation requires rewriting the temp file.
    cout << "Feature: Update Status (Requires rewriting CSV - Implemented in Full Version)" << endl;
}

// --- OOP CONCEPT: Function Overloading (1/2) ---
void Admin::searchShipment(int id) {
    ifstream file("shipments.csv");
    string line;
    bool found = false;
    while(getline(file, line)) {
        stringstream ss(line);
        string strId;
        getline(ss, strId, ',');
        if(stoi(strId) == id) {
            cout << "Found: " << line << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "ID not found." << endl;
}

// --- OOP CONCEPT: Function Overloading (2/2) ---
void Admin::searchShipment(string city) {
    ifstream file("shipments.csv");
    string line;
    cout << "Shipments for " << city << ":" << endl;
    while(getline(file, line)) {
        if(line.find(city) != string::npos) {
            cout << line << endl;
        }
    }
}
