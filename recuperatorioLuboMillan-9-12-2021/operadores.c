#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "operadores.h"



int mostrarListaOperadores(operadores lista[], int tam)
{
  int retorno = 0;
  if (lista != NULL && tam > 0)
  {
    printf("       ***Listado de operadores***\n");
    printf("   ID  |  nombre\n");
    for (int i = 0; i < tam; i++)
    {

      printf("  %d | %s \n",
             lista[i].id,
             lista[i].nombre);
    }
    retorno = 1;
  }
  return retorno;
}


int cargarDescripcionOperadores(operadores lista[], int tam, int idOperadores, char nombre[])
{
  int todoOk = 0;
  if (lista != NULL && tam > 0 && nombre != NULL)
  {
    for (int i = 0; i < tam; i++)
    {
      if(lista[i].id == idOperadores)
      {
        strcpy(nombre, lista[i].nombre);
        todoOk =1; 
        break;
      }
    }
  }

  return todoOk;
}