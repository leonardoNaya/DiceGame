// Grupo 26
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
#include "ShowMenus.cpp"
#include "ControlGame.cpp"
#include "Rules.cpp"
int main() {
    std::srand(std::time(nullptr));
    bool diceAnimation = false, dicePerTime = false, showScore = false, hiddenOptionSelected = false;
	int op1 = 1, op2 = 1, y = 1, maxScore = 0, turnOfMaxScore = 0;
    std::string scoreComplete1, scoreComplete2, maxScoreName = "";
	rlutil::hidecursor();
	do {
        bool played = false, isThereAStair1 = false, isThereAStair2 = false;
        int totalScorePlayer1 = 0, totalScorePlayer2 = 0, turn = 0, scorePlayer1[3] = {0, 0, 0}, scorePlayer2[3] = {0, 0, 0};
        std::string scoreName1 = "", scoreName2 = "";
        rlutil::cls();
		ShowMenu(y, hiddenOptionSelected);
		switch (rlutil::getkey())
		{
		case 1: // ENTER
			switch (y)
			{
                case 1:
                    do
                    {
                        showScore = false;
                        played = true;
                        turn++;
                        StartGame(&scoreName1, scorePlayer1, turn, hiddenOptionSelected, diceAnimation, dicePerTime, showScore);
                        rlutil::cls();
                        ObtainResults(&scoreName1, scorePlayer1, totalScorePlayer1, showScore, isThereAStair1);
                        rlutil::anykey();
                        showScore = false;
                    }while (totalScorePlayer1 < 500 && !isThereAStair1);
                    break;
                case 2:
                    do
                    {
                        showScore = false;
                        played = true;
                        turn++;
                        StartGame(&scoreName1, scorePlayer1, turn, hiddenOptionSelected, diceAnimation, dicePerTime, showScore);
                        StartGame(&scoreName2, scorePlayer2, turn, hiddenOptionSelected, diceAnimation, dicePerTime, showScore);
                        rlutil::cls();
                        ObtainResults(&scoreName1, scorePlayer1, totalScorePlayer1, showScore, isThereAStair1);
                        ObtainResults(&scoreName2, scorePlayer2, totalScorePlayer2, showScore, isThereAStair2);
                        rlutil::anykey();
                    }while (totalScorePlayer1 < 500 && totalScorePlayer2 < 500 && !isThereAStair1 && !isThereAStair2);
                    break;
                case 3:
                    rlutil::setBackgroundColor(15);
                    rlutil::setColor(0);
                    rlutil::locate(15, 8);
                    std::cout << "El m" << (char)160 << "ximo puntaje es de " << maxScore << " coseguido por " << maxScoreName << " al finalizar el turno " << turnOfMaxScore << std::endl;
                    rlutil::setBackgroundColor(0);
                    rlutil::anykey();
                    break;
                case 4:
                    Rules();
                    rlutil::anykey();
                    break;
                case 5:
                    y = 1;
                    do
                    {
                        OptionMenu(y, hiddenOptionSelected, dicePerTime);
                        switch (rlutil::getkey())
                        {
                            case 1: // ENTER
                                switch (y)
                                {
                                    case 1:
                                        if (hiddenOptionSelected)
                                        {
                                            diceAnimation = true;
                                            y = 1;
                                            hiddenOptionSelected = false;
                                        }else {
                                            hiddenOptionSelected = true;
                                        }
                                        break;
                                    case 2:
                                        if (hiddenOptionSelected)
                                        {
                                            diceAnimation = false;
                                            y = 1;
                                            hiddenOptionSelected = false;
                                        }else {
                                            if (dicePerTime)
                                            {
                                                dicePerTime = false;
                                            }else {
                                                dicePerTime = true;
                                            }
                                        }
                                        break;
                                    case 3:
                                        op2 = 0;
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case 14: // UP
                                rlutil::locate(28, 10 - y);
                                y--;
                                if (y < 1) {
                                    y = 3;
                                }
                                break;
                            case 15: // DOWN
                                rlutil::locate(28, 10 + y);
                                y++;
                                if (hiddenOptionSelected)
                                {
                                    y = 2;
                                }
                                if (y > 3) {
                                    y = 1;
                                }
                                break;
                            case 16: // LEFT
                                if (y == 1 || y == 2 && hiddenOptionSelected)
                                {
                                    hiddenOptionSelected = false;
                                    y = 1;
                                    rlutil::locate(65, 10);
                                }
                                break;
                            case 17: // RIGHT
                                if (y == 1)
                                {
                                    hiddenOptionSelected = true;
                                    rlutil::locate(65, 10);
                                }
                                break;
                        }
                    } while (op2 != 0);
                    op2 = 1;
                    y = 5;
                    hiddenOptionSelected = false;
                    break;
                case 6:
                    op1 = 0;
                    break;
                default:
                    break;
			}
			break;
		case 14: // UP
            hiddenOptionSelected = false;
			rlutil::locate(28, 10 + y);
			y--;
			if (y < 1) {
				y = 6;
			}
			break;
		case 15: // DOWN
            hiddenOptionSelected = false;
			rlutil::locate(28, 10 + y);
			y++;
			if (y > 6) {
				y = 1;
			}
			break;
        case 16: // LEFT
            if (y == 1 && hiddenOptionSelected)
            {
                hiddenOptionSelected = false;
                rlutil::locate(65, 10);
            }
            break;
        case 17: // RIGHT
            if (y==1)
            {
                hiddenOptionSelected = true;
                rlutil::locate(65, 10);
            }
            break;
		default:
			break;
		}
        if (turnOfMaxScore == 0 && played)
        {
            maxScore = totalScorePlayer1;
            maxScoreName = scoreName1;
            turnOfMaxScore = turn;
        }else if (totalScorePlayer1 > maxScore || totalScorePlayer2 > maxScore && played)
        {
            if (totalScorePlayer1 >= maxScore && totalScorePlayer1 > totalScorePlayer2)
            {// player 1's ifs
                maxScore = totalScorePlayer1;
                maxScoreName = scoreName1;
                turnOfMaxScore = turn;
            }else if (totalScorePlayer2 >= maxScore && totalScorePlayer1 < totalScorePlayer2)
            {// player 2's ifs
                maxScore = totalScorePlayer2;
                maxScoreName = scoreName2;
                turnOfMaxScore = turn;
            }
        }
	} while (op1 != 0);
	return 0;
}