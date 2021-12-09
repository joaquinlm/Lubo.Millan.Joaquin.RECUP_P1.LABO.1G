#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputsValidados.h"
/**
 * \brief funci�n para ingreso y validacion de enteros dentro de un rango. La validaci�n se realiza a trav�s de un loop do while que verifica el retorn de la funci�n scanf.
 * scanf retorna el n�mero de campos correctamente leidos y asignados, en este caso 1 si se ingresa un entero.
 *
 * \param Input puntero al entero a asignar
 * \param mensaje array de caracteres.
 * \param mensajeError array de caracteres.
 * \param lInf Entero para setear el limite inferior de la validacion.
 * \param lSup Entero para setear el limite superior de la validacion.
 */

int ingresarEnterosRango(char mensaje[], char mensajeError[], int lInf, int lSup)
{
    int input;
    int intCheck;
    do
    {

        printf("%s\n", mensaje);
        fflush(stdin);
        intCheck = scanf("%d", &input);

        if (intCheck == 0 || input < lInf || input > lSup)
        {
            printf("%s", mensajeError);
        }
    } while (intCheck == 0 || input < lInf || input > lSup);

    return input;
}


/**
 \brief funci�n para ingreso y validacion de cadenas. Permite setear una extension m�nima y una maxima. Antes de asignarse en destino, se guarda en un buffer para evitar overflow.
 * checkNum es una funcion filtro que impide que se guarden cadenas que contengan m�s que letras o espacios.
 * \param vec puntero a array de caracteres.
 * \param tam entero largo del array.
 * \param mensaje Mensaje seteable.
 * \param mensajeError mensaje seteable para casos de error.
 * \param minLen entero para setear el largo m�nimo
 * \param maxLen entero para setear el largo m�ximo
 * \return
 */
int ingresarValidarCadena(char *vec, int tam, char mensaje[], char mensajeError[], int minLen, int maxLen)
{
    int todoOk = 0;
    char charBuffer[100];
    if (vec != NULL && tam > 0)
    {
        printf("%s\n", mensaje);
        fflush(stdin);
        gets(charBuffer);
        while (strlen(charBuffer) > maxLen || strlen(charBuffer) < minLen || checkNum(charBuffer) == -1)
        {
            printf("%s\n", mensajeError);
            fflush(stdin);
            gets(charBuffer);
        }
        strcpy(vec, charBuffer);
        todoOk = 1;
    }
        return todoOk;
}
/**
 * \brief Funci�n encargada de imprimir el menu de opciones en pantalla.
 * \return retorna un entero para uso en el switch de main,
 */

/**
 * \brief Funci�n para buscar posiciones libres en un array de estructuras.
 * \param list puntero al array de estructuras.
 * \param len largo del array.
 * \return indice libre en el array
 */

/**
 * brief funci�n para ingreso y validacion de floats dentro de un rango. La validaci�n se realiza a trav�s de un loop do while que verifica el retorn de la funci�n scanf.
 * scanf retorna el n�mero de campos correctamente leidos y asignados, en este caso 1 si se ingresa un float.
 *
 * \param pInput puntero a float de destino.
 * \param mensaje Mensaje seteable.
 * \param mensajeError mensaje seteable para casos de error.
 * \param lInf entero para setear el largo m�nimo
 * \param lSup entero para setear el largo m�ximo
 */
void ingresarFlotantesRango(double *pInput, char mensaje[], char mensajeError[], double lInf, double lSup)
{
    double input;
    int intCheck;
    do
    {

        printf("%s\n", mensaje);
        fflush(stdin);
        intCheck = scanf("%lf", &input);

        if (intCheck == 0 || input < lInf || input > lSup)
        {
            printf("%s", mensajeError);
        }
    } while (intCheck == 0 || input < lInf || input > lSup);

    *pInput = input;
}

/**
 * \brief funci�n para modificar una instancia de Employee. Selecciona la instancia por id.
 * \param list puntero a Array de Employee.
 * \param len Largo del array.
 * \param id entero para seleccionar el id
 * \return retorna 0 en caso de �xito, -1 en caso de error.
 */
/*int modificarEmpleado(Employee *list, int len, int id)
{
    int todoOk = -1;
    int idMd = 0;
    if (list != NULL && len > 0)
    {
        int idMd = findEmployeeById(list, len, id);
        if (idMd == -1)
        {
            printf("no se encontro el ID\n");
        }
        else
        {
            char nameBuffer[21];
            char lastNameBuffer[21];
            float salaryBuffer;
            int sectorBuffer;

            ingresarValidarCadena(nameBuffer, 21, "Ingrese el nuevo nombre", "Error. Reingrese el nuevo nombre", 3, 21);
            ingresarValidarCadena(lastNameBuffer, 21, "Ingrese el nuevo apellido", "Error. Reingrese el nuevo apellido", 3, 21);
            ingresarFlotantesRango(&salaryBuffer, "Ingrese el nuevo salario", "Error, reingrese el nuevo salario", 0.1, 1000000);
            ingresarEnterosRango(&sectorBuffer, "Ingrese el nuevo sector", "Error, reingrese el nuevo sector", 1, 5);
            strcpy(list[idMd].name, nameBuffer);
            strcpy(list[idMd].lastName, lastNameBuffer);
            list[idMd].salary = salaryBuffer;
            list[idMd].sector = sectorBuffer;

            printf("Modificacion realizada con exito\n");
        }
        todoOk = 0;
    }


    return todoOk;
}*/
/**
 * \brief funcion para chequear que una cadena contenga s�lo letras o espacios.
 * \param vec puntero a array de caracteres.
 * \return retorna -1 en caso de error (por ej: se encontr� un n�mero) y 0 en caso de �xito.
 */
int checkNum(char *vec)
{
    int todoOk;
    for (int i = 0; i < strlen(vec); i++)
    {
        if (isalpha(vec[i]) || vec[i] == ' ')
        {
            todoOk = 0;
        }
        else
        {

            todoOk = -1;
            break;
        }
    }

    return todoOk;
}


