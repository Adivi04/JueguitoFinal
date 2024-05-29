#pragma once
#include <string>

class Character {
private:
    std::string name;
    int health;
    int attack1;
    int attack2;
    int attack3;
    int posX;
    int posY;
    bool alive;

public:
    Character(const std::string& name, int health, int attack1, int attack2, int attack3, int posX, int posY, bool alive);

    int getHealth() const;
    void setHealth(int health);

    int getAttack1() const;
    int getAttack2() const;
    int getAttack3() const;

    int getPosX() const;
    void setPosX(int posX);

    int getPosY() const;
    void setPosY(int posY);

    bool isAlive() const;
    void setAlive(bool alive);
};
