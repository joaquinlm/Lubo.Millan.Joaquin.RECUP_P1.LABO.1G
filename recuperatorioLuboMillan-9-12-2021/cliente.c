#include "cliente.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encabezados.h"
#include "inputsValidados.h"
#include "menu.h"

int inicializarClientes(cliente lista[], int tam) {
    int retorno = 0;
    if (lista != NULL && tam > 0) {
        for (int i = 0; i < tam; i++) {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarPosicionLibreCliente(cliente lista[], int tam) {
    int todoOk = -1;
    for (int i = 0; i < tam; i++) {
        if (lista[i].isEmpty == 1) {
            todoOk = i;
            break;
        }
    }
    return todoOk;
}

int altaCliente(cliente lista[], int tam, int* Id) {
    int todoOk = 0;
    cliente auxCliente;

    int indiceCliente;
    char auxClienteNombre[20];
    char auxClienteApellido[20];
    if (lista != NULL && tam > 0) {
        indiceCliente = buscarPosicionLibreCliente(lista, tam);
        if (indiceCliente == -1) {
            printf("No espacios disponibles\n");
        } else {
            imprimirEncabezadoAltaCliente();
            ingresarValidarCadena(
                auxClienteNombre, 20,
                "Ingrese nombre del cliente (solo caracteres alfabeticos o "
                "espacios, hasta 20 caracteres)",
                "Error. Ingrese el nombre del cliente (solo caracteres "
                "alfabeticos o espacios, hasta 20 caracteres)",
                3, 20);
            ingresarValidarCadena(
                auxClienteApellido, 20,
                "Ingrese apellido del cliente (solo caracteres alfabeticos o "
                "espacios, hasta 20 caracteres)",
                "Error. Ingrese el apellido del cliente (solo caracteres "
                "alfabeticos o espacios, hasta 20 caracteres)",
                3, 20);

            ingresarFlotantesRango(&auxCliente.cuil,
                                   "\nIngrese dni (entre 5 millones y 50 millones):\n",
                                   "Error:\n", 5000000, 50000000);

            auxCliente.isEmpty = 0;
            auxCliente.id = *Id;
            (*Id)++;

            strcpy(auxCliente.nombre, auxClienteNombre);
            strcpy(auxCliente.apellido, auxClienteApellido);

            lista[indiceCliente] = auxCliente;

            printf("Alta realizada con exito\n");
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarCliente(cliente cliente, int tamCliente) {
    if (cliente.isEmpty == 0) {
        printf("  %-2d    %s  %s   %.0lf  \n", cliente.id, cliente.nombre,
               cliente.apellido, cliente.cuil);
    }
}

int mostrarClientes(cliente lista[], int tamCliente) {
    int retorno = 0;
    if (lista != NULL && tamCliente > 0) {
        mostrarEncabezadoClientes();
        for (int i = 0; i < tamCliente; i++) {
            if (!lista[i].isEmpty) {
                mostrarCliente(lista[i], tamCliente);
            }
        }
        retorno = 1;
    }
    return retorno;
}

int buscarClientePorId(cliente lista[], int tam, int id) {
    int retorno = -1;
    if (lista != NULL && tam > 0) {
        for (int i = 0; i < tam; i++) {
            if (!lista[i].isEmpty && lista[i].id == id) {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int bajaCliente(cliente lista[], int tam) {
    int todoOk = 0;
    int idRm;
    char confirma;
    if (lista != NULL && tam > 0) {
        imprimirEncabezadoBajaCliente();
        mostrarClientes(lista, tam);
        printf("Ingrese el Id del cliente \n");
        scanf("%d", &idRm);

        int indice = buscarClientePorId(lista, tam, idRm);
        if (indice == -1) {
            printf("No se encontro el ID %d en el  sistema\n", idRm);
        } else {
            mostrarCliente(lista[indice], tam);
            printf("confirma que desea dar de baja?: s-n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's') {
                lista[indice].isEmpty = 1;
                todoOk = 1;
                printf("Baja realizada con exito\n");
            } else {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}

int modificarCliente(cliente listaCliente[], int tamCliente) {
    int todoOk = -1;
    int index;
    char auxNuevoNombre[20];
    char auxNuevoApellido[20];

    char confirma;

    int id;
    mostrarEncabezadoModificacionCliente();
    printf("  ID      Nombre     apellido   CUIL\n");
    mostrarClientes(listaCliente, tamCliente);
    id = ingresarEnterosRango("Ingrese el ID del cliente a modificar:",
                              "Formato no valido, solo se permiten ingresar "
                              "numeros enteros entre 1 y 5000\n",
                              1, 5000);
    index = buscarClientePorId(listaCliente, tamCliente, id);
    if (index != -1) {
        printf("  ID      Nombre     apellido   CUIL\n");
        mostrarCliente(listaCliente[index], tamCliente);

        printf("\nconfirma que desea modificar el Cliente? s/n");
        fflush(stdin);
        scanf("%1c", &confirma);

        if (confirma == 's') {
            int opcion = imprimirOpcionesModificacionCliente();
            if (opcion != 3) {
                switch (opcion) {
                    case 1:
                        ingresarValidarCadena(
                            auxNuevoNombre, 20, "Ingrese el  nuevo nombre: ",
                            "Error. Reingrese el nuevo nombre (solo caracteres "
                            "alfabeticos o espacios)\n",
                            3, 20);
                        if (strcpy(listaCliente[index].nombre,
                                   auxNuevoNombre)) {
                            printf("Nombre modificado con exito\n");
                        }
                        break;
                    case 2:
                        ingresarValidarCadena(
                            auxNuevoNombre, 20, "Ingrese el  nuevo apellido: ",
                            "Error. Reingrese el nuevo apellido (solo "
                            "caracteres alfabeticos o espacios)\n",
                            3, 20);
                        if (strcpy(listaCliente[index].apellido,
                                   auxNuevoApellido)) {
                            printf("Nombre modificado con exito\n");
                        }
                        break;


                }

                mostrarEncabezadoClientesSinTitulo();
                mostrarCliente(listaCliente[index], tamCliente);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int cargarNombreCliente(cliente lista[], int tam, int idCliente, char nombre[])
{
  int todoOk = 0;
  if (lista != NULL && tam > 0 && nombre != NULL)
  {
    for (int i = 0; i < tam; i++)
    {
      if(lista[i].id == idCliente)
      {
        strcpy(nombre, lista[i].nombre);
        todoOk =1; 
        break;
      }
    }
  }

  return todoOk;
}
int cargarApellidoCliente(cliente lista[], int tam, int idCliente, char apellido[])
{
  int todoOk = 0;
  if (lista != NULL && tam > 0 && apellido != NULL)
  {
    for (int i = 0; i < tam; i++)
    {
      if(lista[i].id == idCliente)
      {
        strcpy(apellido, lista[i].apellido);
        todoOk =1; 
        break;
      }
    }
  }

  return todoOk;
}