#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void mostrarVector(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
void mostrarMenu();

void mostrarVectorLine(int vec[],int tam );

//////////////////////

void unJugador();
void dosJugadores();
void modoSimulado(int TAM, int vec[]);

/////funciones combinaciones

bool combinacionSeisX(int vec[],int TAM,int x);
bool combinacionEscalera(int vec[],int TAM);
int combinacionX(int vec[],int TAM);

// complementos
string pedirNombre();
int sumatoriaVector(int vec[],int TAM);
int lanzamiento (int vec[], int tam);
int ronda(int vec[], int TAM);

#endif // FUNCIONES_H_INCLUDED

