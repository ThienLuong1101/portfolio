#include "HuntPvP.h"

HuntPvP::HuntPvP(Player* player_list) {
    player_pokemons = player_list->GetPlayerList();
    cout << endl;
    cout << "Traveling..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    GenerateWildPokemon(player_list, 1, basic);
    cout << wildPokemon << " wants to fight!" << endl;
    cout << "Type: " << opponent[0].getType() << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "choose your pokemon to fight: " << endl;
    cout << "-----------------------" << endl;
    chosenPokemon = player_list->ChoosePokemon();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\033[2J\033[H";
    string PokeName = chosenPokemon.getName();
    cout << "you choose: " << PokeName << endl;

    displayBattle(chosenPokemon, opponent[0], true); //Your Pokemon always goes first in this mode
    if (win) {
        if (HuntPvPYorN(opponent[0])) {
            player_list->AddPokemon("PokemonList.txt", wildPokemon);
            player_list->SavePokeListToFile();
        }
        // Check if the player gets a new pokemon or not and set the number of wins of the chosen pokemon
        checkWin(player_list, PokeName);
    }

    // Check for evolution
    checkEvolve(player_list);

    player_list->SavePokeListToFile();
}

void HuntPvP::GenerateWildPokemon(Player* player_list, int num, string file) {
    Opponent b(num);
    bool found = true;
    vector<string> PokemonNames = player_list->getPokemonNames(player_list->makeFile());

    // Generate a random pokemon which the player doesn't have
    while (found) {
        vector<string> OpponentPokemonNames = b.GenerateRandomPokemon(file);
        wildPokemon = OpponentPokemonNames[0];
        found = false;
        for (string name : PokemonNames) {
            if (wildPokemon == name) {
                found = true;
            }
        }
    }
    opponent = b.GetOpponentList();
}

bool HuntPvP::HuntPvPYorN(Pokemon b) {
    string choice;

    do {
        cout << "Do you want to catch [y/n]: " << b.getName() << endl;
        cin >> choice;
    } while (choice != "y" && choice != "n");

    if (choice == "y") {
        cout << "\033[2J\033[H";
        return true;
    } else {
        cout << "\033[2J\033[H";
        cout << b.getName() << " run away! " << b.getSound() << endl;
        this_thread::sleep_for(chrono::seconds(1));
        return false;
    }
}

void HuntPvP::checkEvolve(Player* player_list) {
    for (int i = 0; i < player_list->get_current(); i++) {
        Stage1Pokemon EvoPokemon;
        Stage2Pokemon FinalEvoPokemon;
        if (EvoPokemon.Evolve(player_pokemons[i], player_list)) {
            player_pokemons[i] = EvoPokemon;
        }
        if (FinalEvoPokemon.Evolve(player_pokemons[i], player_list)) {
            player_pokemons[i] = FinalEvoPokemon;
        }
    }
}

void HuntPvP::checkWin(Player* player_list, string PokeName) {
    for (int i = 0; i < player_list->get_current(); i++) {
        if (player_pokemons[i].getName() == PokeName) {
            player_pokemons[i].setNumOfWins(1);
            win = false;
        }
    }
}
