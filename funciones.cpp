
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

void cargarVectorAleatorio(int vec[], int TAM) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        vec[i]=rand()%6+1;
    }
   // cout<<"Vector correcTAMente cargado con numeros aleatorios..."<<endl;
}

void cargarVectorManual(int vec[],int TAM ) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
    }
    cout<<"Vector correcTAMente cargado..."<<endl;
}
void ponerVectorEn0(int vec[],int TAM ) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        vec[i]=0;
    }
    cout<<"Vector correcTAMente seteado en 0..."<<endl;
}

void mostrarVector(int vec[],int TAM ) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        cout<<"Elemento "<<i+1<<" del vector: "<<vec[i]<<endl;
    }
    system("pause");
}
void mostrarVectorLine(int vec[],int TAM ) {
    int i;
    for (i=0; i<TAM ; i++ ) {
                cout<<"["<<vec[i]<<"] ";

    }
    cout<<endl;
    //system("pause");
}

void unJugador() {
    string jugador;
    jugador=pedirNombre();
    cout<<"Hola "<<jugador<<endl;
    system("pause");

}
void dosJugadores() {
    string jugador1,jugador2;
    jugador1=pedirNombre();
    jugador2=pedirNombre();
}
void modoSimulado( int vec[],int TAM) {
    //bool resultado6, resultadoE;
    int aux, prueba;
    //cargarVectorManual(vec, TAM);
    /*for (int i=1;i<=6;i++){
        resultado6=combinacionSeisX(vec,TAM,i);
        if(resultado6)
            cout<<"Es sexteto de "<<i<<". "<<endl;
        else
            cout<<"No es sexteto de "<<i<<". "<<endl;
    }*/
    //aux=combinacionX(vec,TAM);
    //cout<<"Es sexteto de: "<<aux<<endl;


    /*resultadoE=combinacionEscalera(vec,TAM);
    if (resultadoE)
        cout<<"Es escalera."<<endl;
    else
        cout<<"No es escalera."<<endl;*/
    prueba=ronda(vec,TAM);
    cout<<"Puntaje de la ronda: "<<prueba<<endl;
    //prueba=ronda(vec,TAM);
    //cout<<"Puntaje de la ronda: "<<prueba<<endl;


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
////////////////////////////
int sumatoriaVector(int vec[],int TAM) {
    int i, sumatoria=0;
    for(i=0; i<TAM; i++) {
        sumatoria+=vec[i];
    }
    return sumatoria;
}

/////funciones combinaciones


bool combinacionSeisX(int vec[],int TAM, int x) {
    bool bandera=true;
    for(int i=0; i<6 ; i++) {
        if (vec[i] != x)
            bandera = false;
    }
    return bandera;
}

int combinacionX(int vec[],int TAM) {
    bool bandera;
    int retorno=0;
    for (int i=1; i<=6; i++) {
        if(bandera=combinacionSeisX(vec,TAM,i)){
            retorno=i;
            }
    }
    return retorno;

}

bool combinacionEscalera(int vec[],int TAM) {
    bool vecBool[TAM]= {false};
    int i,h;
    for (i=0; i<TAM; i++) {
        vecBool[vec[i]-1]=true;
    }
    for (h=0; h<TAM; h++) {
        if(vecBool[h]==false)
            return false;
    }
    return true;
}


///jugada

int lanzamiento (int vec[], int TAM) {
    int puntos=0;
    int i,aux;
    bool escalera;
    bool combinacion;
    cargarVectorAleatorio(vec,TAM);
    //cargarVectorManual(vec,TAM);
    mostrarVectorLine(vec,TAM);
    escalera=combinacionEscalera(vec,TAM);
    for (i=1; i<=6; i++) {
        if(combinacion=combinacionSeisX(vec,TAM,i)){
            break;
            }
    }

    if(escalera) {
        return puntos=100;
    } else if(combinacion) {
        aux=combinacionX(vec,TAM);
        if(aux==6)
            puntos=0;
        else
            puntos=aux*10;
    } else {
        puntos=sumatoriaVector(vec,TAM);

    }
    cout<<"puntaje del lanzamiento: "<<puntos<<endl;
    return puntos;

}

int ronda(int vec[], int TAM) {
    int i, valor,aux;
    for (i=0;i<3;i++){
        aux=lanzamiento(vec,TAM);
        if(aux==0)
            return 0;
        else if(aux==100)
            return 100;
        else if(i==0)
            valor=aux;
        else if(aux>valor)
            valor=aux;
    }
    return valor;
}



