#include <iostream>
#include <string>
#include "rlutil.h"
enum Options {
	Option1=1,
	Option2=2,
	Option3=3,
    Option4=4,
    Option5=5,
	Option6=6
};
void ShowItem(const char* text, int posx, int posy, bool selected) {
	if (selected) {
		rlutil::setBackgroundColor(rlutil::RED);
		rlutil::locate(posx, posy);
		std::cout << text <<std::endl;
	}
	else {
		rlutil::setBackgroundColor(0);
		rlutil::locate(posx, posy);
		std::cout << text << std::endl;
	}
	rlutil::setBackgroundColor(0);
}
void ShowMenu(int y, bool hiddenSelected){
    const std::string menuHeader = "Trabajo Integrador 'quinientos o escalera'";
    rlutil::setBackgroundColor(0);
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::cls();
    rlutil::locate(30, 2);
    std::cout << menuHeader << std::endl;
    rlutil::locate(80, 15);
    std::cout << "Hecho por Leonardo Gabriel Naya" <<std::endl;
    ShowItem("   Un jugador  ", 40, 5, y == Options::Option1 && !hiddenSelected);
    rlutil::setColor(0);
    ShowItem("  Activar trucos ", 54, 5, hiddenSelected);
    rlutil::setColor(15);
    ShowItem(" Dos jugadores ", 40, 6, y == Options::Option2);
    ShowItem(" Mayor puntaje ", 40, 7, y == Options::Option3);
    ShowItem("  Reglamento   ", 40, 8, y == Options::Option4);
    ShowItem("   Opciones    ", 40, 9, y == Options::Option5);
    ShowItem("    SALIR      ", 40, 10, y == Options::Option6);
}
void OptionMenu(int y, bool hiddenSelected, bool dicePerTime){
    const std::string menuHeader = "Trabajo Integrador 'quinientos o escalera'", showingMessage = "";
    rlutil::cls();
    rlutil::setBackgroundColor(0);
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::cls();
    rlutil::locate(30, 2);
    std::cout << menuHeader << std::endl;
    rlutil::locate(80, 15);
    std::cout << "Hecho por Leonardo Gabriel Naya" <<std::endl;
    ShowItem("Activar animacion de dados", 40, 5, y == Options::Option1 && !hiddenSelected);
    if (!hiddenSelected)
    {
        rlutil::setColor(0);
    }else {
        rlutil::setColor(15);
    }
    ShowItem("Activada", 70, 5, y == Options::Option1 && hiddenSelected);
    ShowItem("Desactivada (default)", 70, 6, y == Options::Option2 && hiddenSelected);
    rlutil::setColor(15);
    if (dicePerTime)
    {
        ShowItem("Un dado por vez", 45, 6, y == Options::Option2 && !hiddenSelected);
    }else {
        ShowItem("Todos los dados por vez", 41, 6, y == Options::Option2 && !hiddenSelected);
    }
    ShowItem("Salir al menu principal", 41, 7, y == Options::Option3);
}