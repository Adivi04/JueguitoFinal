#include "Enemigos.h"

Enemy::Enemy(int health, int attack1, bool alive)
    : Character("Enemy", health, attack1, 0, 0, 0, 0, alive) {}
