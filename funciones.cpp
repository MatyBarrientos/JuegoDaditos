#include<iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

///////////////////////////////////////
/// MENU://////////////////////////////
///////////////////////////////////////

void mostrarMenu()
{
    system("cls");
    cout<<" ---- Escalera o Cien ---- "<<endl;
    cout<<" 1 - 1 Jugador. "<<endl;
    cout<<" 2 - 2 jugadores. "<<endl;
    cout<<" 3 - Modo simulado. "<<endl;
    cout<<" 0 - Salir "<<endl;
    cout<<" Ingrese la opcion deseada: "<<endl;
}

///////////////////////////////////////
/// VECTORES://////////////////////////
///////////////////////////////////////

void cargarVectorAleatorio(int vec[], int TAM)
{
    int i;
    for (i=0; i<TAM ; i++ )
        vec[i]=rand()%6+1;
}

void cargarVectorManual(int vec[],int TAM )
{
    int i;
    for (i=0; i<TAM ; i++ )
    {
        cout<<"Ingrese el elemento "<<i+1<<" del vector: ";
        cin>>vec[i];
    }
    cout<<"Vector correctamente cargado..."<<endl;
}

void ponerVectorEn0(int vec[],int TAM )
{
    int i;
    for (i=0; i<TAM ; i++ )
    {
        vec[i]=0;
    }
    cout<<"Vector correctamente seteado en 0..."<<endl;
}

void mostrarVector(int vec[],int TAM )
{
    int i;
    for (i=0; i<TAM ; i++ )
    {
        cout<<"Elemento "<<i+1<<" del vector: "<<vec[i]<<endl;
    }
    system("pause");
}

void mostrarVectorLine(int vec[],int TAM )
{
    int i;
    for (i=0; i<TAM ; i++ )
    {
        cout<<"["<<vec[i]<<"] ";
    }
    cout<<endl;
}

////////////////////////////////////////////
/// MODOS DE JUEGO://///////////////////////
////////////////////////////////////////////

void unJugador(int vec[],int TAM)
{
    /// Variables
    int puntaje = 0,acumPuntaje=0;
    int cantRondas=0,lanzamientos=0;
    int posLanzamiento;
    bool banderaEscalera=false, banderaSexteto6=false; //ISA
    string jugador;
    /// Desarrollo
    jugador=pedirNombre("Ingrese su nombre: ");
    cout<<"Hola "<<jugador<<", comencemos a jugar."<<endl;
    system("pause");

    while(acumPuntaje<=100 && puntaje<=100)
    {

        system("cls");
        cout<<"Jugador: " << jugador << endl;
        cout<<"Numero de ronda: "<<cantRondas+1<<"            "<<"Puntos acumulados: "<<acumPuntaje<<endl;
        puntaje=ronda(vec,TAM,posLanzamiento);
        cantRondas++;
        lanzamientos=((cantRondas-1)*3);
        if(puntaje==100)
        {
            cout<<"Ganaste la partida.!!!!!!!!!!!"<<endl;
            cout<<"Sacaste escalera en la ronda "<<cantRondas<<", en el lanzamiento "<<posLanzamiento<<". Felicidades. "<<endl;
            cout<<"Tardaste un total de "<<lanzamientos+posLanzamiento<<" lanzamientos. "<<endl;
            system("pause");
        }
        else if(puntaje==0)
        {
            cout<<"Sacaste un sexteto de seis, tus puntos se reinician a '0'."<<endl;
            system("pause");
            acumPuntaje=0;
        }
        else
        {
            acumPuntaje+=puntaje;
            cout<<endl;
            cout<<"Puntaje de la ronda "<<cantRondas<<": "<<puntaje<<endl;
            system("pause");
        }
    }
    mostrarCartelGanadorTest(jugador,lanzamientos,posLanzamiento,cantRondas, acumPuntaje);
    /*system ("cls");
    cout<<"Jugador: " << jugador << endl;
    cout<<"Numero de ronda: "<<cantRondas<<"            "<<"Puntos acumulados: "<<acumPuntaje<<endl;
    cout<<jugador<<" ganaste la partida.!!!!!!!!!!!"<<endl;
    cout<<"Puntos acumulados: " << acumPuntaje << endl;
    cout<<"Ganaste en la ronda "<<cantRondas<<", en el lanzamiento "<<posLanzamiento<<endl; //ISA
    cout<<"En total fueron "<<lanzamientos+posLanzamiento<<" lanzamientos."<<endl; //ISA
    system("pause");
    system("cls");*/
    ///lo volvimnos funcion para ahorrar lineas de codigo y haceerlo más modular
}


void dosJugadores(int vec[],int TAM)
{
    /// Variables
    string jugador1;
    string jugador2;
    int puntaje1,acumPuntaje1=0;
    int puntaje2,acumPuntaje2=0;
    int round=0,pos1,nLanzamieto1,pos2,nLanzamieto2;
    /// Pedimos los nombres
    jugador1=pedirNombre("Ingrese el nombre del jugador 1: ");
    cout<<endl;
    jugador2=pedirNombre("Ingrese el nombre del jugador 2: ");
    cout<<endl;
    cout<<"Hola "<<jugador1<<" , hola "<<jugador2<<".Bien, comencemos a jugar."<<endl;
    system("pause");

    /// Ciclo inexacto
    while((acumPuntaje1<100 and puntaje1!=100)and(acumPuntaje2<100 and puntaje2!=100))
    {
        system("cls");
        round++;
        /// Jugador 1
        cout<<"Ronda Nro: "<<round<<"        "<<"Turno de "<<jugador1<<endl;
        puntaje1=ronda(vec,TAM,pos1);
        nLanzamieto1=((round-1)*3)+pos1;
        system("cls");
        /// Jugador 2
        cout<<"Ronda Nro: "<<round<<"        "<<"Turno de "<<jugador2<<endl;
        puntaje2=ronda(vec,TAM,pos2);
        nLanzamieto2=((round-1)*3)+pos2;
        system("cls");

        if(puntaje1==100 and (nLanzamieto1<nLanzamieto2) )
        {
            mostrarCartelEscalera(jugador1,round);
        }
        else if(puntaje2==100 and (nLanzamieto2<nLanzamieto1) )
        {
            mostrarCartelEscalera(jugador2,round);
        }
        if (puntaje1==0)
        {
            mostrarCartelSexteto();
            acumPuntaje1=0;
        }
        else
        {
            acumPuntaje1+=puntaje1;
            mostrarCartelPuntosRonda(jugador1,round,puntaje1);
        }
        if (puntaje2==0)
        {
            mostrarCartelSexteto();
            acumPuntaje2=0;
        }
        else
        {
            acumPuntaje2+=puntaje2;
            mostrarCartelPuntosRonda(jugador2,round,puntaje2);
        }
        if(round!=0)
        {
            cout<<"Puntos acumulados!!!"<<endl<<jugador1<<": "<<acumPuntaje1<<endl<<jugador2<<": "<<acumPuntaje2<<endl;
            system("pause");
        }
    }
    if(acumPuntaje1>=100 and acumPuntaje2>=100) //si ambos pasaron a 100 empezamos a contemplar casos
    {

        if(nLanzamieto1<nLanzamieto2) //1ero vamos con el que llegó primero a 100 o lo pasó
        {
            //mostrarCartelGanador(jugador1,nLanzamieto1,round);
            mostrarCartelGanadorTest(jugador1,nLanzamieto1,pos1,round,acumPuntaje1);


        }
        else if(nLanzamieto2<nLanzamieto1)
        {

            //mostrarCartelGanador(jugador2,nLanzamieto2,round);
            mostrarCartelGanadorTest(jugador2,nLanzamieto2,pos2,round,acumPuntaje2);


        }
        else if(acumPuntaje1>acumPuntaje2 and nLanzamieto1==nLanzamieto2)
        {
            //mostrarCartelGanador(jugador1,nLanzamieto1,round);
            mostrarCartelGanadorTest(jugador1,nLanzamieto1,pos1,round,acumPuntaje1);
        }
        else if(acumPuntaje2>acumPuntaje1 and nLanzamieto2==nLanzamieto1)
        {
            //mostrarCartelGanador(jugador1,nLanzamieto1,round);
            mostrarCartelGanadorTest(jugador2,nLanzamieto2,pos2,round,acumPuntaje2);
        }
        //tuve que contemplar 1 caso más, que ambos en el mismo nro de lanzamiento pasen o lleguen a 100
        //si no son iguales que gane el de mayor puntaje
        else if(acumPuntaje1==acumPuntaje2 and nLanzamieto1==nLanzamieto2)
        {
            cout<<"Empataron"<<endl;
            system("pause");
        }
    }
    else if(acumPuntaje1>=100)
    {
        //mostrarCartelGanador(jugador1,nLanzamieto1,round);
        mostrarCartelGanadorTest(jugador1,nLanzamieto1,pos1,round,acumPuntaje1);


    }
    else if (acumPuntaje2>=100)
    {
        //mostrarCartelGanador(jugador2,nLanzamieto2,round);
        mostrarCartelGanadorTest(jugador2,nLanzamieto2,pos2,round,acumPuntaje2);


    }
}
void modoSimulado( int vec[],int TAM)
{
    int vueltas=0, aux=0, prueba;
    cout<<"Ingrese la cantidad de lanzamientos a intentar: ";
    cin>>vueltas;
    for(int i=0; i<vueltas; i++)
    {
        prueba=lanzamientoTesteo(vec,TAM);
        if(prueba==0)
        {
            aux=0;
            cout<<"puntaje del lanzamiento: "<<aux<<endl;
        }
        else if(prueba==100)
        {
            aux=100;
            cout<<"Fin del testeo, 'escalera' ingresada"<<endl;
            cout<<"Puntaje del lanzamiento: "<<prueba<<endl;
            system("pause");
            break;
        }
        else
        {
            aux+=prueba;
            cout<<"puntaje del lanzamiento: "<<prueba<<endl;
        }
        cout<<"Puntaje del testeo: "<<aux<<endl;
        system("pause");
    }
}
//////////////////////////////////////
///////mostrar cartel ganador/////////
//////////////////////////////////////

void mostrarCartelGanador(string jugador, int lanzamieto, int ronda)
{

    cout<<"Tardaste un total de "<<lanzamieto<<" lanzamientos. "<<endl;
    cout<<"Tardaste un total de "<<ronda<<" rondas. "<<endl;
    cout<<jugador<<" ganaste la partida.!!!!!!!!!!!"<<endl;
    system("pause");
}
////es más completa que la de arriba
void mostrarCartelGanadorTest(string jugador, int lanzamiento,int posLanzamiento, int ronda, int puntaje)
{

    system ("cls");
    cout<<jugador<<" ganaste la partida.!!!!!!!!!!!"<<endl;
    //cout<<"Jugador: " << jugador << endl;
    cout<<"Numero de ronda: "<<ronda<<"            "<<"Puntos acumulados: "<<puntaje<<endl;
    //cout<<"Puntos acumulados: " << puntaje << endl;
    cout<<"Ganaste en la ronda "<<ronda<<", en el lanzamiento "<<posLanzamiento<<endl; //ISA
    cout<<"En total fueron "<<lanzamiento+posLanzamiento<<" lanzamientos."<<endl; //ISA
    system("pause");
    system("cls");
}
/*
*/


void mostrarCartelEscalera(string jugador, int ronda)
{
    cout<<jugador<<" ganaste la partida.!!!!!!!!!!!"<<endl;
    cout<<"Sacaste escalera en la ronda "<<ronda<<", felicidades. "<<endl;
    system("pause");
}

void mostrarCartelPuntosRonda(string jugador, int ronda, int puntaje)
{
    cout<<"Puntaje de la ronda "<<ronda<<" de "<<jugador<<": "<<puntaje<<endl;
    system("pause");
}


void mostrarCartelSexteto()
{
    cout<<"Sacaste sexteto de se�s, tus puntos se reinician a '0'."<<endl;
    system("pause");
}

////////////////////////////////////////////
/// CARGAR NOMBRE///////////////////////////
////////////////////////////////////////////
string pedirNombre(string frase)
{
    string nombre;
    cout<<frase;
    fflush(stdin); ///importante, no omite 1er caracter
    ////! por algun motivo no funciona en la pc de bruno !!!preguntar!!!!!!!!!!

    getline(cin,nombre);
    return nombre;
}

//////////////////////////////////////
/// SUMA VECTOR://////////////////////
//////////////////////////////////////

int sumatoriaVector(int vec[],int TAM)
{
    int i, sumatoria=0;
    for(i=0; i<TAM; i++)
    {
        sumatoria+=vec[i];
    }
    return sumatoria;
}
///////////////////////////////////
/// COMBINACIONES//////////////////
///////////////////////////////////
/***
** la idea de evaluarCombinacion() es codificar los valares que retorna
** -1 significa que no hay sexteto o escalera, entonces procedo con la sumatoria
** 0 significa que es escalera y despues devuelve valores entre [1,6]
** donde cada num representa de que est� compuesto el sexteto
*/
int evaluarCombinacion(int vec[],int TAM)
{
    bool banderaRepetidos=false;
    int vecRepetidos[TAM]= {};
    for(int i=0; i<TAM ; i++)
    {
        vecRepetidos[vec[i]-1] += 1; /// Recorre el vector en busca de coincidencias cambiando el valor en caso de ser 0
    }
    for(int h=0; h<TAM; h++)
    {
        if(vecRepetidos[h]==6)   /// Pregunta si hay sexteto de algun numero
        {
            return h+1; /// Sexteto de h+1
        }
        else if(vecRepetidos[h]!=1)     /// Escalera = todos 1. si hay alguno != 1, cambiamos la bandera de repetidos a verdadera
        {
            banderaRepetidos=true;
        }
    }
    if (banderaRepetidos)
    {
        return -1; /// Sumatoria
    }
    else
    {
        return 0; /// Escalera
    }
    ///return banderaRepe==false?0:-1;
    /// //muy abstracto? siguen siendo mis preferidos los operadores o variales ternarias

}

////////////////////////////////////////////
/// JUGADAS/////////////////////////////////
////////////////////////////////////////////
int puntosLanzamiento (int vec[], int TAM)
{
    int puntos, combinacion;

    combinacion=evaluarCombinacion(vec,TAM);

    switch(combinacion)
    {
    case -1: /// Sumatoria
        cout << "Sumatoria"<<endl;
        puntos=sumatoriaVector(vec,TAM);
        break;
    case 0: /// Escalera
        cout<<"ESCALERA!!!"<<endl;
        puntos=100;
        break;
    case 1: /// Sextetos
    case 2:
    case 3:
    case 4:
    case 5:
        cout<<"Sexteto de "<<combinacion<<endl;
        puntos=combinacion*10;
        break;
    case 6:
        cout<<"Sexteto de 6."<<endl;
        puntos=0;
    }
    return puntos;
}

int lanzamientoTesteo (int vec[], int TAM)
{
    int puntos=0;
    int aux;
    cargarVectorManual(vec,TAM);
    mostrarVectorLine(vec,TAM);
    aux=evaluarCombinacion(vec,TAM);
    switch(aux)
    {
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
/***
**modifique ronda() para que retornara el puntaje a tener en cuenta de 3 lanzamientos
** escalera, sexteto o la mayor de las sumatorias decid� agregar un parametro m�s y es por referencia
** ya que no ten�a manera de como sumar los lanzamientos ya que por ronda son 3 pero no siempre contas el
** el 3ero, despu�s de ultima se los explico
*/

int ronda(int vec[], int TAM, int &lanzamiento)
{
    int i, maxPuntaje=0, puntaje;
    bool banderaSexteto6 = false; ///Agregado por Isa.
    for (i=1; i<=3; i++)   /// 3 lanzamientos
    {
        cargarVectorAleatorio(vec,TAM);
        //cargarVectorManual(vec,TAM); //está comentado porque hacemos un poco de feedback desde acá.

        cout<<endl;
        mostrarVectorLine(vec,TAM);
        cout<<endl;
        puntaje = puntosLanzamiento (vec,TAM);
        cout<<"Lanzamiento: "<<i<<"         "<<"Puntos: "<< puntaje << endl;
        system("pause");
        if(puntaje==100)   /// Escalera
        {
            lanzamiento=i;
            return 100; // Retorna con 100 xq el juego termina aca.
        }
        else if(puntaje==0)     /// Sexteto de 6
        {
            banderaSexteto6=true;
            lanzamiento=i;
        }
        else if(i==1)     /// El primer lanzamiento de la ronda es el MAX
        {
            maxPuntaje=puntaje;
            lanzamiento=i;
        }
        else if(puntaje>maxPuntaje)
        {
            maxPuntaje=puntaje;
            lanzamiento=i;
        }
    }
    if (banderaSexteto6)
    {
        return 0; /// Para que no tenga en cuenta los otros 2 lanzamientos y tome el sexteto de 6
    }
    else
    {
        return maxPuntaje;
    }
}

