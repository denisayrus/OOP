#include "Game.h"
#include "Player.h"
#include <iostream>
#include "Ability_Manager.h"
#include "ship_manager.h"

Game::Game() : state() {}

void Game::startNewGame() {
    // Инициализация кораблей для игрока и врага
   // std::vector<int> playerShipLengths = { 2, 3, 3 };
    std::vector<int> enemyShipLengths = { 2, 3, 3 };


    state.enemy.placeShipsRandomly(10, enemyShipLengths);
   
    state.playerTurn = true;

    // Вывод состояния кораблей
  //  std::cout << "Корабли игрока: " << state.player.getShipCounts() << std::endl;
    std::cout << "Корабли противника: " << state.enemy.getShipCounts() << std::endl;
}

void Game::performPlayerTurn() {
    if (state.player.health > 0 && state.enemy.health > 0) {
        std::cout << "Твоя очередь!" << std::endl;
        std::cout << "1. Атака\n2. Способность" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            state.player.attack(state.enemy, sm, gf);
        }
        else if (choice == 2) {
            state.player.useAbility(state.enemy, state.abilityManager, state.field, state.shipManager);
        }

        state.playerTurn = false;
    }
}

void Game::performEnemyTurn() {
    if (state.enemy.health > 0 && state.player.health > 0) {
        std::cout << "Очередь врага!" << std::endl;
        state.enemy.attack(state.player);
        state.playerTurn = true;
    }
}

void Game::playRound() {
    while (state.player.health > 0 && state.enemy.health > 0) {
        state.displayState();
        if (state.playerTurn) {
            performPlayerTurn();
        }
        else {
            performEnemyTurn();
        }
    }

    if (state.player.health <= 0) {
        std::cout << "Вы проиграли этот раунд! Начинаю новую игру..." << std::endl;
        startNewGame();
    }
    else {
        std::cout << "Вы выиграли раунд! Переходим к следующему раунду..." << std::endl;
    }
}


void Game::saveGame(const std::string& filename) {
    state.saveState(filename);
    isSaved = true; // Устанавливаем флаг сохранения
}

void Game::loadGame(const std::string& filename) {
    if (!isSaved) { // Проверяем, была ли игра сохранена
        std::cerr << "Ошибка: Игра не сохранена. Загрузка невозможна!" << std::endl;
        return; // Прерываем выполнение, если игра не сохранена
    }
    state.loadState(filename);
}