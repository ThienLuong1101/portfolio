#include"RandomPoke.h"


RandomPoke::RandomPoke() {} 

RandomPoke::RandomPoke(string filename) : filename(filename) {
    loadNamesFromFile();
}

string RandomPoke::getRandomName() {
     if (names.empty()) {
            return "No names available";
        }

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(0, names.size() - 1);
        int randomIndex = distribution(gen);

        return names[randomIndex];
}


