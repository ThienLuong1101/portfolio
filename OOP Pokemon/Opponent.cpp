#include"Opponent.h"

Opponent::Opponent() {}

Opponent::Opponent(int numPokemon) {
    lenList = numPokemon;
    Opponent_Poke = new Pokemon[lenList];
}


vector<string> Opponent::GenerateRandomPokemon(string file) {
    ifstream randomPokeFile(file);
    vector<string> pokemonNames;
    try {
        if (!randomPokeFile.is_open()) {
            throw std::ios_base::failure("Error opening file: " + file);
            
        } 
        }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
        // Return an empty vector on error
        return pokemonNames;
    }

    RandomPoke randomPoke(file);
    
   
    for (int i = 0; i < lenList; i++) {
        string pokeName = randomPoke.getRandomName();
      
        pokemonNames.push_back(pokeName); // Store the Pokémon name in the vector
        AddPokemon("PokemonList.txt", pokeName);
        
        Opponent_Poke[i].setName(player_list[current - 1].getName());
        // cout << Opponent_Poke[i].getName()<< endl;
        Opponent_Poke[i].setName(player_list[current - 1].getName());
        Opponent_Poke[i].setType(player_list[current - 1].getType());
        Opponent_Poke[i].setSound(player_list[current - 1].getSound());
        Opponent_Poke[i].setHP(player_list[current - 1].getHP());
        Opponent_Poke[i].setAttack(player_list[current - 1].getAttack());
        Opponent_Poke[i].setSpeed(player_list[current - 1].getSpeed());
       
    }

    return pokemonNames;
}

Pokemon* Opponent::GetOpponentList() {
    return Opponent_Poke;
}
void Opponent::printPokemonList() {
    cout << "Opponent's Pokémon List:" << endl;
    for (int i = 0; i < lenList; i++) {
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
    delete [] Opponent_Poke;
}