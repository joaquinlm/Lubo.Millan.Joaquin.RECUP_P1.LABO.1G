#include "encabezados.h"
#include <stdio.h>
#include <stdlib.h>
void imprimirEncabezadoListaTrabajos() {
  system("cls");
  printf("|         *** Listado de Trabajos***                 |\n");
  printf("|------------------------------------------------|\n");
  printf("|  ID     Idnotebook     descripcion      Fecha  |\n");
  printf("|------------------------------------------------|\n\n");
}

void imprimirEncabezadoAltaTrabajo() {
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Alta Trabajo***               \n");
  printf("|---------------------------------------------|\n\n");
}

void mostrarEncabezadoNotebooks() {
  system("cls");
  printf("|         *** Listado de Notebooks***                        |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Marca       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}

void mostrarEncabezadoModificacionNotebook()
{
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("          ***Modificacion Notebook***          \n");
  printf("|---------------------------------------------|\n\n");
}

void imprimirEncabezadoAltaNotebook() {
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Alta Notebook***               \n");
  printf("|---------------------------------------------|\n\n");
}

void imprimirEncabezadoBajaNotebook()
{
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Baja Notebook***               \n");
  printf("|---------------------------------------------|\n\n");
}

void mostrarEncabezadoNotebooksSinTitulo() {  
  printf("|----------------------------------------------------|\n");
  printf("|  ID     Modelo     Marca       Tipo         Precio |\n");
  printf("|----------------------------------------------------|\n\n");
}
void mostrarEncabezadoHardcodeo(){
  system("cls");
  printf("|---------------------------------------------|\n");
  printf("             ***Hardcodeo Notebook***               \n");
  printf("|---------------------------------------------|\n\n");
}
void mostrarEncabezadoMasBarata(){
   system("cls");
  printf("|         *** Notebook/s mas barata/s***                        |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Marca       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}
void mostrarEncabezadoAcer(){
   
  printf("\n|         *** Notebook/s marca Acer***                        |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Marca       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}
void mostrarEncabezadoAsus(){
  
  printf("\n|         *** Notebook/s marca Asus***                        |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Marca       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}
void mostrarEncabezadoCompaq(){
  
  printf("\n|         *** Notebook/s marca Compaq***                        |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Marca       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}
void mostrarEncabezadoHP(){
  
  printf("\n|          *** Notebook/s marca HP***                       |\n");
  printf("|------------------------------------------------------------|\n");
  printf("|  ID     Modelo              Marca       Tipo        Precio |\n");
  printf("|------------------------------------------------------------|\n\n");
}
void mostrarEncabezadoMasElegidas(){
   system("cls");
  printf("|             *** Marca/s mas elegidas/s***                    |\n");
  printf("|--------------------------------------------------------------|\n\n");

}
void imprimirEncabezadoListaTrabajosFecha(){
  
  
  printf("|    *** Trabajos en la fecha seleccionada***    |\n");
  printf("|------------------------------------------------|\n");
  printf("|  ID     Idnotebook     descripcion      Fecha  |\n");
  printf("|------------------------------------------------|\n\n");
}