#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "equipos.h"



int mostrarEquiposs(equipos lista[], int tam)
{
  int retorno = 0;
  if (lista != NULL && tam > 0)
  {
    printf("       ***Listado de equipos***\n");
    printf("   ID  |  Descripcion\n");
    for (int i = 0; i < tam; i++)
    {

      printf("  %d | %s \n",
             lista[i].id,
             lista[i].descripcion);
    }
    retorno = 1;
  }
  return retorno;
}


int cargarDescripcionEquipos(equipos lista[], int tam, int idEquipos, char descripcion[])
{
  int todoOk = 0;
  if (lista != NULL && tam > 0 && descripcion != NULL)
  {
    for (int i = 0; i < tam; i++)
    {
      if(lista[i].id == idEquipos)
      {
        strcpy(descripcion, lista[i].descripcion);
        todoOk =1; 
        break;
      }
    }
  }

  return todoOk;
}

