#include "EnemyShipInitializer.h"
#include <cstdlib>
#include <vector>
#include <set>
#include <utility> // ��� std::pair

std::vector<Ship*> initializeEnemyShips(int shipCount, int fieldWidth, int fieldHeight) {
    std::vector<Ship*> ships;
    std::set<std::pair<int, int>> occupiedCoordinates; // ��������� ��� ������������ ������� ���������

    for (int i = 0; i < shipCount; ++i) {
        std::vector<std::pair<int, int>> segmentCoordinates;

        for (int j = 0; j < 3; ++j) { // ��������, ������ ������� ����� 3 ��������
            std::pair<int, int> coord;
            do {
                int x = rand() % fieldWidth;
                int y = rand() % fieldHeight;
                coord = { x, y }; // ������ ���� ���������
            } while (occupiedCoordinates.count(coord) > 0); // ���������, ������ �� ��� ����������

            // ��������� ���������� � ������ ��������� ������� � � ��������� �������
            segmentCoordinates.push_back(coord);
            occupiedCoordinates.insert(coord);
        }

        ships.push_back(new Ship(segmentCoordinates));
    }

    return ships;
}
