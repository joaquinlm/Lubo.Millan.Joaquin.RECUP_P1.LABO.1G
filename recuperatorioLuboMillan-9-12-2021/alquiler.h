#include "cliente.h"
#include "operadores.h"
#include "equipos.h"

#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
typedef struct
{
  int id;
  int idCliente;
  int idEquipo;
  int tiempoAlquiler;
  int idOperador;
  int estado;
  int isEmpty;

}alquiler;



int inicializarAlquiler(alquiler lista[], int tam);
int buscarPosicionLibreAlquiler(alquiler lista[], int tam);
int altaAlquiler(alquiler lista[], int tam, int* Id, cliente listaCliente[], int tamCliente, operadores listaOperadores[], int tamOperadores, equipos listaEquipos[], int tamEquipos );
int buscarAlquilerPorId(alquiler lista[], int tam, int id);
int saldarAlquiler(alquiler lista[], int tam, int* Id, cliente listaCliente[], int tamCliente);
void mostrarAlquiler(alquiler alquiler,int tamAlquiler, cliente listaCliente[], int tamCliente);
int mostrarAlquilers(alquiler lista[], int tamAlquiler, cliente listaCliente[], int tamCliente);
int mostrarListaOperadores(operadores lista[], int tam);
void mostrarEquiposMasElegidos(alquiler listaAlquiler[], int tam, equipos listaEquipos[], int tamEquipos);
void mostrarPromedioTempoReal( alquiler listaAlquiler[], int tamAlquiler);
#endif // PRESTAMO_H_INCLUDED
