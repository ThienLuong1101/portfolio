#include "Stage2Pokemon.h"

// Constructor for Stage2Pokemon, it initializes the object with default values.
Stage2Pokemon::Stage2Pokemon() : Stage1Pokemon() {}

// Parameterized constructor for Stage2Pokemon, allowing you to set attributes
// during initialization.
Stage2Pokemon::Stage2Pokemon(string _name, string _type, string _sound, int _hp,
                             int _attack, int _speed)
    : Stage1Pokemon(_name, _type, _sound, _hp, _attack, _speed) {}

// Evolve method to evolve a basic Pokemon to a Stage2 Pokemon.
bool Stage2Pokemon::Evolve(Pokemon basic, Player* player_list) {
  // Check if the basic Pokemon has won a certain number of battles and has not
  // evolved already.
  if (basic.getNumOfWin() == s2 && !CheckEvolve(basic.getName(), Stage2Data)) {
    string name = basic.getName();
    int speed = basic.getSpeed();
    int attack = basic.getAttack();
    int hp = basic.getHP();

    // Check if the given name exists in the Stage2Data map.
    if (Stage2Data.find(name) != Stage2Data.end()) {
      // Retrieve the evolved form and update the attributes of the
      // Stage2Pokemon.
      string evolvedName = Stage2Data[name];
      setHP(hp + 100);
      setAttack(attack + 20);
      setSpeed(speed);
      setType(basic.getType());
      setSound(basic.getSound());
      setName(evolvedName);
      cout << "Congratulations! " << name << " has evolved into " << evolvedName
           << endl;
      return true;
    }
  }
  return false;
}

// Emoji method to display a random cute action associated with the
// Stage2Pokemon.
void Stage2Pokemon::Emoji() {
  // List of cute actions in an array.
  string EmojiList[] = {"-.-", ":))", ":D", ":((", ">.<", "@.@", "($.$)"};

  // Initialize random number generator.
  random_device rd;
  mt19937 gen(rd());

  // Calculate the number of actions in the EmojiList array.
  int numActions = sizeof(EmojiList) / sizeof(EmojiList[0]);

  // Create a uniform distribution for generating random numbers within the
  // range of actions.
  uniform_int_distribution<int> distribution(0, numActions - 1);

  // Generate a random index to select a cute action.
  int i = distribution(gen);

  // Display the selected cute action for the Stage2Pokemon.
  cout << getName() << " is making this cute face: " << EmojiList[i] << "! "
       << endl;
}

// GetStage2Data method to retrieve the Stage2Data map.
map<string, string> Stage2Pokemon::GetStage2Data() { return Stage2Data; }
