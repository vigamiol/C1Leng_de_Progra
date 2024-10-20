%{
    #include <string.h>
    #include <stdlib.h>
%}

/* token detection rules (re) */

%%

[0-9]+(\.[0-9]+)?       { yylval.ival = atoi(yytext); return NUMERO; }

"crear ac"



\n                      { return ENDLINE; }



"crear nave"            { return CREAR_NAVE; }
"crear universo "       { return CREAR_UNIVERSO; }
"ubicacion"             { return UBICACION; }
"revisar nave"          {return REVISARNAVE;}
[a-zA-Z_][a-zA-Z0-9_]*  { strcpy(yylval.strval, yytext); return NOMBRENAVE; }
"cargar combustible"    { return CARGARCOMBUSTIBLE; }
"definir estacion carga" { return ESTACIONCARGA; }

%%

int yywrap() {
    if (yyin != stdin) {
        fclose(yyin);  // Cerrar el archivo si no es stdin
        yyin = stdin;  // Cambiar la entrada a stdin
        return 0;      // Continuar procesando
    }
    return 1;  // Finalizar el análisis cuando se alcance EOF en stdin
}