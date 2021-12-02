#ifndef DIA_H_INCLUDED
#define DIA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

eFecha loadAndParseDate();


#endif // DIA_H_INCLUDED
