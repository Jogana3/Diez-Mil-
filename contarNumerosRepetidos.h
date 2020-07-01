#ifndef CONTARNUMEROSREPETIDOS_H_INCLUDED
#define CONTARNUMEROSREPETIDOS_H_INCLUDED

int contarNumerosRepetidos(int v[], int num) {
	int i, cant = 0;

	for (i = 0; i <= 5; i++) {
		if (v[i] == num) { cant++; }
	}

	return cant;
}

#endif // CONTARNUMEROSREPETIDOS_H_INCLUDED
