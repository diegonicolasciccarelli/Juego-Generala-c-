#include <iostream>
# include <cstdlib>
# include <ctime>
# include <cstring>
using namespace std;
# include "funciones.h"
#include<stdlib.h>
#include<time.h>

/*
puntuacion_mejor[0] >> Puntuacion top de generala
puntuacion_mejor[1] >> Rondas de la puntuacion top de generala
total_puntos[0] >> puntuacion del player 1
total_puntos[1] >> puntuacion del player 2
const bool azar se puede cambiar para poner los resultados manualmente
"rondas" puede cambiarse a la cantidad de rondas que se requieran para probarlo

*/


int main(){
    int menu_principal, puntos = 0, generala = 0, puntuacion_top, gencon, total_puntos[2] = {}, puntuacion_mejor[2];
    puntuacion_mejor[0] = 0;
    puntuacion_mejor[1] = 11;
    char jugador1[25], jugador2[25], jugador_mejor[25];
    const bool azar = true;
    const  int tam = 5 ;
    int i, dados [tam];
    while(menu_principal!=0){
    cout << "Bienvenido/s LA GENERALAAAAA!!" <<endl <<endl;
    cout << "Para ingresar al modo de UN JUGADOR, ingrese 1." <<endl;
    cout << "Para ingresar al modo de DOS JUGADORES, ingrese 2." <<endl;
    cout << "Si quiere ver la puntuacion mas alta, ingrese 3." <<endl;
    cout << "Para cerrar el juego, ingrese 0." <<endl;
    cin >> menu_principal;
    switch(menu_principal){
        case 0: cout << "Gracias por jugar a la generala, vuelva prontos" <<endl;
                break;
        case 1: juego_simple(jugador1, puntos, dados, tam, azar, gencon, puntuacion_mejor, jugador_mejor);
                break;
        case 2: juego_doble(jugador1, jugador2, puntos, dados, tam, azar, gencon, puntuacion_mejor, jugador_mejor);
                break;
        case 3: cout << "La puntuacion mas alta es: " << puntuacion_mejor[0] << " en rondas: " << puntuacion_mejor[1] << " por el jugador: " << jugador_mejor << endl;
                system("pause");
                system("cls");
                break;
                default: cout << "Algo ha salido mal, intente nuevamente " <<endl;
                break;
                }}return 0;}
