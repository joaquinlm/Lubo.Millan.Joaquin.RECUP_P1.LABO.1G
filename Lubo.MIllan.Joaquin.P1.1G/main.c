#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "notebook.h"
#include "marca.h"
#include "tipoNotebook.h"
#include "inputsValidados.h"
#include "servicio.h"
#include "trabajo.h"
#include "encabezados.h"
#include "cliente.h"

#define TAM_NOT 100
#define TAM_CLI 100
#define TAM_MARC 4
#define TAM_TIPO 4
#define TAM_SERV 4
#define TAM_TRAB 100

int main()
{

    srand(time(NULL));
    eMarca listaMarca[TAM_MARC] =
    {
        {1000, "Acer"},
        {1001, "Asus"},
        {1002, "Compaq"},
        {1003, "HP"}

    };
    eTipoNotebook listaTipo[TAM_TIPO] =
    {
        {5000, "Gamer"},
        {5001, "Disenio"},
        {5002, "Normalita"},
        {5003, "Ultrabook"}
    };
    eServicio listaServicio[TAM_SERV] =
    {
        {20000, "Bateria", 2250},
        {20001, "Display", 10300},
        {20002, "Fuente", 5600},
        {20003, "Mantenimiento", 4400}
    };

    cliente listaClientes[TAM_CLI];
    inicializarClientes(listaClientes, TAM_CLI);

    eNotebook lista[TAM_NOT];
    inicializarNotebooks(lista, TAM_NOT);

    eTrabajo listaTrabajo[TAM_TRAB];
    inicializarTrabajos(listaTrabajo, TAM_TRAB);

    int notebookIdAux = 3000;
    int trabajoIdAux = 8000;
    int contadorNotebooks = 0;
    int contadorTrabajos = 0;
    char seguir = 's';
    do
    {
        int opcion = imprimirMenu();
        ;
        switch (opcion)
        {
        case 0:
            hardcodearNotebooks(lista, TAM_NOT, &notebookIdAux, &contadorNotebooks, listaClientes, TAM_CLI);
            opcion = 0;
            break;
        case 1:

            mostrarMarcas(listaMarca, TAM_MARC);
            if (altaNotebook(lista, TAM_NOT, &notebookIdAux, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI))
            {
                contadorNotebooks++;
            }
            opcion = 0;
            break;

        case 2:

            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks para modificar\n");
                opcion = 0;
                break;
            } else
            {
                ordenarNotebooksMarcaPrecio(lista, TAM_NOT);
                modificarNotebook(lista, TAM_NOT, listaTipo, TAM_TIPO, listaMarca, TAM_MARC, listaClientes, TAM_CLI);

                opcion = 0;
                break;
            }
        case 3:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks para dar de baja\n");
                opcion = 0;
                break;
            } else
            {
                ordenarNotebooksMarcaPrecio(lista, TAM_NOT);
                if (bajaNotebook(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI)) {
                    contadorNotebooks--;
                }
                opcion = 0;
                break;
            }

        case 4:

            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks para mostrar\n");
                opcion = 0;
                break;
            } else
            {
                ordenarNotebooksMarcaPrecio(lista, TAM_NOT);
                mostrarNotebooks(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                opcion = 0;
                break;
            }
        case 5:
            system("cls");
            mostrarMarcas(listaMarca, TAM_MARC);
            opcion = 0;
            break;

        case 6:
            system("cls");
            mostarTiposNotebook(listaTipo, TAM_TIPO);
            opcion = 0;
            break;
        case 7:
            system("cls");
            listarServicios(listaServicio, TAM_SERV);
            opcion = 0;
            break;

        case 8:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks a las cuales darle de alta un trabajo\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                altaTrabajo(&trabajoIdAux, listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                contadorTrabajos++;
                opcion = 0;
                break;
            }
        case 9:
            if (contadorTrabajos < 1)
            {
                printf("No hay trabajos para listar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostrarTrabajos(listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, lista, TAM_NOT);
                opcion = 0;
                break;
            }
        case 10:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks que mostrar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostarTiposNotebook(listaTipo, TAM_TIPO);
                mostrarNotebooksUnTipo(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                break;
            }

        case 11:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks que mostrar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostrarMarcas(listaMarca, TAM_MARC);
                mostrarNotebooksUnMarca(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                break;
            }
        case 12:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks que mostrar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostrarMarcas(listaMarca, TAM_MARC);
                mostarTiposNotebook(listaTipo, TAM_TIPO);
                mostrarNotebooksUnMarcaUnTipo(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                break;
            }
        case 13:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks que mostrar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostrarNotebookMasBarata(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                break;
            }
        case 14:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks que mostrar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostrarDesgloseMarcas(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO, listaClientes, TAM_CLI);
                break;
            }

        case 15:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks que mostrar\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                mostrarMarcaMasElegida(lista, TAM_NOT, listaMarca, TAM_MARC, listaTipo, TAM_TIPO);
                break;
            }
        case 16:
            if (contadorNotebooks < 1)
            {
                printf("No hay notebooks a las cuales darle de alta un trabajo\n");
                opcion = 0;
                break;
            } else
            {
                system("cls");
                hardcodearTrabajo(&trabajoIdAux, listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, lista, TAM_NOT, &contadorTrabajos);
                opcion = 0;
                break;
            }
        case 17:
            if (contadorNotebooks < 1 || contadorTrabajos < 1)
            {
                printf("No hay trabajos para mostrar\n");
                opcion = 0;
                break;
            } else
            {
                ordenarNotebooksMarcaPrecio(lista, TAM_NOT);
                mostrarTrabajosNotebook(lista, TAM_NOT, listaTipo, TAM_TIPO, listaMarca, TAM_MARC, listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, listaClientes, TAM_CLI);
                opcion = 0;
                break;
            }
        case 18:
            if (contadorNotebooks < 1 || contadorTrabajos < 1)
            {
                printf("No hay trabajos para mostrar\n");
                opcion = 0;
                break;
            } else
            {
                ordenarNotebooksMarcaPrecio(lista, TAM_NOT);
                mostrarTotalPrecioServiciosNotebook(lista, TAM_NOT, listaTipo, TAM_TIPO, listaMarca, TAM_MARC, listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, listaClientes, TAM_CLI);
                opcion = 0;
                break;
            }
        case 19:
            if (contadorNotebooks < 1 || contadorTrabajos < 1)
            {
                printf("No hay trabajos para mostrar\n");
                opcion = 0;
                break;
            } else
            {
                ordenarNotebooksMarcaPrecio(lista, TAM_NOT);
                mostrarServicioRealizadoANotebooks(lista, TAM_NOT, listaTipo, TAM_TIPO, listaMarca, TAM_MARC, listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, listaClientes, TAM_CLI);
                opcion = 0;
                break;
            }
        case 20:
            if (contadorNotebooks < 1 || contadorTrabajos < 1)
            {
                printf("No hay trabajos para mostrar\n");
                opcion = 0;
                break;
            } else
            {                
                mostrarTrabajosFecha(lista, TAM_NOT, listaTipo, TAM_TIPO, listaMarca, TAM_MARC, listaTrabajo, TAM_TRAB, listaServicio, TAM_SERV, listaClientes, TAM_CLI);
                opcion = 0;
                break;
            }
        case 21:
            printf("Ha seleccionado salir\n");
            seguir = 'n';
            break;

        default:
            printf("Opcion incorrecta\n");
            opcion = 0;
            break;
        }
        fflush(stdin);
        system("pause");

    } while (seguir == 's');

    return 0;
}
