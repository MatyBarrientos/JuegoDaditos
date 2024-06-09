#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void mostrarVector(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
void mostrarMenu();

void mostrarVectorLine(int vec[],int tam );

//////////////////////

void unJugador(int vec[],int TAM);
void dosJugadores(int vec[],int TAM);
void modoSimulado(int TAM, int vec[]);

/////funciones combinaciones

int evaluarCombinacion (int vec [], int TAM );
bool combinacionSeisX(int vec[],int TAM,int x);
bool combinacionEscalera(int vec[],int TAM);
int combinacionX(int vec[],int TAM);

// complementos
string pedirNombre(string frase);
int sumatoriaVector(int vec[],int TAM);
int lanzamiento (int vec[], int tam);
int lanzamientoTesteo (int vec[], int TAM);
int ronda(int vec[], int TAM);
int rondaTest(int vec[], int TAM);

///////
#endif // FUNCIONES_H_INCLUDED

