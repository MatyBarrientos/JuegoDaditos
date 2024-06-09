
#include<iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

///////////////////////////////////////
/// MENU:
void mostrarMenu() {
    system("cls");
    cout<<" ---- Escalera o Cien ---- "<<endl;
    cout<<" 1 - Juego nuevo (1 jugador). "<<endl;
    cout<<" 2 - Juego nuevo (2 jugadores). "<<endl;
    cout<<" 3 - Modo simulado. "<<endl;
    cout<<" 0 - Salir "<<endl;
    cout<<" Ingrese la opcion deseada: "<<endl;
}

///////////////////////////////////////
/// VECTORES:

void cargarVectorAleatorio(int vec[], int TAM) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        vec[i]=rand()%6+1;
    }
    // cout<<"Vector correctamente cargado con numeros aleatorios..."<<endl;
}

void cargarVectorManual(int vec[],int TAM ) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
    }
    cout<<"Vector correctamente cargado..."<<endl;
}

void ponerVectorEn0(int vec[],int TAM ) {
    int i;
    for (i=0; i<TAM ; i++ ) {
        vec[i]=0;
    }
    cout<<"Vector correctamente seteado en 0..."<<endl;
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

////////////////////////////////////////////
/// MODOS DE JUEGO:

void unJugador(int vec[],int TAM) {
    int puntaje;
    int round=0,acumulador=0,tiros=0,aux=0;
    string jugador;
    jugador=pedirNombre("Ingrese su nombre: ");
    cout<<"Hola "<<jugador<<endl;
    cout<<"comencemos a jugar."<<endl;
    system("pause");
    system("cls");

    while(true) {
        if(round!=0) {
            cout<<"Numero de ronda: "<<round+1<<endl<<"Puntos acumulados "<<jugador<<": "<<acumulador<<endl;
        }
        puntaje=ronda(vec,TAM);
        round++;
        if(puntaje==100) {
            cout<<"Ganaste la partida.!!!!!!!!!!!"<<endl<<"Sacaste escalera en la ronda "<<round<<", felicidades. "<<endl;
            system("pause");
            break;
        } else if(puntaje==0) {
            cout<<"Sacaste sexteto de seís, tus puntos se reinician a '0'."<<endl;
            system("pause");
            acumulador=0;
        } else {
            acumulador+=puntaje;
            cout<<"Puntaje de la ronda "<<round<<": "<<puntaje<<endl;
            //cout<<"Puntos acumulados: "<<acumulador<<endl;
            system("pause");
        }

        if (acumulador>=100) {
            //cout<<"Tardaste un total de "<<0000<<" lanzamientos. "<<endl;
            cout<<"Tardaste un total de "<<round<<" rondas. "<<endl;
            cout<<jugador<<" ganaste la partida.!!!!!!!!!!!"<<endl;
            system("pause");
            break;
        }
        system("cls");
    }

}
void dosJugadores(int vec[],int TAM) {
    string jugador1;
    string jugador2;
    jugador1=pedirNombre("Ingrese el nombre del jugador 1: ");
    jugador2=pedirNombre("Ingrese el nombre del jugador 2: ");
    int puntaje1,acumulador1=0;
    int puntaje2,acumulador2=0;
    int round=0;
    cout<<"Hola "<<jugador1<<" , hola "<<jugador2<<".Bien, comencemos a jugar."<<endl;
    system("pause");

    while(true) {
        round++;
        /////////////////////jugador1
        system("cls");
        cout<<"Puntos acumulados!!!"<<endl<<jugador1<<": "<<acumulador1<<endl<<jugador2<<": "<<acumulador2<<endl;
        cout<<endl<<"Turno de "<<jugador1<<endl;
        puntaje1=ronda(vec,TAM);
        if(puntaje1==100) {
            cout<<jugador1<<" ganaste la partida.!!!!!!!!!!!"<<endl<<"Sacaste escalera en la ronda "<<round<<", felicidades. "<<endl;
            system("pause");
            break;
        } else if(puntaje1==0) {
            cout<<"Sacaste sexteto de seís, tus puntos se reinician a '0'."<<endl;
            system("pause");
            acumulador1=0;
        } else {
            acumulador1+=puntaje1;
            cout<<"Puntaje de la ronda "<<round<<": "<<puntaje1<<endl;
            ///cout<<"Puntos acumulados: "<<acumulador1<<endl;
            system("pause");
        }

        if (acumulador1>=100) {
            cout<<"Tardaste un total de "<<round<<" rondas. "<<endl;
            cout<<jugador1<<" ganaste la partida.!!!!!!!!!!!"<<endl;
            system("pause");
            break;
        }
        /////////////////////jugador2
        cout<<endl<<"Turno de "<<jugador2<<endl;
        puntaje2=ronda(vec,TAM);
        if(puntaje2==100) {
            cout<<jugador2<<" ganaste la partida.!!!!!!!!!!!"<<endl<<"Sacaste escalera en la ronda "<<round<<", felicidades. "<<endl;
            system("pause");
            break;
        } else if(puntaje2==0) {
            cout<<"Sacaste sexteto de seís, tus puntos se reinician a '0'."<<endl;
            system("pause");
            acumulador2=0;
        } else {
            acumulador2+=puntaje2;
            cout<<"Puntaje de la ronda "<<round<<": "<<puntaje2<<endl;
            ///cout<<"Puntos acumulados: "<<acumulador2<<endl;
            system("pause");
        }

        if (acumulador2>=100) {
            cout<<"Tardaste un total de "<<round<<" rondas. "<<endl;
            cout<<jugador2<<" ganaste la partida.!!!!!!!!!!!"<<endl;
            system("pause");
            break;
        }
    }

}
void modoSimulado( int vec[],int TAM) {
    int vueltas=0, aux=0, prueba;
    cout<<"Ingrese la cantidad de lanzamientos a intentar: ";
    cin>>vueltas;
    for(int i=0; i<vueltas; i++) {
        prueba=lanzamientoTesteo(vec,TAM);
        if(prueba==0){
            aux=0;
            cout<<"puntaje del lanzamiento: "<<aux<<endl;}
        else if(prueba==100) {
            aux=100;
            cout<<"Fin del testeo, 'escalera' ingresada"<<endl;
            cout<<"Puntaje del lanzamiento: "<<prueba<<endl;
            system("pause");
            break;
        } else {
            aux+=prueba;
            cout<<"puntaje del lanzamiento: "<<prueba<<endl;
        }
        cout<<"Puntaje del testeo: "<<aux<<endl;
        system("pause");
    }
}

////////////////////////////////////////////
/// CARGAR NOMBRE
string pedirNombre(string frase) {

    string nombre;
    cout<<frase;
    fflush(stdin); ///importante, no omite 1er caracter
    getline(cin,nombre);
    return nombre;
}

//////////////////////////////////////
/// SUMA VECTOR:
//////////////////////////////////////
int sumatoriaVector(int vec[],int TAM) {
    int i, sumatoria=0;
    for(i=0; i<TAM; i++) {
        sumatoria+=vec[i];
    }
    return sumatoria;
}

///////////////////////////////////
/// COMBINACIONES:
///////////////////////////////////
int combinacionX(int vec[],int TAM) {
    bool banderaRepe=false;
    int vecRepetidos[TAM]= {};
    for(int i=0; i<TAM ; i++) {
        vecRepetidos[vec[i]-1] +=1;
    }
    for(int h=0; h<TAM; h++) {
        if(vecRepetidos[h]==6) {
            return h+1;
        } else if(vecRepetidos[h]!=1) {
            banderaRepe=true;
        }
    }
    return banderaRepe==false?0:-1;
}

////////////////////////////////////////////
/// JUGADAS
////////////////////////////////////////////

int evaluarCombinacion (int vec [], int TAM ) {
    //bool escalera = false;
    int sextetodeX;
    sextetodeX=combinacionX(vec,TAM);
    /// Evaluamos si es escalera
    //escalera=combinacionEscalera(vec,TAM);
    if (sextetodeX==0) {
        return 1; /// para evaluar en un swicht
    }

    /// Evaluamos si es un sexteto de algun numero
    else if (sextetodeX!=-1) {
        return 2;
    }
    /// si los anteriores casos son falsos, entonces tenemos que sumar los dados
    return 3;
}

int lanzamiento (int vec[], int TAM) {
    int puntos=0;
    int i,aux;
    bool escalera;
    bool combinacion;
    cargarVectorAleatorio(vec,TAM);
    mostrarVectorLine(vec,TAM);
    /// Evaluamos que combinacion de dados es y la desarrollamos en un switch
    aux=evaluarCombinacion(vec,TAM);
    switch(aux) {
    case 1:
        puntos=100;
        break;
    case 2:
        aux=combinacionX(vec,TAM);
        if(aux==6)
            puntos=0;
        else
            puntos=aux*10;
        break;
    case 3:
        puntos=sumatoriaVector(vec,TAM);
        break;
    }

    return puntos;
}


int lanzamientoTesteo (int vec[], int TAM) {
    int puntos=0;
    int aux;
    int prueba;
    cargarVectorManual(vec,TAM);
    mostrarVectorLine(vec,TAM);
    aux=combinacionX(vec,TAM);
    switch(aux) {
    case -1:
        puntos=sumatoriaVector(vec,TAM);
        break;
    case 0:
        puntos=100;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        puntos=aux*10;
        break;
    case 6:
        puntos=0;
    }
    return puntos;
}

int ronda(int vec[], int TAM) {
    int i, valor,aux;
    for (i=0; i<3; i++) {
        aux=lanzamiento(vec,TAM);
        cout<<"puntaje del lanzamiento: "<<i+1<<" : "<<aux<<endl;
        system("pause"); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!despues borrar!!!!!!!!!!!!!!!!!!!!!!!!!!1
        if(aux==0)
            valor= 0; //sexteto de 6
        else if(aux==100)
            return 100; //escalera
        else if(i==0)
            valor=aux; //si i es el 1ero, es el mayor
        else if(aux>valor)
            valor=aux; //sino devuelve
    }
    return valor;
}


