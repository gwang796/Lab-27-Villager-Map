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

int main() {
    // declarations
    map<string, tuple<int,string,string>> villagers;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyler"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers.insert({"Draco", make_tuple(7,"Dogs", "Catch em All!")});

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (auto &pair : villagers) {
        cout << pair.first << ": " << "Friendship: " << get<0>(pair.second) << ", Species: " << get<1>(pair.second) << ", Phrase: " << get<2>(pair.second) << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their data (iterators):" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villagers.begin();
                                               it != villagers.end(); ++it) {
        cout << it->first << ": " << "Friendship: " << get<0>(it->second) << ", Species: " << get<1>(it->second) << ", Phrase: " << get<2>(it->second) << endl;
    }

    // delete an element
    villagers.erase("Draco");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
        cout << "\nFound " << searchKey << "'s data: " << "Friendship: " << get<0>(it->second) << ", Species: " << get<1>(it->second) << ", Phrase: " << get<2>(it->second) << endl;
    } else // if searchKey is not found
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
