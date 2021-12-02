#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#include "notebook.h"
#include "inputsValidados.h"
#include "tipoNotebook.h"
#include "encabezados.h"
#include "cliente.h"


int inicializarNotebooks(eNotebook lista[], int tam)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

void mostrarNotebook(eNotebook n, eMarca listaMarca[], int tam_marca, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente)
{

    if (n.isEmpty == 0)
    {
        char descMarca[20];
        char descTipo[20];
        char nombre[20];
        cargarDescripcionMarca(listaMarca, tam_marca, n.idMarca, descMarca);
        cargarNombreCliente(listaCliente, tamCliente, n.idCliente, nombre);
        cargarDescripcionTipo(listaTipo, tam_tipo, n.idTipo, descTipo);

        printf("  %-2d    %-15s  %-15s   %-7s   %10s    $%d   \n",
            n.id,
            n.modelo,
            nombre,
            descMarca,
            descTipo,
            n.precio);
    }
}

int mostrarNotebooks(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        mostrarEncabezadoNotebooks();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty)
            {   
                char auxNombre[20];
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            }
        }
        retorno = 1;
    }
    return retorno;
}

int altaNotebook(eNotebook lista[], int tam, int* Id, eMarca listMarca[], int tamMArca, eTipoNotebook listaTipoNotebook[], int tamTipo, cliente listaCliente[], int tamCliente)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    cliente auxcliente; 
    int indice;
    int indiceCliente;
    char auxClienteNombre[20];
    if (lista != NULL && tam > 0)
    {
        imprimirEncabezadoAltaNotebook();
        indice = buscarPosicionLibre(lista, tam);
        indiceCliente = buscarPosicionLibreCliente(listaCliente, tamCliente);
        if (indice == -1)
        {
            printf("No espacios disponibles\n");
        } else
        {
            printf("Ingrese el Modelo:\n");
            scanf("%s", auxNotebook.modelo);
            ingresarValidarCadena(auxClienteNombre, 20, "Ingrese nombre del cliente (solo caracteres alfabeticos o espacios, hasta 20 caracteres)", "Error. Ingrese el nombre del cliente (solo caracteres alfabeticos o espacios, hasta 20 caracteres)", 3, 20);
            mostrarMarcas(listMarca, tamMArca);
            auxNotebook.idMarca = ingresarEnterosRango("\nIngrese ID de marca:\n", "Error:\n", 1000, 1003);
            mostarTiposNotebook(listaTipoNotebook, tamTipo);
            auxNotebook.idTipo = ingresarEnterosRango("\nIngrese tipo:\n", "Error:\n", 5000, 5003);
            auxNotebook.precio = ingresarEnterosRango("\nIngrese precio (entre $20000 y $500000):\n", "Error:\n", 20000, 500000);
            auxNotebook.isEmpty = 0;
            auxNotebook.id = *Id;
            auxNotebook.idCliente = *Id+30000;
            auxcliente.id = *Id+30000;
            strcpy(auxcliente.nombre, auxClienteNombre);
            (*Id)++;
            lista[indice] = auxNotebook;
            listaCliente[indiceCliente] = auxcliente;
            printf("Alta realizada con exito\n");
        todoOk = 1;
        }
    }
    return todoOk;
}

int bajaNotebook(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente)
{
    int todoOk = 0;
    int idRm;
    char confirma;
    if (lista != NULL && tam > 0)
    {

        imprimirEncabezadoBajaNotebook();
        mostrarNotebooks(lista, tam, listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
        printf("Ingrese el Id de la notebook \n");
        scanf("%d", &idRm);

        int indice = buscarNotebookPorId(lista, tam, idRm);
        if (indice == -1)
        {
            printf("No se encontro el ID %d en el  sistema\n", idRm);
        } else
        {
            mostrarEncabezadoNotebooks();
            mostrarNotebook(lista[indice], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            printf("confirma que desea dar de baja?: s-n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
                printf("Baja realizada con exito\n");
            } else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}

int buscarPosicionLibre(eNotebook lista[], int tam)
{
    int todoOk = -1;
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].isEmpty == 1)
        {
            todoOk = i;
            break;
        }
    }
    return todoOk;
}

int buscarNotebookPorId(eNotebook lista[], int tam, int id)
{
    int retorno = -1;
    if (lista != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int modificarNotebook(eNotebook lista[], int tam, eTipoNotebook listaTipoNotebook[], int tamTipo, eMarca listaMarca[], int tam_marc, cliente listaCliente[], int tamCliente)
{
    int todoOk = 0;
    int indice;
    int idMd = 0;
    if (lista != NULL && tam > 0)
    {
        mostrarEncabezadoModificacionNotebook();
        mostrarNotebooks(lista, tam, listaMarca, tam_marc, listaTipoNotebook, tamTipo, listaCliente, tamCliente);
        printf("Ingrese el Id de la notebook \n");

        scanf("%d", &idMd);
        indice = buscarNotebookPorId(lista, tam, idMd);
        if (indice == -1)
        {
            printf("No se encontro el ID %d en el  sistema\n", idMd);
        } else
        {
            mostrarEncabezadoNotebooks();
            mostrarNotebook(lista[indice], listaMarca, tam_marc, listaTipoNotebook, tamTipo, listaCliente, tamCliente);
            char confirma;
            printf("confirma que desea modificar s-n\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma != 's')
            {
                printf("Modificacion cancelada por el usuario\n");
            }

            else
            {
                int tipo;
                eNotebook auxNotebookMod;
                printf("Que valor desea modificar:\n");
                printf("1- precio \n");
                printf("2- Tipo\n");
                do
                {
                    tipo = ingresarEnterosRango("Ingrese el valor\n", "Error: \n", 1, 2);

                } while (tipo < 1 || tipo > 2);
                switch (tipo)
                {
                case 1:
                    auxNotebookMod.precio = ingresarEnterosRango("ingrese el nuevo precio: entre $20000 y $500000\n",
                        "Error:\n", 20000, 500000);
                    lista[indice].precio = auxNotebookMod.precio;
                    break;
                case 2:

                    mostarTiposNotebook(listaTipoNotebook, tamTipo);
                    auxNotebookMod.idTipo = ingresarEnterosRango("ingrese el nuevo tipo: ", "Error:\n", 5000, 5003);
                    lista[indice].idTipo = auxNotebookMod.idTipo;
                    break;
                }

                printf("Modificacion realizada con exito\n");
            }
        }

        todoOk = 1;
    }

    return todoOk;
}

int ordenarNotebooksMarcaPrecio(eNotebook list[], int tam)
{
    int todoOk = 0;
    if (list != NULL && tam > 0)
    {
        eNotebook auxNotebook;
        for (int i = 0; i < tam - 1; i++)
        {
            for (int j = i + 1; j < tam; j++)
            {
                if (list[i].idMarca == list[j].idMarca && list[i].precio > list[j].precio)
                {
                    auxNotebook = list[i];
                    list[i] = list[j];
                    list[j] = auxNotebook;
                } else if (list[i].idMarca > list[j].idMarca)
                {
                    auxNotebook = list[i];
                    list[i] = list[j];
                    list[j] = auxNotebook;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int mostrarNotebooksUnTipo(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamClientes)
{
    int tipo = 0;

    tipo = ingresarEnterosRango("Seleccione el tipo de notebook: \n", "Error\n", 5000, 5003);
    int retorno = 0;
    int contador = 0;
    if (lista != NULL && tam > 0)
    {
        mostrarEncabezadoNotebooks();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idTipo == tipo)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamClientes);
                contador++;
            }
        }
        if (contador == 0) {
            printf("no hay registradas notebooks de ese tipo\n");
        }
        retorno = 1;
    }
    return retorno;
}

int mostrarNotebooksUnMarca(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[],  int tamCliente)
{
    int marca = 0;

    marca = ingresarEnterosRango("Seleccione la marca de notebook: \n", "Error\n", 1000, 1003);
    int retorno = 0;
    int contador = 0;
    if (lista != NULL && tam > 0)
    {
        mostrarEncabezadoNotebooks();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idMarca == marca)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
                contador++;
            }
        }
        if (contador == 0) {
            printf("no hay registradas notebooks de esa marca\n");
        }
        retorno = 1;
    }
    return retorno;
}

int mostrarNotebooksUnMarcaUnTipo(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente)
{
    int marca = 0;
    int tipo = 0;
    marca = ingresarEnterosRango("Seleccione la marca de notebook: \n", "Error\n", 1000, 1003);
    tipo = ingresarEnterosRango("Seleccione el tipo de notebook: \n", "Error\n", 5000, 5003);
    int retorno = 0;
    int contador = 0;
    if (lista != NULL && tam > 0)
    {
        mostrarEncabezadoNotebooks();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idMarca == marca && lista[i].idTipo == tipo)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
                contador++;
            }
        }

        if (contador == 0) {
            printf("no hay registradas notebooks de esa marca y tipo\n");
        } else {
            printf("\nHay registradas %d notebooks de esa marca y tipo\n", contador);
        }
        retorno = 1;
    }
    return retorno;
}

int hardcodearNotebooks(eNotebook lista[], int tam, int* Id, int* contador, cliente listaCliente[], int tamClientes)
{
    int todoOk = 0;
    char confirma;
    char auxModelo[20];
    mostrarEncabezadoHardcodeo();
    printf("Desea hardcodear 5 notebooks s/n?\n");
    fflush(stdin);
    scanf("%1c", &confirma);
    if (confirma=='s')
    {
        eNotebook auxNotebook;
        int indice;
        if (lista != NULL && tam > 0)
        {
            for (int i = 0; i < 5;i++) {
                indice = buscarPosicionLibre(lista, tam);
                if (indice == -1) {
                    printf("No espacios disponibles\n");
                } else {
                    char auxIndice[5];
                    sprintf(auxIndice, "%d", *Id);
                    strcpy(auxModelo, "hardcodeo");
                    strcat(auxModelo, auxIndice);
                    strcpy(auxNotebook.modelo, auxModelo);
                    int auxMarca = (rand() % (1003 + 1 - 1000) + 1000);
                    printf(" aux marca%d\n", auxMarca);
                    //int auxTipo=(rand() % ((5003 - 5000 + 1) + 5000));
                    auxNotebook.idMarca = auxMarca;
                    auxNotebook.idTipo = (rand() % (5003 + 1 - 5000) + 5000);
                    auxNotebook.precio = (rand() % (500000 + 1 - 20000) + 20000);
                    auxNotebook.isEmpty = 0;
                    auxNotebook.id = *Id;
                    (*Id)++;
                    lista[indice] = auxNotebook;
                    *contador = *contador + 1;
                }

                printf("Alta de hardcodeos realizada con exito\n");
                todoOk = 1;
            }
        }
    }
    return todoOk;
}

int mostrarNotebookMasBarata(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente)
{
    int retorno = 0;
    if (lista != NULL && tam > 0)
    {
        int minimo = 1;
        int precioMinimo = 0;

        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && (lista[i].precio < precioMinimo || minimo))
            {
                precioMinimo = lista[i].precio;
                minimo = 0;
                printf("minimo %d\n", minimo);
            }
        }

        mostrarEncabezadoMasBarata();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].precio == precioMinimo)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            }
        }
        retorno = 1;
    }
    return retorno;
}

void mostrarDesgloseMarcas(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo, cliente listaCliente[], int tamCliente) {

    int contadorAcer = 0;
    int contadorAsus = 0;
    int contadorCompaq = 0;
    int contadorHp = 0;
    for (int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty){
        switch (lista[i].idMarca)
        {
        case 1000:
            contadorAcer++;
            break;

        case 1001:
            contadorAsus++;
            break;

        case 1002:
            contadorCompaq++;
            break;

        case 1003:
            contadorHp++;
            break;
        }
        }
    }
    if (contadorAcer) {
        mostrarEncabezadoAcer();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idMarca == 1000)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            }
        }
    }
    if (contadorAsus) {
        mostrarEncabezadoAsus();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idMarca == 1001)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            }
        }

    }
    if (contadorCompaq) {
        mostrarEncabezadoCompaq();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idMarca == 1002)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            }
        }

    }
    if (contadorHp) {
        mostrarEncabezadoHP();
        for (int i = 0; i < tam; i++)
        {
            if (!lista[i].isEmpty && lista[i].idMarca == 1003)
            {
                mostrarNotebook(lista[i], listaMarca, tam_marc, listaTipo, tam_tipo, listaCliente, tamCliente);
            }
        }
    }


}

void mostrarMarcaMasElegida(eNotebook lista[], int tam, eMarca listaMarca[], int tam_marc, eTipoNotebook listaTipo[], int tam_tipo) {

    int contadoresMarcas[4] = { 0, 0,0,0 };
    int match = 0;//bandera para mostrar si hay empate entre marcas

    

    for (int i = 0; i < tam; i++)
    {
        if(!lista[i].isEmpty){
        switch (lista[i].idMarca)
        {
        case 1000:
        
            contadoresMarcas[0]++;
            break;

        case 1001:
            contadoresMarcas[1]++;
            break;

        case 1002:
            contadoresMarcas[2]++;
            break;

        case 1003:
            contadoresMarcas[3]++;
            break;
        }
        }
    }
    if (lista != NULL && tam > 0)
    {
        int maximo = 1;
        int masNotebooks = 0;

        for (int i = 0; i < tam_marc; i++)
        {
            if (contadoresMarcas[i] > masNotebooks || maximo)
            {
                masNotebooks = contadoresMarcas[i];
                maximo = 0;                
            }
        }
        
        for (int i = 0; i < tam_marc - 1; i++)
        {
            for (int j = i + 1; j < tam_marc; j++)
            {
                if (contadoresMarcas[i] == contadoresMarcas[j]) {
                    if (contadoresMarcas[i] == masNotebooks && contadoresMarcas[j] == masNotebooks) {
                        mostrarEncabezadoMasElegidas();
                        printf("Las marcas mas elegidas son %s y %s con %d notebooks \n", listaMarca[i].descripcion, listaMarca[j].descripcion, contadoresMarcas[i]);
                        match = 1;
                    }
                }
            }
        }
        if (!match) {
            for (int i = 0; i < tam_marc; i++)
            {
                ;
                if (contadoresMarcas[i] == masNotebooks)
                {   
                    mostrarEncabezadoMasElegidas();
                    printf("La marca mas elegida es %s con %d notebooks \n", listaMarca[i].descripcion, contadoresMarcas[i]);
                }
            }
        }

    }

    //  printf("La marca mas elegida es %s con %d notebooks", arrMarca[0].descripcion, arrMarca[0].contador);
}

