#ifndef MODO2JUGADORES_H_INCLUDED
#define MODO2JUGADORES_H_INCLUDED

void modo2jugadores() {
    int puntuacion_jugador = 0, combinacion, ronda = 1, puntuacion_jugador2 = 0, ronda_ganador = 0;
    bool primer_ejecucion = true, jugador_1 = true, jugador_2 = false, fin_juego = false;
    char nombre_apellido_jugador1[30], nombre_apellido_jugador2[30];

    inicializarChar(30, nombre_apellido_jugador1);
    inicializarChar(30, nombre_apellido_jugador2);

    do {
        int puntuacion_ronda = 0, dado[6], tecla, cursorx = 49, cursory = 18, lanzamiento = 1, suma_combinacion = 0;
        int num = 0;
        char opcion = 'P';
        bool mostrar = false, no_combinacion = false, pasado = false;

        if(primer_ejecucion == true){
        showcursor();
        dibujarCuadrado(20, 8, 85, 6);
        gotoxy(24, 10);  cout << "Ingrese nombre y apellido del jugador 1: "; cin.getline(nombre_apellido_jugador1, 30, '\n');
        gotoxy(24, 12);  cout << "Ingrese nombre y apellido del jugador 2: "; cin.getline(nombre_apellido_jugador2, 30, '\n');
        primer_ejecucion = false;
        cls();
        }
        hidecursor();
        do {
            int x = 36, n = 0, fila_nombre = 88, repetidos = 0, escalera_combinacion = 0, par_combinacion = 0, ant = 0;
            int suma_combinacion = 0, y = 9, rep = 0, jugada = 0;
            no_combinacion = false;
            pasado = false;
            gotoxy(31, 5); cout << "Ronda N " << ronda << endl;

            if (jugador_1 == true) {
                gotoxy(47, 5); cout << "Puntuacion total = " << puntuacion_jugador;
            }
            else {
                gotoxy(47, 5); cout << "Puntuacion total = " << puntuacion_jugador2;
            }
            gotoxy(79, 5); cout << "Turno de";

            gotoxy(79, 7); cout << "Lanzamiento N " << lanzamiento;

            if (opcion == 'S') opcion = 'P';

            if (jugador_1 == true) {
                do {
                    gotoxy(fila_nombre, 5); cout << nombre_apellido_jugador1[n];//Muestra nombres y apellidos//
                    n++;
                    fila_nombre++;
                } while (nombre_apellido_jugador1[n] != ' ' && nombre_apellido_jugador1[n] != 'P');
            }
            else {
                do {
                    gotoxy(fila_nombre, 5); cout << nombre_apellido_jugador2[n];//Muestra nombres y apellidos//
                    n++;
                    fila_nombre++;
                } while (nombre_apellido_jugador2[n] != ' ' && nombre_apellido_jugador2[n] != 'P');
            }

            interfaz(fila_nombre);

            tirardado(dado);

            cout << endl; cout << endl;
            for (int i = 0; i < 6; i++) { //Muestra los valores de los dados
                gotoxy(x, y); dibujardados(dado, x, y, i);
                x += 9;
            }


            for (x = 1; x <= 6; x++) {
                repetidos = contarNumerosRepetidos(dado, x);
                combinacion = comprobarJugada(repetidos, x, dado);
                suma_combinacion += combinacion;
                if (combinacion != 0 && combinacion > ant) {
                    puntuacion_ronda -= ant;
                    puntuacion_ronda += combinacion;
                    jugada = comprobarJugada2(repetidos, x, dado);
                    rep = repetidos;
                    num = x;
                    ant = combinacion;
                }
            }

            if (jugada == 6 || jugada == 7) {
                gotoxy(50, 14); escribirjugada(jugada, num, rep);
            }
            else if(jugada != 0){
                gotoxy(52, 14); escribirjugada(jugada, num, rep);
            }

            gotoxy(31, 7); cout << "Puntuacion de la ronda = " << puntuacion_ronda; //Muestra la puntuacion de la ronda
            if ((puntuacion_jugador + puntuacion_ronda > 10000 && jugador_1 == true) || (puntuacion_jugador2 + puntuacion_ronda > 10000 && jugador_2 == true)) {
                gotoxy(54, 16); cout << "Te pasaste de 10000!!";
                pasado = true;
                getch();
            }else if (suma_combinacion == 0) {
                gotoxy(58, 15); escribirjugada(jugada, num, rep);
                no_combinacion = true;
                getch();
            }
            else if ((puntuacion_jugador + puntuacion_ronda == 10000 && jugador_1 == true) || (puntuacion_jugador2 + puntuacion_ronda == 10000 && jugador_2 == true)){
                gotoxy(54, 16); cout << "Llegaste a 10000!!";
                fin_juego = true;
                getch();
            }
            else {
                do {
                    //Es para mostrar todo de vuelta, ya que para mostrar el cursor, se usa cls//
                    while (mostrar == true) {
                        int x = 36, n = 0, fila_nombre = 88;//reinicializo todos los valores para que no se rompa el programa xd
                        gotoxy(31, 5); cout << "Ronda N " << ronda << endl;

                        if(jugador_1 == true){
                        gotoxy(47, 5); cout << "Puntuacion total = " << puntuacion_jugador;
                        }else{
                        gotoxy(47, 5); cout << "Puntuacion total = " << puntuacion_jugador2;
                        }

                        gotoxy(79, 5); cout << "Turno de";

                        gotoxy(31, 7); cout << "Puntuacion de la ronda = " << puntuacion_ronda;

                        gotoxy(79, 7); cout << "Lanzamiento N " << lanzamiento;

                        if(jugador_1 == true){
                    do {
                        gotoxy(fila_nombre, 5); cout << nombre_apellido_jugador1[n];//Muestra nombres y apellidos//
                        n++;
                        fila_nombre++;
                    } while (nombre_apellido_jugador1[n] != ' ' && nombre_apellido_jugador1[n] != 'P');
                    }else{
                    do {
                        gotoxy(fila_nombre, 5); cout << nombre_apellido_jugador2[n];//Muestra nombres y apellidos//
                        n++;
                        fila_nombre++;
                    } while (nombre_apellido_jugador2[n] != ' ' && nombre_apellido_jugador2[n] != 'P');
                    }

                        for (int i = 0; i < 6; i++) { //Muestra los valores de los dados
                            gotoxy(x, y); dibujardados(dado, x, y, i);
                            x += 9;
                        }
                        if (jugada == 6 || jugada == 7) {
                            gotoxy(50, 14); escribirjugada(jugada, num, rep);
                        }
                        else if(jugada != 0){
                            gotoxy(52, 14); escribirjugada(jugada, num, rep);
                        }
                        mostrar = false;
                    }

                    interfaz(fila_nombre);

                    gotoxy(52, 16); cout << (char)168 << "Quiere seguir tirando?" << endl;
                    gotoxy(51, 18); cout << "Si" << endl;
                    gotoxy(74, 18); cout << "No" << endl;
                    gotoxy(cursorx, cursory);

                    cout << (char)175;

                    tecla = getch();

                    cls();
                    mostrar = true;
                    switch (tecla) {
                    case 77:
                        cursorx += 23;
                        if (cursorx >= 72) {
                            cursorx = 72;
                        }
                        break;
                    case 75:
                        cursorx -= 23;
                        if (cursorx <= 49) {
                            cursorx = 49;
                        }
                        break;
                    case 13:
                        if (cursorx == 49) opcion = 'S';
                        else opcion = 'N';
                        mostrar = false;
                        break;
                    }
                } while (opcion != 'N' && opcion != 'S');
            }
            cls();
            lanzamiento++;
        } while (opcion != 'N' && no_combinacion == false && fin_juego == false && pasado == false);

        if (opcion == 'N' && puntuacion_jugador + puntuacion_ronda < 10000 && jugador_1 == true) {
            puntuacion_jugador += puntuacion_ronda;
        }

        if(puntuacion_jugador + puntuacion_ronda == 10000 && no_combinacion == false && jugador_1 == true){
            puntuacion_jugador += puntuacion_ronda;
		}

		if (opcion == 'N' && puntuacion_jugador2 + puntuacion_ronda < 10000 && jugador_2 == true) {
            puntuacion_jugador2 += puntuacion_ronda;
        }

        if(puntuacion_jugador2 + puntuacion_ronda == 10000 && no_combinacion == false && jugador_2 == true){
            puntuacion_jugador2 += puntuacion_ronda;
		}
        if (fin_juego == false) {
            gotoxy(55, 10); cout << "Ronda N " << ronda;
            if (jugador_1 == true) {
                gotoxy(55, 15); cout << nombre_apellido_jugador1;
            }
            else {
                gotoxy(55, 15); cout << nombre_apellido_jugador2;
            }
            gotoxy(53, 17); cout << "Puntaje total jugador 1: " << puntuacion_jugador;
            gotoxy(53, 19); cout << "Puntaje total jugador 2: " << puntuacion_jugador2;

            if (jugador_2 == false) {
                gotoxy(53, 21); cout << "Turno de ";
                gotoxy(62, 21); cout << nombre_apellido_jugador2;
            }
            else {
                gotoxy(53, 21); cout << "Turno de ";
                gotoxy(62, 21); cout << nombre_apellido_jugador1;
            }
            dibujarCuadrado(28, 3, 70, 20);
            getch();
            cls();
            if (jugador_1 == true) {
                jugador_2 = true;
                jugador_1 = false;
            }
            else {
                jugador_1 = true;
                jugador_2 = false;
            }
            ronda++;
        }
    }while ((puntuacion_jugador != 10000 && puntuacion_jugador2 != 10000) && ronda <= 10);

    if(puntuacion_jugador > puntuacion_jugador2){
        if (ronda > 10) {
            ronda_ganador = ronda - 1;
        }else ronda_ganador = ronda;
        dibujarCuadrado(28, 3, 70, 20);
        gotoxy(48, 13);  cout << "Gano el jugador 1 UwU";
        gotoxy(48, 15); cout << "Tardaste " << ronda_ganador << " ronda/s en ganar";
        getch();
        if (ronda < menor_rondas || menor_rondas == 0) {
            menor_rondas = ronda_ganador;
            for (int x = 0; x <= 30; x++) {
                nombre_apellido_ganador[x] = nombre_apellido_jugador1[x];
            }
        }
        cls();
	}else if(puntuacion_jugador2>puntuacion_jugador){
        if (ronda > 10) {
            ronda_ganador = ronda - 1;
        }
        else ronda_ganador = ronda;
        dibujarCuadrado(28, 3, 70, 20);
        gotoxy(48, 13);  cout << "Gano el jugador 2 UwU";
        gotoxy(48, 15); cout << "Tardaste " << ronda_ganador << " ronda/s en ganar";
        getch();
        if (ronda < menor_rondas || menor_rondas == 0) {
            menor_rondas = ronda_ganador;
            
            for (int x = 0; x <= 30; x++) {
                nombre_apellido_ganador[x] = nombre_apellido_jugador2[x];
            }
        }
        cls();
    }
    else {
        dibujarCuadrado(28, 3, 70, 20);
        gotoxy(44, 15); cout << "Empataron OwO";
        getch();
    }
}

#endif // MODO2JUGADORES_H_INCLUDED
