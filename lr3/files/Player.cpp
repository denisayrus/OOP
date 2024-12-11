#include "Player.h"
#include <iostream>
#include "EnemyShipInitializer.h"
#include "Enemy.h"
Player::Player() : health(100), attackPower(10), ability("Fireball") {}

void Player::attack(Enemy& target, ship_manager& sm, game_field& field) {
    // ���������� �������� ���������� �� ����
    std::vector<int> shipLengths = { 2, 3, 3 }; // ������ ��������
   target.placeShipsRandomly(10, shipLengths);

    int x, y;
    std::cout << "������� ���������� ����� (x y): ";
    while (!(std::cin >> x >> y) || x < 0 || x >= 10 || y < 0 || y >= 10) {
        std::cout << "�������� ����. ����������, ������� ����� � ��������� 0-9: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    bool attackSuccessful = false;

    // ������� �������� ��� �������� ���������
    for (const Ship* ship : target.ships) {
        if (ship && ship->isHit(x, y)) {
            attackSuccessful = true;
            break; // ��������� ���� ��� ������ ���������
        }
    }

    // ����� �����������
    if (attackSuccessful) {
        std::cout << "���������!" << std::endl;
    }
    else {
        std::cout << "������!" << std::endl;
    }
}

void Player::useAbility(Enemy& target, Ability_Manager& abilityManager, game_field& field, ship_manager& sm) {
    std::cout << "����� �������� ������������ �����������!" << std::endl;

    // �������� ����� ������������� ����������� �� Ability_Manager
    abilityManager.useAbility(field, sm);

    // ��������� ���� �����������, ��������, 20
    std::cout << "����� ���������� ����������� �� �����!" << std::endl;
    target.health -= 20; // �������������� ���� �� �����������
}
Enemy::Enemy() : health(50), attackPower(10) {}

void Enemy::attack(Player& target) {
    target.health -= attackPower;
    std::cout << "���� ������� ������ �� " << attackPower << " �����!" << std::endl;
}
