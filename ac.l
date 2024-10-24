%{  
    #include "ac.tab.h"
    #include <string.h>
    #include <stdlib.h>
     // Función auxiliar para convertir string a estado
    int string_to_estado(const char* str) {
        if (strcmp(str, "susceptible") == 0) return 0;      // SUSCEPTIBLE
        else if (strcmp(str, "exposed") == 0) return 1;     // EXPOSED
        else if (strcmp(str, "infected") == 0) return 2;    // INFECTED
        else if (strcmp(str, "recovered") == 0) return 3;   // RECOVERED
        return -1; // Error
    }
%}

%option noyywrap

/* token detection rules (re) */

%%

[0-9]+(\.[0-9]+)?                           { yylval.ival = atoi(yytext); return NUMERO; }
                    
"crear automata"                            {return CREAR_AUTOMATA;}
"conectar automata"                         {return CONECTAR_AUTOMATA;}
"ajustar tasa"                              {return AJUSTAR_TASA;}
"imprimir sistema"                          {return IMPRIMIR_SISTEMA;}
"mover individuos"                          {return MOVER_INDIVIDUOS;}
"actualizar estados"                        {return ACTUALIZAR_ESTADOS;}
"cambiar estado individuo"                  {return CAMBIAR_ESTADO_INDIVIDUO;}
susceptible|exposed|infected|recovered      { yylval.ival = string_to_estado(yytext); return ESTADO; }
"definir habitantes por celda"              {return HABITANTES_CELDA;}
"ejecutar simulacion libre"                 {return EJECUTAR_SIMULACION_LIBRE;} 
"ejecutar simulacion confinamiento"         {return EJECUTAR_SIMULACION_CONFINAMIENTO;}
"reiniciar simulacion"                      {return REINICIAR_SIMULACION;}
"reiniciar sistema"                         {return REINICIAR_SISTEMA;} 
"salir"                                     { return SALIR; }

[ \t]                                       ; /* Ignorar espacios en blanco y tabulaciones */
\n                                          { return ENDLINE; }
.                                           { printf("Caracter no reconocido: %s\n", yytext); }

%%


int yylex();  // Inicia el análisis léxico
    