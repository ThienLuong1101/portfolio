#ifndef BATTLE_H
#define BATTLE_H

// Include necessary header files for this class.
#include "Opponent.h"
#include "Player.h"
#include "RandomPoke.h"
#include "pokemon.h"

// Include standard C++ libraries.
#include <algorithm>   // For various algorithms.
#include <chrono>      // For time-related functions.
#include <filesystem>  // For working with the file system.
#include <fstream>     // For file handling.
#include <iostream>    // For input and output streams.
#include <string>      // For string manipulation.
#include <string>      // Include the string header again (redundant).
#include <thread>      // For managing threads.

// Define the Battle class.
class Battle {
 protected:
  // Declare member variables.
  Pokemon* player_pokemons;  // Pointer to an array of player's Pokémon.
  Pokemon* opponent;         // Pointer to the opponent's Pokémon.
  Pokemon chosenPokemon;     // The Pokémon the player has chosen.
  bool win = false;          // Flag to track if the player has won the battle.

 public:
  // Declare public member functions.

  // Virtual function to display a battle between two Pokémon and a check flag.
  virtual void displayBattle(Pokemon a, Pokemon b, bool check);

  // Function to perform an attack between two Pokémon and return the damage.
  int Attack(Pokemon a, Pokemon b);

  // Virtual function to generate an opponent using a specified number and file
  // name.
  virtual void GenerateOpponent(int num, string file);

  // Function to check if a player's Pokémon can evolve.
  void checkEvolve(Player* player_list);

  // Function to check if the player has won by defeating an opponent with a
  // specific Pokémon name.
  void checkWin(Player* player_list, string PokeName);
};

// End of the Battle class declaration.
#endif
