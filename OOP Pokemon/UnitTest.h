#include"NewGame.h"
#include"Stage1Pokemon.h"
#include"Stage2Pokemon.h"
#include"PvP.h"
#include"MasterPvP.h"
class UnitTest
{

public:
    void runTest() {
        testCreateFolder();
        testCreateFile();
        testAddPokemon();
        testCheckEvolve();
        testBasicPokemon();
        testStage1Pokemon();
        testStage2Pokemon();
        testGetOpponentName1();
    }

private:
    NewGame newGame;
    string filePath;
    Player player;
    void testCreateFolder() {
        
        newGame.CreateFolder();
        if (!filesystem::exists("save"))
        {
            cout << "Test 1 failed!" << endl;
        }
    }
    void testCreateFile() {
        string trainer_name = "An";
        filePath = newGame.getFolderPath() + "/" + trainer_name + ".txt";
        newGame.setFilePath(filePath);
        ofstream outputFile(filePath);
        if (newGame.getFilePath() != "save/An.txt")
        {
            cout << "Test 2 failed!" << endl;
        }
        
    }
    void testAddPokemon() {
        
        player.AddPokemon("PokemonList.txt","Treecko");
        player.SavePokeListToFile();
        vector<string> names = player.getPokemonNames(filePath);
        if (names[0] != "Treecko")
        {
            cout << "Test 3 failed!" << endl;
        }
    }

    void testCheckEvolve() {
        Stage1Pokemon clone1;
        map<string, string> Stage1Data = {
        {"Charmander", "Charmeleon"},
        {"Torchic", "Combusken"},
        {"Froakie", "Frogadier"},
        {"Squirtle", "Wartortle"},
        {"Bulbasaur", "Ivysaur"},
        {"Treecko", "Grovyle"}
    };
        if(!clone1.CheckEvolve("Charmeleon",Stage1Data)) {
            cout << "Test 4 failed!" << endl;
        }
    }
    void testPokemonBehavior1() {
        Stage1Pokemon clone1("Charmeleon", "Fire", "CharChar" ,120, 45,35);
        
    }
    void testBasicPokemon() {
        Pokemon Squirtle("Squirtle", "Water", "SquirSquir", 60 ,30 ,25);
        if (Squirtle.getName()!= "Suirtle" && Squirtle.getType()!= "Water" && Squirtle.getSpeed()!= 25 )
        {
            cout << "Test 5 failed!" << endl;
        }
        
    }
    void testStage1Pokemon() {
        Stage1Pokemon Wartortle("Wartortle","Water", "SquirSquir", 120, 50, 25);
        if (Wartortle.getName()!= "Suirtle" && Wartortle.getType()!= "Water" && Wartortle.getSpeed()!= 25 )
        {
            cout << "Test 6 failed!" << endl;
        }
    }
    void testStage2Pokemon() {
        Stage2Pokemon Blastoise("Blastoise", "Water", "SquirSquir", 220, 70, 25);
        if (Blastoise.getName()!= "Suirtle" && Blastoise.getType()!= "Water" && Blastoise.getSpeed()!= 25 )
        {
            cout << "Test 7 failed!" << endl;
        }
    }
    void testGetOpponentName1() {
        PvP enemy1;
        string name1 = enemy1.GenerateOpponentName();
        if (name1 == "")
        {
            cout << "Test 8 failed!" << endl;
        }
        
    }
    
};



