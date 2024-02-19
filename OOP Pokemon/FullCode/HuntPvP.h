#ifndef HUNTPVP_H
#define HUNTPVP_H

#include"Battle.h"
#include"Player.h"
#include"Opponent.h"
#include"RandomPoke.h"
#include"pokemon.h"
#include"Stage1Pokemon.h"
#include"Stage2Pokemon.h"
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class HuntPvP : public Battle
{   

    string wildPokemon;
    string basic = "basic.txt";
    
public:
    HuntPvP(Player* player_list);
    
    void GenerateWildPokemon(Player* player_list, int num, string file);
    bool HuntPvPYorN(Pokemon b);
    void checkEvolve(Player * player_list);
    void checkWin(Player * player_list, string PokeName);
};



#endif
