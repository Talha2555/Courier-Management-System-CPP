#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

// --- OOP CONCEPT: Abstraction ---
class User {
protected:
    string username;
    string password;
    string role;

public:
    // Constructor
    User(string u, string p, string r) : username(u), password(p), role(r) {}
    
    // --- OOP CONCEPT: Destructor (Virtual) ---
    virtual ~User() {
        // Virtual destructor ensures child classes are cleaned up correctly
    }

    string getUsername() const { return username; }

    // --- OOP CONCEPT: Pure Virtual Function (Polymorphism) ---
    // This makes User an Abstract Class. 
    // It forces 'Admin' and 'Customer' to create their own version of menu().
    virtual void menu() = 0;
};

#endif
