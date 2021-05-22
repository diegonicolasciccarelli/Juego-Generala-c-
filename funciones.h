#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

// La función hace una tirada de "tam" dados y guarda los resultados en el vector correspondiente

void tirada(int [], int);

// pone manualmente los dados

void cargar_dados(int [], int);

// muestra los dados

void mostrar_dados(int [], int);

// juego de un jugador

void juego_simple(char [], int, int [], int, bool, int, int[], char[]);

//revisa si hay generala

int generala(int [], int);

// funcion que permite volver a lanzar x dados

int lanzamientos(int, int[], int, char[], bool, int, int[], char[]);

// funcion para calular la puntuacion

void coincidencia(int [], int, int, int);


// ordena los dados de una funcion

void ordenar_dados(int[], int);

// retorna la puntuacion de un jugador en una ronda determinada

int puntuacion(int[], int);

// funcion que permite el juego de a dos

void juego_doble(char[], char[], int, int[], int, bool, int, int[], char[]);

// funcion para hacer los lanzamientos en el juego de a dos

void lanzamientos_dobles(int, int[], int, char[], char[], bool, int[], char[]);

// desarrolla las jugadas del jugador 1

void juegojugador1(int, int[], int, char[], bool, int, int[], int);

// desarrolla las jugadas del jugador 2

void juegojugador2(int, int[], int, char[], bool, int, int[], int);

//permite medir las puntuaciones comparandolas a la mejor lograda hasta el momento

void medir_puntuacion(int[], char[], int, char[], int);

#endif // FUNCIONES_H_INCLUDED
