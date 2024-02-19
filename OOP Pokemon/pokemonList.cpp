#include "pokemonList.h"

pokemonList::pokemonList() {}

void pokemonList::pokemonListRecord() {
    cout << "Welcome to the Pokémon Record Management System" << endl;
    
    string choice;
    while (true) {
        cout << "\n1. Make new Pokémon" << endl;
        cout << "2. Display all your Pokémon" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice (as a number 1, 2, 3): ";
        cin >> choice;

        while (true) {
            if (choice == "1") {
                cout << "\033[2J\033[H";
                makeNewPokemon();
                break;
            } else if (choice == "2") {
                cout << "\033[2J\033[H";
                displayAllPokemons();
                break;
            } else if (choice == "3") {
                return;
            } else {
                cout << "Invalid choice." << endl;
                cin >> choice;
            }
        }
    }
}

void pokemonList::makeNewPokemon() {
    Pukemon pokemon;
    cout << "Enter Pokémon details" << endl;
    cout << "Name: ";
    getline(cin >> ws, pokemon.name);
    cout << "Type: ";
    getline(cin >> ws, pokemon.type);
    cout << "Favorite Food: ";
    getline(cin >> ws, pokemon.favoriteFood);
    cout << "Age: ";
    cin >> pokemon.age;

    pokemons.push_back(pokemon);
    cout << "Pokemon created successfully!" << endl;
}

void pokemonList::displayAllPokemons() {
    if (pokemons.empty()) {
        cout << "You have no Pokémon records." << endl;
        return;
    }

    cout << "Your Pokémon records: " << endl;
    for (const auto& pokemon : pokemons) {
        cout << "Name: " << pokemon.name << endl;
        cout << "Type: " << pokemon.type << endl;
        cout << "Favorite Food: " << pokemon.favoriteFood << endl;
        cout << "Age: " << pokemon.age << endl;
        cout << "-----------------------------" << endl;
    }
}













void pokemonList::PrintPokemonListFile(string filename) {
        
    cout << "\033[2J\033[H";
    cout << "Your Pokemon List: " << endl;
    cout << endl;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string name, type, sound;
    int health, attack, speed;

    while (inputFile >> name >> type >> sound >> health >> attack >> speed) {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Sound: " << sound << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Attack: " << attack << std::endl;
        std::cout << "Speed: " << speed << std::endl;
        std::cout << "-----------------------" << std::endl;
    }

    inputFile.close();
    string quit;
    cout << "Enter R to quit" << endl;
    while (true)
    {   

        cin >> quit;
        if (quit == "R" || quit == "r")
        {
            cout << "\033[2J\033[H";
            return;
        }
    }
        
}