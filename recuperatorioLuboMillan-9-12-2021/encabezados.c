#include "encabezados.h"
#include <stdio.h>
#include <stdlib.h>
void imprimirEncabezadoListaAlquileres() {
  system("cls");
  printf("|         *** Listado de Alquileres***                 |\n");
  printf("|------------------------------------------------|\n");
  printf("|  ID     IdCliente     descripcion      Fecha  |\n");
  printf("|------------------------------------------------|\n\n");
}

void imprimirEncabezadoAltaAlquilere() {
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Alta Alquiler***               \n");
  printf("|---------------------------------------------|\n\n");
}

void mostrarEncabezadoClientes() {
  system("cls");
  printf("|         *** Listado de Clientes***                        |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Equipos       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}

void mostrarEncabezadoModificacionCliente()
{
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("          ***Modificacion Cliente***          \n");
  printf("|---------------------------------------------|\n\n");
}

void imprimirEncabezadoAltaCliente() {
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Alta Cliente***               \n");
  printf("|---------------------------------------------|\n\n");
}

void imprimirEncabezadoBajaCliente()
{
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Baja Cliente***               \n");
  printf("|---------------------------------------------|\n\n");
}

void mostrarEncabezadoClientesSinTitulo() {  
  printf("|----------------------------------------------------|\n");
  printf("|  ID     Modelo     Equipos       Tipo         Precio |\n");
  printf("|----------------------------------------------------|\n\n");
}
