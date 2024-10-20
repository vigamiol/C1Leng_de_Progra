#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INDIVIDUOS 100000
#define MAX_AUTOMATAS 10 // Máximo número de autómatas
#define PROBABILIDAD 50 
static int total_movidos = 0;
static int total_cambios_estado = 0;

typedef enum {
  SUSCEPTIBLE, // Estado S
  EXPOSED,     // Estado E
  INFECTED,    // Estado I
  RECOVERED    // Estado R
} Estados;

typedef struct {
  Estados estado; // Estado del individuo
} Individuo;

typedef struct Cell {
  Individuo poblacion[MAX_INDIVIDUOS];
  int num_individuos;      // Contador de individuos en la célula
  struct Cell **neighbors; // Punteros a los vecinos de la célula
  int num_neighbors;       // Número de vecinos
  int row;                 // Fila de la celda
  int col;
} Cell;

typedef struct {
  int rows;    // Número de filas del AC
  int cols;    // Número de columnas del AC
  Cell **grid; // Puntero a la matriz bidimensional de células
} Automaton;

typedef struct {
  Automaton *automatons[MAX_AUTOMATAS]; // Arreglo de punteros a autómatas
  int count;                            // Número actual de autómatas
  int tiempo;
} Sistema;

Sistema *crear_sistema() {
  Sistema *sistema = (Sistema *)malloc(sizeof(Sistema));
  sistema->count = 0;
  sistema->tiempo= 0;
  return sistema;
}

Automaton *crear_automata(int rows, int cols) {
  Automaton *automaton = (Automaton *)malloc(sizeof(Automaton));
  automaton->rows = rows;
  automaton->cols = cols;

  // Asignar memoria para la matriz de celdas
  automaton->grid = (Cell **)malloc(rows * sizeof(Cell *));
  for (int i = 0; i < rows; i++) {
    automaton->grid[i] = (Cell *)malloc(cols * sizeof(Cell));
  }

  // Inicializar celdas y asignar filas y columnas
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Cell *cell = &automaton->grid[i][j];
      cell->row = i;           // Asigna la fila
      cell->col = j;           // Asigna la columna
      cell->neighbors = NULL;  // Inicializa neighbors
      cell->num_neighbors = 0; // Inicializa número de vecinos
      cell->num_individuos = 0;

      // Inicializa la población
      int individuos_iniciales = 100;
      for (int k = 0; k < individuos_iniciales; k++) {
        cell->poblacion[k].estado = SUSCEPTIBLE; // O inicializa de otra forma
        cell->num_individuos++;
      }
    }
  }

  return automaton;
}

void agregar_vecindad(Automaton *automaton) {
  for (int i = 0; i < automaton->rows; i++) {
    for (int j = 0; j < automaton->cols; j++) {
      Cell *cell = &automaton->grid[i][j];
      cell->neighbors = (Cell **)malloc(8 * sizeof(Cell *)); // Máximo 8 vecinos
      cell->num_neighbors = 0;

      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          if (di == 0 && dj == 0)
            continue; // Ignorar la célula misma
          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && ni < automaton->rows && nj >= 0 &&
              nj < automaton->cols) {
            cell->neighbors[cell->num_neighbors++] = &automaton->grid[ni][nj];
          }
        }
      }
    }
  }
}

void conectar_automatons(Sistema *sistema, int index1, int cell1_row,
                         int cell1_col, int index2, int cell2_row,
                         int cell2_col) {
  if (index1 >= sistema->count || index2 >= sistema->count) {
    printf("Índice de autómata fuera de rango\n");
    return;
  }

  Automaton *automaton1 = sistema->automatons[index1];
  Automaton *automaton2 = sistema->automatons[index2];

  Cell *cell1 = &automaton1->grid[cell1_row][cell1_col];
  Cell *cell2 = &automaton2->grid[cell2_row][cell2_col];

  // Conectar la celda exterior de automaton1 con la celda exterior de
  // automaton2
  cell1->neighbors = (Cell **)realloc(
      cell1->neighbors, (cell1->num_neighbors + 1) * sizeof(Cell *));
  cell1->neighbors[cell1->num_neighbors++] = cell2;

  cell2->neighbors = (Cell **)realloc(
      cell2->neighbors, (cell2->num_neighbors + 1) * sizeof(Cell *));
  cell2->neighbors[cell2->num_neighbors++] = cell1;
}

void liberar_automata(Automaton *automaton) {
  for (int i = 0; i < automaton->rows; i++) {
    free(automaton->grid[i]->neighbors); // Liberar los punteros a vecinos
    free(automaton->grid[i]);
  }
  free(automaton->grid);
  free(automaton);
}
void imprimir_automata(Automaton *automaton) {
  printf("Autómata (%d filas, %d columnas):\n", automaton->rows,
         automaton->cols);
  for (int i = 0; i < automaton->rows; i++) {
    for (int j = 0; j < automaton->cols; j++) {
      Cell *cell = &automaton->grid[i][j];
      printf("Celda [%d][%d] (Individuos: %d): ", i, j,
             cell->num_individuos); // Muestra la cantidad de individuos
      for (int k = 0; k < cell->num_individuos; k++) {
        switch (cell->poblacion[k].estado) {
        case SUSCEPTIBLE:
          printf("S ");
          break;
        case EXPOSED:
          printf("E ");
          break;
        case INFECTED:
          printf("I ");
          break;
        case RECOVERED:
          printf("R ");
          break;
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}

void imprimir_vecinos(Automaton *automaton, int row, int col) {
  if (row < 0 || row >= automaton->rows || col < 0 || col >= automaton->cols) {
    printf("Error: La celda [%d][%d] está fuera de rango.\n", row, col);
    return;
  }

  Cell *cell = &automaton->grid[row][col];

  printf("Vecinos de la celda [%d][%d]:\n", row, col);
  for (int i = 0; i < cell->num_neighbors; i++) {
    Cell *neighbor = cell->neighbors[i];
    printf("  Celda vecina: [%d][%d]\n", neighbor->row, neighbor->col);
  }
}

void mover_individuos(Cell *origen, Cell *destino) {

    if (origen->num_individuos <= 1)
        return; // Debe quedar al menos 1 individuo

    int max_a_mover = origen->num_individuos * 0.3; // 30% de la población actual
    int individuos_a_mover = rand() % (max_a_mover + 1); // Aleatorio entre 0 y max_a_mover

    if (individuos_a_mover >= origen->num_individuos) {
        individuos_a_mover = origen->num_individuos - 1; // Dejar al menos 1
    }

    // Mover individuos al destino
    for (int i = 0; i < individuos_a_mover; i++) {
        destino->poblacion[destino->num_individuos++] = origen->poblacion[origen->num_individuos - 1]; // Mover el último individuo
        origen->num_individuos--; // Reducir el número de individuos en la celda de origen
    }

    // Actualizar el total de movimientos
    total_movidos += individuos_a_mover;

    // Imprimir el total acumulado
}

void mover_individuos_en_sistema(Sistema *sistema) {
  for (int a = 0; a < sistema->count; a++) { // Iterar sobre cada autómata
    Automaton *automaton = sistema->automatons[a];
    for (int i = 0; i < automaton->rows; i++) {
      for (int j = 0; j < automaton->cols; j++) {
        Cell *cell = &automaton->grid[i][j];

        // Mover un número aleatorio de individuos a un vecino aleatorio
        if (cell->num_individuos > 1 &&
            cell->num_neighbors >
                0) { // Asegúrate de que hay al menos 2 individuos
          int vecino_index =
              rand() % cell->num_neighbors; // Selecciona un vecino aleatorio
          Cell *vecino = cell->neighbors[vecino_index];

          mover_individuos(cell, vecino); // Llama a mover_individuos
        }
      }
    }
  }
}

void verificar_totales(Sistema *sistema) {
  int total_individuos = 0;
  for (int a = 0; a < sistema->count; a++) {
    Automaton *automaton = sistema->automatons[a];
    for (int i = 0; i < automaton->rows; i++) {
      for (int j = 0; j < automaton->cols; j++) {
        total_individuos += automaton->grid[i][j].num_individuos;
      }
    }
  }
  printf("Total de individuos en el sistema: %d\n", total_individuos);
}

void actualizar_estados(Sistema *sistema) {
    for (int a = 0; a < sistema->count; a++) { // Iterar sobre cada autómata
        Automaton *automaton = sistema->automatons[a];
        for (int i = 0; i < automaton->rows; i++) {
            for (int j = 0; j < automaton->cols; j++) {
                Cell *cell = &automaton->grid[i][j];

                // Cambiar el estado de los individuos en la celda actual
                for (int k = 0; k < cell->num_individuos; k++) {
                    Individuo *individuo = &cell->poblacion[k];

                    // Transición de SUSCEPTIBLE a EXPOSED
                    if (individuo->estado == SUSCEPTIBLE) {
                        for (int l = 0; l < cell->num_individuos; l++) {
                            if (cell->poblacion[l].estado == EXPOSED || 
                                cell->poblacion[l].estado == INFECTED) {
                                if (rand() % 100 < PROBABILIDAD ) {
                                    individuo->estado = EXPOSED;
                                    total_cambios_estado++; // Incrementar el contador
                                }
                                break;
                            }
                        }
                    }
                    // Transición de EXPOSED a INFECTED
                    else if (individuo->estado == EXPOSED) {
                        if (rand() % 100 < PROBABILIDAD) { // 50% de probabilidad
                            individuo->estado = INFECTED;
                            total_cambios_estado++; // Incrementar el contador
                        }
                    }
                    // Transición de INFECTED a SUSCEPTIBLE
                    else if (individuo->estado == INFECTED) {
                        if (rand() % 100 < PROBABILIDAD) { // 40% de probabilidad
                            individuo->estado = SUSCEPTIBLE;
                            total_cambios_estado++; // Incrementar el contador
                        }
                    }
                }
            }
        }
    }
}

void imprimir_sistema(Sistema *sistema) {
  printf("Sistema de Autómatas:\n");
  for (int a = 0; a < sistema->count; a++) {
    printf("Autómata %d:\n", a + 1);
    imprimir_automata(sistema->automatons[a]);
    printf("\n"); // Espacio entre autómatas
  }
}

void liberar_sistema(Sistema *sistema) {
  for (int i = 0; i < sistema->count; i++) {
    liberar_automata(sistema->automatons[i]);
  }
  free(sistema);
}

void cambiar_estado_individuo(Sistema* sistema, int automaton_index, int cell_row, int cell_col, int individuo_index, Estados nuevo_estado) {
    if (automaton_index < 0 || automaton_index >= sistema->count) {
        printf("Índice de autómata fuera de rango.\n");
        return;
    }

    Automaton* automaton = sistema->automatons[automaton_index];
    if (cell_row < 0 || cell_row >= automaton->rows || cell_col < 0 || cell_col >= automaton->cols) {
        printf("Índice de celda fuera de rango.\n");
        return;
    }

    Cell* cell = &automaton->grid[cell_row][cell_col];
    if (individuo_index < 0 || individuo_index >= cell->num_individuos) {
        printf("Índice de individuo fuera de rango.\n");
        return;
    }

    // Cambiar el estado del individuo
    cell->poblacion[individuo_index].estado = nuevo_estado;
    printf("Estado del individuo en la celda [%d][%d] cambiado a %d.\n", cell_row, cell_col, nuevo_estado);
}

void imprimir_estado(Sistema *sistema) {
    for (int a = 0; a < sistema->count; a++) {
        Automaton *automaton = sistema->automatons[a];
        printf("Autómata %d:\n", a + 1);
        for (int i = 0; i < automaton->rows; i++) {
            for (int j = 0; j < automaton->cols; j++) {
                Cell *cell = &automaton->grid[i][j];
                printf("Celda [%d][%d]: ", i, j);

                for (int k = 0; k < cell->num_individuos; k++) {
                    Individuo *individuo = &cell->poblacion[k];
                    switch (individuo->estado) {
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
}

void avanzar_simulacion(Sistema *sistema, int pasos) {
    for (int p = 0; p < pasos; p++) {
        // Actualizar estados y mover individuos
        actualizar_estados(sistema);
        mover_individuos_en_sistema(sistema);
        sistema->tiempo++; // Incrementar el tiempo
        printf("Tiempo: %d\n", sistema->tiempo);
        printf("Total de individuos movidos en este paso: %d\n", total_movidos);
        printf("Total de cambios de estado: %d\n", total_cambios_estado);
        total_movidos=0;
        total_cambios_estado=0;
    }
}
void avanzar_simulacion_confin(Sistema *sistema, int pasos) {
    for (int p = 0; p < pasos; p++) {
        // Actualizar estados y mover individuos
        actualizar_estados(sistema);
        sistema->tiempo++; // Incrementar el tiempo
        printf("Tiempo: %d\n", sistema->tiempo);
        printf("Total de cambios de estado: %d\n", total_cambios_estado);
        total_cambios_estado=0;
    }
}

void simular_libre(Sistema *sistema, int pasos) {
    avanzar_simulacion(sistema, pasos);
    imprimir_estado(sistema);
}
void simular_confin(Sistema *sistema, int pasos) {
    avanzar_simulacion_confin(sistema, pasos);
    imprimir_estado(sistema);
}

int main() {
  srand(time(NULL)); // Inicializa el generador de números aleatorios
  Sistema *sistema = crear_sistema();

  // Crear dos autómatas
  sistema->automatons[sistema->count++] = crear_automata(5, 5);
  sistema->automatons[sistema->count++] = crear_automata(5, 5);

  // Agregar vecindad a ambos autómatas
  for (int i = 0; i < sistema->count; i++) {
    agregar_vecindad(sistema->automatons[i]);
  }

  // Conectar las celdas exteriores de los dos autómatas
  conectar_automatons(sistema, 0, 0, 4, 1, 0,0); // Conecta la celda (0, 4) de automata 1 a (0, 0) de automata 2

  cambiar_estado_individuo(sistema, 0, 0, 0, 0, EXPOSED); // Cambia el estado del primer individuo


  simular_libre(sistema, 100);

  liberar_sistema(sistema);
  return 0;
}
