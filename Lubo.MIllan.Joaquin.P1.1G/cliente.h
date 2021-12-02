#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct {
int id;
char nombre[20];
char sexo;
int isEmpty;
} cliente;

int inicializarClientes(cliente lista[], int tam);
int buscarPosicionLibreCliente(cliente lista[], int tam);
int cargarNombreCliente(cliente listaCliente[], int tamCliente, int idCliente, char nombre[]);

#endif // CLIENTE_H_INCLUDED
