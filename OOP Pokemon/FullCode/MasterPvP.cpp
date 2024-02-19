#include"MasterPvP.h"

MasterPvP::MasterPvP(Player * player_list) {
    if (player_list->get_current() < NumOfPokemons)
    {
        cout << "You need to have at least 3 pokemons to play this mode" << endl;
        return;
    }
    OpponentName = GenerateOpponentName();
    
    cout << "\033[2J\033[H";
    cout << OpponentName << endl;
    cout << "Welcome to The hardest mode" << endl;
    this_thread::sleep_for(chrono::seconds(2)); 
    cout << "\033[2J\033[H";
    cout << "You win the battle you become Master Trainer!!" << endl; 
    this_thread::sleep_for(chrono::seconds(3)); 
    // Generate Stage2 Pokemon
    GenerateOpponent(NumOfPokemons,stage2);
    player_pokemons = player_list->GetPlayerList();
    advanceDisplayBattle(player_list,NumOfPokemons);
    DisplayResult();
}

void MasterPvP::DisplayResult() {
    cout << "Result: " <<Results << "-" << 3-Results << endl;
    if (Results > 1)
    {
        cout << "Victory!" << endl;
        cout << "CONGRTUALATION! YOU ARE THE MASTER TRAINER!" << endl;
        outGame();
    }
    else {
        cout << "You Lose!" << endl;
        cout << OpponentName<< ": haha! it's not easy to get what you desire, dude!" << endl;
    }
}

string MasterPvP::GenerateOpponentName() {
    vector<string> names = {"ChatGPT", "Elon Musk", "Steve Job", "Messi"};

    // Random device for seed
    random_device rd;
    mt19937 gen(static_cast<unsigned>(time(nullptr)));
    
    // Generate a random index within the range of the vector size
    uniform_int_distribution<int> distribution(0, names.size() - 1);
    int randomIndex = distribution(gen);
    cout << "\033[2J\033[H";
    cout << names[randomIndex] << " challanges you 3v3 Master Pokemon Battle, let's fight..."<< endl;
    this_thread::sleep_for(chrono::seconds(3)); 
    cout << "\033[2J\033[H";
    return names[randomIndex];
}

void MasterPvP::outGame() {
    cout << "Thank for playing our game!" << endl;
    exit(0);
}