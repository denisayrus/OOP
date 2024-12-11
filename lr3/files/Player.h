#ifndef PLAYER_H
#define PLAYER_H
#include "ship.h"
#include <string>
#include <random>
#include <iostream>
#include <algorithm>

#include "Ability_Manager.h"
class Enemy;  // Предварительное объявление класса Enemy

class Player {
private:
    int attackPower;
    ship_manager manager;
    int count;
    std::vector<Ability*> abilityList;
public:
    int health;
    //int attackPower;
    std::string ability;
    Player(int attackPower) : attackPower(attackPower) {}
    Player();
  
    void attack(Enemy& target, ship_manager& sm, game_field& field);   // Изменили параметр с Player на Enemy
    void useAbility(Enemy& target, Ability_Manager& abilityManager, game_field& field, ship_manager& sm);  // Способность, которая будет работать с Enemy
    // Список кораблей игрока
    std::vector<Ship*> ships;

    // Другие методы и переменные



    // Метод для добавления способности
    void addRandomAbility() {
        // Массив указателей на способности
        Ability* abilities[] = { new DoubleDamage(), new Scanner(), new Bombardment() };

        // Генерируем случайный индекс
        int randomIndex = rand() % 3; // 0, 1 или 2

        // Добавляем случайную способность в список
        abilityList.push_back(abilities[randomIndex]);
        std::cout << "Получена новая способность: " << typeid(*abilities[randomIndex]).name() << std::endl;

        // Освобождение памяти - если не использовать умные указатели, освободите память по окончании
        delete abilities[randomIndex];
    }
    void destroyEnemyShip(Enemy& target, Ship* destroyedShip) {
        // Логика для уничтожения корабля противника
        std::cout << "Корабль противника уничтожен!" << std::endl;

        // Добавление новой способности
        addRandomAbility();
    }
    // Проверка, остались ли корабли у игрока
    // Проверка, остались ли корабли у игрока
    bool hasShips() const {
        return std::any_of(ships.begin(), ships.end(), [](const Ship* ship) {
            return !ship->isDestroyed(); // Проверяет, есть ли не уничтоженные корабли
            });
    }
};


#endif
