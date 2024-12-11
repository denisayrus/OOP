#include "GameState.h"
#include <fstream>
#include <iostream>
#include "Ability_Manager.h"
GameState::GameState() : player(), enemy(), playerTurn(true) {}

void GameState::saveState(const std::string& filename) {
    // ������ ���������� ��������� ���� � ����
    std::cout << "���� ��������� � " << filename << std::endl;
}

void GameState::displayState() const {
    std::cout << "�������� ������: " << player.health << std::endl;
    std::cout << "�������� �����: " << enemy.health << std::endl;
}

void GameState::loadState(const std::string& filename) {
    // ������ �������� ��������� ���� �� �����
    std::cout << "���� ��������� �� " << filename << std::endl;
}