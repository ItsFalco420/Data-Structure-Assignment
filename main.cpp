#include "Resident.hpp"
#include <iostream>

using namespace std;

int main() {
    int input = 0; 

    while (input != 3) { 
        cout << "1. Use Array Program" << endl;
        cout << "2. Use Linked List Program" << endl;
        cout << "3. Exit Program" << endl;
        cout << "Enter Choice: ";

        cin >> input;

        if (input == 1) {
            runArrayVersion();
        }
        else if (input == 2) {
            runLinkedListVersion();
        }
        else if (input == 3) {
            cout << "Closing system..." << endl;
        }
        else {
            cout << "Invalid input. Please select 1, 2, or 3." << endl;
        }
    }

    return 0;
}