#include "Funciones.h"
#include <string.h>
void cargarPelicula(ePeliculas lista[], eSector sector[], eActor actor[], int tam, int ts, int ta)
{
    int i;
    int idaux;

    i = buscarLibre(lista, tam);
    if(i!=-1)
    {

        idaux = lista[i-1].id;
        lista[i].id = idaux + 1;

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese el genero: \n");
        mostrarSector(sector, ts);
        scanf("%d", &lista[i].idSector);
        printf("Ingrese el anio: ");
        fflush(stdin);
        scanf("%d", &lista[i].fecha);
        printf("Ingrese un actor: \n");
        mostrarActor(actor[i], ta);
        scanf("%d", &lista[i].idActor);



        lista[i].estado = OCUPADO;

    }
    else
    {
        printf("No hay espacio.");
    }



}
int buscarLibre(ePeliculas lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mostrarSector(eSector sector[], int ts)
{
    int i;
    for(i=0; i<ts; i++)
    {
        printf("%d. %s\n", i+1, sector[i].descripcion);
    }
}

void mostrarActoresOrdenados(eActor actor[], int ta)
{
    int i;
    for(i=0; i<ta; i++)
    {
        printf("%d.%s.\t %s\n", i+1,actor[i].pais,  actor[i].nombre);
    }
}

void mostrarActor(eActor actor[], int ta)
{
    int i;
    for(i=0; i<ta; i++)
    {
        printf("%d. %s\n", i+1, actor[i].nombre);
    }
}

void mostrarListaActores(eActor actores[], int ta)
{
    int i;
    int j;
    eActor aux;

    for(i=0; i<ta; i++)
    {
        for(j=i+1; j<ta; j++)
        {
            if(strcmp(actores[j].pais, actores[i].pais)>0)
            {
                aux = actores[j];
                actores[j] = actores[i];
                actores[i] = aux;
            }
        }
    }


    mostrarActoresOrdenados(actores, ta);


}


void mostrarListaPelis(ePeliculas lista[], int tam, eSector sectores[], int ts, eActor actores[], int ta)
{
    int i;
    int j;

    ePeliculas aux;


    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[j].fecha < lista[i].fecha)
            {
                aux = lista[j];
                lista[j] = lista[i];
                lista[i] = aux;
            }
        }
    }


    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarPelis(lista[i], sectores, actores, ts, ta);
        }

    }
}
void mostrarPelis(ePeliculas Pelicula, eSector sectores[], eActor actores[], int ts, int ta)
{


    char descripcionSector[20];
    char nombreActor[30];
    int i;

    for(i=0; i<ts; i++)
    {
        if(Pelicula.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }
    for(i=0; i<ta; i++)
    {
        if(Pelicula.idActor==actores[i].idActor)
        {
            strcpy(nombreActor, actores[i].nombre);
            break;
        }
    }

    printf("%d |%s |%s |%s |Id: %d\n",  Pelicula.fecha, Pelicula.nombre, nombreActor,descripcionSector, Pelicula.id);




}

void hardcodearDatosPeliculas(ePeliculas lista[], int tam)
{
    int i;
    int id[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011};
    char nombres[][50]= {"End Game","Thor","Cellular","MiB 4","Iron Man","13 Going on 30","Lucy","A Star is Born", "Dime con cuantos?", "Guardianes de la Galaxia", "A perfect murderer", "La Isla"};
    int fecha[] = {2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005};
    int idActor[]= {2,5,4,5,2,3,1,9,4,9,7,1};
    int sector[]= {1,1,1,1,1,4,1,4,4,1,3,3};



    for(i=0; i<tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].fecha = fecha[i];
        lista[i].estado = OCUPADO;
        lista[i].idActor = idActor[i];
        lista[i].idSector = sector[i];
    }
}
void inicializarPelis(ePeliculas lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void modificar(ePeliculas lista[], int tam, int id, eActor actor[], int ta)
{

    int i;
    int opcion;
    int loEncontro = 0;
    printf("Ingrese Id: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id)
        {
            do
            {
                opcion = menuDeOpciones("Que desea modificar:\n\n1.Titulo.\n2.Fecha de Estreno.\n3.Actor.\n4.Dejar de modificar.\nEliga una opcion:");

                switch(opcion)
                {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    fflush(stdin);
                    gets(lista[i].nombre);
                    break;
                case 2:
                    printf("Ingrese el nuevo anio: ");
                    scanf("%d", &lista[i].fecha);
                    break;
                case 3:
                    printf("Ingrese un actor: \n");
                    mostrarActor(actor, ta);
                    scanf("%d", &lista[i].idActor);
                    break;

                }
            }
            while(opcion!=4);


            loEncontro = 1;
            break;
        }
    }

    if(loEncontro==0)
    {
        printf("El Id no existe.");
    }
}

void borrarPelis(ePeliculas lista[], int tam, int id)
{

    int i;
    int loEncontro = 0;
    printf("Ingrese Id: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id)
        {
            lista[i].estado = LIBRE;

            printf("Se ha borrado la pelicula: %s, Id: %d.", lista[i].nombre, lista[i].id);

            loEncontro = 1;
            break;
        }
    }

    if(loEncontro==0)
    {
        printf("El Id no existe.");
    }
}
int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
