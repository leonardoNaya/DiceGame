#include <iostream>
void Rules(){
    rlutil::cls();
    std::cout << "--------------------------------------------------------Reglamento:--------------------------------------------------------" << std::endl;
    std::cout << "El objetivo del juego es obtener al menos 500 puntos en la menor cantidad posible de  rondas, o sacar una escalera en un lanzamiento. " << std::endl;
    std::cout << "Una ronda est" << (char)160 << " compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje." << std::endl;
    std::cout << "El puntaje de un lanzamiento est" << (char)160 << " determinado por una serie de reglas que figuran en la secci" << (char)162 << "n Combinaciones ganadoras." << std::endl;
    std::cout << "El puntaje final de la ronda ser" << (char)160 << " el valor m" << (char)160 << "ximo obtenido entre los 3 lanzamientos, con las siguientes excepciones:" << std::endl;
    std::cout << "       * Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento" << std::endl;
    std::cout << "       * Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje de la ronda entera ser" << (char)160 << " 0." << std::endl;
    std::cout << "Para el caso de la opcion para 2 jugadores:" << std::endl;
    std::cout << "       * Los jugadores debe completar una ronda (3 lanzamientos) alternativamente." << std::endl;
    std::cout << "Combinaciones ganadoras: " << std::endl;
    std::cout << "       * Menos de 3 dados con valores iguales (cualquier combinacion) Ejemplo: 6,5,5,2,2,1." << std::endl;
    std::cout << "         " << "Puntaje otorgado: Suma de los valores de todos los dados. Para el ejemplo ser" << (char)161 <<"a 6+5+5+2+2+1=21" << std::endl;
    std::cout << "       * 3 dados o m" << (char)160 <<"s con el mismo valor (hasta 5 iguales). Ejemplo: 5, 5, 5,1,2,3." << std::endl;
    std::cout << "         " << "Puntaje otorgado: X*10puntos. Para el ejemplo ser" << (char)161 <<"a 5*10=50" << std::endl;
    std::cout << "       * 6 dados iguales (menos para el n" << (char)163 <<"mero 6)." << std::endl;
    std::cout << "         " << "Puntaje otorgado: X*50 puntos" << std::endl;
    std::cout << "       * Escalera (1, 2, 3, 4, 5, 6)." << std::endl;
    std::cout << "         " << "Puntaje otorgado: Gana la partida en esa ronda" << std::endl;
    std::cout << "       * Seis 6." << std::endl;
    std::cout << "         " << "Puntaje otorgado: Pierde todos los puntos de la ronda " << std::endl;
}