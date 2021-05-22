#include <iostream>
# include <cstdlib>
# include <ctime>
# include <cstring>
#include<stdlib.h>
#include<time.h>
using namespace std;
# include "funciones.h"



void tirada(int dados[], int tam){
int i;
srand ( time ( NULL ));
    for (i = 0 ; i <tam; i ++) {
     dados [i] =1 + rand ()% 6 ;
     }}
void cargar_dados(int dados[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"Ingresar el valor del " << i+1 <<" dado: " <<endl;
        cin>>dados[i];
        }
}

void mostrar_dados(int dados[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout << "El dado numero " << i+1 << " es " << dados[i] <<endl; }}

int generala(int dados[], int tam){
    int i, generala = 0, gencon = 0;
    for(i=0;i<tam;i++){
        if (generala==0){
                generala = dados[i];
                gencon++;}
            else{
                if (dados[i]==generala){
                gencon++;}
    }}    return gencon;}


int lanzamientos(int gencon, int dados[], int tam, char jugador1[], bool azar, int puntuacion_mejor[], char jugador_mejor[]){
        char sigue_lanzando, jugadorganador[25];
        int puntosganador = 0, rondastotales = 0, i, x, z = 0, dados_a_lanzar, cambio_dado, rondas = 10, puntos = 0, total_puntos=0, termina_generala = 0;
        for(x=0;x<rondas;x++){
        cout << "RONDA N " << x+1 << " || JUGADOR " << jugador1 << " || PUNTAJE ACUMULADO: " << total_puntos << endl;
        cout << "LANZAMIENTO N 1" <<endl;
        if(azar == true){
        tirada(dados, tam);
        mostrar_dados(dados, tam);
        }
        else{
        cargar_dados(dados, tam);
        mostrar_dados(dados, tam);
        }
        gencon = generala(dados, tam);
        if (gencon==5){
        cout << "Generala servida!!!! El jugador " << jugador1 << " gana la partida." << endl;
        cout << "El jugador ha ganado en " << x+1 << " ronda/s, felicitaciones!" <<endl;
        termina_generala = x+1;
        x = rondas;
        }
        else{
        for(z=0;z<2;z++){
        cout << "Desea seguir lanzando? (S/N)" << endl;
        cin >> sigue_lanzando;
        if  (sigue_lanzando == 'S' || sigue_lanzando == 's' ){
            cout << "LANZAMIENTO N " << z+2 <<endl;
            cout << "Cuantos dados quiere lanzar?" <<endl;
            cin >> dados_a_lanzar;
            for(i=0; i<dados_a_lanzar; i++){
                cout << "Que dados quiere cambiar?" << endl;
                cin >> cambio_dado;
                srand ( time ( NULL ));
                dados[cambio_dado-1] = 1 + rand ()% 6 ;
                }mostrar_dados(dados, tam);

        }else{
                if(sigue_lanzando == 'N' || sigue_lanzando == 'n'){
                z = 2;
                }
                else{
                    z--;
                    cout << "Opción incorrecta, vuelva a intentarlo." <<endl;
                }}}      }
        puntos = puntuacion(dados, tam);
        cout << "PUNTAJE DE LA RONDA: " << puntos << endl;
        total_puntos += puntos;
        system("pause");
        system("cls");
        if(x == rondas){
                cout << "FINALIZA LA RONDA N " << termina_generala << " || jugador1" << " || PUNTAJE TOTAL: " << total_puntos <<endl;}
                else{cout << "FINALIZA RONDA N " << x+1 << " || JUGADOR " << jugador1 << " || PUNTAJE ACUMULADO: " << total_puntos <<endl;
                    }
        system("pause");
        }
        ///sin generala
        if(termina_generala == 0){
        cout << "Le llevo " << x << " Rondas acabar con el puntaje: " << total_puntos <<endl;
            strcpy(jugadorganador, jugador1);
            rondastotales = x;
            puntosganador=total_puntos;
            medir_puntuacion(puntuacion_mejor, jugador_mejor, puntosganador, jugadorganador, rondastotales);
        }
        /// con generala
        else{
            cout << "Le llevo " << termina_generala << " Rondas acabar con el puntaje: " << total_puntos <<endl;
            strcpy(jugadorganador, jugador1);
            rondastotales = termina_generala;
            puntosganador=total_puntos;
            medir_puntuacion(puntuacion_mejor, jugador_mejor, puntosganador, jugadorganador, rondastotales);}
       return total_puntos;
       }

void lanzamientos_dobles(int gencon, int dados[], int tam, char jugador1[], char jugador2[], bool azar, int puntuacion_mejor[], char jugador_mejor[]){
        char sigue_lanzando, jugadorganador[25];
        int puntosganador = 0, rondastotales = 0, x, gencon1, dados_a_lanzar, cambio_dado, rondas = 2, puntos = 0, total_puntos[2] = {}, termina_generala = 0;
        for(x=0;x<rondas;x++){
        juegojugador1(gencon, dados, tam, jugador1, azar, rondas, total_puntos, x);
        gencon = generala(dados, tam);
        gencon1 = gencon;
        cout << "RONDA NUMERO:  " << x+1 << " || PROXIMO TURNO: " << jugador2 << endl;
        cout << "PUNTAJE DEL JUGADOR " << jugador1 << " : " << total_puntos[0] << endl;
        cout << "PUNTAJE DEL JUGADOR " << jugador2 << " : " << total_puntos[1] << endl;
        gencon = 0;
        system("pause");
        system("cls");
        juegojugador2(gencon, dados, tam, jugador2, azar, rondas, total_puntos, x);
        gencon = generala(dados, tam);
       if(x+1!=rondas){
        cout << "RONDA NUMERO:  " << x+1 << " || PROXIMO TURNO: " << jugador1 << endl;
        cout << "PUNTAJE DEL JUGADOR " << jugador1 << " : " << total_puntos[0] << endl;
        cout << "PUNTAJE DEL JUGADOR " << jugador2 << " : " << total_puntos[1] << endl;
        system("pause");
        system("cls");
        }
        if(gencon==gencon1 && gencon==5){
        termina_generala = x+1;
        x=rondas;
        cout << "Los jugadores consiguen un empate sacando generala servida en la misma ronda!!!" << endl;
        }
        else{
            if(gencon==5){
                termina_generala = x+1;
                x=rondas;
                cout << "El jugador " << jugador2 << "saco GENERALA!! " << endl;
            }
            else{
                if(gencon1==5){
                    termina_generala = x+1;
                    x=rondas;
                    cout << "El jugador " << jugador1 << " saco GENERALA!! " << endl;
                }
            }
        }


        }

        /// sin generala
        if(termina_generala == 0){
        if(total_puntos[0] > total_puntos[1]){
            cout << "INCREIBLE DEMOSTRACION DE " << jugador1 << ", GANANDO LA GENERALA!!! " << endl;
            strcpy(jugadorganador, jugador1);
            rondastotales = x;
            puntosganador=total_puntos[0];
            medir_puntuacion(puntuacion_mejor,jugador_mejor, puntosganador, jugadorganador, rondastotales);}
        else{
            if(total_puntos[0] < total_puntos[1]){
            cout << "EL JUGADOR " << jugador2 << " GANA EN LA GENERALA!!! " <<endl;
            puntosganador=total_puntos[1];
            strcpy(jugadorganador, jugador2);
            rondastotales = x;
            medir_puntuacion(puntuacion_mejor,jugador_mejor, puntosganador, jugadorganador, rondastotales);}
            else{
            cout << "ESTO NO PUEDE SER!!!, ES UN EMPATE " <<endl;
            puntosganador=total_puntos[0];
            strcpy(jugadorganador, jugador1);
            rondastotales = x;
            medir_puntuacion(puntuacion_mejor,jugador_mejor, puntosganador, jugadorganador, rondastotales);
            }}
        cout << "Le llevo " << x << " Rondas acabar con el puntaje: " << total_puntos[0] << " al jugador: " << jugador1 <<endl;
        cout << "Le llevo " << x << " Rondas acabar con el puntaje: " << total_puntos[1] << " al jugador: " << jugador2 <<endl;
            }
        /// con generala
            else{
            cout << "FINAL" << endl << endl << "JUGADOR: " << jugador1 << " || RONDAS/S: " << termina_generala << " || PUNTAJE: " << total_puntos[0] <<endl;
            cout << "JUGADOR: " << jugador2 << " || RONDAS/S: " << termina_generala << " || PUNTAJE: " << total_puntos[1] <<endl <<endl;
            if(total_puntos[0] > total_puntos[1]){
            cout << "INCREIBLE DEMOSTRACION DE " << jugador1 << ", GANANDO LA GENERALA!!! " << endl;
            puntosganador=total_puntos[0];
            rondastotales = termina_generala;
            strcpy(jugadorganador, jugador1);
            medir_puntuacion(puntuacion_mejor,jugador_mejor, puntosganador, jugadorganador, rondastotales);}
            else{
            if(total_puntos[0] < total_puntos[1]){
            cout << "EL JUGADOR " << jugador2 << " GANA EN LA GENERALA!!! " <<endl;
            puntosganador=total_puntos[1];
            rondastotales = termina_generala;
            strcpy(jugadorganador, jugador2);
            medir_puntuacion(puntuacion_mejor,jugador_mejor, puntosganador, jugadorganador, rondastotales);}
            else{
            cout << "ESTO NO PUEDE SER!!!, ES UN EMPATE " <<endl;
            puntosganador=total_puntos[0];
            rondastotales = termina_generala;
            strcpy(jugadorganador, jugador2);
            medir_puntuacion(puntuacion_mejor,jugador_mejor, puntosganador, jugadorganador, rondastotales);
            }}}system("pause");
                system("cls");
                }


void juegojugador1(int gencon, int dados[], int tam, char jugador1[], bool azar, int rondas, int total_puntos[], int x){
        char sigue_lanzando;
        int i, z, dados_a_lanzar, cambio_dado, puntos = 0, termina_generala = 0;
        cout << "RONDA N " << x+1 << " || JUGADOR " << jugador1 << " || PUNTAJE ACUMULADO: " << total_puntos[0] << endl;
        cout << "LANZAMIENTO N 1" <<endl;
        if(azar == true){
        tirada(dados, tam);
        mostrar_dados(dados, tam);
        }
        else{
        cargar_dados(dados, tam);
        mostrar_dados(dados, tam);
        }
        gencon = generala(dados, tam);
        if (gencon==5){
        cout << "Generala servida!!!! VEAMOS SI EL PROXIMO JUGADOR PUEDE IGUALAR ESTO." << endl;
        termina_generala = x+1;
        x = rondas;
        }
        else{
        for(z=0;z<2;z++){
        cout << "Desea seguir lanzando? (S/N)" << endl;
        cin >> sigue_lanzando;
        if  (sigue_lanzando == 'S' || sigue_lanzando == 's' ){
            cout << "LANZAMIENTO N " << z+2 <<endl;
            cout << "Cuantos dados quiere lanzar?" <<endl;
            cin >> dados_a_lanzar;
            for(i=0; i<dados_a_lanzar; i++){
                cout << "Que dados quiere cambiar?" << endl;
                cin >> cambio_dado;
                srand ( time ( NULL ));
                dados[cambio_dado-1] = 1 + rand ()% 6 ;
                }mostrar_dados(dados, tam);

        }else{
                if(sigue_lanzando == 'N' || sigue_lanzando == 'n'){
                z = 2;
                }
                else{
                    z--;
                    cout << "Opción incorrecta, vuelva a intentarlo." <<endl;
                }}}      }
        puntos = puntuacion(dados, tam);
        cout << "PUNTAJE DE LA RONDA: " << puntos << endl;
        total_puntos[0] += puntos;
        system("pause");
        system("cls");
        if(x == rondas){
                cout << "FINALIZA LA RONDA N " << termina_generala << " || jugador" << " || PUNTAJE TOTAL: " << total_puntos[0] <<endl;}
                else{cout << "FINALIZA RONDA N " << x+1 << " || JUGADOR " << jugador1 << " || PUNTAJE ACUMULADO: " << total_puntos[0] <<endl;
                    }
        system("pause");
        }


void juegojugador2(int gencon, int dados[], int tam, char jugador2[], bool azar, int rondas, int total_puntos[], int x){
    char sigue_lanzando;
        int i, z, dados_a_lanzar, cambio_dado, puntos = 0, termina_generala = 0;
        gencon = 0;
        cout << "RONDA N " << x+1 << " || JUGADOR " << jugador2 << " || PUNTAJE ACUMULADO: " << total_puntos[1] << endl;
        cout << "LANZAMIENTO N 1" <<endl;
        if(azar == true){
        tirada(dados, tam);
        mostrar_dados(dados, tam);
        }
        else{
        cargar_dados(dados, tam);
        mostrar_dados(dados, tam);
        }
        gencon = generala(dados, tam);
        if (gencon==5){
        cout << "GENERALA SERVIDA!!!! " << endl;
        termina_generala = x+1;
        x = rondas;
        }
        else{
        for(z=0;z<2;z++){
        cout << "Desea seguir lanzando? (S/N)" << endl;
        cin >> sigue_lanzando;
        if  (sigue_lanzando == 'S' || sigue_lanzando == 's' ){
            cout << "LANZAMIENTO N " << z+2 <<endl;
            cout << "Cuantos dados quiere lanzar?" <<endl;
            cin >> dados_a_lanzar;
            for(i=0; i<dados_a_lanzar; i++){
                cout << "Que dados quiere cambiar?" << endl;
                cin >> cambio_dado;
                srand ( time ( NULL ));
                dados[cambio_dado-1] = 1 + rand ()% 6 ;
                }mostrar_dados(dados, tam);

        }else{
                if(sigue_lanzando == 'N' || sigue_lanzando == 'n'){
                z = 2;
                }
                else{
                    z--;
                    cout << "Opción incorrecta, vuelva a intentarlo." <<endl;
                }}}      }
        puntos = puntuacion(dados, tam);
        cout << "PUNTAJE DE LA RONDA: " << puntos << endl;
        total_puntos[1] += puntos;
        system("pause");
        system("cls");
        if(x == rondas){
                cout << "FINALIZA LA RONDA N " << termina_generala << " || jugador " << jugador2 << " || PUNTAJE TOTAL: " << total_puntos[1] <<endl;}
                else{cout << "FINALIZA RONDA N " << x+1 << " || JUGADOR " << jugador2 << " || PUNTAJE ACUMULADO: " << total_puntos[1] <<endl;
                    }
        system("pause");
        }

void ordenar_dados(int dados[], int tam){
    int j, i, posmin, aux;
    for(i=0;i<tam;i++){
    posmin=i;
    for(j=i+1;j<tam;j++){
    if(dados[j]<dados[posmin]) posmin=j;
    }
    aux=dados[i];
    dados[i]=dados[posmin];
    dados[posmin]=aux;
}
}


int puntuacion(int dados[], int tam){
    int x, puntos = 0, cont_escalera = 1, cont1 = 0, cont2 = 0;
    ordenar_dados(dados, tam);
    int n1 = dados[0], y, n2=0;
    for(y=0; y<5; y++){
        if (dados[y]%2==0){
        if(dados[y]==n1){
                cont1++;
        }else{
            if(n2==0){
                n2=dados[y];
                cont2 ++;
            }         else{
                if(dados[y]==n2){
                    cont2++;}}}
    if (cont1 == 5){
        puntos = 50;
    }
    else{
        if (cont1 == 4 || cont2 == 4){
            puntos = 40;
        }
        else{
            if (cont1 == 3 && cont2 == 2 || cont1 == 2 && cont2 == 3 ){
                puntos = 30;
            }
            else{
                for(x=0; x<5; x++){
                    if (dados[x] == dados[x+1]-1){
                            cont_escalera++;
                    }
                    else{
                    }
                }if(cont_escalera == 5){
                puntos = 25;
                }else{
                int u, w, numero=0, maxpunto=0;
                    for (w=0; w<6; w++){
                int cant=0, valornumerito =0;
                numero++;
            for(u=0;u<tam;u++){
                if(dados[u]==numero) cant++;
            }
                valornumerito= cant*numero;
                if (valornumerito > maxpunto){
                    maxpunto=valornumerito;

       }

    }
    puntos = maxpunto;}
                }
                }}}
    else{

    }
    }
     return puntos;
    }

void juego_simple(char jugador1[], int puntos, int dados[], int tam, bool azar, int gencon, int puntuacion_mejor[], char jugador_mejor[]){
    int i, total_puntos, puntuacion_top;
    cout << "Ingrese nombre de jugador: " << endl;
    cin.ignore();
    cin.getline (jugador1, 25);
    system("cls");
    total_puntos = lanzamientos(gencon, dados, tam, jugador1, azar, puntuacion_mejor, jugador_mejor);
    cout << jugador1 << " ha logrado una nueva mejor puntuacion:  " << puntuacion_mejor[0] << " || Conseguido en  " << puntuacion_mejor[1] << " Rondas!!!! " <<endl;
    system("pause");
    system("cls");

    }

void juego_doble(char jugador1[], char jugador2[], int puntos, int dados[], int tam, bool azar, int gencon, int puntuacion_mejor[], char jugador_mejor[]){
    system("cls");
    cout << "Ingrese nombre del jugador 1: " <<endl;
    cin.ignore();
    cin.getline(jugador1, 25);
    cout << "Ingrese nombre del jugador 2: " <<endl;
    cin.getline(jugador2, 25);
    lanzamientos_dobles(gencon, dados, tam, jugador1, jugador2, azar, puntuacion_mejor, jugador_mejor);
    }

void medir_puntuacion(int puntuacion_mejor[],char jugador_mejor[], int puntosganador, char jugadorganador[], int rondastotales){
if(rondastotales<puntuacion_mejor[1]){
    puntuacion_mejor[1]=rondastotales;
    puntuacion_mejor[0]=puntosganador;
    strcpy(jugador_mejor, jugadorganador);
}else{
    if(rondastotales==puntuacion_mejor[1]){
        if(puntosganador>puntuacion_mejor[0]){
            puntuacion_mejor[1]=rondastotales;
            puntuacion_mejor[0]=puntosganador;
            strcpy(jugador_mejor, jugadorganador);

        }
    }}}

