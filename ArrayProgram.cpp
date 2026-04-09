#include "Resident.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

void loadArrayCSV(string filename, vector<Resident>& list) {
    ifstream file(filename);
    string line, word;
    if (!file.is_open()) {
        return;
    }
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
        list.push_back(r);
    }
}

void performTask4Analysis(const vector<Resident>& list) {
    
    string groupNames[5] = {
        "6-17: Children/Teens",
        "18-25: Students/Young Adults",
        "26-45: Working (Early)",
        "46-60: Working (Late)",
        "61-100: Seniors/Retirees"
    };

    double totalEmissions[5] = { 0, 0, 0, 0, 0 };
    int residentCounts[5] = { 0, 0, 0, 0, 0 };

    int modeCounts[5][4] = { 0 }; 
    string modeNames[4] = { "Car", "Bus", "Bicycle", "Walking" };

    for (int i = 0; i < list.size(); i++) {
        Resident r = list[i];
        int groupIdx = -1;

        if (r.age >= 6 && r.age <= 17) {
            groupIdx = 0;
        }
        else if (r.age >= 18 && r.age <= 25) {
            groupIdx = 1;
        }
        else if (r.age >= 26 && r.age <= 45) {
            groupIdx = 2;
        }
        else if (r.age >= 46 && r.age <= 60) {
            groupIdx = 3;
        }
        else if (r.age >= 61) {
            groupIdx = 4;
        }

        if (groupIdx != -1) {
            totalEmissions[groupIdx] += r.monthlyEmission;
            residentCounts[groupIdx]++;

            if (r.mode == "Car") {
                modeCounts[groupIdx][0]++;
            }
            else if (r.mode == "Bus") {
                modeCounts[groupIdx][1]++;
            }
            else if (r.mode == "Bicycle") {
                modeCounts[groupIdx][2]++;
            }
            else if (r.mode == "Walking") {
                modeCounts[groupIdx][3]++;
            }
        }
    }

    // 2. Display the results in a table
    cout << "\n---------------------------------------------------------------------------" << endl;
    cout << left << setw(30) << "Age Group" << setw(15) << "Pref. Mode" << setw(15) << "Total CO2" << "Avg CO2" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        if (residentCounts[i] > 0) {
            int maxVal = -1;
            int bestModeIdx = 0;
            for (int m = 0; m < 4; m++) {
                if (modeCounts[i][m] > maxVal) {
                    maxVal = modeCounts[i][m];
                    bestModeIdx = m;
                }
            }

            double avg = totalEmissions[i] / residentCounts[i];

            cout << left << setw(30) << groupNames[i]
                << setw(15) << modeNames[bestModeIdx]
                << setw(15) << fixed << setprecision(2) << totalEmissions[i]
                << avg << " kg" << endl;
        }
    }
}

void runArrayVersion() {
    vector<Resident> cityA;
    loadArrayCSV("dataset1-cityA.csv", cityA);
    cout << "\n--- Array Program ---" << endl;
    performTask4Analysis(cityA);
}