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
    int dados[TAM]={1,2,3,4,5,6};
    while(opcion!=0){
    mostrarMenu();
    cin>>opcion;
        switch (opcion)
        {
        case 1:
            unJugador();
            break;
        case 2:
            dosJugadores();
            break;
        case 3:
            modoSimulado(TAM,dados);
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
