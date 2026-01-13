#include <iostream>
#include <fstream>
#include <sstream>
#include "admin.h"
#include "customer.h"

using namespace std;
int Shipment::totalShipmentCount = 0;
// Helper to check login
// Returns "ADMIN", "CUSTOMER", or "" if failed
string authenticate(string u, string p) {
    ifstream file("users.csv");
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string fileUser, filePass, fileRole;
        
        getline(ss, fileUser, ',');
        getline(ss, filePass, ',');
        getline(ss, fileRole, ',');

        if(fileUser == u && filePass == p) {
            return fileRole;
        }
    }
    return "";
}

void registerCustomer() {
    string u, p;
    cout << "Enter new username: "; cin >> u;
    cout << "Enter new password: "; cin >> p;
    
    ofstream file("users.csv", ios::app);
    file << u << "," << p << ",CUSTOMER" << endl;
    file.close();
    cout << "Registered successfully! Please login." << endl;
}

int main() {
    int choice;
    cout << "======================================" << endl;
    cout << "   COURIER MANAGEMENT SYSTEM (CLI)    " << endl;
    cout << "======================================" << endl;
    
    while(true) {
        cout << "\n1. Login\n2. Register (Customer)\n3. Exit\nSelect: ";
        cin >> choice;

        if (choice == 3) break;
        
        if (choice == 2) {
            registerCustomer();
            continue;
        }

        if (choice == 1) {
            string u, p;
            cout << "Username: "; cin >> u;
            cout << "Password: "; cin >> p;

            string role = authenticate(u, p);

            // --- OOP CONCEPT: Polymorphism ---
            // We use a base class pointer 'User*' to hold child objects
            User* currentUser = nullptr;

            if (role == "ADMIN") {
                currentUser = new Admin(u, p);
            } else if (role == "CUSTOMER") {
                currentUser = new Customer(u, p);
            } else {
                cout << "Invalid Credentials!" << endl;
                continue;
            }

            // Polymorphic Call: Executes the specific menu() for Admin or Customer
            currentUser->menu();

            // Cleanup
            delete currentUser;
        }
    }
    return 0;
}
