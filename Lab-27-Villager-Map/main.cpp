//
//  main.cpp
//  COMSC-210 | Lab-27-Villager-Map | Guo An Wang
//  IDE: Xocde
//  Created by Guo An Wang on 11/2/25.
//

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//function output displays map content
//argument: std::map
//return: none
void output(const map<string, tuple<int,string,string>> &villagers);

//function search_map searches for an element based on searchKey
//arugment: std::map
//return: none
void search_map(const map<string, tuple<int,string,string>> &villagers);

//function friendship_level either increases the selected element
//argument: std::map
//return: none
void friendship_level(map<string, tuple<int,string,string>> &villagers,bool increase);

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagers;
    bool again = true;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyler"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers.insert({"Draco", make_tuple(7,"Dogs", "Catch em All!")});
    int choice;
    while (again) {
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                friendship_level(villagers, true);
                output(villagers);
                break;
            case 2:
                friendship_level(villagers, false);
                output(villagers);
                break;
            case 3:
                search_map(villagers);
                break;
            case 4:
                cout << "Exit Program" << endl;
                again = false;
                break;
            default:
                cout << "Not a valid choice" << endl;
                break;
        }
    }

    return 0;
}

void output(const map<string, tuple<int,string,string>> &villagers){
    // access the map using a range-based for loop
    cout << "Villagers and their data:" << endl;
    for (auto &pair : villagers) {
        cout << pair.first << ": " << "Friendship: " << get<0>(pair.second) << ", Species: " << get<1>(pair.second) << ", Phrase: " << get<2>(pair.second) << endl;
    }
}

void search_map(const map<string, tuple<int,string,string>> &villagers){
    string searchKey;
    cout << "Enter villager name: ";
    cin >> searchKey;
    cin.ignore();
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
        cout << "\nFound " << searchKey << "'s data: " << "Friendship: " << get<0>(it->second) << ", Species: " << get<1>(it->second) << ", Phrase: " << get<2>(it->second) << endl;
    } else // if searchKey is not found
        cout << endl << searchKey << " not found." << endl;

}

void friendship_level(map<string, tuple<int,string,string>> &villagers, bool increase){
    string searchKey;
    cout << "Enter villager name: ";
    cin >> searchKey;
    cin.ignore();
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
        int current = get<0>(it->second);
        if (increase) {
            if (current < 10) {
                get<0>(it->second) = current + 1;
            } else {
                cout << searchKey << "'s Already at Max Friendship level(10)" << endl;
            }
        } else {
            if (current > 0) {
                get<0>(it->second) = current - 1;
            } else {
                cout << searchKey << "'s Friendship level cannot go below 0" << endl;
            }
        }
    } else // if searchKey is not found
        cout << endl << searchKey << " not found." << endl;
}
