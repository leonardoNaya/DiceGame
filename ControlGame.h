#include <iostream>
#include <algorithm>
#include "rlutil.h"
#include "DrawDices.h"
#include "Sort.h"
int RollDice(std::string* namePlayer, int turn, int throwNumber, bool cheat, bool diceAnimation, bool dicePerTime) {
    rlutil::cls();
    bool sameDice = true, threeOrMoreSameDice = false, stair[6] = {false, false, false, false, false, false};
    int dice[6] {0, 0, 0, 0, 0, 0}, score = 0, sameDiceNumber;
    std::string stairExist;
    if (diceAnimation && dicePerTime)
    {
        if (!cheat)
        {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    rlutil::cls();
                    dice[i] = rand() % 6 + 1;
                    StartDrawing(i, dice);
                    if (j == 9)
                    {
                        DrawThePreviousDice(i, dice);
                    }
                    rlutil::msleep(100);
                }
                rlutil::cls();
                std::cout << "En el turno " << turn << ", lanzamiento "<< throwNumber << ", dado numero " << i + 1 << ", obtuviste un " << dice[i] << std::endl;
                if (i == 5)
                {
                    std::cout << "En el turno " << turn << " el jugador " << *namePlayer << " ";
                }else {
                    std::cout << "Pulsa una tecla para lanzar el siguiente..." << std::endl;
                    rlutil::anykey();
                }
            }
        }else {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    rlutil::cls();
                    dice[i] = rand() % 6 + 1;
                    StartDrawing(i, dice);
                    if (j == 9)
                    {
                        DrawThePreviousDice(i, dice);
                    }
                    rlutil::msleep(100);
                }
                dice[i] = 6;
                rlutil::cls();
                if (i == 3 || i == 4 || i == 5)
                {
                    dice[i] = rand() % 5 + 1;
                }
                std::cout << "En el turno " << turn << ", lanzamiento "<< throwNumber << ", dado numero " << i + 1 << ", obtuviste un " << dice[i] << std::endl;
                if (i == 5)
                {
                    std::cout << "En el turno " << turn << " el jugador " << *namePlayer << " ";
                }else {
                    std::cout << "Pulsa una tecla para lanzar el siguiente..." << std::endl;
                    rlutil::anykey();
                }
            }
        }
    }else if (diceAnimation && !dicePerTime)
    {
        if (!cheat)
        {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    system("cls");
                    rlutil::cls();
                    dice[i] = rand() % 6 + 1;
                    StartDrawing(i, dice);
                    if (j == 9)
                    {
                        DrawThePreviousDice(i, dice);
                    }
                    rlutil::msleep(100);
                }
            }
            rlutil::cls();
            std::cout << "En el turno " << turn << " lanzamiento "<< throwNumber << " el jugador " << *namePlayer << " ";
        }else {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    rlutil::cls();
                    dice[i] = rand() % 6 + 1;
                    if (i == 3 || i == 4 || i == 5)
                    {
                        dice[i] = rand() % 5 + 1;
                    }
                    if (j == 9 && i < 3)
                    {
                        dice[i] = 6;
                    }
                    StartDrawing(i, dice);
                    if (j == 9)
                    {
                        DrawThePreviousDice(i, dice);
                    }
                    rlutil::msleep(100);
                }
            }
            rlutil::msleep(1000);
            system("cls");
            std::cout << "En el turno " << turn << " lanzamiento "<< throwNumber << " el jugador " << *namePlayer << " ";
        }
    }else if (!diceAnimation && !dicePerTime) {
        for (int i = 0; i < 6; i++)
        {
            if (!cheat)
            {
                dice[i] = rand() % 6 + 1;
                /*
                    ! Tirada comun:
                    * dice[i] = rand() % 6 + 1;
                    ! Escalera:
                    * dice[i] = i + 1;
                    ! 3 dados iguales
                    * dice[i] = 1;
                    * if (i > 2)
                    * {
                    * dice[i] = rand() % 5 + 2;
                    * }
                    ! 6 dados iguales
                    * dice[i] = 5;
                */
            }else {
                dice[i] = 5;
            }
        }
        rlutil::cls();
        StartDrawing(2, dice);
        rlutil::anykey();
        rlutil::cls();
        std::cout << "En el turno " << turn << " lanzamiento "<< throwNumber << " el jugador " << *namePlayer << " ";
    }else {
        for (int i = 0; i < 6; i++)
        {
            rlutil::cls();
            if (!cheat)
            {
                dice[i] = rand() % 6 + 1;
            }else {
                dice[i] = 6;
                if (i == 3 || i == 4 || i == 5)
                {
                    dice[i] = rand() % 5 + 1;
                }
            }
            StartDrawing(i, dice);
            rlutil::msleep(250);
        }
        rlutil::anykey();
        system("cls");
        std::cout << "En el turno " << turn << " el jugador " << *namePlayer << " ";
    }
    for (int i = 0; i < 5; i++)
    {
        if (dice[i] != dice[i+1])
        {
            sameDice = false;
        }
    }
    SortDice(dice);
    for (int i = 0; i < 4; i++)
    {
        if (dice[i]==dice[i + 1] && dice[i]==dice[i + 2])
        {
            threeOrMoreSameDice = true;
            sameDiceNumber = i;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (i + 1 == dice[i])
        {
            stair[i] = true;
        }
    }
    if (sameDice)
    {
        std::cout << " todos tus dados son iguales!";
        if (dice[0]==6)
        {
            std::cout << " Lastimosamente, son todos 6. Pierdes tus puntos." << std::endl;
            score = -1;
        }else
        {
            std::cout << " Increible jugada!" << std::endl;
            score = dice[0] * 50;
        }
    }else if (threeOrMoreSameDice)
    {
        std::cout << "ha logrado tener 3 dados iguales!" << std::endl;
        score = dice[sameDiceNumber] * 10;
    }else if (stair[0] && stair[1] && stair[2] && stair[3] && stair[4] && stair[5])
    {
        std::cout << "ha obtenido una escalera!! Has ganado!!!" << std::endl;
        score = 0;
    }else{
        std::cout << "no hizo ninguna tirada especial. Sumando los dados..." << std::endl;
        for (int i = 0; i < 6; i++)
        {
            score += dice[i];
        }
    }
    return score;
}
void ObtainResults(bool showScore, bool* isThereAStair, int scorePlayer[], int* totalScorePlayer, std::string* scoreName){
    if (!showScore)
    {
        rlutil::anykey();
        showScore = false;
    }
    if (scorePlayer[0]==-1 || scorePlayer[1]==-1 || scorePlayer[2]==-1)
    {
        std::cout << scoreName << ", lamentablemente has sacado 6 dados de 6, pierdes los puntos de esta ronda" << std::endl;
        std::cout << "El total de puntaje que llevas es: " << *totalScorePlayer << std::endl;
    }else if (scorePlayer[0]==0 || scorePlayer[1]==0 || scorePlayer[2]==0)
    {
        *isThereAStair = true;
    }else if (scorePlayer[0] >= scorePlayer[1] && scorePlayer[0] >= scorePlayer[2])
    {
        *totalScorePlayer += scorePlayer[0];
        std::cout << "El jugador " << *scoreName << " tiene como mayor puntaje " << scorePlayer[0] << " en el lanzamiento " << 1 << " sumandolo a tu total de puntos..." << std::endl;
        std::cout << "El total de puntaje que llevas es: " << *totalScorePlayer << std::endl;
    }else if (scorePlayer[1] >= scorePlayer[0] && scorePlayer[1] >= scorePlayer[2])
    {
        *totalScorePlayer += scorePlayer[1];
        std::cout << "El jugador " << *scoreName << " tiene como mayor puntaje " << scorePlayer[0] << " en el lanzamiento " << 2 << " sumandolo a tu total de puntos..." << std::endl;
        std::cout << "El total de puntaje que llevas es: " << *totalScorePlayer << std::endl;
    }else if (scorePlayer[2] >= scorePlayer[1] && scorePlayer[2] >= scorePlayer[0])
    {
        *totalScorePlayer += scorePlayer[2];
        std::cout << "El jugador " << *scoreName << " tiene como mayor puntaje " << scorePlayer[0] << " en el lanzamiento " << 3 << " sumandolo a tu total de puntos..." << std::endl;
        std::cout << "El total de puntaje que llevas es: " << *totalScorePlayer << std::endl;
    }
    if (*isThereAStair == false)
    {
        rlutil::anykey();
    }
}