📦 Courier Management System (CMS)

A Console-Based C++ application designed to manage courier logistics, shipment tracking, and user management. This project demonstrates advanced Object-Oriented Programming (OOP) concepts and file handling in a real-world scenario.

🚀 Features

🔐 Authentication Module

Secure Login: Role-based access control (Admin vs. Customer).

Registration: New customers can sign up instantly.

Data Persistence: User credentials stored securely in users.csv.

👨‍💼 Admin Features (Manager)

Add Shipments: Create new shipment records with validation.

View All Shipments: List all parcels in the network.

Audit System: Uses Friend Functions to access confidential shipment data (e.g., Profit Margins).

Search: Find shipments by ID or City using Function Overloading.

👤 Customer Features (User)

Place Order: Calculate costs dynamically using Templates and generate unique Tracking IDs.

Track Order: Real-time status updates by searching the CSV database.

Order History: View personal shipment logs.

🛠️ Technical Stack

Language: C++ (Standard C++11)

IDE Used: Dev-C++ / VS Code

Database: Text-based File Handling (CSV)

Paradigm: Object-Oriented Programming (OOP)

📚 OOP Concepts Implemented

This project covers a comprehensive list of OOP principles:

Concept

Implementation in Project

Classes & Objects

Shipment, User, Admin, Customer

Inheritance

Admin and Customer inherit from the User class

Polymorphism

Runtime polymorphism using User* pointers and virtual functions

Abstraction

User is an Abstract Base Class (Pure Virtual Function)

Encapsulation

Private data members (password, profit margin) accessed via Getters

File Handling

Reading/Writing to shipments.csv and users.csv

Templates

Generic calculateCost<T>() function for int/float weights

Exception Handling

try-catch blocks to validate inputs (e.g., negative weight)

Friend Functions

auditShipment() allows Admin to see private financial data

Function Overloading

Search logic: search(int ID) vs search(string City)

Operator Overloading

<< operator overloaded to print Shipment objects easily

Static Members

totalShipmentCount tracks active objects in memory

Composition

Shipment class has-a Date class

Deep/Shallow Copy

Custom Copy Constructor implemented

⚙️ How to Run

Clone the Repository

git clone [https://github.com/YourUsername/Courier-Management-System.git](https://github.com/YourUsername/Courier-Management-System.git)


Compile the Code
Ensure you have a C++ compiler (g++) installed.

g++ main.cpp admin.cpp customer.cpp -o cms.exe


Note: If using Dev-C++, simply open CMS.dev and press F11.

Run the Application

./cms.exe


🔑 Default Credentials

Use these details to test the application:

Role

Username

Password

Admin

admin

admin123

Admin

manager

manager123

Customer

ali

pass1

📂 File Structure

main.cpp: Entry point, handles Authentication and Polymorphism.

User.h: Abstract Base Class for users.

Admin.h/cpp: Logic for management tasks.

Customer.h/cpp: Logic for ordering and tracking.

shipment.h: Data class containing Core Logic, Friend functions, and Operator Overloading.

Utils.h: Contains Template definitions.

*.csv: Database files for data persistence.

📝 Author

TALHA KHAN
University Project - Object Oriented Programming (OOP)
