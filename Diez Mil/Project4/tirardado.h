#ifndef TIRARDADO_H_INCLUDED
#define TIRARDADO_H_INCLUDED

void tirardado(int Dado[]) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 6; i++) {
		Dado[i] = (rand() % 6) + 1;
	}
}

#endif // TIRARDADO_H_INCLUDED
