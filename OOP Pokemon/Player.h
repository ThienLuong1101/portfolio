#ifndef PLAYER_H
#define PLAYER_H
#include"pokemon.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;
class Player
{
protected:
    string name;
    int len_list = 3;
    int current = 0;
    Pokemon* player_list;
public:
    Player();
    void set_trainer_name(string _name);
    void set_len_list(int len);
    int get_len_list();
    int get_current();


    Pokemon* GetPlayerList();
    string get_trainer_name(); 
    Player(string _name);
    string makeFile();
    void AddPokemon(string filename, string PokeName);
    void SavePokeListToFile();
    virtual void printPokemonList();
    Pokemon ChoosePokemon();
    vector<string> getPokemonNames(string filename);
    ~Player();
};



#endif