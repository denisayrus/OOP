#include "Game.h"
#include "Player.h"
#include <iostream>
#include "Ability_Manager.h"
#include "ship_manager.h"

Game::Game() : state() {}

void Game::startNewGame() {
    // ������������� �������� ��� ������ � �����
   // std::vector<int> playerShipLengths = { 2, 3, 3 };
    std::vector<int> enemyShipLengths = { 2, 3, 3 };


    state.enemy.placeShipsRandomly(10, enemyShipLengths);
   
    state.playerTurn = true;

    // ����� ��������� ��������
  //  std::cout << "������� ������: " << state.player.getShipCounts() << std::endl;
    std::cout << "������� ����������: " << state.enemy.getShipCounts() << std::endl;
}

void Game::performPlayerTurn() {
    if (state.player.health > 0 && state.enemy.health > 0) {
        std::cout << "���� �������!" << std::endl;
        std::cout << "1. �����\n2. �����������" << std::endl;
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
        std::cout << "������� �����!" << std::endl;
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
        std::cout << "�� ��������� ���� �����! ������� ����� ����..." << std::endl;
        startNewGame();
    }
    else {
        std::cout << "�� �������� �����! ��������� � ���������� ������..." << std::endl;
    }
}


void Game::saveGame(const std::string& filename) {
    state.saveState(filename);
    isSaved = true; // ������������� ���� ����������
}

void Game::loadGame(const std::string& filename) {
    if (!isSaved) { // ���������, ���� �� ���� ���������
        std::cerr << "������: ���� �� ���������. �������� ����������!" << std::endl;
        return; // ��������� ����������, ���� ���� �� ���������
    }
    state.loadState(filename);
}