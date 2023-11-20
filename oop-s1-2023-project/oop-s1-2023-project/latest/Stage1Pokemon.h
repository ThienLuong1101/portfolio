#ifndef STAGE1POKEMON_H
#define STAGE1POKEMON_H

#include <cstdlib>  // Include the standard library for functions like rand and srand.
#include <ctime>     // Include the standard library for time-related functions.
#include <iostream>  // Include the standard input/output stream library.
#include <map>  // Include the standard map container from the C++ Standard Library.
#include <string>  // Include the standard string library.

#include "NewGame.h"  // Include the "NewGame.h" header file, presumably used in this class.
#include "Player.h"  // Include the "Player.h" header file for using the Player class.
#include "pokemon.h"  // Include the "pokemon.h" header file, assuming it contains the base class for Pokemon.

// Declare a class named Stage1Pokemon that inherits from the Pokemon class.
class Stage1Pokemon : public Pokemon {
 private:
  int s1 =
      1;  // An integer member variable named 's1' with an initial value of 1.

  // Define a map to store the stage 1 Pokemon data where the key is the name of
  // the basic form and the value is the name of the stage 1 evolved form.
  std::map<std::string, std::string> Stage1Data = {
      {"Charmander", "Charmeleon"}, {"Torchic", "Combusken"},
      {"Froakie", "Frogadier"},     {"Squirtle", "Wartortle"},
      {"Bulbasaur", "Ivysaur"},     {"Treecko", "Grovyle"}};

 public:
  // Default constructor for the Stage1Pokemon class.
  Stage1Pokemon();

  // Parameterized constructor for the Stage1Pokemon class, taking several
  // attributes of a Pokemon.
  Stage1Pokemon(std::string _name, std::string _type, std::string _sound,
                int _hp, int _attack, int _speed);

  // Virtual function to handle the evolution of a Pokemon.
  bool virtual Evolve(Pokemon basic, Player* player_list);

  // Function to check if a Pokemon can evolve based on its name and the
  // provided data map.
  bool CheckEvolve(std::string name,
                   std::map<std::string, std::string> dataMap);

  // Function to perform an action specific to Stage 1 Pokemon.
  void Action();

  // Getter function to retrieve the Stage1Data map.
  std::map<std::string, std::string> GetStage1Data();
};

#endif
