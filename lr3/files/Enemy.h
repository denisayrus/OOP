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
    std::vector<Ship*> ships; // Противник имеет вектор кораблей
   // Enemy(int hp, int ap) : health(hp), attackPower(ap) {}
    Enemy(int health) : health(health) {}
    //  Enemy() : attackPower(10) {}
    void addShip(Ship* ship) {
        ships.push_back(ship);
    }
    Enemy();
    void setShipManager(const ship_manager& manager) {
        this->manager = manager; // Храните экземпляр ship_manager
    }




    void attack(Player& target);
    //  std::vector<Ship*> ships; // Вектор для хранения указателей на корабли
    int health = 100;         // Здоровье противника

    void placeShipsRandomly(int boardSize, const std::vector<int>& shipLengths);

     // Другие методы и переменные

     // Метод для проверки количества кораблей остающихся у врага
    std::string getShipCounts() const;






    std::vector<int> getShipLengths() const {
        return manager.getShipLengths(); // Получаем длины кораблей
    }

private:
    bool canPlaceShip(int x, int y, int length, bool horizontal, int boardSize) {
        if (horizontal) {
            if (x + length > boardSize) return false; // Проверка по горизонтали
        }
        else {
            if (y + length > boardSize) return false; // Проверка по вертикали
        }

        // Проверка на пересечение с уже размещенными кораблями
        for (const Ship* ship : ships) {
            for (int i = 0; i < length; ++i) {
                int checkX = horizontal ? x + i : x; // координаты для проверки
                int checkY = horizontal ? y : y + i; // " "
                if (ship->isAt(checkX, checkY)) {
                    return false; // Если координаты заняты, вернем false
                }
            }
        }
        return true; // Если свободно, возвращаем true
    }
    ship_manager manager;

};
