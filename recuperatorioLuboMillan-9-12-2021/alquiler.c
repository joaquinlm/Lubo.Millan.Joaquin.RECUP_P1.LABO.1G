#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "alquiler.h"
#include "operadores.h"

#include "inputsValidados.h"



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
int inicializarAlquiler(alquiler lista[], int tam)
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

int buscarPosicionLibreAlquiler(alquiler lista[], int tam)
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



int altaAlquiler(alquiler lista[], int tam, int* Id, cliente listaCliente[], int tamCliente, operadores listaOperadores[], int tamOperadores, equipos listaEquipos[], int tamEquipos )
{
    int todoOk = 0;
    alquiler auxAlquiler;
    int auxIdCLiente;
    int auxIdEquipo;
    int auxTiempo;
    int auxIdOperador;
    int indiceAlquiler;
    int indiceCliente;

    if (lista != NULL && tam > 0)
    {


        indiceAlquiler = buscarPosicionLibreAlquiler(lista, tam);
        if (indiceAlquiler == -1)
        {
            printf("No espacios disponibles\n");
        } else
        {

            mostrarClientes(listaCliente, tamCliente);
            auxIdCLiente = ingresarEnterosRango("\nIngrese el id del cliente", "Error:\n", 3000, 3100);

            if((indiceCliente = buscarClientePorId(listaCliente, tamCliente,  auxIdCLiente)) ==-1)
            {
              printf("no se encontro el ID\n");
            }
            else{
            mostrarEquiposs(listaEquipos, tamEquipos);
            auxIdEquipo = ingresarEnterosRango("\nIngrese el Id del equipo", "Error:\n", 5000, 5002);

            auxTiempo = ingresarEnterosRango("\nIngrese el tiempo de alquiler en dias (entre 1 y 10", "Error:\n", 1, 10);

            mostrarListaOperadores(listaOperadores, tamOperadores);

            auxIdOperador= ingresarEnterosRango("Ingrese el Id del operador\n", "Error. Ingrese el Id del operador\n", 1000, 1004);

            auxAlquiler.idEquipo = auxIdEquipo;
            auxAlquiler.tiempoAlquiler = auxTiempo;
            auxAlquiler.idCliente = auxIdCLiente;
            auxAlquiler.idOperador = auxIdOperador;
            auxAlquiler.estado = 1;
            auxAlquiler.isEmpty = 0;
            auxAlquiler.id = *Id;
            (*Id)++;
            lista[indiceAlquiler] = auxAlquiler;

            printf("Alta realizada con exito\n");
            todoOk = 1;
            }


        }
    }
    return todoOk;
}

int buscarAlquilerPorId(alquiler lista[], int tam, int id)
{
    int retorno = -1;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void mostrarAlquiler(alquiler alquiler,int tamAlquiler, cliente listaCliente[], int tamCliente)
{

    if (alquiler.isEmpty == 0)
    {
      char auxEstado[20];
      if(alquiler.estado == 1)
      {
        strcpy(auxEstado , "ALQUILADO");
      }
      else {
        strcpy(auxEstado , "FINALIZADO");
      }

        printf("  %-2d       %-2d     $%-2d       %-2d     %s\n", alquiler.id, alquiler.idCliente , alquiler.idOperador, alquiler.tiempoAlquiler, auxEstado);
    }
}

int mostrarAlquilers(alquiler lista[], int tamAlquiler, cliente listaCliente[], int tamCliente)
{
    int retorno = 0;
    if (lista != NULL && tamAlquiler > 0)
    {
       printf("           ***listado de alquileres***   \n");
            printf("idAlquiler  idCliente    Id operador    idEquipo    tiempo    estado   \n");
      for (int i = 0; i < tamAlquiler; i++)
        {
            if (!lista[i].isEmpty)
            {

                mostrarAlquiler(lista[i], tamAlquiler, listaCliente, tamCliente);
            }
        }
        retorno = 1;
    }
    return retorno;
}

int saldarAlquiler(alquiler lista[], int tam, int* Id, cliente listaCliente[], int tamCliente)
{
    int todoOk = 0;
    int idAlquiler;
    int auxTiempo;

    int indiceAlquiler;
    int indiceCliente;

    if (lista != NULL && tam > 0)
    {

            printf("           ***listado de alquileres***   \n");
            printf("idAlquiler  idCliente    Id operador    idEquipo    tiempo    estado   \n");
            mostrarAlquilers(lista, tam,  listaCliente, tamCliente);
            idAlquiler = ingresarEnterosRango("\nIngrese el id del alquiler", "Error:\n", 8000, 8100);

            if((indiceAlquiler = buscarAlquilerPorId(lista, tam,  idAlquiler)) ==-1)
            {
              printf("no se encontro el ID\n");
            }
            else{
                if(lista[indiceAlquiler].estado == 0){
                    printf("Ya se devolvio el equipo \n");
                    return todoOk;
                }
              indiceCliente =   buscarClientePorId(listaCliente, tamCliente, lista[indiceAlquiler].idCliente);
              printf("El alquiler pertenece a :\n");
              mostrarCliente(listaCliente[indiceCliente], tam);

            char confirma;

             printf("confirma que desea devolver el equipo? s/n\n");

             fflush(stdin);
             scanf("%1c", &confirma);

             if(confirma =='s')
             {
               auxTiempo= ingresarEnterosRango("Ingrese el tiempo real de alquiler (entre 1 y 10 dias)\n", "Error. Ingrese el tiempo real de alquiler (entre 1 y 10 dias)\n", 1, 10);
               lista[indiceAlquiler].tiempoAlquiler = auxTiempo;
               lista[indiceAlquiler].estado = 0;
            printf("Se saldo el alquiler con exito con exito\n");
             }



            todoOk = 1;
            }



    }
    return todoOk;
}

void mostrarEquiposMasElegidos(alquiler listaAlquiler[], int tam, equipos listaEquipos[], int tamEquipos) {

    int contadoresEquipos[3] = { 0, 0,0 };
    int match = 0;//bandera para mostrar si hay empate entre marcas



    for (int i = 0; i < tam; i++)
    {
        if(!listaAlquiler[i].isEmpty){
        switch (listaAlquiler[i].idEquipo)
        {
        case 5000:

            contadoresEquipos[0]++;
            break;

        case 5001:
            contadoresEquipos[1]++;
            break;

        case 5002:
            contadoresEquipos[2]++;
            break;


        }
        }
    }
    if (listaAlquiler != NULL && tam > 0)
    {
        int maximo = 1;
        int masNotebooks = 0;

        for (int i = 0; i < tamEquipos; i++)
        {
            if (contadoresEquipos[i] > masNotebooks || maximo)
            {
                masNotebooks = contadoresEquipos[i];
                maximo = 0;
            }
        }

        for (int i = 0; i < tamEquipos - 1; i++)
        {
            for (int j = i + 1; j < tamEquipos; j++)
            {
                if (contadoresEquipos[i] == contadoresEquipos[j]) {
                    if (contadoresEquipos[i] == masNotebooks && contadoresEquipos[j] == masNotebooks) {
                      //  mostrarEncabezadoMasElegidas();
                        printf("los equipos mas elegidos son son %s y %s con %d unidades \n", listaEquipos[i].descripcion, listaEquipos[j].descripcion, contadoresEquipos[i]);
                        match = 1;
                    }
                }
            }
        }
        if (!match) {
            for (int i = 0; i < tamEquipos; i++)
            {
                ;
                if (contadoresEquipos[i] == masNotebooks)
                {
     //               mostrarEncabezadoMasElegidas();
                    printf("el equipo mas elegido es %s con %d unidades \n", listaEquipos[i].descripcion, contadoresEquipos[i]);
                }
            }
        }

    }


}


void mostrarPromedioTempoReal( alquiler listaAlquiler[], int tamAlquiler){
  float sumadorDias = 0;
  int contador =0;
  for(int i = 0; i < tamAlquiler; i++)
  {
    if(listaAlquiler[i].estado == 0)
    {
      contador++;
      sumadorDias += listaAlquiler[i].tiempoAlquiler;
    }
  }
  if(!contador){
    printf("no se puede calcular el promedio de dias, nadie devolvio un equipo\n");
  }
  else{
    printf("el promedio real de dias de alquiler es de %f", (sumadorDias/contador));
  }
}
