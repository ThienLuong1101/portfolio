#include"PvP.h"
PvP::PvP(){}
PvP::PvP(Player * player_list) {
    if (player_list->get_current() < 2)
    {
        cout << "You need to have at least 2 pokemons to play this mode" << endl;
        return;
    }
    OpponentName = GenerateOpponentName();
    GenerateOpponent(NumOfPokemons,stage1);
    player_pokemons = player_list->GetPlayerList();
    advanceDisplayBattle(player_list,NumOfPokemons);
    DisplayResult();
}

void PvP::DisplayResult() {
    cout << "\033[2J\033[H";
    cout << "Final Result: ";
    if (Results == 1)
    {
        cout << "1-1" << endl;
        cout << OpponentName<< ": it's a draw! good game :))" << endl;
    }else if (Results == 2) {
        cout << "2-0" << endl;
        cout << "Victory!" << endl;
        cout << OpponentName<< ": Amazing trainer! I lose T^T" << endl;
    }
    else {
        cout << "0-2" << endl;
        cout << "Defeated!" << endl;
        cout << OpponentName<< ": haha! Need more practice, dumbass :D" << endl;
    }
}

Pokemon PvP::AdvanceChoosePokemon(Pokemon * pokemons, int len) {
    string pre_poke = chosenPokemon.getName();
    int invalidNum;
    for (int i = 0; i < len; i++) {
        if (pre_poke != pokemons[i].getName())
        {
            cout << "Press " << i << " to choose " << pokemons[i].getName() << endl;
            cout << "Type: " << pokemons[i].getType() << "  Health: " << pokemons[i].getHP() << "  Attack: " << pokemons[i].getAttack() << "  Speed: " << pokemons[i].getSpeed() << endl;
        }
    }
    while (true) {
        
        cout << "Enter your choice (as a number): ";
        string choiceStr;
        cin >> choiceStr;
        
        try {
            int choice = stoi(choiceStr);

            if (choice >= 0 && choice < len && choice != invalidNum) {
                cout << "\033[2J\033[H";
                cout << "I choose you: " << pokemons[choice].getName() << endl;
                return pokemons[choice];
            } else {
                cout << "Invalid choice." << endl;
            }
        } catch (const invalid_argument&) {
            cout << "Invalid input." << endl;
        }
    }
    
    return pokemons[0];
}

// Function to generate a random name
string PvP::GenerateOpponentName() {
    vector<string> names = {"Naruto", "Luffy", "Levi", "Zoro", "Saitama"};

    // Random device for seed
    random_device rd;
    mt19937 gen(static_cast<unsigned>(time(nullptr)));
    
    // Generate a random index within the range of the vector size
    uniform_int_distribution<int> distribution(0, names.size() - 1);
    int randomIndex = distribution(gen);
    cout << "\033[2J\033[H";
    cout << names[randomIndex] << " challanges you 2v2 Pokemon Battle, let's fight..."<< endl;
    this_thread::sleep_for(chrono::seconds(3)); 
    cout << "\033[2J\033[H";
    return names[randomIndex];
}

void PvP::advanceDisplayBattle(Player * player_list, int NumOfFights) {
    int len = NumOfFights;
    for (int i = 0; i < len; i++)
    {
        cout << "--------------------ROUND "<<i+1<<"--------------------" << endl;
        cout << OpponentName << " chooses " << opponent[i].getName() << endl;
        cout << "Type: " << opponent[i].getType() << "  Health: " << opponent[i].getHP() << "  Attack: " << opponent[i].getAttack() << "  Speed: " << opponent[i].getSpeed() << endl;
        cout << "Warning: Pokemon has higher speed attack first!" << endl;
        this_thread::sleep_for(chrono::seconds(2)); 
        cout << endl;
        cout << "---------Choose your pokemon to fight-----------" << endl;
        chosenPokemon = AdvanceChoosePokemon(player_pokemons,player_list->get_current());
        int YourSpeed = chosenPokemon.getSpeed();
        int OppSpeed = opponent[i].getSpeed();
        
        if (OppSpeed > YourSpeed)
        {     
            displayBattle(opponent[i],chosenPokemon,false);
        } else {
            displayBattle(chosenPokemon, opponent[i],true);
        }
        if (win)
        {
            Results++;
            cout << OpponentName << ": Ahh! my " << opponent[i].getName() << endl;
            checkWin(player_list,chosenPokemon.getName());
            win = false;
            checkEvolve(player_list);
            player_list->SavePokeListToFile();
        } else{
            cout << OpponentName << ": haha! my " << opponent[i].getName() << " is the best!!" << endl;
        }
        string quit;
        cout << endl;
        cout << "Enter R to go to the next round: " << endl;
        while (true)
        {   
            cin >> quit;
            if (quit == "R" || quit == "r")
            {
                cout << "\033[2J\033[H";
                break;
            }
        }
    }
}