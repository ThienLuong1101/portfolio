#include "Stage1Pokemon.h"

Stage1Pokemon::Stage1Pokemon() : Pokemon() {}

Stage1Pokemon::Stage1Pokemon(string _name, string _type, string _sound, int _hp, int _attack, int _speed)
: Pokemon(_name, _type, _sound, _hp, _attack, _speed) {}

bool Stage1Pokemon::Evolve(Pokemon basic,Player* player_list) {
    // Define a map to store the evolution data for each Pokémon
    
   
    if (basic.getNumOfWin() == s1 && !CheckEvolve(basic.getName(), Stage1Data))
    {
        string name = basic.getName();
        int speed = basic.getSpeed();
        int attack = basic.getAttack();
        int hp = basic.getHP();
        
        // Check if the given name exists in the map
        if (Stage1Data.find(name) != Stage1Data.end()) {
            // Retrieve the evolved form and update the attributes
            string evolvedName = Stage1Data[name];
            setHP(hp * 2);
            setAttack(attack + 20);
            setSpeed(speed);
            setType(basic.getType());
            setSound(basic.getSound());
            setName(evolvedName);
            
            cout << "congratulation! " << name << " evolve to " << evolvedName << endl; 
            this_thread::sleep_for(chrono::seconds(1));
            return true;
        }
    }
    return false;
}

bool Stage1Pokemon::CheckEvolve(string name, map<string, string> dataMap) {
    for (const auto& pair : dataMap) {
        if (pair.second == name) {
            return true; // Name found in the second column
        }
    }
    return false; // Name not found in the second column
}

void Stage1Pokemon::Action() {
    // List of cute actions
    string cuteActions[] = {"Sleeping z.z","Hiding","Belly Dancing","Doing nothing","Rapping","Depressing"};
    random_device rd;
    mt19937 gen(rd());
    int numActions = sizeof(cuteActions) / sizeof(cuteActions[0]);
    uniform_int_distribution<int> distribution(0, numActions - 1);
    int i = distribution(gen);

    cout << getName() << " is " << cuteActions[i] << "!!!" << endl;
}

map<string, string> Stage1Pokemon::GetStage1Data() {
        return Stage1Data;
}
