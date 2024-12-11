#include "Enemy.h"
std::string Enemy:: getShipCounts() const {
    int twoDeckCount = 0, threeDeckCount = 0, fourDeckCount = 0;

    for (const Ship* ship : ships) {
        if (ship->isDestroyed()) continue; // ���������� ����������� �������
        int length = ship->getLength();
        if (length == 2) twoDeckCount++;
        else if (length == 3) threeDeckCount++;
        else if (length == 4) fourDeckCount++;
    }

    return "������������: " + std::to_string(twoDeckCount) +
        ", ������������: " + std::to_string(threeDeckCount) +
        ", ���������������: " + std::to_string(fourDeckCount);
}

void Enemy:: placeShipsRandomly(int boardSize, const std::vector<int>& shipLengths) {
    ships.clear(); // ������� ���������� ��������

    std::random_device rd; // �������� ��������� seed
    std::mt19937 gen(rd()); // ������������� ����������
    std::uniform_int_distribution<> dis(0, boardSize - 1); // ������������� ��� ���������

    for (int length : shipLengths) {
        bool placed = false;
        while (!placed) {
            // �������� ���������� ���������� � ���������� (�������������/�����������)
            bool horizontal = dis(gen) % 2 == 0;

            int x = dis(gen);
            int y = dis(gen);

            // �������� ����������� ����������
            if (canPlaceShip(x, y, length, horizontal, boardSize)) {
                ships.push_back(new Ship(x, y, length, horizontal)); // �������� ������ �������
                placed = true; // ��������� ����� � ����������
            }
        }
    }
}