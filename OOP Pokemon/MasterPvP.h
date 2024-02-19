#ifndef MASTERPVP_H
#define MASTERPVP_H

#include"PvP.h"

class MasterPvP : public PvP
{
private:
    int NumOfPokemons = 3;

    string stage2 = "stage2.txt";
public:
    MasterPvP(Player * player_list);
    void DisplayResult() override;
    string GenerateOpponentName() override;
    void outGame();
};


#endif