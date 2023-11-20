#include "HuntPvP.h"

// Constructor for the HuntPvP class, takes a Player object as input
HuntPvP::HuntPvP(Player* player_list) {
  // Initialize the player's Pokemon list using the provided Player object
  player_pokemons = player_list->GetPlayerList();

  // Output a message to indicate traveling
  cout << endl;
  cout << "Traveling..." << endl;
  // Pause for 1 second for dramatic effect
  this_thread::sleep_for(chrono::seconds(1));

  // Generate a wild Pokemon for battle
  GenerateWildPokemon(player_list, 1, basic);
  cout << wildPokemon << " wants to fight!" << endl;
  cout << "Type: " << opponent[0].getType() << endl;
  this_thread::sleep_for(chrono::seconds(1));

  // Prompt the player to choose their Pokemon for the battle
  cout << "choose your Pokemon to fight: " << endl;
  cout << "-----------------------" << endl;
  chosenPokemon = player_list->ChoosePokemon();
  this_thread::sleep_for(chrono::seconds(1));

  // Clear the console screen
  cout << "\033[2J\033[H";
  string PokeName = chosenPokemon.getName();
  cout << "you choose: " << PokeName << endl;

  // Start the battle with chosenPokemon against the wild opponent
  displayBattle(chosenPokemon, opponent[0],
                true);  // Your Pokemon always goes first in this mode

  // Check if the player wins the battle
  if (win) {
    // Prompt the player to decide whether to catch the wild Pokemon
    if (HuntPvPYorN(opponent[0])) {
      // Add the wild Pokemon to the player's collection
      player_list->AddPokemon("PokemonList.txt", wildPokemon);
      // Save the updated Pokemon list to a file
      player_list->SavePokeListToFile();
    }
    // Check if the player's Pokemon gets a win and set the number of wins
    checkWin(player_list, PokeName);
  }

  // Check for evolution of the player's Pokemon
  checkEvolve(player_list);

  // Save the updated Pokemon list to a file
  player_list->SavePokeListToFile();
}

// Generate a wild Pokemon for battle
void HuntPvP::GenerateWildPokemon(Player* player_list, int num, string file) {
  Opponent b(num);
  bool found = true;
  // Get the names of Pokemon in the player's collection
  vector<string> PokemonNames =
      player_list->getPokemonNames(player_list->makeFile());

  // Generate a random Pokemon that the player doesn't have
  while (found) {
    vector<string> OpponentPokemonNames = b.GenerateRandomPokemon(file);
    wildPokemon = OpponentPokemonNames[0];
    found = false;
    for (string name : PokemonNames) {
      if (wildPokemon == name) {
        found = true;
      }
    }
  }
  opponent = b.GetOpponentList();
}

// Prompt the player to decide whether to catch the wild Pokemon
bool HuntPvP::HuntPvPYorN(Pokemon b) {
  string choice;

  do {
    cout << "Do you want to catch [y/n]: " << b.getName() << endl;
    cin >> choice;
  } while (choice != "y" && choice != "n");

  if (choice == "y") {
    // Clear the console screen
    cout << "\033[2J\033[H";
    return true;
  } else {
    // Clear the console screen and display a message
    cout << "\033[2J\033[H";
    cout << b.getName() << " run away! " << b.getSound() << endl;
    this_thread::sleep_for(chrono::seconds(1));
    return false;
  }
}

// Check for evolution of the player's Pokemon
void HuntPvP::checkEvolve(Player* player_list) {
  for (int i = 0; i < player_list->get_current(); i++) {
    Stage1Pokemon EvoPokemon;
    Stage2Pokemon FinalEvoPokemon;
    if (EvoPokemon.Evolve(player_pokemons[i], player_list)) {
      player_pokemons[i] = EvoPokemon;
    }
    if (FinalEvoPokemon.Evolve(player_pokemons[i], player_list)) {
      player_pokemons[i] = FinalEvoPokemon;
    }
  }
}

// Check if the player's Pokemon won the battle and update the number of wins
void HuntPvP::checkWin(Player* player_list, string PokeName) {
  for (int i = 0; i < player_list->get_current(); i++) {
    if (player_pokemons[i].getName() == PokeName) {
      player_pokemons[i].setNumOfWins(1);
      win = false;
    }
  }
}
