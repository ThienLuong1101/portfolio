#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
// #include "Skill.h"  // This is a commented-out include statement, possibly
// for a future feature.

using namespace std;

class Pokemon {
 protected:
  string name, type, sound;
  int hp, attack, speed;
  int NumOfWin;

 public:
  // Default constructor
  Pokemon();

  // Destructor
  ~Pokemon();

  // Parameterized constructor
  Pokemon(string _name, string _type, string _sound, int _hp, int _attack,
          int _speed);

  // Getters for the class properties
  string getName();
  string getType();
  virtual string
  getSound();  // A virtual function for getting the sound of a Pokemon.
  int getHP();
  int getAttack();
  int getSpeed();
  int getNumOfWin();

  // Setters for the class properties
  void setName(string _name);
  void setType(string _type);
  void setSound(string _sound);
  void setHP(int hp);
  void setAttack(int attack);
  void setNumOfWins(int num);
  void setSpeed(int speed);

  // Additional methods or features can be added in the future, such as a method
  // for using skills. void useSkill(Skill& skill);
};

#endif
