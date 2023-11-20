#ifndef MASTERPVP_H
#define MASTERPVP_H

#include "PvP.h"  // Include the header file for the base class 'PvP'.

class MasterPvP : public PvP {
 private:
  int NumOfPokemons =
      3;  // Declare a private integer variable to store the number of Pokemons
          // each player has in this specific PvP game mode.

  string stage2 =
      "stage2.txt";  // Declare a private string variable 'stage2' and
                     // initialize it with the value "stage2.txt", presumably
                     // representing a file containing stage information.

 public:
  MasterPvP(Player* player_list);  // Declare a constructor for the 'MasterPvP'
                                   // class, which takes a pointer to an array
                                   // of 'Player' objects as a parameter.

  void DisplayResult()
      override;  // Declare a public member function 'DisplayResult' that is
                 // marked as an override, indicating that it overrides a
                 // virtual function from the base class.

  string GenerateOpponentName()
      override;  // Declare a public member function 'GenerateOpponentName' that
                 // is marked as an override, indicating that it overrides a
                 // virtual function from the base class.

  void outGame();  // Declare a public member function 'outGame' without any
                   // parameters.
};

#endif
