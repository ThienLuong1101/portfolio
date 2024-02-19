#ifndef POKEMONLIST_H
#define POKEMONLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
#include"CurrentGame.h"
#include"pokemon.h"
#include <cstdio>

using namespace std;

class pokemonList {
private:
    
    // Nested struct to represent Pokémon with attributes (name, type, favorite food, and age).
    struct Pukemon {
        std::string name;
        std::string type;
        std::string favoriteFood;
        std::string age;
    };
public:
    std::vector<Pukemon> pokemons;  // A vector to store Pokémon data.
    pokemonList();
    pokemonList(int num);
    void PrintPokemonListFile(string filename);
    // Method to add a new Pokémon to the list.
    void makeNewPokemon();
    
    void pokemonListRecord(); 
    // Method to display all Pokémon in the list.
    void displayAllPokemons();

    void deleteFile();

};

#endif