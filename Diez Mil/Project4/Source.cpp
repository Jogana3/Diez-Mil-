#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include "rlutil.h"
int menor_rondas = 0;
char nombre_apellido_ganador[30];
using namespace std;
using namespace rlutil;
#include"tirardado.h"
#include"contarNumerosRepetidos.h"
#include"Titulo.h"
#include"Combinaciones.h"
#include"Dados.h"
#include"Cuadrado.h"
#include"modo1jugador.h"
#include"modo2jugadores.h"
#include"Menu.h"

int	main() {
	bool continuar = true;
	inicializarChar(30, nombre_apellido_ganador);
	do {
		continuar = menu();
	} while (continuar != false);
	return 0;
}
