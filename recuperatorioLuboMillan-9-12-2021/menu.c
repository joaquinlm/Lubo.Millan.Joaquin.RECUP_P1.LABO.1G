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
    
    printf("1. Alta de cliente\n");
    printf("2. Modificar datos de cliente\n");
    printf("3. Baja de cliente\n\n");

    printf("4. Nuevo alquiler\n");
    printf("5. Saldar alquiler\n\n");

    printf("6. Mostrar el equipo más elegido\n\n");

    printf("7. Imprimir cliente\n");
    printf("8. Imprimir alquilers\n\n");

    printf("9. Informar promedio real de dias de alquiler\n");
   // printf("10. Informar alquilers\n");

    printf("11. Salir\n\n");
    
    printf("Indique la opcion: ");
    fflush(stdin);
    seleccion = ingresarEnterosRango("", "Error ingrese una opcion entre 1 y 11 ", 0, 11);
    return seleccion;
}


 int imprimirOpcionesModificacionCliente() 
{
  printf("1-Modificar nombre\n");
  printf("2-Modificar apellido\n");
 
  printf("3-Cancelar\n\n");
  int opcion = ingresarEnterosRango("Seleccione una opcion\n", "Error. El rango valido de opciones es: 1-4\n", 1, 3);

  return opcion;
}