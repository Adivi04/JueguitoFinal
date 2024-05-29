#include "Enemigos.h"
#include "FinalBoss.h"
#include "Personajes.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
bool gameOver = false;
bool gameWon = false;

void printMap(string map[WIDTH][HEIGHT], int posX, int posY, Character* enemies) {
    // Create outer walls
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            if (i == 0 || j == 0 || i == WIDTH - 1 || j == HEIGHT - 1) {
                map[i][j] = " * ";
            }
            else {
                map[i][j] = "   ";
            }
        }
    }

    // Create inner walls
    int midX = HEIGHT / 2;
    int midY = WIDTH / 2;

    for (int i = 1; i < WIDTH - 1; ++i) {
        map[i][midX] = " * ";
    }

    for (int j = 1; j < HEIGHT - 1; ++j) {
        map[midY][j] = " * ";
    }

    // Grass
    for (size_t i = 1; i < 10; ++i) {
        for (size_t j = 6; j < 9; ++j) {
            map[i][j] = " w ";
        }
    }

    for (size_t i = 6; i < 10; ++i) {
        for (size_t j = 11; j < 19; ++j) {
            map[i][j] = " w ";
        }
    }

    for (size_t i = 11; i < 19; ++i) {
        for (size_t j = 11; j < 14; ++j) {
            map[i][j] = " w ";
        }
    }

    int holeX = 10;
    int holeY = 2;

    map[holeY][holeX] = "   ";

    holeX = 18;
    holeY = 10;

    map[holeY][holeX] = "   ";

    holeX = 10;
    holeY = 14;

    map[holeY][holeX] = "   ";

    // Place character on the map
    map[posY][posX] = " P ";

    map[15][3] = " ! ";

    // Print the map
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

//Se encuentra a un enemigo
void battle(int enemyIndex, Character enemies[], Character& player) {
    system("cls");
    int choice;
    cout << "\n\n\t\tHAS ENCONTRADO UN ENEMIGO\n\n";

    do {
        cout << "\nQue ataque usas?: [1 | 2 | 3]: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Le has atacado " << player.getAttack1() << " damage.\n";
            enemies[enemyIndex].setHealth(enemies[enemyIndex].getHealth() - player.getAttack1());
            break;
        case 2:
            cout << "Le has atacado " << player.getAttack2() << " damage.\n";
            enemies[enemyIndex].setHealth(enemies[enemyIndex].getHealth() - player.getAttack2());
            break;
        case 3:
            cout << "Le has atacado " << player.getAttack3() << " damage.\n";
            enemies[enemyIndex].setHealth(enemies[enemyIndex].getHealth() - player.getAttack3());
            break;
        default:
            break;
        }

        cout << "Te ha atacado el enemigo " << enemies[enemyIndex].getAttack1() << " damage.\n";
        player.setHealth(player.getHealth() - enemies[enemyIndex].getAttack1());

        cout << "Tienes " << player.getHealth() << " HP left!\n";
        cout << "El enemigo tiene " << enemies[enemyIndex].getHealth() << " HP left!\n";

        if (enemies[enemyIndex].getHealth() <= 0) {
            enemies[enemyIndex].setAlive(false);
            cout << "Has ganado";
            Sleep(1000);
        }
        else if (player.getHealth() <= 0) {
            player.setAlive(false);
            cout << "GAME OVER";
            Sleep(1000);
        }
    } while (player.isAlive() && enemies[enemyIndex].isAlive());
}

//Batalla con FinalBoss

bool finalBattle(Character& player) {
    system("cls");
    Boss boss(200, 40, 30, 10, true);
    int choice;
    cout << "TE HAS ENCONTRADO CON EL BOSS FINAL\n";
    Sleep(1000);

    do {
        cout << "\nQue ataque usas?: [1 | 2 | 3]: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Le has atacado " << player.getAttack1() << " damage.\n";
            boss.setHealth(boss.getHealth() - player.getAttack1());
            break;
        case 2:
            cout << "Le has atacado " << player.getAttack2() << " damage.\n";
            boss.setHealth(boss.getHealth() - player.getAttack2());
            break;
        case 3:
            cout << "Le has atacado " << player.getAttack3() << " damage.\n";
            boss.setHealth(boss.getHealth() - player.getAttack3());
            break;
        default:
            break;
        }

        int bossAttack = rand() % 2;
        if (bossAttack == 0) {
            cout << "El boss ha usado Attack1 " << boss.getAttack1() << " damage.\n";
            player.setHealth(player.getHealth() - boss.getAttack1());
        }
        else {
            cout << "The boss used attack2 and dealt " << boss.getAttack2() << " damage.\n";
            player.setHealth(player.getHealth() - boss.getAttack2());
        }

        cout << "You have " << player.getHealth() << " HP left!\n";
        cout << "The boss has " << boss.getHealth() << " HP left!\n";

        if (boss.getHealth() <= 0) {
            cout << "BOSS DEFEATED! YOU WON!";
            return true;
        }
        else if (player.getHealth() <= 0) {
            cout << "YOU LOST!";
            return false;
        }
    } while (player.isAlive() && boss.isAlive());

    return false;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Character player("Player", 100, 10, 20, 30, 1, 1, true);
    Enemy enemies[] = { Enemy(50, 5, true), Enemy(60, 6, true), Enemy(70, 7, true) };

    string map[WIDTH][HEIGHT];
    int posX = 1, posY = 1;

    while (!gameOver && !gameWon) {
        system("cls");
        printMap(map, posX, posY, enemies);

        char move = _getch();
        switch (move) {
        case 'w':
            if (posY > 1) posY--;
            break;
        case 's':
            if (posY < HEIGHT - 2) posY++;
            break;
        case 'a':
            if (posX > 1) posX--;
            break;
        case 'd':
            if (posX < WIDTH - 2) posX++;
            break;
        }

        for (int i = 0; i < sizeof(enemies) / sizeof(enemies[0]); i++) {
            if (enemies[i].isAlive() && enemies[i].getPosX() == posX && enemies[i].getPosY() == posY) {
                battle(i, enemies, player);
                if (!player.isAlive()) {
                    gameOver = true;
                    break;
                }
            }
        }

        if (posX == 15 && posY == 3) {
            gameWon = finalBattle(player);
            gameOver = true;
        }
    }

    if (gameWon) {
        cout << "Congratulations! You won the game!";
    }
    else {
        cout << "Game Over!";
    }

    return 0;
}
