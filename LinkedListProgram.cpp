#include "Resident.hpp"
#include <fstream>
#include <sstream>

struct Node {
    Resident data;
    Node* next;
};

void loadListCSV(string filename, Node*& head) {
    ifstream file(filename);
    string line, word;
    if (!file.is_open()) return;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        Resident r;
        getline(ss, r.id, ',');
        getline(ss, word, ','); r.age = stoi(word);
        getline(ss, r.mode, ',');
        getline(ss, word, ','); r.distance = stod(word);
        getline(ss, word, ','); r.factor = stod(word);
        getline(ss, word, ','); r.days = stoi(word);
        r.monthlyEmission = r.distance * r.factor * r.days;

        Node* newNode = new Node{ r, head };
        head = newNode;
    }
}

void runLinkedListVersion() {
    Node* head = nullptr;
    loadListCSV("dataset1-cityA.csv", head);
    cout << "\n--- Linked List Program ---" << endl;
    // (Your team members will add sorting/searching here later)
}