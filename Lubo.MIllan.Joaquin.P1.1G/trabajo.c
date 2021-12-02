#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"
#include "servicio.h"
#include "dia.h"
#include "inputsValidados.h"
#include "notebook.h"
#include "encabezados.h"

int altaTrabajo(int* idTrabajo, eTrabajo listaTrabajo[], int tam_trab, eServicio listaServicios[], int tam_serv, eNotebook listaNotebook[], int tam_not, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente)
{
  int todoOk = 0;
  eTrabajo auxTrabajo;
  int idAltaNotebookTrabajo = 0;
  int indiceTrab;
  int indice;
  if (listaTrabajo != NULL && tam_trab > 0 && listaServicios != NULL && tam_serv > 0 && listaNotebook != NULL && tam_not > 0)
  {
    imprimirEncabezadoAltaTrabajo();
    indiceTrab = buscarPosicionLibreTrabajo(listaTrabajo, tam_trab);
    if (indiceTrab == -1) {
      printf("No espacios disponibles\n");
    } else {
      mostrarNotebooks(listaNotebook, tam_not, listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
      printf("\nIngrese el Id de la notebook \n");
      scanf("%d", &idAltaNotebookTrabajo);

      indice = buscarNotebookPorId(listaNotebook, tam_not, idAltaNotebookTrabajo);
      if (indice == -1) {
        printf("\nNo se encontro el ID %d en el  sistema\n", idAltaNotebookTrabajo);
      } else {
        char confirma;
        mostrarEncabezadoNotebooksSinTitulo();
        mostrarNotebook(listaNotebook[indice], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
        printf("\nconfirma que desea dar de alta el trabajo para esta notebook?: s-n: \n");
        fflush(stdin);
        scanf("%c", &confirma);
        if (confirma == 's')
        {
          eFecha workAuxFecha;
          auxTrabajo.isEmpty = 0;
          auxTrabajo.idNotebook = idAltaNotebookTrabajo;
          system("cls");
          listarServicios(listaServicios, tam_serv);
          int auxInt = ingresarEnterosRango("Ingrese un tipo de servicio\n", "Error:\n", 20000, 20003);
          workAuxFecha = loadAndParseDate();
          auxTrabajo.idServicio = auxInt;
          auxTrabajo.id = *idTrabajo;
          auxTrabajo.precio = *idTrabajo;
          auxTrabajo.fecha = workAuxFecha;
          listaTrabajo[indiceTrab] = auxTrabajo;
          printf("Alta realizada con exito\n");
          (*idTrabajo)++;
        } else
        {
          printf("Alta cancelada por el usuario\n");
        }
      }
    }

    todoOk = 1;
  }
  return todoOk;
}

int inicializarTrabajos(eTrabajo lista[], int tam)
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

int buscarPosicionLibreTrabajo(eTrabajo lista[], int tam) {
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

int mostrarTrabajos(eTrabajo lista[], int tam, eServicio listaServ[], int tam_serv, eNotebook listaNotebook[], int tam_not) {

  int retorno = 0;
  if (lista != NULL && tam > 0)
  {
    imprimirEncabezadoListaTrabajos();
    for (int i = 0; i < tam; i++)
    {
      if (!lista[i].isEmpty && (buscarNotebookPorId(listaNotebook, tam_not, lista[i].idNotebook) != -1))
      {
        mostrarTrabajo(lista[i], listaServ, tam_serv);
      }
    }
    retorno = 1;
  }
  return retorno;
}

void mostrarTrabajo(eTrabajo t, eServicio listaServ[], int tam_serv) {

  if (t.isEmpty == 0)
  {

    char descServicio[20];
    cargarDescripcionServicio(listaServ, tam_serv, t.idServicio, descServicio);

    printf("  %-2d    %-2d       %10s       %2d/%2d/%4d   \n",
      t.id,
      t.idNotebook,
      descServicio,
      t.fecha.dia,
      t.fecha.mes,
      t.fecha.anio
    );

  }
}

int hardcodearTrabajo(int* idTrabajo, eTrabajo listaTrabajo[], int tam_trab, eServicio listaServicios[], int tam_serv, eNotebook listaNotebook[], int tam_not, int* pContadorTrabajo)
{
  int todoOk = 0;
  eTrabajo auxTrabajo;
  int idAltaNotebookTrabajo = 0;
  int indiceTrab;
  int indice;
  int flagLugar = 0;
  if (listaTrabajo != NULL && tam_trab > 0 && listaServicios != NULL && tam_serv > 0 && listaNotebook != NULL && tam_not > 0)
  {

    int contadorHarcodeosTrabajos = 0;
    printf("                 ***Hardcodeando trabajos***                \n");
    while (contadorHarcodeosTrabajos < 5 || flagLugar)
    {
      indiceTrab = buscarPosicionLibreTrabajo(listaTrabajo, tam_trab);
      if (indiceTrab == -1) {
        printf("No espacios disponibles para hardcodear trabajos\n");
        flagLugar = 1;
        break;
      } else {
        idAltaNotebookTrabajo = (rand() % (3005 + 1 - 3000) + 3000);
        printf("hardcodeando en el id %d \n", idAltaNotebookTrabajo);

        indice = buscarNotebookPorId(listaNotebook, tam_not, idAltaNotebookTrabajo);
        printf("el indice %d\n", indice);
        if (indice == -1) {

          printf("No encontramos las notebooks para hardcodear trabajos\n");

        } else {

          eFecha workAuxFecha;
          auxTrabajo.isEmpty = 0;
          auxTrabajo.idNotebook = idAltaNotebookTrabajo;

          int auxInt = (rand() % (20003 + 1 - 20000) + 20000);
          workAuxFecha.dia = 1;
          workAuxFecha.mes = 1;
          workAuxFecha.anio = 2021;
          auxTrabajo.idServicio = auxInt;
          auxTrabajo.id = *idTrabajo;
          auxTrabajo.precio = *idTrabajo;
          auxTrabajo.fecha = workAuxFecha;
          listaTrabajo[indiceTrab] = auxTrabajo;

          (*idTrabajo)++;
          contadorHarcodeosTrabajos++;
          *pContadorTrabajo = *pContadorTrabajo + 1;
        }
      }
    }
    todoOk = 1;
  }

  return todoOk;
}

int mostrarTrabajosNotebook(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamcliente)
{
  int todoOk = 0;
  int indice;
  int contadorServicios = 0;
  int idMd = 0;

  if (lista != NULL && tam > 0)
  {

    mostrarNotebooks(lista, tam, listaMarca, tam_marc, listaTipoNotebook, tamTipo, listaCliente, tamcliente);
    printf("Ingrese el Id de la notebook \n");

    scanf("%d", &idMd);
    indice = buscarNotebookPorId(lista, tam, idMd);
    if (indice == -1)
    {
      printf("No se encontro el ID %d en el  sistema\n", idMd);
    } else
    {
      mostrarEncabezadoNotebooks();
      mostrarNotebook(lista[indice], listaMarca, tam_marc, listaTipoNotebook, tamTipo, listaCliente, tamcliente);
      if (lista != NULL && tam > 0)
      {
        imprimirEncabezadoListaTrabajos();
        for (int i = 0; i < tam; i++)
        {
          if (!listaTrabajo[i].isEmpty && listaTrabajo[i].idNotebook == idMd)
          {
            mostrarTrabajo(listaTrabajo[i], listaServicios, tamServicio);
            contadorServicios++;
          }
        }
        if (!contadorServicios) {
          printf("No se registran trabajos realizados a la notebook ingresada\n");
        }
      }
    }
    todoOk = 1;
  }
  return todoOk;
}

int mostrarTotalPrecioServiciosNotebook(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamCliente)
{
  int todoOk = 0;
  int indice;
  int contadorServicios = 0;
  int sumadorPreciosServicios = 0;
  int idMd = 0;

  if (lista != NULL && tam > 0)
  {

    mostrarNotebooks(lista, tam, listaMarca, tam_marc, listaTipoNotebook, tamTipo ,listaCliente, tamCliente);
    printf("Ingrese el Id de la notebook \n");

    scanf("%d", &idMd);
    indice = buscarNotebookPorId(lista, tam, idMd);
    if (indice == -1)
    {
      printf("No se encontro el ID %d en el  sistema\n", idMd);
    } else
    {
      mostrarEncabezadoNotebooks();
      mostrarNotebook(lista[indice], listaMarca, tam_marc, listaTipoNotebook, tamTipo,listaCliente, tamCliente);
      if (lista != NULL && tam > 0)
      {

        for (int i = 0; i < tam; i++)
        {
          if (!listaTrabajo[i].isEmpty && listaTrabajo[i].idNotebook == idMd)
          {
            switch (listaTrabajo[i].idServicio)
            {
            case 20000:
              sumadorPreciosServicios += 2250;
              contadorServicios++;
              break;
            case 20001:
              sumadorPreciosServicios += 10300;
              contadorServicios++;
              break;
            case 20002:
              sumadorPreciosServicios += 5600;
              contadorServicios++;
              break;
            case 20003:
              sumadorPreciosServicios += 4400;
              contadorServicios++;
              break;
            }
          }
        }
        if (!contadorServicios) {
          printf("\nNo se registran trabajos realizados a la notebook ingresada\n");
        } else {
          printf("\nEl monto total percibido por servicios a la notebook ingresada es de $%d por la cantidad de %d trabajos\n", sumadorPreciosServicios, contadorServicios);
        }
      }

    }
    todoOk = 1;
  }
  return todoOk;
}

int mostrarServicioRealizadoANotebooks(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamCliente)
{
  int todoOk = 0;
  int indice;
  int contadorServicios = 0;



  if (lista != NULL && tam > 0 && listaTrabajo != NULL && tamTrabajo > 0 && listaServicios != NULL && tamServicio > 0)
  {

    listarServicios(listaServicios, tamServicio);

    int idServicio = ingresarEnterosRango("Ingrese el Id del servicio \n", "Error\n", 20000, 20003);


    mostrarEncabezadoNotebooks();
    for (int i = 0; i < tam; i++)
    {
      if (!listaTrabajo[i].isEmpty && listaTrabajo[i].idServicio == idServicio)
      {
        indice = buscarNotebookPorId(lista, tam, listaTrabajo[i].idNotebook);
        printf("--------------------------------------------------------------\n");
        mostrarNotebook(lista[indice], listaMarca, tam_marc, listaTipoNotebook, tamTipo, listaCliente, tamCliente);
        mostrarTrabajo(listaTrabajo[i], listaServicios, tamServicio);
        printf("--------------------------------------------------------------\n");
        contadorServicios++;

      }
    }
    if (!contadorServicios) {
      printf("\nNo se registran trabajos de ese tipo realizados realizados\n");
    }
    todoOk = 1;
  }
  return todoOk;
}

int mostrarTrabajosFecha(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamCliente)
{
  int todoOk = 0;
  int contadorServicios = 0;
  if (lista != NULL && tam > 0 && listaTipoNotebook != NULL &&listaTrabajo !=NULL && listaServicios !=NULL && listaMarca !=NULL && tamTrabajo >0 && tam_marc >0 && tamTipo >0 && tamServicio >0)
  {
  system("cls");
  eFecha auxFecha = loadAndParseDate();
    imprimirEncabezadoListaTrabajosFecha();
    for (int i = 0; i < tam; i++)
    {
      if (!listaTrabajo[i].isEmpty && listaTrabajo[i].fecha.dia == auxFecha.dia && listaTrabajo[i].fecha.mes == auxFecha.mes && listaTrabajo[i].fecha.anio == auxFecha.anio)
      {
        mostrarTrabajo(listaTrabajo[i], listaServicios, tamServicio);
        contadorServicios++;
      }
    }
    if (!contadorServicios) {
      printf("No se registran trabajos realizados en la fecha seleccionada\n");
    }
    todoOk = 1;
  }
  return todoOk;
}

