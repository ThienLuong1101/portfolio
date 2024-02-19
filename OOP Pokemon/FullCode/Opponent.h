#ifndef OPPONENT_H
#define OPPONENT_H
#include"RandomPoke.h"
#include"Player.h"
#include"pokemon.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time
using namespace std;
class Opponent : public Player
{
protected:
    int lenList;
    Pokemon* Opponent_Poke;
public:
    // Constructor that sets the opponent's name and generates Pokémon
    Opponent();
    Opponent(int numPokemon);
    Pokemon* GetOpponentList();

    // Function to generate random Pokémon for the opponent
    vector<string> GenerateRandomPokemon(string file);

    // Function to print the opponent's Pokémon list
    ~Opponent();
    void printPokemonList();
};


#endif