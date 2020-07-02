#ifndef CUADRADO_H_INCLUDED
#define CUADRADO_H_INCLUDED

void dibujarCuadrado(int ubiX, int ubiY, int ancho, int largo) {

	for (int y = ubiY, i = 0; i < largo; y++, i++) {

		gotoxy(ubiX, y); printf("%c", 186);
		gotoxy(ubiX+ancho, y); printf("%c", 186);
	}

	for (int e = ubiX, i = 0; i < ancho; e++, i++) {
			gotoxy(e, ubiY); printf("%c", 205);
			gotoxy(e, ubiY + largo); printf("%c", 205);
	}

	gotoxy(ubiX + ancho, ubiY); printf("%c", 187);//Esquina Derecha
	gotoxy(ubiX, ubiY); printf("%c", 201);//Esquina Izquierda
	gotoxy(ubiX + ancho, ubiY + largo); printf("%c", 188);//Esquina inferior derecha
	gotoxy(ubiX, ubiY + largo); printf("%c", 200);//Esquina inferior Izquierda

}

#endif // CUADRADO_H_INCLUDED
