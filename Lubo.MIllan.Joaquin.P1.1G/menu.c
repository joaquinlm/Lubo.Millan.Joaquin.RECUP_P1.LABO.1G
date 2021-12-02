#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "inputsValidados.h"

int imprimirMenu()
{
    int seleccion;
    system("cls");

    printf("MENU DE OPCIONES\n\n");
    printf("1. Alta de Notebooks\n");
    printf("2. Modificacion de Notebooks\n");
    printf("3. Baja de Notebooks\n");
    printf("4. Listar Notebooks\n");
    printf("5. Listar marcas de Notebook\n");
    printf("6. Listar tipos de Notebook\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n");
    printf("10. Listar notebooks por tipo\n");
    printf("11. Listar notebooks por marca\n");
    printf("12. Listar notebooks por tipo y marca\n");
    printf("13. Mostrar notebook/s mas barata/s\n");
    printf("14. Mostrar listado de las notebooks separadas por marca.\n");
    printf("15. Mostrar la marca mas elegida\n");
    printf("16. Hardcodear trabajos\n");
    printf("17. Mostrar todos los trabajos realizados a una notebook\n");
    printf("18. Mostrar el monto total por todos los trabajos realizados a una notebook\n");
    printf("19. Mostrar detalle de notebooks segun servicio\n");
    printf("20. Filtrar trabajos segun fecha\n");
    printf("21. Salir\n\n");
    printf("00. MENU TEST HARDCODEO\n\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    seleccion = ingresarEnterosRango("", "Error ingrese una opcion entre 1 y 19 ", 0, 21);
    return seleccion;
}
int imprimirMenuCargaNotebookM()
{
    int seleccion;
    system("cls");

    printf("MENU DE OPCIONES\n\n");
    printf("1. Alta de Notebooks\n");
    printf("2. Modificacion de Notebooks\n");
    printf("3. Baja de Notebooks\n");
    printf("4. Listar Notebooks\n");
    printf("5. Listar marcas de Notebook\n");
    printf("6. Listar tipos de Notebook\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n");
    printf("10. Salir\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    seleccion = ingresarEnterosRango("", "Error ingrese una opcion entre 1 y 10 ", 1, 20);
    return seleccion;
}

