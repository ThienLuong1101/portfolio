#ifndef PVP_H
#define PVP_H

#include"Battle.h"

class PvP : public Battle
{
protected:
    int NumOfPokemons = 2;
    int Results = 0;
    string OpponentName;
    string stage1 = "stage1.txt";
public:
    PvP();
    PvP(Player * player_list);
    Pokemon AdvanceChoosePokemon(Pokemon * pokemons, int len);
    virtual void DisplayResult();
    virtual string GenerateOpponentName();
    void advanceDisplayBattle(Player * player_list,int NumOfFights);
};


#endif