#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
  int id;
  char nombre[20];
  char apellido[20];
  double cuil;
  int isEmpty;
} cliente;



int inicializarClientes(cliente lista[], int tam);
int buscarPosicionLibreCliente(cliente lista[], int tam);
int altaCliente(cliente lista[], int tam, int* Id);
int buscarClientePorId(cliente lista[], int tam, int id);
int bajaCliente(cliente lista[], int tam);


void mostrarCliente(cliente cliente, int tam);
int mostrarClientes(cliente lista[], int tam);

int modificarCliente(cliente lista[], int tam);

int cargarNombreCliente(cliente lista[], int tam, int idCliente, char nombre[]);
int cargarApellidoCliente(cliente lista[], int tam, int idCliente, char apellido[]);



#endif // CLIENTE_H_INCLUDED