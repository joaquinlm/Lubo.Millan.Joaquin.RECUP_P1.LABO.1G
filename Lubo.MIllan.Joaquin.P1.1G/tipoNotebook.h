#ifndef TIPONOTEBOOK_H_INCLUDED
#define TIPONOTEBOOK_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipoNotebook;

int mostarTiposNotebook (eTipoNotebook lista[], int tam);
int cargarDescripcionTipo(eTipoNotebook lista[], int tam, int idTipo, char descripcion[]);
#endif // TIPONETBOOK_H_INCLUDED
