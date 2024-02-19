#ifndef STAGE2POKEMON_H
#define STAGE2POKEMON_H

#include"pokemon.h"
#include"Player.h"
#include"Stage1Pokemon.h"
#include <iostream>
#include<string>
#include<map>
#include <cstdlib> // for rand and srand functions
#include <ctime>   // for time function

class Stage2Pokemon : public Stage1Pokemon {
private:
    int s2 = 2;
    
    map<string, string> Stage2Data = {
        {"Charmeleon", "Charizard"},
        {"Combusken", "Blaziken"},
        {"Frogadier", "Greninja"},
        {"Wartortle","Blastoise"},
        {"Ivysaur","Venusaur"},
        {"Grovyle","Sceptile"}
    };
public:
    Stage2Pokemon();
    Stage2Pokemon(string _name, string _type, string _sound, int _hp, int _attack, int _speed);
   
    bool Evolve(Pokemon basic, Player * player_list) override;

    map<string, string> GetStage2Data();
    
    void Emoji();
};

#endif