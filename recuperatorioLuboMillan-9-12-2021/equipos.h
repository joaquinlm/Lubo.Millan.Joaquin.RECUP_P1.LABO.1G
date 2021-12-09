#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

typedef struct equipos
{
  int id;
  char descripcion[20];
}equipos;

void mostrarEquipos(equipos equipos);
int mostrarEquiposs(equipos lista[], int tam);
int esEquiposValida(equipos lista[], int tam, int id);
int precargarEquipos(equipos lista[], int tam, int cant, char equipos[][20]);
int cargarDescripcionEquipos(equipos lista[], int tam, int idEquipos, char descripcion[]);

#endif // EQUIPOS_H_INCLUDED
