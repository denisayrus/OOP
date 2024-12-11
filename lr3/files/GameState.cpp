#include "GameState.h"
#include <fstream>
#include <iostream>
#include "Ability_Manager.h"
GameState::GameState() : player(), enemy(), playerTurn(true) {}

void GameState::saveState(const std::string& filename) {
    // Логика сохранения состояния игры в файл
    std::cout << "Игра сохранена в " << filename << std::endl;
}

void GameState::displayState() const {
    std::cout << "Здоровье игрока: " << player.health << std::endl;
    std::cout << "Здоровье врага: " << enemy.health << std::endl;
}

void GameState::loadState(const std::string& filename) {
    // Логика загрузки состояния игры из файла
    std::cout << "Игра загружена из " << filename << std::endl;
}