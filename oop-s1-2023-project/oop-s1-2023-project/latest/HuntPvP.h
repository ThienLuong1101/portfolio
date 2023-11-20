#ifndef HUNTPVP_H
#define HUNTPVP_H

// Include necessary header files
#include <algorithm>  // Standard template library algorithms
#include <iostream>   // Input and output stream
#include <string>     // String manipulation

#include "Battle.h"         // Battle class definition
#include "Opponent.h"       // Opponent class definition
#include "Player.h"         // Player class definition
#include "RandomPoke.h"     // RandomPoke class definition
#include "Stage1Pokemon.h"  // Stage1Pokemon class definition
#include "Stage2Pokemon.h"  // Stage2Pokemon class definition
#include "pokemon.h"        // Pokemon class definition

using namespace std;

// Define the HuntPvP class, which is derived from the Battle class
class HuntPvP : public Battle {
  string wildPokemon;          // String to store the wild Pokemon's name
  string basic = "basic.txt";  // Default filename for basic data

 public:
  // Constructor for the HuntPvP class, which takes an array of Player objects
  HuntPvP(Player* player_list);

  // Function to generate wild Pokemon and add it to the player's list
  void GenerateWildPokemon(Player* player_list, int num, string file);

  // Function to prompt the user whether to hunt for a wild Pokemon or not
  bool HuntPvPYorN(Pokemon b);

  // Function to check if a player's Pokemon can evolve to a higher stage
  void checkEvolve(Player* player_list);

  // Function to check if a player has won the game with a specific Pokemon
  void checkWin(Player* player_list, string PokeName);
};

#endif
