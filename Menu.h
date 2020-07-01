#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

bool menu() {
	int tecla, cursorx = 48, cursory = 20;
	hidecursor();
	do {
		dibujarCuadrado(10, 1, 101, 25);
		titulo();

		gotoxy(50, 20); cout << "Modo 1 jugador";
		gotoxy(50, 21); cout << "Modo 2 jugadores";
		gotoxy(50, 22); cout << "Puntuacion mas alta";
		gotoxy(50, 23); cout << "Salir del juego";

		gotoxy(cursorx, cursory); cout << (char)175;

		tecla = getch();
		cls();
		switch (tecla) {
		case 72:
			cursory--;
			if (cursory <= 20) {
				cursory = 20;
			}
			break;
		case 80:
			cursory++;
			if (cursory >= 23) {
				cursory = 23;
			}
			break;
		case 13:
			if (cursory == 20) {
				modo1jugador();
			}
			else if (cursory == 21) {
				modo2jugadores();
			}
			else if (cursory == 22) {
				if (menor_rondas != 0) {
					cls();
					dibujarCuadrado(24, 14, 70, 9);
					gotoxy(35, 17);  cout << "El jugador con la puntuacion maxima es: " << nombre_apellido_ganador;
					gotoxy(35, 18); cout << "Tardo " << menor_rondas << " rondas en ganar la partida";
					getch();
					cls();
				}
				else {
					cls();
					dibujarCuadrado(24, 14, 70, 9);
					gotoxy(44, 18); cout << "Aun no se han jugado partidas";
					getch();
					cls();
				}
			}
			else {
				return false;
			}
		}
	} while (cursory != 52 && tecla != 13);
	return true;
}

#endif // MENU_H_INCLUDED
