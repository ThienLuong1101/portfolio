#include "CurrentGame.h"

// Constructor for CurrentGame
CurrentGame::CurrentGame() {}

// Display the game menu and handle user input
void CurrentGame::displayMenu() {
  string input;
  Player player;

  // Get the list of Pokémon names from the player's file
  vector<string> PokemonNames = player.getPokemonNames(get_filePath());

  // Add the Pokémon to the player's collection
  for (string name : PokemonNames) {
    player.AddPokemon("PokemonList.txt", name);
  }

  player.set_len_list(3);

  // Main game loop
  while (true) {
    cout << endl;
    cout << "------------Main-------------" << endl;
    cout << "Press 1 for battle" << endl;
    cout << "Press 2 for displaying your Pokémon list" << endl;
    cout << "press 3 for playing with your Pokémon" << endl;
    cout << "-----------------------------" << endl;
    cout << "Press 4 for Creative Mode" << endl;
    cout << "Press 5 to quit the game" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter your choice: ";
    cin >> input;

    if (input == "1") {
      string input1;
      cout << "\033[2J\033[H";  // Clear the screen

      cout << "---------Battle----------" << endl;
      cout << "Press 1 for Catch Pokémon" << endl;
      cout << "Press 2 for PvP battle" << endl;
      cout << "Press 3 for Master PvP battle" << endl;
      cout << "-----------------------" << endl;
      cout << "Enter your choice: ";
      cin >> input1;

      if (input1 == "1") {
        cout << "\033[2J\033[H";  // Clear the screen
        HuntPvP mode1(&player);
      } else if (input1 == "2") {
        cout << "\033[2J\033[H";  // Clear the screen
        PvP mode2(&player);
      } else if (input1 == "3") {
        cout << "\033[2J\033[H";  // Clear the screen
        MasterPvP mode3(&player);
      }
    } else if (input == "2") {
      cout << AccessFilePath() << "here" << endl;
      pokemonList print;

      // Print the Pokémon list
      print.PrintPokemonListFile(AccessFilePath());
    } else if (input == "3") {
      cout << "\033[2J\033[H";  // Clear the screen
      PokemonBehavior(player);
    } else if (input == "4") {
      cout << "\033[2J\033[H";  // Clear the screen
      pokemonList list;
      list.pokemonListRecord();
    } else if (input == "5") {
      cout << "\033[2J\033[H";  // Clear the screen
      exit(0);                  // Exit the game
    } else {
      cout << "Invalid choice." << endl;
      // Loop will continue until a valid choice is entered
    }
  }
}

// Handle the behavior of the player's Pokémon
void CurrentGame::PokemonBehavior(Player& player) {
  int len = player.get_current();
  Pokemon** pokemonsPtr = new Pokemon*[len];
  Pokemon* pokemons = player.GetPlayerList();
  Stage1Pokemon clone1;
  Stage2Pokemon clone2;

  cout << "What is your Pokémon doing???" << endl;
  this_thread::sleep_for(chrono::seconds(1));

  // Loop through the player's Pokémon
  for (int i = 0; i < len; i++) {
    string pokemon = pokemons[i].getName();
    string sound = pokemons[i].getSound();

    if (clone2.CheckEvolve(pokemon, clone2.GetStage2Data())) {
      // Create a Stage2 Pokémon
      pokemonsPtr[i] = new Stage2Pokemon(pokemon, "", sound, 0, 0, 0);
      Stage2Pokemon* Ptr2 = dynamic_cast<Stage2Pokemon*>(pokemonsPtr[i]);

      cout << Ptr2->getName() << " says " << Ptr2->getSound() << endl;
      Ptr2->Action();
      Ptr2->Emoji();
    } else if (clone1.CheckEvolve(pokemon, clone1.GetStage1Data())) {
      // Create a Stage1 Pokémon
      pokemonsPtr[i] = new Stage1Pokemon(pokemon, "", sound, 0, 0, 0);
      Stage1Pokemon* Ptr1 = dynamic_cast<Stage1Pokemon*>(pokemonsPtr[i]);

      cout << Ptr1->getName() << " says " << Ptr1->getSound() << endl;
      Ptr1->Action();
    } else {
      // Display the Pokémon's sound
      cout << pokemon << " says " << sound << endl;
    }
    cout << "-----------------------" << endl;
  }

  string quit;
  cout << "Enter R to quit" << endl;

  // Wait for user input to quit the Pokémon behavior menu
  while (true) {
    cin >> quit;
    if (quit == "R" || quit == "r") {
      cout << "\033[2J\033[H";  // Clear the screen
      return;
    }
  }
}

// Set the file path for the player's Pokémon data
void CurrentGame::set_filePath(string _filePath) { this->filePath = _filePath; }

// Get the file path for the player's Pokémon data
string CurrentGame::get_filePath() { return filePath; }

// Check if a folder is empty
bool CurrentGame::isFolderEmpty(string folderPath) {
  return fs::is_empty(folderPath);
}

// Access the file path for Pokémon data
string CurrentGame::AccessFilePath() {
  try {
    if (!fs::exists(folderPath) ||
        !fs::is_directory(folderPath)) {  // Find folder
      throw filesystem::filesystem_error(
          "The folder does not exist or is not a directory.",
          make_error_code(errc::no_such_file_or_directory));
    }
    for (const auto& entry : fs::directory_iterator(folderPath)) {
      if (entry.is_regular_file()) {
        // Process the file.
        return entry.path().string();
      }
    }
  } catch (const filesystem::filesystem_error& e) {  // Catch error occur
    cerr << "Error: " << e.what() << endl;
  }
  return "";
}
