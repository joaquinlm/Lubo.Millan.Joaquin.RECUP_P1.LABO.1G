#ifndef OPERADORES_H_INCLUDED
#define OPERADORES_H_INCLUDED

typedef struct 
{
  int id;
  char nombre[20];
}operadores;


//int mostrarListaOperadores(operadores lista[], int tam);
int cargarDescripcionOperadores(operadores lista[], int tam, int idOperadores, char descripcion[]);

#endif // OPERADORES_H_INCLUDED
