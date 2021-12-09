#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "alquiler.h"
#include "cliente.h"
#include "equipos.h"
#include "menu.h"
#include "operadores.h"

#define TAM_CLIENTE 50
#define TAM_ALQUILER 50
#define TAM_OPERADOR 5
#define TAM_EQUIPO 3
#define ALQUILADO 1
#define FINALIZADO 0

int main() {
    operadores listaOperadores[TAM_OPERADOR] = {{1000, "Franco"},
                                                {1001, "Juan"},
                                                {1002, "Pablo"},
                                                {1003, "Renzo"},
                                                {1004, "Tomas"}

    };
    equipos listaEquipo[TAM_EQUIPO] = {
        {5000, "Amoladora"}, {5001, "Mezcladora"}, {5002, "Taladro"}};

    // ARRAY DE ESTRUCTURAS 1 E INICIALIZACION
    cliente listaCliente[TAM_CLIENTE];
    inicializarClientes(listaCliente, TAM_CLIENTE);

    // ARRAY DE ESTRUCTURAS 2E INICIALIZACION
    alquiler listaAlquiler[TAM_ALQUILER];

    inicializarAlquiler(listaAlquiler, TAM_ALQUILER);

    int clienteIdAux = 3000;
    int alquilerIdAux = 8000;
    int contadorClientes = 0;
    int contadorAlquileres = 0;
    char seguir = 's';
    do {
        int opcion = imprimirMenu();

        switch (opcion) {
            case 1:

                if (altaCliente(listaCliente, TAM_CLIENTE, &clienteIdAux)) {
                    contadorClientes++;
                }
                opcion = 0;
                break;

            case 2:

                if (contadorClientes < 1) {
                    printf("No hay clientes para modificar\n");
                    opcion = 0;
                    break;
                } else {
                    modificarCliente(listaCliente, TAM_CLIENTE);

                    opcion = 0;
                    break;
                }
            case 3:
                if (contadorClientes < 1) {
                    printf("No hay clientes para dar de baja\n");
                    opcion = 0;
                    break;
                } else {
                    if (bajaCliente(listaCliente, TAM_CLIENTE)) {
                        contadorClientes--;
                    }
                    opcion = 0;
                    break;
                }

            case 4:
                if (contadorClientes < 1) {
                    printf("No hay clientes para asignarles alquilers\n");
                    opcion = 0;
                    break;
                } else {
                    if (altaAlquiler(listaAlquiler, TAM_ALQUILER,
                                     &alquilerIdAux, listaCliente, TAM_CLIENTE,
                                     listaOperadores, TAM_OPERADOR, listaEquipo,
                                     TAM_EQUIPO)) {
                        contadorAlquileres++;
                    }
                    opcion = 0;
                    break;
                }
            case 5:
                if (contadorAlquileres < 1) {
                    printf("No hay alquilers para saldar\n");
                    opcion = 0;
                    break;
                } else {
                    if (saldarAlquiler(listaAlquiler, TAM_ALQUILER,
                                       &alquilerIdAux, listaCliente,
                                       TAM_CLIENTE)) {
                        contadorAlquileres++;
                    }
                }
                opcion = 0;
                break;
            case 6:
                if (contadorAlquileres < 1) {
                    printf("No hay alquileres para informar\n");
                    opcion = 0;
                    break;
                } else {
                    mostrarEquiposMasElegidos(listaAlquiler, TAM_ALQUILER,
                                              listaEquipo, TAM_EQUIPO);
                }
                opcion = 0;
                break;
            case 7:
                if (contadorClientes < 1) {
                    printf("No hay clientes para mostrar\n");
                    opcion = 0;
                    break;
                } else {
                    system("cls");
                    mostrarClientes(listaCliente, TAM_CLIENTE);
                    opcion = 0;
                    break;
                }
            case 8:
                if (contadorClientes < 1 || contadorAlquileres <1) {
                    printf("No hay clientes o alquileres para mostrarpara mostrar\n");
                    opcion = 0;
                    break;
                } else {
                    system("cls");
                    mostrarAlquilers(listaAlquiler, TAM_ALQUILER, listaCliente, TAM_CLIENTE);
                    opcion = 0;
                    break;
                }
            case 9:
                if (contadorClientes < 1 || contadorAlquileres <1) {
                    printf("No hay clientes o alquileres para mostrarpara mostrar\n");
                    opcion = 0;
                    break;
                } else {
                    system("cls");
                    mostrarPromedioTempoReal(listaAlquiler, TAM_ALQUILER);
                    opcion = 0;
                    break;
                }

            case 11:;
                char sale;
                printf("Confirma que desea salir? s/n\n");
                fflush(stdin);
                scanf("%1c", &sale);
                if (sale != 's') {
                    printf("Cierre cancelado\n");

                    break;
                } else {
                    printf("Ha seleccionado salir.\n");
                    seguir = 'n';
                    break;
                }

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
