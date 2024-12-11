#include "Player.h"
#include <iostream>
#include "EnemyShipInitializer.h"
#include "Enemy.h"
Player::Player() : health(100), attackPower(10), ability("Fireball") {}

void Player::attack(Enemy& target, ship_manager& sm, game_field& field) {
    // Размещение кораблей противника на поле
    std::vector<int> shipLengths = { 2, 3, 3 }; // Пример кораблей
   target.placeShipsRandomly(10, shipLengths);

    int x, y;
    std::cout << "Введите координаты атаки (x y): ";
    while (!(std::cin >> x >> y) || x < 0 || x >= 10 || y < 0 || y >= 10) {
        std::cout << "Неверный ввод. Пожалуйста, введите числа в диапазоне 0-9: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool attackSuccessful = false;

    // Перебор кораблей для проверки попадания
    for (const Ship* ship : target.ships) {
        if (ship && ship->isHit(x, y)) {
            attackSuccessful = true;
            break; // Завершить цикл при первом попадании
        }
    }

    // Вывод результатов
    if (attackSuccessful) {
        std::cout << "Попадание!" << std::endl;
    }
    else {
        std::cout << "Промах!" << std::endl;
    }
}

void Player::useAbility(Enemy& target, Ability_Manager& abilityManager, game_field& field, ship_manager& sm) {
    std::cout << "Игрок пытается использовать способность!" << std::endl;

    // Вызываем метод использования способности из Ability_Manager
    abilityManager.useAbility(field, sm);

    // Примерная сила способности, например, 20
    std::cout << "Игрок использует способность на враге!" << std::endl;
    target.health -= 20; // Предполагаемый урон от способности
}
Enemy::Enemy() : health(50), attackPower(10) {}

void Enemy::attack(Player& target) {
    target.health -= attackPower;
    std::cout << "Враг атакует игрока за " << attackPower << " ущерб!" << std::endl;
}
