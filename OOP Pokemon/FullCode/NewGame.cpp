#include"NewGame.h"

void NewGame::displayMenu() {
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        fs::remove(entry);
    }
    cout << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "---------POKEMON SIMULATION---------" << endl;
    cout << "Welcome to Pokemon World!!!" << endl;
    cout << "What's your name Trainer: ";
    cin >> Trainer_name;
    cout << "HI " << Trainer_name << "! Let start the journey..." << endl;
    Player player(Trainer_name);
    RandomPoke randomPoke("basic.txt");
    this_thread::sleep_for(chrono::seconds(1)); // Wait for 1 second
    // Construct the file path
    filePath = "save/" + Trainer_name + ".txt";
    setFilePath(filePath);
    // Open a text file for writing
    ofstream outputFile(filePath);
    player.AddPokemon("PokemonList.txt",randomPoke.getRandomName());
    player.SavePokeListToFile();
    cout << "\033[2J\033[H";
    cout << "Game Loading..." << endl;
    this_thread::sleep_for(chrono::seconds(1)); 
    cout << "\033[2J\033[H";
    cout << player.getPokemonNames(filePath)[0]<< " will be your start Pokemon! " << player.get_trainer_name() <<"!"<< endl;
    this_thread::sleep_for(chrono::seconds(2)); 
}

void NewGame::CreateFolder() {
    filesystem::create_directory(folderPath);
}

void NewGame::setTrainerName(string name) {
    Trainer_name = name;
}

string NewGame::getTrainerName()  {
    return Trainer_name;
}

void NewGame::setFolderPath(string path) {
    folderPath = path;
}

string NewGame::getFolderPath() {
    return folderPath;
}

void NewGame::setFilePath( string path) {
    filePath = path;
}

string NewGame::getFilePath() {
    return filePath;
}


