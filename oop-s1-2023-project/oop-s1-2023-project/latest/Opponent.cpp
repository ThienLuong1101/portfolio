#include "Opponent.h"

Opponent::Opponent() {}  // Default constructor for the Opponent class

Opponent::Opponent(int numPokemon) {
  lenList = numPokemon;  // Initialize the length of the Opponent's Pokemon list
  Opponent_Poke =
      new Pokemon[lenList];  // Create a dynamic array to store Pokemon objects
}

vector<string> Opponent::GenerateRandomPokemon(string file) {
  ifstream randomPokeFile(
      file);  // Open a file stream to read random Pokemon names from a file
  vector<string>
      pokemonNames;  // Create a vector to store the generated Pokemon names

  try {
    if (!randomPokeFile.is_open()) {  // Didn't open Pokemon file
      throw std::ios_base::failure("Error opening file: " + file);
    }
  } catch (const std::ios_base::failure& e) {
    std::cerr << e.what() << std::endl;
    // Return an empty vector on error
    return pokemonNames;
  }

  RandomPoke randomPoke(
      file);  // Create a RandomPoke object with the provided file

  for (int i = 0; i < lenList; i++) {
    string pokeName =
        randomPoke.getRandomName();  // Generate a random Pokemon name using the
                                     // RandomPoke object

    pokemonNames.push_back(pokeName);  // Store the Pokémon name in the vector
    AddPokemon("PokemonList.txt",
               pokeName);  // Add the generated Pokemon to a Pokemon list

    // Copy the attributes of the player's Pokemon to the opponent's Pokemon
    Opponent_Poke[i].setName(player_list[current - 1].getName());
    Opponent_Poke[i].setType(player_list[current - 1].getType());
    Opponent_Poke[i].setSound(player_list[current - 1].getSound());
    Opponent_Poke[i].setHP(player_list[current - 1].getHP());
    Opponent_Poke[i].setAttack(player_list[current - 1].getAttack());
    Opponent_Poke[i].setSpeed(player_list[current - 1].getSpeed());
  }

  return pokemonNames;  // Return the vector of generated Pokemon names
}

Pokemon* Opponent::GetOpponentList() {
  return Opponent_Poke;  // Return a pointer to the Opponent's Pokemon list
}

void Opponent::printPokemonList() {
  cout << "Opponent's Pokémon List:" << endl;

  for (int i = 0; i < lenList; i++) {
    // Print information about each Pokemon in the Opponent's list
    cout << "Pokemon: " << Opponent_Poke[i].getName() << endl;
    cout << "Type: " << Opponent_Poke[i].getType() << endl;
    cout << "Sound: " << Opponent_Poke[i].getSound() << endl;
    cout << "Health: " << Opponent_Poke[i].getHP() << endl;
    cout << "Attack: " << Opponent_Poke[i].getAttack() << endl;
    cout << "Speed: " << Opponent_Poke[i].getSpeed() << endl;
    cout << "-----------------------" << endl;
  }
}

Opponent::~Opponent() {
  delete[] Opponent_Poke;  // Destructor to release the dynamically allocated
                           // Pokemon array
}
