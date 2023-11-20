#ifndef STAGE2POKEMON_H
#define STAGE2POKEMON_H

// Include necessary header files for this class.
#include <cstdlib>  // for rand and srand functions
#include <ctime>    // for the time function
#include <iostream>
#include <map>
#include <string>

#include "Player.h"
#include "Stage1Pokemon.h"
#include "pokemon.h"

// Define the Stage2Pokemon class, which inherits from the Stage1Pokemon class.
class Stage2Pokemon : public Stage1Pokemon {
 private:
  int s2 = 2;  // A constant representing the stage 2 of evolution.
  map<string, string> Stage2Data = {
      {"Charmeleon", "Charizard"}, {"Combusken", "Blaziken"},
      {"Frogadier", "Greninja"},   {"Wartortle", "Blastoise"},
      {"Ivysaur", "Venusaur"},     {"Grovyle", "Sceptile"}};

 public:
  // Default constructor for the Stage2Pokemon class.
  Stage2Pokemon();

  // Parameterized constructor for the Stage2Pokemon class, specifying
  // attributes for a Stage 2 Pokemon.
  Stage2Pokemon(string _name, string _type, string _sound, int _hp, int _attack,
                int _speed);

  // Function to evolve a Stage 2 Pokemon if certain conditions are met.
  bool Evolve(Pokemon basic, Player* player_list) override;

  // Function to retrieve the Stage 2 evolution data map.
  map<string, string> GetStage2Data();

  // Function to display a random emoji for the Pokemon.
  void Emoji();
};

#endif
