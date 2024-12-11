#pragma once
#include "ship.h"
#include <string>
#include <random>
#include <iostream>
#include <algorithm>

#include "Ability_Manager.h"
#include "Player.h"
class Enemy {
public:

    // int health;
    int attackPower;
    //  int health;
    std::vector<Ship*> ships; // ��������� ����� ������ ��������
   // Enemy(int hp, int ap) : health(hp), attackPower(ap) {}
    Enemy(int health) : health(health) {}
    //  Enemy() : attackPower(10) {}
    void addShip(Ship* ship) {
        ships.push_back(ship);
    }
    Enemy();
    void setShipManager(const ship_manager& manager) {
        this->manager = manager; // ������� ��������� ship_manager
    }




    void attack(Player& target);
    //  std::vector<Ship*> ships; // ������ ��� �������� ���������� �� �������
    int health = 100;         // �������� ����������

    void placeShipsRandomly(int boardSize, const std::vector<int>& shipLengths);

     // ������ ������ � ����������

     // ����� ��� �������� ���������� �������� ���������� � �����
    std::string getShipCounts() const;






    std::vector<int> getShipLengths() const {
        return manager.getShipLengths(); // �������� ����� ��������
    }

private:
    bool canPlaceShip(int x, int y, int length, bool horizontal, int boardSize) {
        if (horizontal) {
            if (x + length > boardSize) return false; // �������� �� �����������
        }
        else {
            if (y + length > boardSize) return false; // �������� �� ���������
        }

        // �������� �� ����������� � ��� ������������ ���������
        for (const Ship* ship : ships) {
            for (int i = 0; i < length; ++i) {
                int checkX = horizontal ? x + i : x; // ���������� ��� ��������
                int checkY = horizontal ? y : y + i; // " "
                if (ship->isAt(checkX, checkY)) {
                    return false; // ���� ���������� ������, ������ false
                }
            }
        }
        return true; // ���� ��������, ���������� true
    }
    ship_manager manager;

};
