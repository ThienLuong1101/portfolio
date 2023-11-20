#ifndef OPPONENT_H
#define OPPONENT_H

#include <cstdlib>  // Include the C standard library for functions like rand and srand
#include <ctime>     // Include the C standard time library for time functions
#include <fstream>   // Include the C++ standard file input/output library
#include <iostream>  // Include the C++ standard input/output library
#include <string>    // Include the C++ standard string library
#include <vector>    // Include the C++ standard vector container

#include "Player.h"      // Include the header file for Player
#include "RandomPoke.h"  // Include the header file for RandomPoke
#include "pokemon.h"     // Include the header file for the Pokemon class
using namespace std;

class Opponent : public Player {
 protected:
  int lenList;  // An integer to store the length of the opponent's Pokemon list
  Pokemon* Opponent_Poke;  // A pointer to an array of Pokemon objects to store
                           // the opponent's Pokemon

 public:
  // Constructor that sets the opponent's name and generates Pokémon
  Opponent();
  Opponent(int numPokemon);  // Constructor with an argument to specify the
                             // number of Pokemon

  Pokemon* GetOpponentList();  // Function to get the list of opponent's Pokemon

  // Function to generate random Pokémon for the opponent
  vector<string> GenerateRandomPokemon(
      string file);  // Function to generate random Pokemon from a file

  // Function to print the opponent's Pokémon list
  ~Opponent();  // Destructor to clean up resources when the Opponent object is
                // destroyed

  void printPokemonList();  // Function to print the list of opponent's Pokemon
};

#endif
