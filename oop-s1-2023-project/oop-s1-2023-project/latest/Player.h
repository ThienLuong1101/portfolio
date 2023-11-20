#ifndef PLAYER_H
#define PLAYER_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "pokemon.h"  // Include the Pokemon class header file.

namespace fs = std::filesystem;
using namespace std;

class Player {
 protected:
  string name;  // The name of the player or trainer.
  int len_list =
      3;  // The length of the player's list of Pokémon (default is 3).
  int current = 0;       // The current position in the list.
  Pokemon* player_list;  // An array of Pokemon objects.

 public:
  Player();                             // Default constructor.
  void set_trainer_name(string _name);  // Setter for the player's name.
  void set_len_list(int len);  // Setter for the length of the Pokemon list.
  int get_len_list();          // Getter for the length of the Pokemon list.
  int get_current();           // Getter for the current position in the list.
  Pokemon* GetPlayerList();    // Getter for the player's list of Pokemon.
  string get_trainer_name();   // Getter for the player's name.

  Player(
      string _name);  // Parameterized constructor that sets the player's name.
  string makeFile();  // Function to create a file (not defined in this code).
  void AddPokemon(string filename,
                  string PokeName);  // Function to add a Pokemon to the list.
  void SavePokeListToFile();  // Function to save the Pokemon list to a file.
  virtual void printPokemonList();  // Function to print the list of Pokemon (to
                                    // be defined in derived classes).
  Pokemon
  ChoosePokemon();  // Function to choose a Pokemon (not defined in this code).
  vector<string> getPokemonNames(
      string filename);  // Function to get Pokemon names from a file.
  ~Player();  // Destructor to release resources (memory in this case).
};

#endif  // PLAYER_H
