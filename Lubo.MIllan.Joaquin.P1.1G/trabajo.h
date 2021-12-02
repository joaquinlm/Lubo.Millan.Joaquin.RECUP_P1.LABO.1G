#include "servicio.h"
#include "dia.h"
#include "inputsValidados.h"
#include "notebook.h"


#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct {
    int id;
    int idNotebook;
    int idServicio;
    int precio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

int altaTrabajo(int* idTrabajo, eTrabajo listaTrabajo[], int tam_trab, eServicio listaServicios[], int tam_serv, eNotebook listaNotebook[], int tam_not, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente);
int inicializarTrabajos(eTrabajo lista[], int tam);
int buscarPosicionLibreTrabajo(eTrabajo lista[], int tam);
void mostrarTrabajo(eTrabajo t, eServicio listaServ[], int tam_serv);
int mostrarTrabajos(eTrabajo lista[], int tam, eServicio listaServ[], int tam_serv, eNotebook listaNotebook[], int tam_not) ;
int hardcodearTrabajo(int* idTrabajo, eTrabajo listaTrabajo[], int tam_trab, eServicio listaServicios[], int tam_serv, eNotebook listaNotebook[], int tam_not, int* pContadorTrabajo);
int mostrarTrabajosNotebook(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamcliente);
int mostrarTotalPrecioServiciosNotebook(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamCliente);
int mostrarServicioRealizadoANotebooks(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamCliente);
int mostrarTrabajosFecha(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, eTrabajo listaTrabajo[], int tamTrabajo, eServicio listaServicios[], int tamServicio, cliente listaCliente[], int tamCliente);

#endif // TRABAJO_H_INCLUDED
