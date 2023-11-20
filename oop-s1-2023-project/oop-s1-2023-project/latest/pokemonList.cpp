#include "pokemonList.h"  // Include the header file for the pokemonList class

pokemonList::pokemonList() {}  // Constructor for the pokemonList class

void pokemonList::pokemonListRecord() {
  cout << "Welcome to the Pokémon Record Management System"
       << endl;  // Welcome message

  string choice;
  while (true) {
    cout << "\n1. Make new Pokémon" << endl;
    cout << "2. Display all your Pokémon" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice (as a number 1, 2, 3): ";
    cin >> choice;

    while (true) {
      if (choice == "1") {
        cout << "\033[2J\033[H";  // Clear the console screen
        makeNewPokemon();         // Call the function to create a new Pokémon
        break;
      } else if (choice == "2") {
        cout << "\033[2J\033[H";  // Clear the console screen
        displayAllPokemons();     // Call the function to display all Pokémon
        break;
      } else if (choice == "3") {
        return;  // Exit the program
      } else {
        cout << "Invalid choice."
             << endl;   // Display an error message for an invalid choice
        cin >> choice;  // Get a valid choice from the user
      }
    }
  }
}

void pokemonList::makeNewPokemon() {
  Pukemon pokemon;  // Create a new Pokémon object
  cout << "Enter Pokémon details" << endl;
  cout << "Name: ";
  getline(cin >> ws, pokemon.name);  // Read the name of the Pokémon
  cout << "Type: ";
  getline(cin >> ws, pokemon.type);  // Read the type of the Pokémon
  cout << "Favorite Food: ";
  getline(cin >> ws,
          pokemon.favoriteFood);  // Read the favorite food of the Pokémon
  cout << "Age: ";
  cin >> pokemon.age;  // Read the age of the Pokémon

  pokemons.push_back(pokemon);  // Add the new Pokémon to the list
  cout << "Pokemon created successfully!" << endl;  // Display a success message
}

void pokemonList::displayAllPokemons() {
  if (pokemons.empty()) {
    cout << "You have no Pokémon records."
         << endl;  // Display a message if there are no Pokémon records
    return;
  }

  cout << "Your Pokémon records: " << endl;
  for (const auto& pokemon : pokemons) {  // Loop through all Pokémon records
    cout << "Name: " << pokemon.name
         << endl;  // Display the name of the Pokémon
    cout << "Type: " << pokemon.type
         << endl;  // Display the type of the Pokémon
    cout << "Favorite Food: " << pokemon.favoriteFood
         << endl;  // Display the favorite food of the Pokémon
    cout << "Age: " << pokemon.age << endl;  // Display the age of the Pokémon
    cout << "-----------------------------" << endl;
  }
}

void pokemonList::PrintPokemonListFile(string filename) {
  cout << "\033[2J\033[H";  // Clear the console screen
  cout << "Your Pokemon List: " << endl;
  cout << endl;
  std::ifstream inputFile(
      filename);  // Open the file with the specified filename

  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << filename
              << std::endl;  // Display an error message if the file couldn't be
                             // opened
    return;
  }

  std::string name, type, sound;
  int health, attack, speed;

  while (inputFile >> name >> type >> sound >> health >> attack >> speed) {
    std::cout << "Name: " << name
              << std::endl;  // Display the name of the Pokémon
    std::cout << "Type: " << type
              << std::endl;  // Display the type of the Pokémon
    std::cout << "Sound: " << sound
              << std::endl;  // Display the sound of the Pokémon
    std::cout << "Health: " << health
              << std::endl;  // Display the health of the Pokémon
    std::cout << "Attack: " << attack
              << std::endl;  // Display the attack of the Pokémon
    std::cout << "Speed: " << speed
              << std::endl;  // Display the speed of the Pokémon
    std::cout << "-----------------------" << std::endl;
  }

  inputFile.close();  // Close the input file
  string quit;
  cout << "Enter R to quit" << endl;
  while (true) {
    cin >> quit;
    if (quit == "R" || quit == "r") {
      cout << "\033[2J\033[H";  // Clear the console screen
      return;                   // Return to the main menu
    }
  }
}
