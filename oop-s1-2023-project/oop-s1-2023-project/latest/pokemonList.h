#ifndef POKEMONLIST_H
#define POKEMONLIST_H

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

#include "CurrentGame.h"
#include "pokemon.h"

using namespace std;

class pokemonList {
 private:
  // Nested struct to represent Pokémon with attributes (name, type, favorite
  // food, and age).
  struct Pukemon {
    std::string name;
    std::string type;
    std::string favoriteFood;
    std::string age;
  };

 public:
  std::vector<Pukemon> pokemons;  // A vector to store Pokémon data.

  // Constructor without arguments
  pokemonList();

  // Constructor with an integer argument
  pokemonList(int num);

  // Method to print the list of Pokémon to a file
  void PrintPokemonListFile(string filename);

  // Method to add a new Pokémon to the list
  void makeNewPokemon();

  // Method to record the Pokémon list
  void pokemonListRecord();

  // Method to display all Pokémon in the list
  void displayAllPokemons();

  // Method to delete a file
  void deleteFile();
};

#endif
