#include "Player.h"  // Include the Player class header file

#include "pokemon.h"  // Include the Pokemon class header file

Player::Player() {
  player_list = new Pokemon[len_list];  // Initialize player_list with an array
                                        // of Pokemon objects
};

void Player::AddPokemon(string filename, string PokeName) {
  if (current == len_list) {
    cout << "Cannot get the new pokemon! Maximum " << len_list
         << " pokemons in your pocket!!!" << endl;
    return;
  }

  ifstream pokemonFile(filename);  // Open the file for reading

  if (!pokemonFile.is_open()) {
    cout << "Error opening file: " << filename << endl;
    return;
  }

  while (!pokemonFile.eof()) {
    string name, type, sound;
    int health, attack, speed;
    pokemonFile >> name >> type >> sound >> health >> attack >> speed;

    if (name == PokeName) {
      // Set the attributes of the Pokemon object in the player_list
      player_list[current].setName(name);
      player_list[current].setType(type);
      player_list[current].setSound(sound);
      player_list[current].setHP(health);
      player_list[current].setAttack(attack);
      player_list[current].setSpeed(speed);
      current++;  // Move to the next slot in player_list
      break;      // Exit the loop after finding the Pokémon
    }
  }
  pokemonFile.close();  // Close the file when done
}

void Player::SavePokeListToFile() {
  // Construct the file path based on the trainer's name
  string filePath = "save/" + get_trainer_name() + ".txt";

  // Open a text file for writing
  ofstream outputFile(filePath);

  if (!outputFile.is_open()) {
    cout << "Error opening file for writing: " << filePath << endl;
    return;
  }

  for (int i = 0; i < current; i++) {
    // Concatenate all attributes into a single string
    string pokemonInfo =
        player_list[i].getName() + " " + player_list[i].getType() + " " +
        player_list[i].getSound() + " " + to_string(player_list[i].getHP()) +
        " " + to_string(player_list[i].getAttack()) + " " +
        to_string(player_list[i].getSpeed());

    // Write the concatenated string to the file
    outputFile << pokemonInfo << endl;
  }

  // Close the file when done
  outputFile.close();
}

vector<string> Player::getPokemonNames(string filename) {
  vector<string> PokemonNames;   // Create a vector to store the first words.
  ifstream inputFile(filename);  // Open the file for reading.
  string line;                   // Variable to store each line of the file.

  if (inputFile.is_open()) {
    while (getline(inputFile, line)) {  // Read each line of the file.
      // Find the first space character to extract the first word.
      size_t pos = line.find(' ');
      if (pos != string::npos) {
        string name = line.substr(0, pos);  // Extract the first word.
        PokemonNames.push_back(name);       // Add it to the vector.
      }
    }
    inputFile.close();  // Close the file when done.
  } else {
    cerr << "Unable to open the file: " << filename << endl;
  }

  return PokemonNames;  // Return the vector containing the first words.
}

Pokemon Player::ChoosePokemon() {
  string chosenPokemon;
  for (int i = 0; i < current; i++) {
    cout << "Press " << i << " to choose " << player_list[i].getName() << endl;
    cout << "Type: " << player_list[i].getType()
         << "  Health: " << player_list[i].getHP()
         << "  Attack: " << player_list[i].getAttack()
         << "  Speed: " << player_list[i].getSpeed() << endl;
  }
  while (true) {
    cout << "Enter your choice (as a number): ";
    string choiceStr;
    cin >> choiceStr;
    try {
      int choice = stoi(choiceStr);
      if (choice >= 0 && choice < current) {
        chosenPokemon = player_list[choice].getName();
        return player_list[choice];
      } else {
        cout << "Invalid choice." << endl;
      }
    } catch (const invalid_argument&) {
      cout << "Invalid input." << endl;
    }
  }
  return player_list[0];
}

void Player::printPokemonList() {
  for (int i = 0; i < current; i++) {
    cout << "Pokemon: " << player_list[i].getName() << endl;
    cout << "Type: " << player_list[i].getType() << endl;
    cout << "Sound: " << player_list[i].getSound() << endl;
    cout << "Health: " << player_list[i].getHP() << endl;
    cout << "Attack: " << player_list[i].getAttack() << endl;
    cout << "Speed: " << player_list[i].getSpeed() << endl;
    cout << "-----------------------" << endl;
  }
}

Player::~Player() {
  delete[] player_list;  // Deallocate the memory for the player_list array
}

// Setters and getters
int Player::get_current() { return current; }

Player::Player(string _name) : name(_name) {
  player_list = new Pokemon[len_list];  // Initialize the player_list with an
                                        // array of Pokemon objects
}

void Player::set_trainer_name(string _name) { name = _name; }

string Player::get_trainer_name() {
  string name;
  for (const auto& entry : fs::directory_iterator("save")) {
    name = entry.path().stem();
  }
  return name;  // Return the trainer's name
}

Pokemon* Player::GetPlayerList() {
  return player_list;  // Return a pointer to the player_list array
}

void Player::set_len_list(int len) {
  len_list = len;  // Set the length of the player_list array
}

int Player::get_len_list() {
  return len_list;  // Return the length of the player_list array
}

string Player::makeFile() {
  // Construct the file path
  string filePath = "save/" + get_trainer_name() + ".txt";

  return filePath;  // Return the file path
}
