#ifndef BATTLE_H
#define BATTLE_H
#include"Player.h"
#include"Opponent.h"
#include"RandomPoke.h"
#include"pokemon.h"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <filesystem>
#include<algorithm>
#include<string>

class Battle
{

protected:
    Pokemon* player_pokemons;
    Pokemon* opponent;
    Pokemon chosenPokemon;
    bool win = false;
    
    
public:
    
    virtual void displayBattle(Pokemon a, Pokemon b, bool check) ;
    int Attack(Pokemon a, Pokemon b);
    virtual void GenerateOpponent( int num, string file);
    void checkEvolve(Player* player_list);
    void checkWin(Player* player_list, string PokeName);
    
};




#endif