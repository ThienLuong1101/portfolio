#include"CurrentGame.h"

CurrentGame::CurrentGame() {}

void CurrentGame::displayMenu() {
    string input;
    Player player;
    vector<string> PokemonNames = player.getPokemonNames(get_filePath());
    for (string name : PokemonNames)
    {
        player.AddPokemon("PokemonList.txt",name);
    }
    
    player.set_len_list(3);
    while (true) {
        cout << endl;
        cout << "------------Main-------------" << endl;
        cout << "Press 1 for battle" << endl;
        cout << "Press 2 for displaying your Pokemon list" << endl;
        cout << "press 3 for playing with your pokemons" << endl;
        cout << "-----------------------------" << endl;
        cout << "press 4 for Creative Mode" << endl;
        cout << "press 5 for quit the game" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> input;
        
        if (input == "1") {
            string input1;
            cout << "\033[2J\033[H";
            cout << "---------Battle----------" << endl;
            cout << "Press 1 for Catch Pokemon" << endl;
            cout << "Press 2 for PvP battle" << endl;
            cout << "Press 3 for MasterPvP battle" << endl;
            cout << "-----------------------" << endl;
            cout << "Enter your choice: ";
            cin >> input1;
            if (input1 == "1")
            {
                cout << "\033[2J\033[H";
                HuntPvP mode1(&player);
                
            } else if (input1 == "2")
            {
                cout << "\033[2J\033[H";
                PvP mode2(&player);
                
            } else if (input1 == "3")
            {
                cout << "\033[2J\033[H";
                MasterPvP mode3(&player);
                
            }
            
        } else if (input == "2") {
            cout << AccessFilePath() << "here" <<endl;
            pokemonList print;
            
            print.PrintPokemonListFile(AccessFilePath());
       } else if (input == "3") {
            cout << "\033[2J\033[H";
            PokemonBehavior(player);
        } else if (input == "4") {
            cout << "\033[2J\033[H";
            pokemonList list;
            list.pokemonListRecord();

        } else if (input == "5") {

            cout << "\033[2J\033[H";
            exit(0);
            
        } else {
            cout << "Invalid choice." << endl;
            // Loop will continue until a valid choice is entered
        }
    }
}



void CurrentGame::PokemonBehavior(Player& player) {
    int len = player.get_current();
    Pokemon** pokemonsPtr = new Pokemon*[len];
    Pokemon * pokemons = player.GetPlayerList();
    Stage1Pokemon clone1;
    Stage2Pokemon clone2;
    cout << "What is your pokemon doing???" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    for (int i = 0; i < len; i++)
    {   
        string pokemon = pokemons[i].getName();
        string sound = pokemons[i].getSound();
        if(clone2.CheckEvolve(pokemon,clone2.GetStage2Data())) {
            pokemonsPtr[i] = new Stage2Pokemon(pokemon,"",sound,0,0,0);  
            Stage2Pokemon* Ptr2 = dynamic_cast<Stage2Pokemon*>(pokemonsPtr[i]);
            
            std::cout << Ptr2->getName() << " says "<<Ptr2->getSound() << std::endl;
            Ptr2->Action();
            Ptr2->Emoji();     
        }
        else if(clone1.CheckEvolve(pokemon,clone1.GetStage1Data())) {
            pokemonsPtr[i] = new Stage1Pokemon(pokemon,"",sound,0,0,0);   
            Stage1Pokemon * Ptr1 = dynamic_cast<Stage1Pokemon*>(pokemonsPtr[i]); 

            std::cout << Ptr1->getName() << " says "<<Ptr1->getSound() << std::endl;
            Ptr1->Action();

        }else{
            std::cout << pokemon << " says "<< sound << std::endl;
        }
        cout << "-----------------------" << endl;
    }

    
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

void CurrentGame::set_filePath(string _filePath) {
    this->filePath = _filePath;
}

string CurrentGame::get_filePath() {
    return filePath;}

bool CurrentGame::isFolderEmpty(string folderPath) {
    return fs::is_empty(folderPath);
}

string CurrentGame::AccessFilePath() {
   try {
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
            throw std::filesystem::filesystem_error("The folder does not exist or is not a directory.", std::make_error_code(std::errc::no_such_file_or_directory));
        }
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                // Process the file.
                return entry.path().string();
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return "";
}