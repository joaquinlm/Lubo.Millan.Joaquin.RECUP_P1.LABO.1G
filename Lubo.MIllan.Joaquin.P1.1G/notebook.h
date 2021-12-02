#include "marca.h"
#include "tipoNotebook.h"
#include "cliente.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    int precio;
    int isEmpty;
    int idCliente;
} eNotebook;



int inicializarNotebooks(eNotebook lista[], int tam);
void mostrarNotebook(eNotebook n, eMarca listaMarca[], int tam_marca, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente);
int mostrarNotebooks(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente);
int bajaNotebook(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente);
int buscarNotebookPorId(eNotebook lista[], int tam, int id);
int modificarNotebook(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, cliente listaCliente[], int tamCliente);
int altaNotebook(eNotebook lista[], int tam, int* Id, eMarca listMarca[], int tamMArca, eTipoNotebook listaTipoNotebook[], int tamTipo, cliente listaCliente[], int tamCliente);
int buscarPosicionLibre(eNotebook list[], int len);
int ordenarNotebooksMarcaPrecio(eNotebook list[], int tam);

int mostrarNotebooksUnMarcaUnTipo(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente);
int mostrarNotebooksUnMarca(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamClientes);
int mostrarNotebooksUnTipo(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamClientes);
int hardcodearNotebooks(eNotebook lista[], int tam, int* Id, int* contador, cliente listaCliente[], int tamClientes);
int mostrarNotebookMasBarata(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo ,cliente listaCliente[], int tamClientes);
void mostrarDesgloseMarcas(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamClientes);
void mostrarMarcaMasElegida(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo);
#endif // NOTEBOOK_H_INCLUDED
