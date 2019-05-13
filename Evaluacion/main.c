#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"

#define T 1000
#define S 5
#define A 10

int main()
{
    int opcion;

    ePeliculas lista[T];
    eSector sectores[S] = {{1, "Accion",102},{2, "Comedia", 100}, {3, "Drama", 101}, {4, "Romance", 103}, {5, "Terror", 104} };
    eActor actores[A] = {{1, "Johansson", "Argentina"}, {2, "Downey Jr.", "EEUU"}, {3, "Ruffalo", "Canada"}, {4, "Evans", "EEUU"}, {5, "Hemsworth", "Argentina"}, {6, "Jackson", "EEUU"}, {7, "Paltrow", "Canada"}, {8, "Rudd", "Argentina"}, {9, "Cooper", "EEUU"}, {10, "Brolin", "Canada"}};
    inicializarPelis(lista, T);
    hardcodearDatosPeliculas(lista, 10);

    do
    {
        opcion = menuDeOpciones("1.Subir una pelicula.\n2.Modificar una pelicula.\n3.Remover una pelicula.\n4.Mostrar peliculas por anio.\n5.Mostrar actores por pais.\n6.Salir.\nEliga una opcion: ");
        switch(opcion)
        {
        case 1:
            cargarPelicula(lista, sectores, actores, T, S, A);
            printf("Pelicula Subida.\n");
            break;
        case 2:
            modificar(lista, T, 3, actores, A);
            break;
        case 3:
            borrarPelis(lista, T, 3);
            break;
        case 4:
            mostrarListaPelis(lista, T, sectores, S, actores, A);

            break;
        case 5:
            mostrarListaActores(actores, A);

            break;

        }system("pause");
        system("cls");
    }
    while(opcion!=6);

    return 0;
}
