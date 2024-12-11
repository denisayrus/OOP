#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "ship_manager.h"
#include "game_field.h"
#include "Player.h"
#include <string>
#include "Enemy.h"

class GameState {
public:
    Player player;
    Enemy enemy;
    bool playerTurn;
    Ability_Manager abilityManager; 
    game_field field;                 
    ship_manager shipManager;

    GameState();
    

    void displayState() const;
    void saveState(const std::string& filename);

    void loadState(const std::string& filename);
};


#endif
