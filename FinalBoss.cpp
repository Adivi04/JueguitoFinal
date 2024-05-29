#include "FinalBoss.h"

Boss::Boss(int health, int attack1, int attack2, int superAttack, bool alive)
    : Character("Boss", health, attack1, attack2, 0, 0, 0, alive), superAttack(superAttack) {}

int Boss::getSuperAttack() const {
    return superAttack;
}

void Boss::setSuperAttack(int superAttack) {
    this->superAttack = superAttack;
}
