#ifndef RANDOMPOKE_H
#define RANDOMPOKE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<random>
using namespace std;
class RandomPoke {
    void loadNamesFromFile() {
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Failed to open " << filename << endl;
            return;
        }

        string name;
        while (getline(file, name)) {
            names.push_back(name);
        }

        file.close();
    }

    string filename;
    vector<string> names;
public:
    RandomPoke();
    RandomPoke(string filename);
    string getRandomName();
};


#endif