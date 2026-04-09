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
cancion biblioteca[MAX];
int totalCanciones = 0;


//Prototipos de función
void menugestion();
void menuconsultar();
void menuestadisticas();
//gestion
void agregarcancion();
void mostrarlistado();
void eliminarcancion();

//consulta
void buscarporartista(char artista[]);
void buscarporgenero(char genero[]);
void mostrarreproducciones();

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
        break;4
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
    printf("3.-Mostrar reproducciones\n");
    printf("4.-Salir.\n");
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
        mostrarreproducciones();
        break;
        default:
        printf("\nIngresa una opción válida.\n");
        break;
        }
    }while(opcion!=4);


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


//función para eliminar canciones

void eliminarcancion(){
    if(totalCanciones == 0){
    printf("No hay canciones.\n");
    return;
    }

    char titulo[100];
    printf("Ingresa el título de la canción a eliminar: ");
    scanf(" %[^\n]", titulo);

    int pos = -1;
    for(int i=0; i< totalCanciones; i++){
        if (strcmp(biblioteca[i].titulo, titulo) == 0){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("Canción no encontrada.\n");
        return;
    }

    for(int i= pos; i < totalCanciones -1; i++){
        biblioteca[i] = biblioteca[i+1];
    }

    totalCanciones--;
    printf("La canción se ha eliminado con éxito.\n");
}


//función para buscar por artista
void buscarporartista(char artista[]){
   int encontrado=0;

    for(int i=0; i<totalCanciones; i++){
    if(strcmp(biblioteca[i].artista, artista)==0){

    printf("Nombre de la canción: %s\n", biblioteca[i].titulo);
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

    printf("Nombre de la canción: %s\n", biblioteca[i].titulo);
    printf("Artista: %s\n", biblioteca[i].artista);

            encontrado=1;
        }
    }
    
    if(encontrado==0){
    printf("Género no encontrado\n");
    }
}

//función para mostrar reproducciones canciones
void mostrarreproducciones(){
    if(totalCanciones==0){
    printf("No hay canciones para mostrar\n");
        return;
    }
    for(int i=0; i<totalCanciones; i++){
    printf("Canción: %s\n", biblioteca[i].titulo);
    printf("Número de reproducciones: %d\n", biblioteca[i].reproducciones);
    }
}

