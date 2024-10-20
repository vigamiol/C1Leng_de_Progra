/* Declarations-definitions */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <limits.h>
#include <stdbool.h>
extern FILE *yyin;

int yylex();
void yyerror(const char*);

typedef enum {
    SUSCEPTIBLE,  // Estado S
    EXPOSED,      // Estado E
    INFECTED,     // Estado I
    RECOVERED     // Estado R
} CellState;

typedef struct {
    CellState state;          // Estado actual de la célula
    CellState nextState;      // Estado en el siguiente paso (transición)
    struct Cell **neighbors;  // Punteros a los vecinos de la célula
    int num_neighbors;        // Número de vecinos
} Cell;

typedef struct {
    int rows;       // Número de filas del AC
    int cols;       // Número de columnas del AC
    Cell **grid;    // Puntero a la matriz bidimensional de células
} Automaton;

(declaracion de estructuras)



(declaracion de variables)

(declaracion de funciones)


%}

%union {
    int ival;
    char strval[50];
}


/* Token Declarations */

%token<strval>EJEMPLO


/* Sintax detection rules (re) */


%%
instrucciones:
    instrucciones instruccion
    | instruccion
    ;

instruccion:
    funcion endline
    | endline
    ;

funcion: IMPRIMIR_UNIVERSO {
            if (universo != NULL) {
                printf("universo:\n");
                imprimirUniverso(universo);
            } else {
                printf("Error: No se ha creado un universo\n");
            }
        }

        | MODIFICAR_PESO GALAXIA GALAXIA NUMERO {
            if (existeGalaxia($2) && existeGalaxia($3)) {
                agregarArista(universo, $2, $3, $4);
                imprimirUniverso(universo);
                printf("Modificar peso de arista entre %s y %s a %d\n", $2, $3, $4);
            } else {
                printf("Error: Una o ambas galaxias no existen\n");
            }
        }

        | CREAR_UNIVERSO NUMERO listaGalaxias{
            if ($2 != contadorGalaxias) {
                printf("Error: El número de galaxias no coincide con la cantidad de nombres proporcionados\n");
            } else {
                universo = inicializarUniverso($2, nombresGalaxias);
                if (universo != NULL) {
                    printf("Crear universo con %d galaxias\n", $2);
                    imprimirUniverso(universo);
                }
            }
            contadorGalaxias = 0;
        }

        | NOMBRENAVE VIAJAR MODO_VIAJE RADIO NUMERO{
            mostrarListaAdyacencia(universo, &nave, $5);
        }
        | MOVER ADYACENTE GALAXIA{
            viajarNave(universo,&nave,$3);
        }
        | MOVER SECUENCIA listaDestinos {
            if (contadorDestinos > 0) {
                viajarCadenaNave(universo, &nave, destinos, contadorDestinos);
                printf("Ubicacion Nave: %s", nave.ubicacion);
            } else {
                printf("Error: No se han ingresado destinos para la secuencia.\n");
            }
            contadorDestinos = 0; // Reiniciar contador después del viaje
        } 

        | ESTACIONCARGA GALAXIA {
            if (existeGalaxia($2)) {
                printf("Definir estacion de carga en %s\n", $2);
                for (int i = 0; i < universo->numGalaxias; i++) {
                    if (strcmp(universo->galaxias[i].nombre, $2) == 0) {
                        universo->galaxias[i].Cargacombustible = true;
                    }
                }
            } else {
                printf("Error: La galaxia %s no existe\n", $2);
            }
        }

        | NOMBRENAVE CARGARCOMBUSTIBLE NUMERO{
            if (existeGalaxia(nave.ubicacion)){
                printf("La nave %s se encuentra en la galaxia %s\n", $1, nave.ubicacion);
                if (universo->galaxias[encontrarIndiceGalaxia(universo, nave.ubicacion)].Cargacombustible == true) {
                    nave.combustible += $3;
                    printf("La nave %s ha sido cargada con combustible\n", $2);
                    printf("Combustible restante: %d\n", nave.combustible);
                } else {
                    printf("Error: La galaxia %s no tiene estacion de carga\n", nave.ubicacion);
                }
            } else {
                printf("Error: La nave %s no existe\n", nave.nombre);
            }
        }

        | CREAR_NAVE NOMBRENAVE NUMERO GALAXIA {
            if (existeGalaxia($4)) {
                printf("Crear nave %s con combustible %d en %s\n", $2, $3, $4);
                nave = *inicializarNave($2, $3, $4);

            } else {
                printf("Error: La galaxia %s no existe\n", $4);
            }
        }
        
        | REVISARNAVE NOMBRENAVE{
            if(strcmp($2,nave.nombre)==0){
                printf("La nave %s existe y se encuentra en la galaxia %s con combustible %d",$2, nave.ubicacion,nave.combustible);
            }
            else{
                printf("La nave %s no existe",$2);
            }
        }

        | NOMBRENAVE VIAJAR MODO_VIAJE GALAXIA{
            if (existeGalaxia($4)) {
                if(strcmp($3,"autonomo")==0){
                    printf("La nave %s viaja de forma autonoma a %s\n", $1, $4);
                    viajarUniversoAuto(universo, &nave, $4);
                    printf("Combustible restante: %d\n", nave.combustible);
                    printf("Ubicacion Nave: %s", nave.ubicacion);
                }
            }
        }

    
        ;

listaDestinos: GALAXIA {
        if (contadorDestinos < 100) {
            strcpy(destinos[contadorDestinos], $1);
            contadorDestinos++;
        } else {
            printf("Error: Se ha excedido el número máximo de destinos\n");
        }
    }
    | listaDestinos GALAXIA {
        if (contadorDestinos < 100) {
            strcpy(destinos[contadorDestinos], $2);
            contadorDestinos++;
        } else {
            printf("Error: Se ha excedido el número máximo de destinos\n");
        }
    }
    ;

listaGalaxias: GALAXIA {
        if (contadorGalaxias < 100) {
            strcpy(nombresGalaxias[contadorGalaxias], $1);
            contadorGalaxias++;
        } else {
            printf("Error: Se ha excedido el número máximo de galaxias\n");
        }
    }
    | listaGalaxias GALAXIA {
        if (contadorGalaxias < 100) {
            strcpy(nombresGalaxias[contadorGalaxias], $2);
            contadorGalaxias++;
        } else {
            printf("Error: Se ha excedido el número máximo de galaxias\n");
        }
    }
    ;

endline: ENDLINE
        ;

%%

void yyerror(const char* msg){
    printf("error: %s\n", msg);
}

(implementacion de funciones)


int main(int argc, char **argv) {
    // Intentar abrir el archivo de comandos predeterminado
    yyin = fopen("universo.txt", "r");
    if (yyin) {
        yyparse();
        fclose(yyin);  // Cierra el archivo después de procesarlo
    }

    // Cambiar la entrada a stdin para continuar leyendo instrucciones
    yyin = stdin;
    yyparse();

    return 0;
}