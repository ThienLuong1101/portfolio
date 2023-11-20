#include "NewGame.h"  // Include the header file for the NewGame class

// Define the member function displayMenu for the NewGame class
void NewGame::displayMenu() {
  // Iterate through the files in the folderPath and remove them
  for (const auto& entry : fs::directory_iterator(folderPath)) {
    fs::remove(entry);
  }

  cout << endl;

  // Sleep for 1 second to create a pause
  this_thread::sleep_for(chrono::seconds(1));

  // Display the game title and welcome message
  cout << "---------POKEMON SIMULATION---------" << endl;
  cout << "Welcome to Pokemon World!!!" << endl;

  // Prompt the user for their name and store it in Trainer_name
  cout << "What's your name Trainer: ";
  cin >> Trainer_name;

  // Greet the player by their name and inform them the journey is starting
  cout << "HI " << Trainer_name << "! Let's start the journey..." << endl;

  // Create a Player object with the provided Trainer_name
  Player player(Trainer_name);

  // Create a RandomPoke object with "basic.txt" as a parameter
  RandomPoke randomPoke("basic.txt");

  // Wait for 1 second
  this_thread::sleep_for(chrono::seconds(1));

  // Construct the file path for saving the game progress
  filePath = "save/" + Trainer_name + ".txt";
  setFilePath(filePath);

  // Open a text file for writing the game progress
  ofstream outputFile(filePath);

  // Add a random Pokémon to the player's list and save the list to the file
  player.AddPokemon("PokemonList.txt", randomPoke.getRandomName());
  player.SavePokeListToFile();

  // Clear the console screen
  cout << "\033[2J\033[H";

  // Display a loading message
  cout << "Game Loading..." << endl;

  // Wait for 1 second
  this_thread::sleep_for(chrono::seconds(1));

  // Clear the console screen again
  cout << "\033[2J\033[H";

  // Display the player's starting Pokémon and their name
  cout << player.getPokemonNames(filePath)[0] << " will be your start Pokemon! "
       << player.get_trainer_name() << "!" << endl;

  // Wait for 2 seconds
  this_thread::sleep_for(chrono::seconds(2));
}

// Define the member function CreateFolder for the NewGame class
void NewGame::CreateFolder() {
  // Create a directory with the folderPath
  filesystem::create_directory(folderPath);
}

// Define the member function setTrainerName to set the Trainer_name member
// variable
void NewGame::setTrainerName(string name) { Trainer_name = name; }

// Define the member function getTrainerName to retrieve the Trainer_name member
// variable
string NewGame::getTrainerName() { return Trainer_name; }

// Define the member function setFolderPath to set the folderPath member
// variable
void NewGame::setFolderPath(string path) { folderPath = path; }

// Define the member function getFolderPath to retrieve the folderPath member
// variable
string NewGame::getFolderPath() { return folderPath; }

// Define the member function setFilePath to set the filePath member variable
void NewGame::setFilePath(string path) { filePath = path; }

// Define the member function getFilePath to retrieve the filePath member
// variable
string NewGame::getFilePath() { return filePath; }
