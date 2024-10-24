# C1Leng_de_Progra
## Vicente Miralles Olivares - Nataniel Palacios Toro

### COMANDOS
* Comando "definir habitantes por celda numero": Comando que modifica el valor de la variable INDIVIDUOS_POR_CELDA a "numero", lo que indica la cantidad de individuos por celda al momento de crear un automata.
* Comando "crear automata numero numero": Comando que inicializa un automata celular ordinario de 1er "numero" filas y 2do "numero"2 columnas.
* Comando "conectar automata numero numero numero numero numero numero": Comando que conecta al automata 1er"numero"  fila 2do"numero" columna 3er"numero" con el automata 4to"numero" fila 5to"numero" columna 6to"numero".
* Comando "ajustar tasa exposed numero": Comando que modifica la variable PROBABILIDAD_E a "numero", esta variable indica el porcentaje para pasar de expuesto a infectado.
* Comando "ajustar tasa infected numero": Comando que modifica la variable PROBABILIDAD_I a "numero", esta variable indica el porcentaje para pasar de infectado a recuperado.
* Comando "ajustar tasa recovered numero": Comando que modifica la variable PROBABILIDAD_R a "numero", esta variable indica el porcentaje para pasar de recuperado a suceptible.
* Comando "ajustar tasa susceptible numero": Comando que modifica la variable PROBABILIDAD_S a "numero", esta variable indica el porcentaje para pasar de suceptible a expuesto.
* Comando "imprimir sistema": Comando que imprime por pantalla los automatas que existen actualmente en el sistema ademas de cada celda con la cantidad de individuos y a todos los individuos de la casilla.
* Comando "cambiar estado individuo numero numero numero numero estado": Comando que le cambia el estado de un individuo a "estado" en el automata 1er"numero" fila 2do"numero" columna 3er"numero" posicion 4to"numero".
* Comando "mover inividuos": Comando que mueve una cantidad no maxima del 30% de una celda a una celda aleatoria vecina. El sistema hace esto por cada celda de cada automata del sistema.
* Comando "actualizar estado": Comando que actualiza los estados de todos los individuos de todas las celdas de todos los automatas.
* Comando "ejecutar simulacion libre numero": Comando que inicia la simulacion con movimientos libres de individuos entre celdas por una cantidad "numero" de pasos. Al finalizar la simulacion imprime el estado final del sistema.
* Comando "ejecutar simulacion confinamiento numero": Comando que inicia la simulacion sin movimientos de individuos entre celdas por una cantidad "numero" de pasos. Al finalizar la simulacion imprime el estado final del sistema.
* Conamdo "reiniciar simulacion": Comando que reinicia a los automatas a sus estados iniciales con todos los individuos en todas las casillas con estado susceptible.
* Comando "reiniciar sistema": Comando que reinicia el sistema, eliminando todos los automatas y liberando sus memorias para poder crear mas automatas.
* Comando "salir": Comando que finaliza la ejecucion del programa.



Repositorio para el certamen 1 de lenguajes de programacion
