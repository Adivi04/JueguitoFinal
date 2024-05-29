#include "Personajes.h"

Character::Character(const std::string& name, int health, int attack1, int attack2, int attack3, int posX, int posY, bool alive)
    : name(name), health(health), attack1(attack1), attack2(attack2), attack3(attack3), posX(posX), posY(posY), alive(alive) {}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(int health) {
    this->health = health;
}

int Character::getAttack1() const {
    return attack1;
}

int Character::getAttack2() const {
    return attack2;
}

int Character::getAttack3() const {
    return attack3;
}

int Character::getPosX() const {
    return posX;
}

void Character::setPosX(int posX) {
    this->posX = posX;
}

int Character::getPosY() const {
    return posY;
}

void Character::setPosY(int posY) {
    this->posY = posY;
}

bool Character::isAlive() const {
    return alive;
}

void Character::setAlive(bool alive) {
    this->alive = alive;
}
