#include <iostream>
#include "rlutil.h"
void DiceBase(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (j == 9) {
                std::cout << " ";
            }
            if (j == 18) {
                std::cout << " ";
            }
            if (i == 0 || i == 8 ||
            j == 0 || j == 8 ||
            j == 9 || j == 17 ||
            j == 18 || j == 26)
            {
                std::cout << (char)219;
            }else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
void DrawDice(int typeOfDice, int posx, int posy) {
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(posx, posy);
    switch (typeOfDice)
    {
    case 1:
        rlutil::locate(posx + 5, posy + 5);
        std::cout << (char)219;
        break;
    case 2:
        rlutil::locate(posx + 3, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 3);
        std::cout << (char)219;
        break;
    case 3:
        rlutil::locate(posx + 3, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 5, posy + 5);
        std::cout << (char)219;
        break;
    case 4:
        rlutil::locate(posx + 3, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 3, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 7);
        std::cout << (char)219;
        break;
    case 5:
        rlutil::locate(posx + 3, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 3, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 5, posy + 5);
        std::cout << (char)219;
        break;
    case 6:
        rlutil::locate(posx + 3, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 3, posy + 3);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 7);
        std::cout << (char)219;
        rlutil::locate(posx + 3, posy + 5);
        std::cout << (char)219;
        rlutil::locate(posx + 7, posy + 5);
        std::cout << (char)219;
        break;
    default:
        break;
    }
}
void DrawThePreviousDice(int i, int dice[]){
    if (i == 1)
    {
        DrawDice(dice[0], 0, 0);
    }else if (i == 2)
    {
        DrawDice(dice[0], 0, 0);
        DrawDice(dice[1], 10, 0);
    }else if (i == 3)
    {
        DrawDice(dice[0], 0, 0);
        DrawDice(dice[1], 10, 0);
        DrawDice(dice[2], 20, 0);
    }else if (i == 4)
    {
        DrawDice(dice[0], 0, 0);
        DrawDice(dice[1], 10, 0);
        DrawDice(dice[2], 20, 0);
        DrawDice(dice[3], 0, 6);
    }else if (i == 5)
    {
        DrawDice(dice[0], 0, 0);
        DrawDice(dice[1], 10, 0);
        DrawDice(dice[2], 20, 0);
        DrawDice(dice[3], 0, 6);
        DrawDice(dice[4], 10, 6);
    }
}
void DrawCorrectlyTheNextDice(int i,int dice[]){
    if (i < 3)
        {
            if (dice[i] == 1 || dice[i] == 3 || dice[i] == 5 || dice[i] == 6)
            {
                std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
            }else if (dice[i] == 2)
            {
                std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
            }else if (dice[i] == 4)
            {
                std::cout << std::endl << std::endl << std::endl << std::endl;
            }
        }else {
            if (dice[2] == 1 || dice[2] == 3 || dice[2] == 5 || dice[2] == 6)
            {
                std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
            }else if (dice[2] == 2)
            {
                std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
            }else if (dice[2] == 4)
            {
                std::cout << std::endl << std::endl << std::endl << std::endl;
            }
        }
}
void StartDrawing(int i, int dice[]){
    DiceBase();
    DrawDice(dice[0], 0, 0);
    DrawDice(dice[1], 10, 0);
    DrawDice(dice[2], 20, 0);
    DrawCorrectlyTheNextDice(i, dice);
    DiceBase();
    DrawDice(dice[3], 0, 10);
    DrawDice(dice[4], 10, 10);
    DrawDice(dice[5], 20, 10);
}