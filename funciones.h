#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void mostrarVector(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
void mostrarMenu();
void unJugador();
void dosJugadores();
void modoSimulado(int TAM, int vec[]);


/////funciones combinaciones

bool combinacionSeis6(int vec[],int TAM);
bool combinacionSeisX(int vec[],int TAM);

bool combinacionEscalera(int vec[],int TAM);

string pedirNombre();



#endif // FUNCIONES_H_INCLUDED

