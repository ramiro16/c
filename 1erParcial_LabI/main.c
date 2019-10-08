#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Pelicula.h"
#include "Genero.h"
#define TAMP 10
#define TAMG 5
#define TAMA 7

#define OCUPADO 1
#define LIBRE 0



typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;

    int estado;

}eActor;

typedef struct
{
    int codigoPelicula;
    int codigoActor;
    int valorContrato;

}eElenco;



int menu();

void hardcodePeliculas(ePelicula lista[],int);
void hardcodeGenero(eGenero lista[],int);
void hardcodeActores(eActor lista[],int);

void listarPeliculas(ePelicula[],int,eGenero[],int);

void inicializarActores(eActor[],int);
void listarActores(eActor[],int);
void mostrarListadoActores(eActor[],int);
void mostrarUnActor(eActor);
int eliminarActor(eActor[], int);

int buscarActorxId(eActor[], int, int);
int modificarActor(eActor[], int);

int buscarLibre(eActor[], int);

int main()
{
    ePelicula listaPeliculas[TAMP];
    eGenero listaGeneros[TAMG];
    eActor listaActores[TAMA];

    inicializarActores(listaActores,TAMA);

    hardcodePeliculas(listaPeliculas,TAMP);
    hardcodeGenero(listaGeneros,TAMG);
    hardcodeActores(listaActores,5);

    int opcion;

    do
    {
       opcion = menu();

        switch(opcion)
        {
            case 1:

                break;
            case 2:
                system("cls");
                modificarActor(listaActores,TAMA);
                system("pause");
                break;
            case 3:
                system("cls");
                eliminarActor(listaActores,TAMA);
                system("pause");
                break;
            case 4:
                system("cls");
                /*listarActores(listaActores,TAMA);*/
                mostrarListadoActores(listaActores,TAMA);
                system("pause");

                break;
            case 5:
                opcion = 5;
                break;
            default:
                printf("Opcion invalida.");
                break;
        }

    }while(opcion != 5);


    return 0;
}


int menu()
{
    int retorno;

    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Listar \n");

    printf("5- Salir\n\n");

    printf("Ingrese una opcion:");
    scanf("%d",&retorno);

    return retorno;

}

void hardcodeGenero(eGenero lista[],int tamg)
{
    int i;

    int auxId[5] = {911,912,913,914,915};
    char auxNombre[5][51] = {"Accion","Terror","Comedia","Drama","Ciencia Ficcion"};

    for(i=0;i<tamg;i++)
    {
        lista[i].id = auxId[i];
        strcpy(lista[i].descripcion,auxNombre[i]);
    }

}

void hardcodePeliculas(ePelicula lista[],int tamp)
{
    int i;

    int auxCodigo[10] = {100,101,102,103,104,105,106,107,108,109};
    char auxDescripcion[10][51] = {"AAAAAAAAAA","BBBBBBBBBB","CCCCCC","DDDDDDD","EEEEEE","FFFFF","GGGGGG","HHHHHH","IIIIII","JJJJJJ"};
    int auxDuracion[10] = {150,121,87,123,101,147,95,74,118,109};
    int auxIdGenero[10] = {911,915,913,915,914,911,912,912,915,911};

    for(i=0;i<tamp;i++)
    {
        lista[i].codigo = auxCodigo[i];
        strcpy(lista[i].descripcion,auxDescripcion[i]);
        lista[i].duracion = auxDuracion[i];
        lista[i].idGenero = auxIdGenero[i];

    }
}

void hardcodeActores(eActor lista[],int tama)
{
    int i;

    char auxNombre[5][21] = {"Carlos","Maria","Marta","Pedro","Esteban"};
    char auxApellido[5][21] = {"Gomez","Fonseca","Perez","Sanchez","Etcheverria"};
    char auxSexo[5] = {'h','m','m','h','h'};
    int auxCodigo[5] = {1,2,3,4,5};

    for(i=0;i<tama;i++)
    {
        strcpy(lista[i].nombre,auxNombre[i]);
        strcpy(lista[i].apellido,auxApellido[i]);
        lista[i].sexo = auxSexo[i];
        lista[i].codigo = auxCodigo[i];
        lista[i].estado = OCUPADO;

    }
}


void listarPeliculas(ePelicula listaPeliculas[],int tamp,eGenero listaGeneros[], int tamg)
{
    int i,j;

    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [10] = "NOMBRE";
    char auxTitulo3 [10] = "DURACION";
    char auxTitulo4 [10] = "GENERO";

    printf("%s%15s%16s%12s\n",auxTitulo1,auxTitulo2,auxTitulo3,auxTitulo4);

    for(i=0;i<tamp;i++)
    {
        printf("%d%15s%10d Min",listaPeliculas[i].codigo,listaPeliculas[i].descripcion,listaPeliculas[i].duracion);

        for(j=0;j<tamg;j++)
        {
            if(listaPeliculas[i].idGenero == listaGeneros[j].id)
            {
                printf("%15s\n",listaGeneros[j].descripcion);
            }
        }
    }
}

/*void listarActores(eActor listaActores[],int tama)
{
    int i;

    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [10] = "NOMBRE";
    char auxTitulo3 [10] = "APELLIDO";
    char auxTitulo4 [10] = "SEXO";

    printf("%s%15s%16s%12s\n",auxTitulo1,auxTitulo2,auxTitulo3,auxTitulo4);

    for(i=0;i<tama;i++)
    {
        if(listaActores[i].estado == OCUPADO)
        {
            printf("%d%15s%17s%12c\n",listaActores[i].codigo,listaActores[i].nombre,listaActores[i].apellido,listaActores[i].sexo);
        }
    }
}*/

void mostrarUnActor(eActor Actor)
{
    if(Actor.estado == OCUPADO)
    {
        printf("%d %15s %15s %12c\n",Actor.codigo,Actor.nombre, Actor.apellido, Actor.sexo);
    }
}

void mostrarListadoActores(eActor listadoDeActores[], int tama)
{
    int i;

    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [10] = "NOMBRE";
    char auxTitulo3 [10] = "APELLIDO";
    char auxTitulo4 [10] = "SEXO";

    printf("%s%15s%16s%12s\n",auxTitulo1,auxTitulo2,auxTitulo3,auxTitulo4);

    for(i=0; i<tama; i++)
    {
        if(listadoDeActores[i].estado == OCUPADO)
        {
            mostrarUnActor(listadoDeActores[i]);
        }
    }
}



int eliminarActor(eActor listaActores[], int tama)
{
    int auxId;
    int i;
    /*int flag = 0 ;*/
    char respuesta;

    int quePaso = -1;

    mostrarListadoActores(listaActores,tama);

    printf("Ingrese el ID del actor que desea eliminar: ");
    scanf("%d", &auxId);

    for(i=0; i<tama; i++)
    {
        if(listaActores[i].codigo == auxId && listaActores[i].estado == OCUPADO)
        {
            mostrarUnActor(listaActores[i]);
            printf("Esta seguro que desea eliminar este alumno? :");
            fflush(stdin);
            respuesta = getche();

            if(respuesta == 's' || respuesta == 'S')
            {
                listaActores[i].estado = LIBRE;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
            break;
        }

    }

    return quePaso;

}


int buscarActorxId(eActor listaActores[], int tam, int id)
{
    int i;
    int retorno = -1;


    if(listaActores != NULL && tam > 0)
    {

     for(i=0; i<tam; i++)
        {
            if(listaActores[i].codigo == id && listaActores[i].estado == OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }


    return retorno;
}

int modificarActor(eActor listaActores[], int tam)
{
    int index;
    /*char nombre[30];*/
    int quePaso = -1;
    char respuesta;
    eActor aux;
    int eleccion;

    mostrarListadoActores(listaActores,tam);

    printf("Ingrese ID de actor que desea modificar:");
    scanf("%d",&eleccion);

    index = buscarActorxId(listaActores,tam,eleccion);
    if(index!=-1)
    {
        aux = listaActores[index];
        mostrarUnActor(aux);

        printf("Que desea modificar?\n1-Nombre2-Apellido");
        scanf("%d",&eleccion);

        if(eleccion == 1)
        {
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(aux.nombre);
            printf("Esta seguro que desea modificar este alumno? S/N :");
            fflush(stdin);
            respuesta = getche();

            if(respuesta == 's' || respuesta == 'S')
            {
                listaActores[index] = aux;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
        }

        else if(eleccion == 2)
        {
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            gets(aux.apellido);
            printf("Esta seguro que desea modificar este alumno? S/N :");
            fflush(stdin);
            respuesta = getche();

            if(respuesta=='s' || respuesta == 'S')
            {
                listaActores[index] = aux;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
        }

        else
        {
            printf("Opcion invalida. Operacion cancelada");
        }

    }
    return quePaso;
}

void inicializarActores(eActor listaActores[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        listaActores[i].estado = LIBRE;
    }
}

int buscarLibre(eActor listaActores[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listaActores[i].estado != OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


eActor cargarActor(void)
{
    eActor miActor;

    /*printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);*/
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miActor.nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(miActor.apellido);

    printf("Ingrese sexo");
    fflush(stdin);
    scanf("%c",&miActor.sexo);


    /*miAlumno.estado = OCUPADO;*/

    return miAlumno;
}
