#ifndef COMBINACIONES_H_INCLUDED
#define COMBINACIONES_H_INCLUDED


int	pares(int v[]) {
	int cant = 0, puntos = 0, num;
	for (int x = 1; x <= 6; x++){
		num = contarNumerosRepetidos(v, x);
		if (num == 2) { puntos += 2; }
		else if (num == 6)puntos = 6; 

	}
	if (puntos == 6) { puntos = 1000; }
	else { puntos = 0; }
	return puntos;
}
int escalera(int v[]) {
	int igual = 0, c = 0;
	for (int i = 1; i <= 6; i++) {
		igual = contarNumerosRepetidos(v, i);
		if (igual == 1)c += igual;
	}
	if (c == 6) { c = 1500; }
	else { c = 0; }
	return c;
}
int combinacion_1(int cant, int num){
	int contador_de_puntos=0;
	if (cant == 6 && num == 1) contador_de_puntos = 10000 - contador_de_puntos;
	return contador_de_puntos;
	}
int combinacion_2(int cant, int num) {
	int contador_de_puntos = 0;

	if ((cant == 1 || cant == 2) && num == 1) {
		contador_de_puntos = 100 * cant;
	}


	return contador_de_puntos;
}
int combinacion_3(int cant, int num) {
	int contador_de_puntos = 0;

	if ((cant == 1 || cant == 2) && num == 5) {
		contador_de_puntos = 50 * cant;

	}
	return contador_de_puntos;
}
int combinacion_4(int cant, int num){
	int contador_de_puntos = 0;

	if (cant == 3 && num == 1) {
		contador_de_puntos = 1000;
	}

	return contador_de_puntos;

}
int combinacion_5(int cant, int num) {
	int contador_de_puntos = 0;
	if (cant == 3 && num != 1) {
		contador_de_puntos = 100 * num;
	}
	return contador_de_puntos;
}
int combinacion_6(int cant, int num) {
	int contador_de_puntos = 0;
	if ((cant == 4 || cant == 5) && num != 1) {
		contador_de_puntos = 200 * num;
	}
	return contador_de_puntos;
}
int combinacion_7(int cant, int num){
	int contador_de_puntos = 0;

	if ((cant == 4 || cant == 5) && num == 1) {

		contador_de_puntos = 2000;
	}
	return contador_de_puntos;
}

int comprobarJugada(int repetidos, int x, int dados[]){
    int puntaje=0, ant=0;

		puntaje = combinacion_1(repetidos, x); ant = puntaje;
		puntaje = combinacion_2(repetidos, x); if (puntaje > ant) ant = puntaje;
		puntaje = combinacion_3(repetidos, x); if (puntaje > ant) ant = puntaje;
		puntaje = combinacion_4(repetidos, x); if (puntaje > ant) ant = puntaje;
		puntaje = combinacion_5(repetidos, x); if (puntaje > ant) ant = puntaje;
		puntaje = combinacion_6(repetidos, x); if (puntaje > ant) ant = puntaje;
		puntaje = combinacion_7(repetidos, x); if (puntaje > ant) ant = puntaje;
	
    puntaje = escalera(dados); if (puntaje > ant)ant = puntaje;
    puntaje = pares(dados); if (puntaje > ant)ant = puntaje;
    return ant;
}
int comprobarJugada2(int repetidos, int x, int dados[]) {
	int puntaje = 0, ant = 0,jugada=0;

	puntaje = combinacion_1(repetidos, x); ant = puntaje; jugada=1;
	puntaje = combinacion_2(repetidos, x); if (puntaje > ant) ant = puntaje, jugada=2;
	puntaje = combinacion_3(repetidos, x); if (puntaje > ant) ant = puntaje, jugada=3;
	puntaje = combinacion_4(repetidos, x); if (puntaje > ant) ant = puntaje, jugada=4;
	puntaje = combinacion_5(repetidos, x); if (puntaje > ant) ant = puntaje, jugada=5;
	puntaje = combinacion_6(repetidos, x); if (puntaje > ant) ant = puntaje, jugada=6;
	puntaje = combinacion_7(repetidos, x); if (puntaje > ant) ant = puntaje, jugada=7;

	puntaje = escalera(dados); if (puntaje > ant)ant = puntaje, jugada=8;
	puntaje = pares(dados); if (puntaje > ant)ant = puntaje, jugada=9;
	return jugada;
}
void escribirjugada(int x, int num, int repetido) {

	switch (x)
	{
	case 1:cout << "Sexteto"; break;
	case 2:cout << "Juego de 1, +"<<repetido*100<<" puntos"; break;
	case 3:cout << "Juego de 5, +"<<repetido*50<<" puntos"; break;
	case 4:cout << "  Trio 1, +1000 puntos";  break;
	case 5:cout << " Trio de "<<num<<", +"<<num*100<<" puntos"; break;
	case 6:cout << "Trio de "<<num<< " ampliado, +"<<num*200<<" puntos"; break;
	case 7:cout <<"Trio 1 ampliado, +2000 puntos"; break;
	case 8:cout << "  Escalera, +1500 puntos"; break;
	case 9:cout << "Tres Pares, +1000 puntos";  break;
	default: cout << "No hay jugada";
		break;
	}

}
#endif // COMBINACIONES_H_INCLUDED