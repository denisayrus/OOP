#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include <string>
#include "Enemy.h"

class Game {
private :
    bool isSaved;
public:
    GameState state;

    Game();
    ship_manager sm;  // ��� ship_manager_instance ���� ���� ��� ������
    game_field gf;
    void startNewGame();
    void performPlayerTurn();
    void performEnemyTurn();
    void playRound();
    //void saveGame(const std::string& filename);
   // void loadGame(const std::string& filename);
   // Game() : isSaved(false) {} // ���������� ���� �� ���������

   // ����� ��� ���������� ����
    void saveGame(const std::string& filename);
    // ����� ��� �������� ����
    void loadGame(const std::string& filename);
};


#endif
