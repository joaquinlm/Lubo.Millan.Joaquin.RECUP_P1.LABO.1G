

#ifndef INPUTSVALIDADOS_H_INCLUDED
#define INPUTSVALIDADOS_H_INCLUDED

int imprimirMenu();

int ingresarEnterosRango(char *mensaje, char *mensajeError, int lInf, int lSup);
int ingresarValidarCadena(char *vec, int tam, char mensaje[],
                          char mensajeError[], int minLen, int maxLen);
void ingresarFlotantesRango(double *pInput, char mensaje[], char mensajeError[],
                            double lInf, double lSup);
int ingresarEnterosLongRango(char mensaje[], char mensajeError[],
                             long long lInf, long long lSup);
int checkNum(char vec[]);

#endif  // INPUTSVALIDADOS_H_INCLUDED
