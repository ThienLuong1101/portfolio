#ifndef POKEMON_H
#define POKEMON_H

#include<iostream>
// #include "Skill.h"
using namespace std;
class Pokemon
{
protected:
    string name, type, sound;
    int hp, attack, speed;
    int NumOfWin;
public:
    
    Pokemon();
    ~Pokemon();
    Pokemon(string _name, string _type, string _sound, int _hp, int _attack, int _speed);
    string getName();
    string getType();
    virtual string getSound();
    int getHP();
    int getAttack();
    int getSpeed();
    int getNumOfWin();
    // Setters
    void setName( string _name);
    void setType( string _type);
    void setSound( string _sound);
    void setHP(int hp);
    void setAttack(int attack);
    void setNumOfWins(int num);
    void setSpeed(int speed);
    // void useSkill(Skill& skill);

};

#endif