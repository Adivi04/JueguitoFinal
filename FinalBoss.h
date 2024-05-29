#pragma once
#include "Personajes.h"

class Boss : public Character {
private:
    int superAttack;

public:
    Boss(int health, int attack1, int attack2, int superAttack, bool alive);

    int getSuperAttack() const;
    void setSuperAttack(int superAttack);
};
