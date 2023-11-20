#include "Stage1Pokemon.h"

// Default constructor for Stage1Pokemon, initializes it as a base Pokemon.
Stage1Pokemon::Stage1Pokemon() : Pokemon() {}

// Parameterized constructor for Stage1Pokemon, sets attributes based on the
// provided values.
Stage1Pokemon::Stage1Pokemon(string _name, string _type, string _sound, int _hp,
                             int _attack, int _speed)
    : Pokemon(_name, _type, _sound, _hp, _attack, _speed) {}

// Evolve function to evolve a Stage1Pokemon from its basic form (basic) if
// conditions are met.
bool Stage1Pokemon::Evolve(Pokemon basic, Player* player_list) {
  // Define a map to store the evolution data for each Pokémon

  // Check if the basic Pokemon has won a certain number of battles (s1) and if
  // it is eligible for evolution.
  if (basic.getNumOfWin() == s1 && !CheckEvolve(basic.getName(), Stage1Data)) {
    string name = basic.getName();
    int speed = basic.getSpeed();
    int attack = basic.getAttack();
    int hp = basic.getHP();

    // Check if the given name exists in the map
    if (Stage1Data.find(name) != Stage1Data.end()) {
      // Retrieve the evolved form and update the attributes
      string evolvedName = Stage1Data[name];
      setHP(hp * 2);
      setAttack(attack + 20);
      setSpeed(speed);
      setType(basic.getType());
      setSound(basic.getSound());
      setName(evolvedName);

      cout << "Congratulations! " << name << " evolved to " << evolvedName
           << endl;
      this_thread::sleep_for(chrono::seconds(1));
      return true;
    }
  }
  return false;
}

// Function to check if a Pokemon's name is in the evolution data map.
bool Stage1Pokemon::CheckEvolve(string name, map<string, string> dataMap) {
  for (const auto& pair : dataMap) {
    if (pair.second == name) {
      return true;  // Name found in the second column
    }
  }
  return false;  // Name not found in the second column
}

// Function to perform a random cute action for the Stage1Pokemon.
void Stage1Pokemon::Action() {
  // List of cute actions
  string cuteActions[] = {"Sleeping z.z",  "Hiding",  "Belly Dancing",
                          "Doing nothing", "Rapping", "Depressing"};
  random_device rd;
  mt19937 gen(rd());
  int numActions = sizeof(cuteActions) / sizeof(cuteActions[0]);
  uniform_int_distribution<int> distribution(0, numActions - 1);
  int i = distribution(gen);

  cout << getName() << " is " << cuteActions[i] << "!!!" << endl;
}

// Function to get the evolution data map for Stage1Pokemon.
map<string, string> Stage1Pokemon::GetStage1Data() { return Stage1Data; }
