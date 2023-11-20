#include "MasterPvP.h"

// Constructor for the MasterPvP class
MasterPvP::MasterPvP(Player* player_list) {
  // Check if the player has at least 3 pokemons to play this mode
  if (player_list->get_current() < NumOfPokemons) {
    cout << "You need to have at least 3 pokemons to play this mode" << endl;
    return;  // Return from the constructor if the player doesn't meet the
             // requirement
  }

  // Generate a name for the opponent
  OpponentName = GenerateOpponentName();

  // Clear the console screen
  cout << "\033[2J\033[H";

  // Display opponent name and welcome message
  cout << OpponentName << endl;
  cout << "Welcome to The hardest mode" << endl;

  // Sleep for 2 seconds
  this_thread::sleep_for(chrono::seconds(2));

  // Clear the console screen again
  cout << "\033[2J\033[H";

  // Display a message about the objective
  cout << "You win the battle you become Master Trainer!!" << endl;

  // Sleep for 3 seconds
  this_thread::sleep_for(chrono::seconds(3));

  // Generate Stage2 Pokemon for the opponent
  GenerateOpponent(NumOfPokemons, stage2);

  // Get the player's list of pokemons
  player_pokemons = player_list->GetPlayerList();

  // Start the battle and display it
  advanceDisplayBattle(player_list, NumOfPokemons);

  // Display the battle result
  DisplayResult();
}

// Display the battle result
void MasterPvP::DisplayResult() {
  // Display the results, which is the player's score and the opponent's score
  cout << "Result: " << Results << "-" << 3 - Results << endl;

  // Check if the player won (score > 1)
  if (Results > 1) {
    cout << "Victory!" << endl;
    cout << "CONGRATULATIONS! YOU ARE THE MASTER TRAINER!" << endl;
    // Exit the game
    outGame();
  } else {
    // Player lost
    cout << "You Lose!" << endl;
    cout << OpponentName
         << ": haha! it's not easy to get what you desire, dude!" << endl;
  }
}

// Generate a random opponent name
string MasterPvP::GenerateOpponentName() {
  // List of opponent names
  vector<string> names = {"ChatGPT", "Elon Musk", "Steve Job", "Messi"};

  // Random device for seed
  random_device rd;
  // Mersenne Twister random number generator with a seed from the current time
  mt19937 gen(static_cast<unsigned>(time(nullptr)));

  // Generate a random index within the range of the vector size
  uniform_int_distribution<int> distribution(0, names.size() - 1);
  int randomIndex = distribution(gen);

  // Clear the console screen
  cout << "\033[2J\033[H";

  // Display a challenge message with the opponent's name
  cout << names[randomIndex]
       << " challenges you 3v3 Master Pokemon Battle, let's fight..." << endl;

  // Sleep for 3 seconds
  this_thread::sleep_for(chrono::seconds(3));

  // Clear the console screen again
  cout << "\033[2J\033[H";

  // Return the opponent's name
  return names[randomIndex];
}

// Exit the game
void MasterPvP::outGame() {
  cout << "Thank you for playing our game!" << endl;
  exit(0);  // Terminate the program
}
