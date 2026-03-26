#include <stdio.h>

//Definición de la estructura de una canción

typedef struct{
    char titulo[100];
    char artista[100];
    char genero[50];
    int duracion;
}cancion;


//Definicion del arreglo que servirá de biblioteca
#define MAX 100
cancion biblioteca[MAX];
int totalCanciones = 0;


//Prototipos de función
void menugestion();
void menuconsultar();
void menuestadisticas();
void agregarcancion();
void mostrarlistado();
void eliminarcancion();


int main(){
    int opcion; 
    do{
    printf("\n---Bienvenido a la Biblioteca Musical---\nIngresa una opción del menú: \n");
    printf("1.- Gestionar canciones.\n");
    printf("2.- Hacer una consulta.\n");
    printf("3.- Visualizar estadísticas.\n");
    printf("4.- Salir.\n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
        menugestion();
        break;
        case 2:
        menuconsultar();
        break;
        case 3:
        menuestadisticas();
        break;
        case 4:
        break;
        default:
        printf("\nIngresa una opción válida.\n");
        break;
    }
    }while(opcion!=4);


return 0;

}

void menugestion(){
    int opcion;
     do{
    printf("\n---Gestión Musical---\nIngresa una opción del menú: \n");
    printf("1.- Ver listado de canciones.\n");
    printf("2.- Agregar canción.\n");
    printf("3.- Eliminar canción.\n");
    printf("4.- Salir.\n");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
        mostrarlistado();
        break;
        case 2:
        agregarcancion();
        break;
        case 3:
        eliminarcancion();
        break;
        case 4:
        break;
        default:
        printf("\nIngresa una ocpión válida.\n");
        break;
    }
    }while(opcion!=4);


}
void menuconsultar(){
    printf("2");

}
void menuestadisticas(){
    printf("3");

}

//función para agregar canciones a la biblioteca
void agregarcancion(){
    if(totalCanciones>=MAX){
        printf("La biblioteca está llena.\n");
        return;
    }

    printf("Titulo: ");
    scanf(" %[^\n]", biblioteca[totalCanciones].titulo);

    printf("Artista: ");
    scanf(" %[^\n]", biblioteca[totalCanciones].artista);

    printf("Género: ");
    scanf(" %[^\n]", biblioteca[totalCanciones].genero);

    printf("Duración: ");
    scanf(" %d", &biblioteca[totalCanciones].duracion);

    totalCanciones++;
}


//función para mostrar listado de canciones 
void mostrarlistado() {
    if (totalCanciones == 0) {
        printf("No hay canciones\n");
        return;
    }

    for (int i = 0; i < totalCanciones; i++) {
        printf("\nCancion %d:\n", i + 1);
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("Artista: %s\n", biblioteca[i].artista);
        printf("Genero: %s\n", biblioteca[i].genero);
        printf("Duracion: %d\n", biblioteca[i].duracion);
    }
}

void eliminarcancion(){
    printf("4");
}

