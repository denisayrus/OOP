#include "Enemy.h"
std::string Enemy:: getShipCounts() const {
    int twoDeckCount = 0, threeDeckCount = 0, fourDeckCount = 0;

    for (const Ship* ship : ships) {
        if (ship->isDestroyed()) continue; // Пропустить потопленные корабли
        int length = ship->getLength();
        if (length == 2) twoDeckCount++;
        else if (length == 3) threeDeckCount++;
        else if (length == 4) fourDeckCount++;
    }

    return "Двухпалубных: " + std::to_string(twoDeckCount) +
        ", Трехпалубных: " + std::to_string(threeDeckCount) +
        ", Четырехпалубных: " + std::to_string(fourDeckCount);
}

void Enemy:: placeShipsRandomly(int boardSize, const std::vector<int>& shipLengths) {
    ships.clear(); // Очистка предыдущих кораблей

    std::random_device rd; // Получаем случайное seed
    std::mt19937 gen(rd()); // Инициализация генератора
    std::uniform_int_distribution<> dis(0, boardSize - 1); // Распределение для координат

    for (int length : shipLengths) {
        bool placed = false;
        while (!placed) {
            // Случайно определяем координаты и ориентацию (горизонтально/вертикально)
            bool horizontal = dis(gen) % 2 == 0;

            int x = dis(gen);
            int y = dis(gen);

            // Проверка возможности размещения
            if (canPlaceShip(x, y, length, horizontal, boardSize)) {
                ships.push_back(new Ship(x, y, length, horizontal)); // Создание нового корабля
                placed = true; // Установка флага о размещении
            }
        }
    }
}