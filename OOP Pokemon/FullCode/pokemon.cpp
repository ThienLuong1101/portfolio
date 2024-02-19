#include "pokemon.h"

Pokemon::Pokemon() {
    name = "";
    type = "";
    sound = "";
    hp = 0;
    attack = 0;
    speed = 0;
    NumOfWin = 0;
}

Pokemon::Pokemon(string _name, string _type, string _sound, int _hp, int _attack, int _speed)
    : name(_name), type(_type), sound(_sound), hp(_hp), attack(_attack), speed(_speed) {}


//set
void Pokemon::setName(string _name) { name = _name; }
void Pokemon::setType(string _type) { type = _type; }
void Pokemon::setSound(string _sound) { sound = _sound; }
void Pokemon::setHP(int _hp) { hp = _hp; }
void Pokemon::setAttack(int _attack) { attack = _attack; }
void Pokemon::setSpeed(int _speed) { speed = _speed; }
void Pokemon::setNumOfWins(int num) { NumOfWin += num; }

//get
string Pokemon::getName() { return name; }
string Pokemon::getType() { return type; }
string Pokemon::getSound() { return sound; }
int Pokemon::getHP() { return hp; }
int Pokemon::getAttack() { return attack; }
int Pokemon::getSpeed() { return speed; }
int Pokemon::getNumOfWin() { return NumOfWin; }

// void Pokemon::useSkill(Skill& skill) {
//     std::cout << name << " used " << skill.getName() << " for " << skill.getPower() << " damage!" << std::endl;
// }

Pokemon::~Pokemon() {}
