#include <stdio.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idSector;

    char descripcion[20];
     float valor;

}eSector;

typedef struct
{
    int idSector;
    int contador;
    int acumuladorSueldos;
}eAux;

typedef struct
{
    int idActor;
    char nombre[20];
    char pais[20];
}eActor;

typedef struct
{
    int id;
    char nombre[50];
    int fecha;
    int idSector;
    int idActor;

    int estado;

} ePeliculas;

void mostrarPelis(ePeliculas, eSector[], eActor[], int, int);
float calcularSueldos(ePeliculas, eSector[], int);
void cargarPelicula(ePeliculas[], eSector[], eActor[], int, int, int);
void mostrarListaPelis(ePeliculas[], int, eSector[], int, eActor[], int ta);

int buscarLibre(ePeliculas[], int);
void inicializarPelis(ePeliculas[], int);
void hardcodearDatosPeliculas(ePeliculas[], int);
void modificar(ePeliculas[], int, int , eActor actores[], int ta);
void borrarPelis(ePeliculas[], int, int);

void mostrarSector(eSector[], int);
int menuDeOpciones(char[]);



