#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

void dibujardados(int dado[], int x, int y, int indice) {

	for (int i = x; i < x+8; i++) {
		gotoxy(i, y); printf("%c", 196);
		gotoxy(i, y+4); printf("%c", 196);
	}

	for (int i = y; i < y + 4; i++) {
		gotoxy(x, i); printf("%c",179);
		gotoxy(x+8, i); printf("%c", 179);
	}

	gotoxy(x, y); printf("%c", 218);
	gotoxy(x, y+4); printf("%c", 192);
	gotoxy(x+8, y); printf("%c", 191);
	gotoxy(x+8, y+4); printf("%c", 217);
	
	switch (dado[indice]) {
		case 1:
			gotoxy(x + 4, y + 2); printf("%c", 254);
		break;
		case 2:
				gotoxy(x+2, y+1); printf("%c", 254);
				gotoxy(x+6, y+3); printf("%c", 254);
		break;
		case 3:
			gotoxy(x + 2, y + 1); printf("%c", 254);
			gotoxy(x + 4, y + 2); printf("%c", 254);
			gotoxy(x + 6, y + 3); printf("%c", 254);
		break;
		case 4:
			gotoxy(x + 2, y + 1); printf("%c", 254);
			gotoxy(x + 6, y + 1); printf("%c", 254);
			gotoxy(x + 2, y + 3); printf("%c", 254);
			gotoxy(x + 6, y + 3); printf("%c", 254);
		break;
		case 5:
			gotoxy(x + 2, y + 1); printf("%c", 254);
			gotoxy(x + 6, y + 1); printf("%c", 254);
			gotoxy(x + 2, y + 3); printf("%c", 254);
			gotoxy(x + 6, y + 3); printf("%c", 254);
			gotoxy(x + 4, y + 2); printf("%c", 254);
		break;
		case 6:
			gotoxy(x + 2, y + 1); printf("%c", 254);
			gotoxy(x + 2, y + 2); printf("%c", 254);
			gotoxy(x + 2, y + 3); printf("%c", 254);
			gotoxy(x + 6, y + 1); printf("%c", 254);
			gotoxy(x + 6, y + 2); printf("%c", 254);
			gotoxy(x + 6, y + 3); printf("%c", 254);
		break;
	}
}

#endif // DADOS_H_INCLUDED
