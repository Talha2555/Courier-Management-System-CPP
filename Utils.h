#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

// --- OOP CONCEPT: Generic Functions (Templates) ---
// Calculates cost based on weight. Works for int (10kg) and float (10.5kg).
template <typename T>
T calculateCost(T weight) {
    // Simple formula: Rate is 100 per unit + 50 base charge
    return (weight * 100) + 50;
}

#endif
