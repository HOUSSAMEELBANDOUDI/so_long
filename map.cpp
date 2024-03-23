#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to validate if a character is valid
bool isValidChar(char c) {
    return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

// Function to validate if the map is surrounded by walls
bool isSurroundedByWalls(const vector<string>& map) {
    // Check top and bottom rows
    for (int i = 0; i < map[0].size(); ++i) {
        if (map[0][i] != '1' || map.back()[i] != '1') {
            return false;
        }
    }
    // Check left and right columns
    for (int i = 0; i < map.size(); ++i) {
        if (map[i][0] != '1' || map[i].back() != '1') {
            return false;
        }
    }
    return true;
}

// Function to validate the map
bool validateMap(const vector<string>& map) {
    // Track counts of required components
    int exitCount = 0, collectibleCount = 0, startPositionCount = 0;

    for (const string& line : map) {
        // Validate each character in the line
        for (char c : line) {
            if (!isValidChar(c)) {
                return false;
            }
            if (c == 'E') {
                exitCount++;
            } else if (c == 'C') {
                collectibleCount++;
            } else if (c == 'P') {
                startPositionCount++;
            }
        }
    }

    // Check for duplicate characters
    if (exitCount > 1 || startPositionCount > 1) {
        return false;
    }

    // Check for required components
    if (exitCount != 1 || collectibleCount < 1 || startPositionCount != 1) {
        return false;
    }

    // Check if the map is surrounded by walls
    if (!isSurroundedByWalls(map)) {
        return false;
    }

    // Check for a valid path (implement this logic)

    return true;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Open the file
    ifstream file("map.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file map.txt" << endl;
        return 1;
    }

    // Vector to store map data
    vector<string> map;

    // Read the file line by line
    string line;
    while (getline(file, line)) {
        // Add the line to the vector
        map.push_back(line);
    }

    // Close the file
    if (validateMap(map)) {
        cout << "Map is valid." << endl;
    } else {
        cout << "Map is invalid." << endl;
    }
     cout << "Map Contents:" << endl;
     const string row ;
    for (const string& row : map) {
        cout << row << endl;
    }
    cout << row << endl;
}


