
void inicializarChar(int tamanio, char nombre_apellido[]) {
    for (int i = 0; i < tamanio; i++) {
        nombre_apellido[i] = 'P';
    }
}

void interfaz(int limite) {
    for (int i = 30; i <= limite + 1; i++) {
        gotoxy(i, 19); printf("%c", 205);
        gotoxy(i, 4); printf("%c", 205);
        gotoxy(i, 6); printf("%c", 205);
        gotoxy(i, 8); printf("%c", 205);
    }
    gotoxy(limite + 2, 19); printf("%c", 188);
    gotoxy(29, 19); printf("%c", 200);
    gotoxy(29, 4); printf("%c", 201);

    for (int y = 18; y >= 5; y--) {
        gotoxy(limite + 2, y); printf("%c", 186);
        gotoxy(29, y); printf("%c", 186);
    }
    gotoxy(limite + 2, 4); printf("%c", 187);
    gotoxy(45, 5); printf("%c", 186);
    gotoxy(45, 4); printf("%c", 203);
    gotoxy(45, 6); printf("%c", 202);
    gotoxy(74, 5); printf("%c", 186);
    gotoxy(74, 4); printf("%c", 203);
    gotoxy(74, 6); printf("%c", 202);
    gotoxy(29, 6); printf("%c", 204);
    gotoxy(29, 8); printf("%c", 204);
    gotoxy(limite + 2, 6); printf("%c", 185);
    gotoxy(limite + 2, 8); printf("%c", 185);
}

void modo1jugador() {
    int puntuacion_jugador = 0, combinacion, ronda = 1, ronda_ganador = 0;
    bool primer_ejecucion = true, fin_juego = false;
    char nombre_apellido[30];

    inicializarChar(30, nombre_apellido);

    do {
        int puntuacion_ronda = 0, dado[6], tecla, cursorx = 49, cursory = 18, lanzamiento = 1, suma_combinacion = 0;
        char opcion = 'P';
        bool mostrar = false, no_combinacion = false;

        if(primer_ejecucion == true){
        showcursor();
        dibujarCuadrado(28, 8, 70, 6);
        gotoxy(32, 10); cout << "Ingrese nombre y apellido: "; cin.getline(nombre_apellido, 30, '\n');
        primer_ejecucion = false;
        cls();
        }
        hidecursor();
        do {
            int x = 36, n = 0, fila_nombre = 88, repetidos = 0, jugada = 0, ant = 0, num = 0, y = 9, rep = 0;
            int suma_combinacion = 0;
            no_combinacion = false;
            gotoxy(31, 5); cout << "Ronda N " << ronda << endl;

            gotoxy(47, 5); cout << "Puntuacion total = " << puntuacion_jugador;

            gotoxy(79, 5); cout << "Turno de";

            gotoxy(79, 7); cout << "Lanzamiento N " << lanzamiento;

            if (opcion == 'S') opcion = 'P';

            do {
                gotoxy(fila_nombre, 5); cout << nombre_apellido[n];//Muestra nombres y apellidos//
                n++;
                fila_nombre++;
            } while (nombre_apellido[n] != ' ' && nombre_apellido[n] != 'P');

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
            else if (jugada != 0){
                gotoxy(52, 14); escribirjugada(jugada, num, rep);
            }
            gotoxy(31, 7); cout << "Puntuacion de la ronda = " << puntuacion_ronda; //Muestra la puntuacion de la ronda

            if (puntuacion_jugador + puntuacion_ronda > 10000) {
                gotoxy(54, 16); cout << "Te pasaste de 10000!!";
                getch();
            }else if(suma_combinacion == 0){
                gotoxy(58, 15); escribirjugada(jugada, num, rep);
                no_combinacion = true;
                getch();
            }
            else if (puntuacion_jugador + puntuacion_ronda == 10000) {
                gotoxy(54, 16); cout << "Llegaste a 10000!!";
                fin_juego = true;
                getch();
            }
            else {
                do {
                    //Es para mostrar todo de vuelta, ya que para mostrar el cursor, se usa cls//
                    while (mostrar == true) {
                        int x = 36, n = 0, fila_nombre = 88, y = 9;//reinicializo todos los valores para que no se rompa el programa xd
                        gotoxy(31, 5); cout << "Ronda N " << ronda << endl;

                        gotoxy(47, 5); cout << "Puntuacion total = " << puntuacion_jugador;

                        gotoxy(79, 5); cout << "Turno de";

                        gotoxy(31, 7); cout << "Puntuacion de la ronda = " << puntuacion_ronda;

                        gotoxy(79, 7); cout << "Lanzamiento N " << lanzamiento;

                        do {
                            gotoxy(fila_nombre, 5); cout << nombre_apellido[n];//Muestra nombres y apellidos//
                            n++;
                            fila_nombre++;
                        } while (nombre_apellido[n] != ' ' && nombre_apellido[n] != 'P');

                        cout << endl; cout << endl;
                        for (int i = 0; i < 6; i++) { //Muestra los valores de los dados
                            gotoxy(x, y); dibujardados(dado, x, y, i);
                            x += 9;
                        }
                        if (jugada == 6 || jugada == 7) {
                            gotoxy(50, 14); escribirjugada(jugada, num, rep);
                        }
                        else {
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
        } while (opcion != 'N' && no_combinacion == false && fin_juego == false && puntuacion_jugador + puntuacion_ronda < 10000);

        if (opcion == 'N' && puntuacion_jugador + puntuacion_ronda < 10000) {
            puntuacion_jugador += puntuacion_ronda;
        }

        if(puntuacion_jugador + puntuacion_ronda == 10000 && no_combinacion == false && puntuacion_ronda != 5000){
            puntuacion_jugador += puntuacion_ronda;
            ronda_ganador = ronda;
		}
        if (fin_juego == false) {
            gotoxy(55, 10); cout << "Ronda N " << ronda;
            gotoxy(55, 15); cout << nombre_apellido;
            gotoxy(55, 17); cout << "Puntaje total: " << puntuacion_jugador;

            dibujarCuadrado(28, 3, 70 , 20);
            cout << endl;
            getch();
            cls();
            ronda++;
        }
    }while (puntuacion_jugador != 10000 && ronda <= 10);
    
    if (puntuacion_jugador == 10000) {
        dibujarCuadrado(28, 3, 70, 20);
        gotoxy(45, 10); cout << "Felicidades ganaste UwU" << endl;
        gotoxy(45, 12); cout << "Tardaste " << ronda_ganador << " ronda/s en llegar a 10000" << endl;
        getch();
        if (ronda < menor_rondas || menor_rondas == 0) {
            menor_rondas = ronda_ganador;
            for (int x = 0; x <= 30; x++) {
                nombre_apellido_ganador[x] = nombre_apellido[x];
            }
        }
        cls();
    }
    else {
        dibujarCuadrado(28, 3, 70, 20);
        gotoxy(50, 10); cout << "Perdiste";
        gotoxy(65, 10); cout << "$";
        gotoxy(65, 11); cout << "$";
        gotoxy(65, 12); cout << "$";
        gotoxy(65, 13); cout << "$";
        gotoxy(65, 14); cout << "$";
        gotoxy(65, 15); cout << "$";
        gotoxy(65, 16); cout << "$";
        gotoxy(65, 17); cout << "$";
        gotoxy(65, 18); cout << "$";
        gotoxy(65, 19); cout << "$";

        gotoxy(66, 14); cout << "$";
        gotoxy(67, 14); cout << "$";
        gotoxy(68, 14); cout << "$";
        gotoxy(69, 14); cout << "$";
        gotoxy(70, 14); cout << "$";
        gotoxy(71, 14); cout << "$";

        gotoxy(66, 10); cout << "$";
        gotoxy(67, 10); cout << "$";
        gotoxy(68, 10); cout << "$";
        gotoxy(69, 10); cout << "$";
        gotoxy(70, 10); cout << "$";
        gotoxy(71, 10); cout << "$";
        getch();
        cls();
    }
}
