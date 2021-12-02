#include "dia.h"
#include <stdio.h>
eFecha loadAndParseDate() {
  eFecha auxFecha;
  int auxDia;
  int auxMes;
  int auxAnio;
  int checkscan;
  do
  {
  printf("Ingrese la fecha(formato valido: 01/12/2020 | rango valido 01/01/1999-31/12/2050 ) ");
  checkscan = scanf("%2d/%2d/%4d", &auxDia, &auxMes, &auxAnio);

  } while(checkscan < 3 ||auxDia<0||auxDia>31||auxMes<0||auxMes>12||auxAnio<1999||auxAnio>2050);
  auxFecha.dia = auxDia;
  auxFecha.mes = auxMes;
  auxFecha.anio = auxAnio;
  return auxFecha;

}
