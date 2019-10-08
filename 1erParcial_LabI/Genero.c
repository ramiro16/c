#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Genero.h"
#include "Pelicula.h"

void listarGeneros(eGenero lista[],int tamg)
{
    int i;

    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [10] = "NOMBRE";

    printf("%s%15s\n",auxTitulo1,auxTitulo2);

    for(i=0;i<tamg;i++)
    {
        printf("%d%15s\n",lista[i].id,lista[i].descripcion);
    }
}
