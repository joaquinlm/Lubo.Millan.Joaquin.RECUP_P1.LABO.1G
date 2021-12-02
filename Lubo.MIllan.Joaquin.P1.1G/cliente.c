#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "notebook.h"
#include "cliente.h"

int buscarPosicionLibreCliente(cliente lista[], int tam)
{
    int todoOk = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty == 1)
        {
            todoOk = i;
            break;
        }
    }
    return todoOk;
}

int inicializarClientes(cliente lista[], int tam)
{
  int retorno = 0;
  if (lista != NULL && tam > 0)
  {
    for (int i = 0; i < tam; i++)
    {
      lista[i].isEmpty = 1;
    }
    retorno = 1;
  }
  return retorno;
}

int cargarNombreCliente(cliente listaCliente[], int tamCliente, int idCliente, char nombre[])
{
  int todoOk = 0;
  if (listaCliente != NULL && tamCliente > 0 && nombre != NULL)
  {
    for (int i = 0; i < tamCliente; i++)
    {
      if(listaCliente[i].id== idCliente)
      {
        strcpy(nombre, listaCliente[i].nombre);
        todoOk =1; 
        break;
      }
    }
  }

  return todoOk;
}  