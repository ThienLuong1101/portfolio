#include "Battle.h"

#include "Stage1Pokemon.h"
#include "Stage2Pokemon.h"

// Function to calculate the attack and apply type advantages
int Battle::Attack(Pokemon attacker, Pokemon defender) {
  int damage = attacker.getAttack();

  // Check for type advantages and calculate damage
  if ((attacker.getType() == "Water" && defender.getType() == "Fire") ||
      (attacker.getType() == "Fire" && defender.getType() == "Grass") ||
      (attacker.getType() == "Grass" && defender.getType() == "Water")) {
    damage *= 2;  // Double damage for type advantage
    cout << attacker.getName() << " strictly attacks for "
         << attacker.getAttack() * 2 << " damage to " << defender.getName()
         << endl;
  } else {
    cout << attacker.getName() << " attacks for " << attacker.getAttack()
         << " damage to " << defender.getName() << endl;
  }
  return damage;
}

// Function to generate random opponent Pokemon names
void Battle::GenerateOpponent(int num, string file) {
  Stage2Pokemon clone;
  Opponent rival(num);
  // Generate random opponent Pokemon names and store them
  vector<string> OpponentPokemonNames = rival.GenerateRandomPokemon(file);
  opponent = rival.GetOpponentList();
}

// Function to display the battle between two Pokemon
void Battle::displayBattle(Pokemon a, Pokemon b, bool IsYourPokeGoFirst) {
  cout << "Pokemon battle start!!!" << endl;
  cout << a.getName() << " vs " << b.getName() << endl;
  cout << "---------------------------------------" << endl;
  cout << a.getName() << " attacks first!" << endl;
  this_thread::sleep_for(chrono::milliseconds(600));
  int turn = 0;

  // Battle loop
  while (b.getHP() > 0 && a.getHP() > 0) {
    if (turn % 2 == 0) {
      int damage = Attack(a, b);
      b.setHP(b.getHP() - damage);
      cout << b.getName() << ": " << b.getHP() << " HP!" << endl;
      this_thread::sleep_for(chrono::milliseconds(500));
    } else {
      int damage = Attack(b, a);
      a.setHP(a.getHP() - damage);
      cout << a.getName() << ": " << a.getHP() << " HP!" << endl;
      this_thread::sleep_for(chrono::milliseconds(500));
    }
    turn++;

    // Check for battle result
    if (IsYourPokeGoFirst) {
      if (b.getHP() <= 0) {
        win = true;
        cout << "---------------------------------------" << endl;
        cout << "You win!" << endl;
      } else if (a.getHP() <= 0) {
        cout << "---------------------------------------" << endl;
        cout << "You lose!" << endl;
        return;
      }
    } else {
      if (a.getHP() <= 0) {
        win = true;
        cout << "---------------------------------------" << endl;
        cout << "You win!" << endl;
      } else if (b.getHP() <= 0) {
        cout << "---------------------------------------" << endl;
        cout << "You lose!" << endl;
        return;
      }
    }
  }
}

// Function to check if a player's Pokemon can evolve
void Battle::checkEvolve(Player* player_list) {
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

// Function to check if the player's Pokemon has won a battle
void Battle::checkWin(Player* player_list, string PokeName) {
  for (int i = 0; i < player_list->get_current(); i++) {
    if (player_pokemons[i].getName() == PokeName) {
      player_pokemons[i].setNumOfWins(1);
      win = false;
    }
  }
}
