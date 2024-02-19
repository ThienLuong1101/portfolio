#ifndef CURRENTGAME_H
#define CURRENTGAME_H

#include"pokemonList.h"
#include"Player.h"
#include"RandomPoke.h"
#include"HuntPvP.h"
#include"MasterPvP.h"
#include"PvP.h"
#include"NewGame.h"
#include <iostream>
#include<vector>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <filesystem>
using namespace std;
namespace fs = filesystem;
class CurrentGame : public Menu
{
    string filePath;
    string folderPath = "save";
public:
    CurrentGame();
    bool isFolderEmpty(string folderPath);
    void set_filePath(string _filePath);
    string get_filePath();
    string AccessFilePath();
    void displayMenu() override;
    void PokemonBehavior(Player& player);

};


#endif