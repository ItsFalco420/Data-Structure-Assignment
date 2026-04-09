#ifndef RESIDENT_HPP
#define RESIDENT_HPP

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Resident {
    string id;
    int age;
    string mode;
    double distance;
    double factor;
    int days;
    double monthlyEmission; 
};

inline string GetAge(int age) {
    if (age >= 6 && age <= 17) {
        return "6-17: Children/Teens";
    }
    else if (age >= 18 && age <= 25) {
        return "18-25: Students/Young Adults";
    }
    else if (age >= 26 && age <= 45) {
        return "26-45: Working (Early Career)";
    }
    else if (age >= 46 && age <= 60) {
        return "46-60: Working (Late Career)";
    }
    else {
        return "61-100: Seniors/Retirees";
    }
}

void runArrayVersion();
void runLinkedListVersion();

#endif