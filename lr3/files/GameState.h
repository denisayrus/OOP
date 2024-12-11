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
    Ability_Manager abilityManager; // Убедитесь, что этот класс существует
    game_field field;                 // Убедитесь, что этот класс существует
    ship_manager shipManager;

    GameState();
    

    void displayState() const;
    void saveState(const std::string& filename);

    void loadState(const std::string& filename);
};


#endif
