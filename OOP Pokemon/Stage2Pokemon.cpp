#include "Stage2Pokemon.h"

Stage2Pokemon::Stage2Pokemon() : Stage1Pokemon() {}

Stage2Pokemon::Stage2Pokemon(string _name, string _type, string _sound, int _hp, int _attack, int _speed)
: Stage1Pokemon(_name, _type, _sound, _hp, _attack, _speed) {}

bool Stage2Pokemon::Evolve(Pokemon basic,Player* player_list) {
    if (basic.getNumOfWin() == s2 && !CheckEvolve(basic.getName(), Stage2Data))
    {
        string name = basic.getName();
        int speed = basic.getSpeed();
        int attack = basic.getAttack();
        int hp = basic.getHP();
        
        // Check if the given name exists in the map
        if (Stage2Data.find(name) != Stage2Data.end()) {
            // Retrieve the evolved form and update the attributes
            string evolvedName = Stage2Data[name];
            setHP(hp + 100);
            setAttack(attack + 20);
            setSpeed(speed);
            setType(basic.getType());
            setSound(basic.getSound());
            setName(evolvedName);
            cout << "congratulation! " << name << " final evolve to " << evolvedName << endl; 
            return true;
        }
    }
    return false;
}

void Stage2Pokemon::Emoji() {
    // List of cute actions
    string EmojiList[] = {"-.-",":))",":D",":((",">.<","@.@","($.$)"};
    random_device rd;
    mt19937 gen(rd());
    int numActions = sizeof(EmojiList) / sizeof(EmojiList[0]);
    uniform_int_distribution<int> distribution(0, numActions - 1);
    int i = distribution(gen);
    cout << getName() << " is making this stupid face: " << EmojiList[i] << "! "<< endl;
}

map<string, string> Stage2Pokemon::GetStage2Data() {
        return Stage2Data;
}
