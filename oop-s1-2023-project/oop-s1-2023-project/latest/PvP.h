#ifndef PVP_H
#define PVP_H

#include "Battle.h"  // Include the Battle class header file.

// Define a class named PvP which is derived from the Battle class.
class PvP : public Battle {
 protected:
  int NumOfPokemons = 2;  // Number of Pokémon in a PvP battle (default is 2).
  int Results = 0;        // Variable to store the results of the battle.
  string OpponentName;    // Variable to store the name of the opponent.
  string stage1 =
      "stage1.txt";  // A string variable for the file name "stage1.txt".

 public:
  // Default constructor for the PvP class.
  PvP();

  // Parameterized constructor for the PvP class that takes an array of Player
  // pointers as input.
  PvP(Player* player_list);

  // A function to choose a Pokémon from an array of Pokémon, used for advancing
  // the battle.
  Pokemon AdvanceChoosePokemon(Pokemon* pokemons, int len);

  // Virtual function to display the result of the battle.
  virtual void DisplayResult();

  // Virtual function to generate a random opponent name.
  virtual string GenerateOpponentName();

  // A function to advance and display the battle. It takes an array of Player
  // pointers and the number of fights as input.
  void advanceDisplayBattle(Player* player_list, int NumOfFights);
};

#endif  // PVP_H
