#ifndef PLAYER_H
#define PLAYER_H
#include "ship.h"
#include <string>
#include <random>
#include <iostream>
#include <algorithm>

#include "Ability_Manager.h"
class Enemy;  // ��������������� ���������� ������ Enemy

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
  
    void attack(Enemy& target, ship_manager& sm, game_field& field);   // �������� �������� � Player �� Enemy
    void useAbility(Enemy& target, Ability_Manager& abilityManager, game_field& field, ship_manager& sm);  // �����������, ������� ����� �������� � Enemy
    // ������ �������� ������
    std::vector<Ship*> ships;

    // ������ ������ � ����������



    // ����� ��� ���������� �����������
    void addRandomAbility() {
        // ������ ���������� �� �����������
        Ability* abilities[] = { new DoubleDamage(), new Scanner(), new Bombardment() };

        // ���������� ��������� ������
        int randomIndex = rand() % 3; // 0, 1 ��� 2

        // ��������� ��������� ����������� � ������
        abilityList.push_back(abilities[randomIndex]);
        std::cout << "�������� ����� �����������: " << typeid(*abilities[randomIndex]).name() << std::endl;

        // ������������ ������ - ���� �� ������������ ����� ���������, ���������� ������ �� ���������
        delete abilities[randomIndex];
    }
    void destroyEnemyShip(Enemy& target, Ship* destroyedShip) {
        // ������ ��� ����������� ������� ����������
        std::cout << "������� ���������� ���������!" << std::endl;

        // ���������� ����� �����������
        addRandomAbility();
    }
    // ��������, �������� �� ������� � ������
    // ��������, �������� �� ������� � ������
    bool hasShips() const {
        return std::any_of(ships.begin(), ships.end(), [](const Ship* ship) {
            return !ship->isDestroyed(); // ���������, ���� �� �� ������������ �������
            });
    }
};


#endif
