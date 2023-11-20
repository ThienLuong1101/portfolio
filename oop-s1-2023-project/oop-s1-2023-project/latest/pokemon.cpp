#include "pokemon.h"

// Constructor with no arguments
Pokemon::Pokemon() {
  name = "";
  type = "";
  sound = "";
  hp = 0;
  attack = 0;
  speed = 0;
  NumOfWin = 0;
}

// Constructor with arguments to initialize the Pokemon object
Pokemon::Pokemon(string _name, string _type, string _sound, int _hp,
                 int _attack, int _speed)
    : name(_name),
      type(_type),
      sound(_sound),
      hp(_hp),
      attack(_attack),
      speed(_speed) {}

// Setter methods to assign values to the private member variables

// Set the name of the Pokemon
void Pokemon::setName(string _name) { name = _name; }

// Set the type of the Pokemon
void Pokemon::setType(string _type) { type = _type; }

// Set the sound of the Pokemon
void Pokemon::setSound(string _sound) { sound = _sound; }

// Set the hit points (HP) of the Pokemon
void Pokemon::setHP(int _hp) { hp = _hp; }

// Set the attack power of the Pokemon
void Pokemon::setAttack(int _attack) { attack = _attack; }

// Set the speed of the Pokemon
void Pokemon::setSpeed(int _speed) { speed = _speed; }

// Set the number of wins for the Pokemon
void Pokemon::setNumOfWins(int num) { NumOfWin += num; }

// Getter methods to retrieve the values of the private member variables

// Get the name of the Pokemon
string Pokemon::getName() { return name; }

// Get the type of the Pokemon
string Pokemon::getType() { return type; }

// Get the sound of the Pokemon
string Pokemon::getSound() { return sound; }

// Get the hit points (HP) of the Pokemon
int Pokemon::getHP() { return hp; }

// Get the attack power of the Pokemon
int Pokemon::getAttack() { return attack; }

// Get the speed of the Pokemon
int Pokemon::getSpeed() { return speed; }

// Get the number of wins of the Pokemon
int Pokemon::getNumOfWin() { return NumOfWin; }

// void Pokemon::useSkill(Skill& skill) {
//     std::cout << name << " used " << skill.getName() << " for " <<
//     skill.getPower() << " damage!" << std::endl;
// }

// Destructor for the Pokemon class
Pokemon::~Pokemon() {}
