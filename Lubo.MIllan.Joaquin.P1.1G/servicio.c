#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"
#include "trabajo.h"

int listarServicios(eServicio lista[], int tam){

  int retorno = 0;
  if (lista != NULL && tam > 0)
  {
    printf("       ***Listado de servicios ***\n");
    printf("------------------------------------------\n");
    printf("   ID   |  Descripcion        |   Precio \n");
    for (int i = 0; i < tam; i++)
    {

      printf("  %d | %-15s     |   %d \n",
             lista[i].id,
             lista[i].descripcion,
             lista[i].precio
             );
    }
    retorno = 1;
  }
  return retorno;

}

int cargarDescripcionServicio(eServicio listaServicios[], int tam_serv, int idServicio, char descServicio[])
{
  int todoOk = 0;
  if (listaServicios != NULL && tam_serv > 0 && descServicio != NULL)
  {
    for (int i = 0; i < tam_serv; i++)
    {
      if(listaServicios[i].id == idServicio)
      {
        strcpy(descServicio, listaServicios[i].descripcion);
        todoOk =1; 
        break;
      }
    }
  }

  return todoOk;
}  