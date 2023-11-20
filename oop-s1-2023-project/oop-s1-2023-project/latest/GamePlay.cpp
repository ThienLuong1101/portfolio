#include "Battle.h"
#include "CurrentGame.h"
#include "NewGame.h"
#include "Opponent.h"
#include "Player.h"
#include "PvP.h"
#include "RandomPoke.h"
#include "Stage1Pokemon.h"
#include "pokemon.h"
#include "pokemonList.h"

int main() {
  // Create an array of Menu pointers to store different game modes.
  Menu* game[2];
  game[0] = new NewGame();
  game[1] = new CurrentGame();

  // Display a welcome message.
  cout << "Welcome to Pokemon Game!!!" << endl;

  int choice;
  string folderPath = static_cast<NewGame*>(game[0])->getFolderPath();
  string filePath;

  // Check if the game folder exists, and if not, create it.
  if (!filesystem::exists(folderPath)) {
    static_cast<NewGame*>(game[0])->CreateFolder();
  }

  // Check if the game folder is empty, and if so, prompt for a choice.
  if (static_cast<CurrentGame*>(game[1])->isFolderEmpty(folderPath)) {
    game[0]->displayMenu();
    filePath = static_cast<NewGame*>(game[0])->getFilePath();
    static_cast<CurrentGame*>(game[1])->set_filePath(filePath);
    game[1]->displayMenu();
  } else {
    while (true) {
      cout << "Press 1 to start a new game or 2 to continue: ";
      cin >> choice;

      if (choice == 1) {
        cout << "Starting a new game..." << endl;
        game[0]->displayMenu();
        filePath = static_cast<NewGame*>(game[0])->getFilePath();
        static_cast<CurrentGame*>(game[1])->set_filePath(filePath);
        game[1]->displayMenu();
        break;  // Exit the loop to start the game.
      } else if (choice == 2) {
        cout << "Continuing the game..." << endl;
        filePath = static_cast<CurrentGame*>(game[1])->AccessFilePath();
        static_cast<CurrentGame*>(game[1])->set_filePath(filePath);
        game[1]->displayMenu();
        break;  // Exit the loop to continue the game.
      } else {
        // Clear the input buffer in case of invalid input.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  }

  // Clean up and release memory by deleting the game objects.
  for (size_t i = 0; i < 2; i++) {
    delete game[i];
  }

  return 0;
}
