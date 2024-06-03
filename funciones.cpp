
#include<iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

void mostrarMenu() {
    system("cls");
    cout<<" ---- Escalera o Cien ---- "<<endl;
    cout<<" 1 - Juego nuevo (1 jugador). "<<endl;
    cout<<" 2 - Juego nuevo (2 jugadores). "<<endl;
    cout<<" 3 - Modo simulado. "<<endl;
    cout<<" 0 - Salir "<<endl;
    cout<<" Ingrese la opcion deseada: "<<endl;
}

void cargarVectorAleatorio(int vec[], int tam) {
    int i;
    for (i=0; i<tam ; i++ ) {
        vec[i]=rand()%6+1;
    }
    cout<<"Vector correctamente cargado con numeros aleatorios..."<<endl;
}

void cargarVectorManual(int vec[],int tam ) {
    int i;
    for (i=0; i<tam ; i++ ) {
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
    }
    cout<<"Vector correctamente cargado..."<<endl;
}
void ponerVectorEn0(int vec[],int tam ) {
    int i;
    for (i=0; i<tam ; i++ ) {
        vec[i]=0;
    }
    cout<<"Vector correctamente seteado en 0..."<<endl;
}

void mostrarVector(int vec[],int tam ) {
    int i;
    for (i=0; i<tam ; i++ ) {
        cout<<"Elemento "<<i+1<<" del vector: "<<vec[i]<<endl;
    }
    system("pause");
}

void unJugador() {
    string jugador;
    jugador=pedirNombre();
    //cout<<jugador<<endl;
    system("pause");

}
void dosJugadores() {
    string jugador1,jugador2;
    jugador1=pedirNombre();
    jugador2=pedirNombre();
}
void modoSimulado(int TAM, int vec[]) {
    bool resultado;
    cargarVectorManual(vec, TAM);
    resultado=seis6(TAM,vec);
    cout<<resultado<<endl;
    system("pause");
}
////////////////////////
string pedirNombre() {

    string nombre;
    cout<<"Ingrese el nombre: ";
    cin.ignore(); ///importante
    getline(cin,nombre);
    return nombre;
}

bool seis6(int TAM, int vec[]) {
    bool bandera=true;
    for(int i=0; i<6 ; i++){
        if (vec[i] != 6)
            bandera = false;
    }
        return bandera;
    }

