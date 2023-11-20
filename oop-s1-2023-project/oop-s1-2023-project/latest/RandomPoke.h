#ifndef RANDOMPOKE_H
#define RANDOMPOKE_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

// Declaration of the RandomPoke class
class RandomPoke {
  // Private member function to load names from a file
  void loadNamesFromFile() {
    // Attempt to open the specified file
    ifstream file(filename);

    // Check if the file was successfully opened
    if (!file.is_open()) {
      cerr << "Failed to open " << filename << endl;
      return;
    }

    string name;
    // Read names from the file and store them in the 'names' vector
    while (getline(file, name)) {
      names.push_back(name);
    }

    // Close the file after reading
    file.close();
  }

  // Private members of the class
  string filename;  // Stores the name of the file from which names are loaded
  vector<string> names;  // Stores the loaded names

 public:
  // Default constructor for RandomPoke class
  RandomPoke();

  // Parameterized constructor for RandomPoke class
  RandomPoke(string filename);

  // Public member function to get a random name from the loaded names
  string getRandomName();
};

#endif
