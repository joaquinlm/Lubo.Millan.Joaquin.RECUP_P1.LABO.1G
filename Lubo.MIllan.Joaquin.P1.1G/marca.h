#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
typedef struct{
    int id;
    char descripcion[20];
} eMarca;

void mostrarMarca(eMarca marca);
int mostrarMarcas(eMarca lista[], int tam);
int esMarcaValida(eMarca lista[], int tam, int id);
int precargarMarca(eMarca lista[], int tam, int cant, char marcas[][20]);
int cargarDescripcionMarca(eMarca lista[], int tam, int idMarca, char descripcion[]);
#endif // MARCA_H_INCLUDED
