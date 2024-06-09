#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

#include "funciones.h"
#include "funciones.cpp"


int main(){
    srand(time(NULL));
    const int TAM=6;
    int opcion=1;
    int dados[TAM];
    while(opcion!=0){
    mostrarMenu();
    cin>>opcion;
        switch (opcion)
        {
        case 1:
            unJugador(dados, TAM);
            break;
        case 2:
            dosJugadores(dados,TAM);
            break;
        case 3:
            modoSimulado(dados,TAM);
            break;

        case 0:
            cout<<"Saliendo del programa..."<<endl;
            break;

        default:
            cout<<"Ingrese una opcion correcta."<<endl;
            system("pause");
            break;
        }
    }
    return 0;
}
