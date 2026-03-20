#include <stdio.h>
#include <string.h>

//Definición de la estructura de una canción

typedef struct{
    char titulo[100];
    char artista[100];
    char genero[50];
    int duracion;
    int reproducciones;
}cancion;


//Definición del arreglo que servirá de biblioteca
#define MAX 100
cancion biblioteca[100];
int totalCanciones = 0;


//Prototipos de función
void menugestion();
void menuconsultar();
void menuestadisticas();
void agregarcancion();
void mostrarlistado();
void eliminarcancion();

//Funciones mod "consulta"
void buscarporartista(char artista[]);
void buscarporgenero(char genero[]);
void masreproduccion();
void menosreproduccion();

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
    int opcion;
    char artista[100];
    char genero[50];

    do{
    printf("\n---Consultas---\nIngresa una opción del menú: \n");
    printf("1.-Buscar por artista.\n");
    printf("2.-Buscar por género.\n");
    printf("3.-Más reproducciones.\n");
    printf("4.-Menos reproducciones.\n");
    printf("5.-Salir.\n");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
        printf("Ingresa artista: ");
        scanf(" %[^\n]", artista);
        buscarporartista(artista);
        break;
        case 2:
        printf("Ingresa género: ");
        scanf(" %[^\n]", genero);
        buscarporgenero(genero);
        break;
        case 3:
        masreproduccion();
        break;
        case 4:
        menosreproduccion();
        break;
        default:
        printf("\nIngresa una ocpión válida.\n");
        break;
        }
    }while(opcion!=5);


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
    
    printf("Reproducciones: ");
    scanf("%d", &biblioteca[totalCanciones].reproducciones); 
    totalCanciones++;
}


//función para mostrar listado de canciones 
void mostrarlistado() {
    if (totalCanciones == 0) {
        printf("No hay canciones\n");
        return;
    }

    for (int i = 0; i < totalCanciones; i++) {
        printf("\nCanción %d:\n", i + 1);
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("Artista: %s\n", biblioteca[i].artista);
        printf("Genero: %s\n", biblioteca[i].genero);
        printf("Duracion: %d\n", biblioteca[i].duracion);
    }
}

void eliminarcancion(){
    printf("4");
}

//función para buscar por artista
void buscarporartista(char artista[]){
   int encontrado=0;

   for(int i=0; i<totalCanciones; i++){
     if(strcmp(biblioteca[i].artista, artista)==0){

        printf("\nNombre de la canción: %s\n", biblioteca[i].titulo);
        printf("Género: %s\n", biblioteca[i].genero);
        
        encontrado=1;
     }

   }

   if(encontrado==0){
        printf("Artista no encontrado\n");
   }

}

//función buscar por género
void buscarporgenero(char genero[]){
    int encontrado=0;

    for(int i=0; i<totalCanciones; i++){
        if(strcmp(biblioteca[i].genero, genero)==0){

            printf("\nNombre de la canción: %s\n", biblioteca[i].titulo);
            printf("Artista: %s\n", biblioteca[i].artista);

            encontrado=1;
        }
    }
    
    if(encontrado==0){
        printf("Género no enocntrado\n");
    }
}

//función para canción más reproducida
void masreproduccion(){
    if(totalCanciones==0){
        printf("No hay canciones para mostrar\n");
        return;
    }

    int max=0;

    for(int i=1; i<totalCanciones; i++){
        if(biblioteca[i].reproducciones > biblioteca[max].reproducciones){
        max=i;
        }
    }
    printf("\nLa canción más reproducida es: %s\n", biblioteca[max].titulo);
    printf("\nNúmero de reproducciones: %d\n", biblioteca[max].reproducciones);
}

//función para canción menos reproducida
void menosreproduccion(){
    if(totalCanciones==0){
        printf("No hay canciones para mostrar\n");
        return;
    }

    int min=0;

    for(int i=1; i<totalCanciones; i++){
        if(biblioteca[i].reproducciones < biblioteca[min].reproducciones){
        min=i;
        }
    }
    printf("\nLa canción menos reproducida es: %s\n", biblioteca[min].titulo);
    printf("\nNúmero de reproducciones: %d\n", biblioteca[min].reproducciones);
}
