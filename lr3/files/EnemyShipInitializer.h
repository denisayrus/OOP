#define ENEMY_SHIP_INITIALIZER_H

#include <vector>
#include "ship.h"
//������� ��������� ������� �� ������� ���� 

std::vector<Ship*> initializeEnemyShips(int shipCount, int fieldWidth, int fieldHeight);

#endif // ENEMY_SHIP_INITIALIZER_H