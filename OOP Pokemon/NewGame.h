#ifndef NEWGAME_H
#define NEWGAME_H
#include"Menu.h"
#include"Player.h"
#include"RandomPoke.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <filesystem>
using namespace std;
namespace fs = filesystem;
class NewGame : public Menu
{
protected:
    string Trainer_name; 
    string folderPath = "save";
    string filePath;
public:
    void setTrainerName(string name);
    string getTrainerName();
    void setFolderPath( string path);
    string getFolderPath();
    void setFilePath( string path);
    string getFilePath();
    void CreateFolder();

    void displayMenu() override;

};



#endif