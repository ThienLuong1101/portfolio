#ifndef STAGE1POKEMON_H
#define STAGE1POKEMON_H

#include"pokemon.h"
#include"Player.h"
#include"NewGame.h"
#include <iostream>
#include<string>
#include<map>
#include <cstdlib> // for rand and srand functions
#include <ctime>   // for time function

class Stage1Pokemon : public Pokemon {
private:
    int s1 = 1;
    
    
    std::map<string, string> Stage1Data = {
        {"Charmander", "Charmeleon"},
        {"Torchic", "Combusken"},
        {"Froakie", "Frogadier"},
        {"Squirtle", "Wartortle"},
        {"Bulbasaur", "Ivysaur"},
        {"Treecko", "Grovyle"}
    };
public:
    Stage1Pokemon();
    Stage1Pokemon(string _name, string _type, string _sound, int _hp, int _attack, int _speed);
    bool virtual Evolve(Pokemon basic, Player * player_list);
    bool CheckEvolve(string name, map<string, string> dataMap);
    void Action();

    map<string, string> GetStage1Data();
    
};

#endif