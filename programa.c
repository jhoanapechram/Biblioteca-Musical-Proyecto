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
//estadisticas
void promediaduracion();
void porcentajegenero();
void masreproducida();
void menosreproducida();
void totalminutos();
//archivos
void cargarBiblioteca();
void guardarBiblioteca();

int main(){
    cargarBiblioteca(); // Carga las canciones guardadas al iniciar

    int opcion;
    do{
        printf("\n---Bienvenido a la Biblioteca Musical---\nIngresa una opciÃ³n del menÃº: \n");
        printf("1.- Gestionar canciones.\n");
        printf("2.- Hacer una consulta.\n");
        printf("3.- Visualizar estadÃ­sticas.\n");
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
                printf("\nIngresa una opciÃ³n vÃ¡lida.\n");
                break;
        }
    }while(opcion!=4);

    guardarBiblioteca(); // Guarda todas las canciones al salir
    return 0;
}


	//FUNCIONES DE ARCHIVO 

void cargarBiblioteca(){
    FILE *archivo = fopen("biblioteca.csv", "r");
    if(archivo == NULL) return; // Si no existe el archivo, no pasa nada

    while(fscanf(archivo, " %99[^,],%99[^,],%49[^,],%d,%d\n",
        biblioteca[totalCanciones].titulo,
        biblioteca[totalCanciones].artista,
        biblioteca[totalCanciones].genero,
        &biblioteca[totalCanciones].duracion,
        &biblioteca[totalCanciones].reproducciones) == 5){
        totalCanciones++;
        if(totalCanciones >= MAX) break;
    }

    fclose(archivo);
    printf("Biblioteca cargada: %d canciÃ³n(es) encontrada(s).\n", totalCanciones);
}

void guardarBiblioteca(){
    FILE *archivo = fopen("biblioteca.csv", "w");
    if(archivo == NULL){
        printf("Error: no se pudo guardar la biblioteca.\n");
        return;
    }

    for(int i = 0; i < totalCanciones; i++){
        fprintf(archivo, "%s,%s,%s,%d,%d\n",
            biblioteca[i].titulo,
            biblioteca[i].artista,
            biblioteca[i].genero,
            biblioteca[i].duracion,
            biblioteca[i].reproducciones);
    }

    fclose(archivo);
    printf("Biblioteca guardada con éxito.\n");
}

// MENUS

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
                printf("\nIngresa una opciÃ³n vÃ¡lida.\n");
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
            case 4:
                break;
            default:
                printf("\nIngresa una opción válida.\n");
                break;
        }
    }while(opcion!=4);
}

void menuestadisticas(){
    int opcion;

    do{
        printf("\n---Estadísticas---\n");
        printf("1.- Promedio de duración.\n");
        printf("2.- Porcentaje por género.\n");
        printf("3.- Canción más reproducida.\n");
        printf("4.- Canción menos reproducida.\n");
        printf("5.- Total de minutos.\n");
        printf("6.- Salir.\n");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                promediaduracion();
                break;
            case 2:
                porcentajegenero();
                break;
            case 3:
                masreproducida();
                break;
            case 4:
                menosreproducida();
                break;
            case 5:
                totalminutos();
                break;
            case 6:
                break;
            default:
                printf("\nIngresa una opción válida.\n");
                break;
        }
    }while(opcion != 6);
}

// GESTION
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

    printf("Duración (minutos): ");
    scanf(" %d", &biblioteca[totalCanciones].duracion);

    printf("Reproducciones: ");
    scanf("%d", &biblioteca[totalCanciones].reproducciones);

    totalCanciones++;
    guardarBiblioteca(); // Guarda inmediatamente despuÃ©s de agregar
}

void mostrarlistado(){
    if(totalCanciones == 0){
        printf("No hay canciones\n");
        return;
    }

    for(int i = 0; i < totalCanciones; i++){
        printf("\nCanción %d:\n", i + 1);
        printf("Titulo: %s\n", biblioteca[i].titulo);
        printf("Artista: %s\n", biblioteca[i].artista);
        printf("Genero: %s\n", biblioteca[i].genero);
        printf("Duracion: %d min\n", biblioteca[i].duracion);
        printf("Reproducciones: %d\n", biblioteca[i].reproducciones);
    }
}

void eliminarcancion(){
    if(totalCanciones == 0){
        printf("No hay canciones.\n");
        return;
    }

    char titulo[100];
    printf("Ingresa el título de la canción a eliminar: ");
    scanf(" %[^\n]", titulo);

    int pos = -1;
    for(int i=0; i < totalCanciones; i++){
        if(strcmp(biblioteca[i].titulo, titulo) == 0){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("Canción no encontrada.\n");
        return;
    }

    for(int i = pos; i < totalCanciones - 1; i++){
        biblioteca[i] = biblioteca[i+1];
    }

    totalCanciones--;
    printf("La canción se ha eliminado con éxito.\n");
    guardarBiblioteca(); // Guarda inmediatamente después de eliminar
}

// CONSULTAS

void buscarporartista(char artista[]){
    int encontrado = 0;

    for(int i = 0; i < totalCanciones; i++){
        if(strcmp(biblioteca[i].artista, artista) == 0){
            printf("Nombre de la canciÃ³n: %s\n", biblioteca[i].titulo);
            printf("Género: %s\n", biblioteca[i].genero);
            encontrado = 1;
        }
    }

    if(encontrado == 0){
        printf("Artista no encontrado\n");
    }
}

void buscarporgenero(char genero[]){
    int encontrado = 0;

    for(int i = 0; i < totalCanciones; i++){
        if(strcmp(biblioteca[i].genero, genero) == 0){
            printf("Nombre de la canción: %s\n", biblioteca[i].titulo);
            printf("Artista: %s\n", biblioteca[i].artista);
            encontrado = 1;
        }
    }

    if(encontrado == 0){
        printf("Género no encontrado\n");
    }
}

void mostrarreproducciones(){
    if(totalCanciones == 0){
        printf("No hay canciones para mostrar\n");
        return;
    }

    for(int i = 0; i < totalCanciones; i++){
        printf("Canción: %s\n", biblioteca[i].titulo);
        printf("NÃºmero de reproducciones: %d\n", biblioteca[i].reproducciones);
    }
}

// ESTADÍSTICAS

void promediaduracion(){
    if(totalCanciones == 0){
        printf("No hay canciones.\n");
        return;
    }

    int suma = 0;
    for(int i = 0; i < totalCanciones; i++){
        suma += biblioteca[i].duracion;
    }

    float promedio = (float)suma / totalCanciones;
    printf("El promedio de duración es: %.2f minutos\n", promedio);
}

void porcentajegenero(){
    if(totalCanciones == 0){
        printf("No hay canciones.\n");
        return;
    }

    int pop = 0, rock = 0, jazz = 0, otros = 0;

    for(int i = 0; i < totalCanciones; i++){
        if(strcmp(biblioteca[i].genero, "pop") == 0){
            pop++;
        }else if(strcmp(biblioteca[i].genero, "rock") == 0){
            rock++;
        }else if(strcmp(biblioteca[i].genero, "jazz") == 0){
            jazz++;
        }else{
            otros++;
        }
    }

    printf("\nPorcentaje por género:\n");
    printf("Pop: %.2f%%\n", (pop * 100.0) / totalCanciones);
    printf("Rock: %.2f%%\n", (rock * 100.0) / totalCanciones);
    printf("Jazz: %.2f%%\n", (jazz * 100.0) / totalCanciones);
    printf("Otros: %.2f%%\n", (otros * 100.0) / totalCanciones);
}

void masreproducida(){
    if(totalCanciones == 0){
        printf("No hay canciones.\n");
        return;
    }

    int pos = 0;
    for(int i = 1; i < totalCanciones; i++){
        if(biblioteca[i].reproducciones > biblioteca[pos].reproducciones){
            pos = i;
        }
    }

    printf("\nCanción más reproducida:\n");
    printf("TÃ­tulo: %s\n", biblioteca[pos].titulo);
    printf("Reproducciones: %d\n", biblioteca[pos].reproducciones);
}

void menosreproducida(){
    if(totalCanciones == 0){
        printf("No hay canciones.\n");
        return;
    }

    int pos = 0;
    for(int i = 1; i < totalCanciones; i++){
        if(biblioteca[i].reproducciones < biblioteca[pos].reproducciones){
            pos = i;
        }
    }

    printf("\nCanciÃ³n menos reproducida:\n");
    printf("Título: %s\n", biblioteca[pos].titulo);
    printf("Reproducciones: %d\n", biblioteca[pos].reproducciones);
}

void totalminutos(){
    if(totalCanciones == 0){
        printf("No hay canciones.\n");
        return;
    }

    int suma = 0;
    for(int i = 0; i < totalCanciones; i++){
        suma += biblioteca[i].duracion;
    }

    printf("Total de minutos almacenados: %d\n", suma);
}
