#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
    int precio;
} eServicio;

int listarServicios(eServicio lista[], int tam);
int cargarDescripcionServicio(eServicio listaServicios[], int tam_serv, int idServicio, char descServicio[]);

#endif // SERVICIO_H_INCLUDED
