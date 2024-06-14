#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void cargarVectorManual(int vec[], int tam);
void cargarVectorAleatorio(int vec[], int tam);
void mostrarVector(int vec[], int tam);
void ponerVectorEn0(int vec[], int tam);
void mostrarMenu();
void mostrarVectorLine(int vec[],int tam );
/////////////////////////////////////////////////////
void unJugador(int vec[],int TAM);
void dosJugadores(int vec[],int TAM);
void modoSimulado(int TAM, int vec[]);
/////funciones combinaciones/////////////////////////

string pedirNombre(string frase);

int sumatoriaVector(int vec[],int TAM);
int evaluarCombinacion (int vec [], int TAM );
int puntosLanzamiento  (int vec[], int tam);
int lanzamientoTesteo (int vec[], int TAM);
int ronda(int vec[], int TAM, int &lanzamiento);

//////////////////////////////////////////////////////
///////////////////////////////////////////////////////
void mostrarCartelGanador(string jugador, int lanzamieto, int ronda);
void mostrarCartelGanadorTest(string jugador, int lanzamiento,int posLanzamiento, int ronda, int puntaje);
void mostrarCartelEscalera(string jugador, int ronda);
void mostrarCartelPuntosRonda(string jugador, int ronda, int puntaje);
void mostrarCartelSexteto();

#endif // FUNCIONES_H_INCLUDED

