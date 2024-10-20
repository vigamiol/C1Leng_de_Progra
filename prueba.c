#include <stdio.h>
#include <stdlib.h>

#define MAX_INDIVIDUOS 100
#define MAX_AUTOMATAS 10 // Máximo número de autómatas

typedef enum {
    SUSCEPTIBLE,  // Estado S
    EXPOSED,      // Estado E
    INFECTED,     // Estado I
    RECOVERED     // Estado R
} Estados;

typedef struct {
    Estados estado; // Estado del individuo
} Individuo;

typedef struct Cell {
    Individuo poblacion[MAX_INDIVIDUOS];
    int num_individuos;  // Contador de individuos en la célula
    struct Cell **neighbors;  // Punteros a los vecinos de la célula
    int num_neighbors;        // Número de vecinos
    int row;                 // Fila de la celda
    int col;  
} Cell;

typedef struct {
    int rows;       // Número de filas del AC
    int cols;       // Número de columnas del AC
    Cell **grid;    // Puntero a la matriz bidimensional de células
} Automaton;

typedef struct {
    Automaton *automatons[MAX_AUTOMATAS]; // Arreglo de punteros a autómatas
    int count; // Número actual de autómatas
} Sistema;

Sistema* crear_sistema() {
    Sistema* sistema = (Sistema*)malloc(sizeof(Sistema));
    sistema->count = 0;
    return sistema;
}

Automaton* crear_automata(int rows, int cols) {
    Automaton* automaton = (Automaton*)malloc(sizeof(Automaton));
    automaton->rows = rows;
    automaton->cols = cols;

    // Asignar memoria para la matriz de celdas
    automaton->grid = (Cell**)malloc(rows * sizeof(Cell*));
    for (int i = 0; i < rows; i++) {
        automaton->grid[i] = (Cell*)malloc(cols * sizeof(Cell));
    }

    // Inicializar celdas y asignar filas y columnas
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Cell* cell = &automaton->grid[i][j];
            cell->row = i; // Asigna la fila
            cell->col = j; // Asigna la columna
            cell->neighbors = NULL; // Inicializa neighbors
            cell->num_neighbors = 0; // Inicializa número de vecinos

            // Inicializa la población
            for (int k = 0; k < MAX_INDIVIDUOS; k++) {
                cell->poblacion[k].estado = SUSCEPTIBLE; // O inicializa de otra forma
            }
        }
    }

    return automaton;
}

void agregar_vecindad(Automaton* automaton) {
    for (int i = 0; i < automaton->rows; i++) {
        for (int j = 0; j < automaton->cols; j++) {
            Cell* cell = &automaton->grid[i][j];
            cell->neighbors = (Cell**)malloc(8 * sizeof(Cell*)); // Máximo 8 vecinos
            cell->num_neighbors = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // Ignorar la célula misma
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < automaton->rows && nj >= 0 && nj < automaton->cols) {
                        cell->neighbors[cell->num_neighbors++] = &automaton->grid[ni][nj];
                    }
                }
            }
        }
    }
}

void conectar_automatons(Sistema* sistema, int index1, int cell1_row, int cell1_col, 
                         int index2, int cell2_row, int cell2_col) {
    if (index1 >= sistema->count || index2 >= sistema->count) {
        printf("Índice de autómata fuera de rango\n");
        return;
    }

    Automaton* automaton1 = sistema->automatons[index1];
    Automaton* automaton2 = sistema->automatons[index2];

    Cell* cell1 = &automaton1->grid[cell1_row][cell1_col];
    Cell* cell2 = &automaton2->grid[cell2_row][cell2_col];

    // Conectar la celda exterior de automaton1 con la celda exterior de automaton2
    cell1->neighbors = (Cell**)realloc(cell1->neighbors, (cell1->num_neighbors + 1) * sizeof(Cell*));
    cell1->neighbors[cell1->num_neighbors++] = cell2;

    cell2->neighbors = (Cell**)realloc(cell2->neighbors, (cell2->num_neighbors + 1) * sizeof(Cell*));
    cell2->neighbors[cell2->num_neighbors++] = cell1;
}

void liberar_automata(Automaton* automaton) {
    for (int i = 0; i < automaton->rows; i++) {
        free(automaton->grid[i]->neighbors); // Liberar los punteros a vecinos
        free(automaton->grid[i]);
    }
    free(automaton->grid);
    free(automaton);
}
void imprimir_automata(Automaton* automaton) {
    printf("Autómata (%d filas, %d columnas):\n", automaton->rows, automaton->cols);
    for (int i = 0; i < automaton->rows; i++) {
        for (int j = 0; j < automaton->cols; j++) {
            Cell* cell = &automaton->grid[i][j];
            printf("Celda [%d][%d]: ", i, j);
            for (int k = 0; k < cell->num_individuos; k++) {
                switch (cell->poblacion[k].estado) {
                    case SUSCEPTIBLE: printf("S "); break;
                    case EXPOSED:    printf("E "); break;
                    case INFECTED:   printf("I "); break;
                    case RECOVERED:  printf("R "); break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

void imprimir_vecinos(Automaton* automaton, int row, int col) {
    if (row < 0 || row >= automaton->rows || col < 0 || col >= automaton->cols) {
        printf("Error: La celda [%d][%d] está fuera de rango.\n", row, col);
        return;
    }

    Cell* cell = &automaton->grid[row][col];

    printf("Vecinos de la celda [%d][%d]:\n", row, col);
    for (int i = 0; i < cell->num_neighbors; i++) {
        Cell* neighbor = cell->neighbors[i];
        printf("  Celda vecina: [%d][%d]\n", neighbor->row, neighbor->col);
    }
}

void liberar_sistema(Sistema* sistema) {
    for (int i = 0; i < sistema->count; i++) {
        liberar_automata(sistema->automatons[i]);
    }
    free(sistema);
}

int main() {
    Sistema* sistema = crear_sistema();

    // Crear dos autómatas
    sistema->automatons[sistema->count++] = crear_automata(5, 5);
    sistema->automatons[sistema->count++] = crear_automata(5, 5);

    // Agregar vecindad a ambos autómatas
    for (int i = 0; i < sistema->count; i++) {
        agregar_vecindad(sistema->automatons[i]);
    }

    // Conectar las celdas exteriores de los dos autómatas
    conectar_automatons(sistema, 0, 0, 4, 1, 0, 0); // Conecta la celda (0, 4) de automata 1 a (0, 0) de automata 2
 
  // Imprimir los vecinos de una celda específica
  imprimir_vecinos(sistema->automatons[0], 0, 4);// Aquí puedes añadir la lógica para simular y actualizar estados

    liberar_sistema(sistema);
    return 0;
}
