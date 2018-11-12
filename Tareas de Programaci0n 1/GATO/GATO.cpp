//ENRIQUE ANTONIO MENDEZ CACERES
//Ultima fecha de modificacion 2/10/2018

#include <iostream> //Libreria de entradas y salidas

using namespace std; //Implificar codigo

char square[10] = {'o','1','2','3','4','5','6','7','8','9'}; //Variable para los codigos del tablero
int checkwin(); //Variable para validar la victoria
void board(); //Variable para tablero vacio

//Cuaerpo del codigo
int main() {
	int player = 1; //Variable de jugador
	int i; //Variable de validacion
	int choice; //Variable para conocer seleccion
	char mark; //Variavle de marca o ficha
	
	do {
		board(); //Funcion del tablero
		player = (player%2)?1:2; //Para conocer el turno del jugador 

		cout << "Jugador " << player << ", introduce un numero: "; //Impirmir en pantalla de quien es el turno
		cin >> choice; //Agregar a variable de seleccion

		mark=(player == 1) ? 'X' : 'O'; //Variable marcador lo obtiene de variable jugador, segun sea el turno

		if (choice == 1 && square[1] == '1') { //Para a;adir marca o ficha a espacio 1
			square[1] = mark;
		}
		else if (choice == 2 && square[2] == '2') { //Para a;adir marca o ficha a espacio 2
			square[2] = mark;
		}
		else if (choice == 3 && square[3] == '3') { //Para a;adir marca o ficha a espacio 1
			square[3] = mark;
		}
		else if (choice == 4 && square[4] == '4') { //Para a;adir marca o ficha a espacio 1
			square[4] = mark;
		}
		else if (choice == 5 && square[5] == '5') { //Para a;adir marca o ficha a espacio 1
			square[5] = mark;
		}
		else if (choice == 6 && square[6] == '6') { //Para a;adir marca o ficha a espacio 1
			square[6] = mark;
		}
		else if (choice == 7 && square[7] == '7') { //Para a;adir marca o ficha a espacio 1
			square[7] = mark;
		}
		else if (choice == 8 && square[8] == '8'){ //Para a;adir marca o ficha a espacio 1
			square[8] = mark;
		}
		else if (choice == 9 && square[9] == '9') { //Para a;adir marca o ficha a espacio 1
			square[9] = mark;
		}
		else {
			cout << "Movimiento invalido, introduce cualquier numero para repetir "; //En caso de existir una ficha en esa coordenada

			player--; //Disminuir en variable jugador
			cin.ignore(); //Ignorar
			cin.get(); //Obtener
		}
		i=checkwin(); //Chequeo de la victoria

		player++; ///Aumentar en variable jugador
	}
	while(i==-1); //Mientras sea menor a -1
	
	board(); //Para mostrar resultados del tablero
	if(i==1) {
		cout << "==>\aJugador " << --player << " gana\a<=="; //Imprimie caso, gano un jugador	
	}
	else {
		cout << "==>\aEmpate"; //Imprimir caso de empate	
	}
	cout << endl << endl;
	
	system ("pause"); //Pausar pantalla
	
	return 0; //Retornar valores a cero
}

int checkwin() { //Chequear espacios de linea para la victoria
	if (square[1] == square[2] && square[2] == square[3]) { //Caso 1 de victoria
		return 1; //Terminar juego
	}
	else if (square[4] == square[5] && square[5] == square[6]) { //Caso 2 de victoria
		return 1; //Terminar juego
	}
	else if (square[7] == square[8] && square[8] == square[9]) { //Caso 3 de victoria
		return 1; //Terminar juego
	}
	else if (square[1] == square[4] && square[4] == square[7]) { //Caso 4 de victoria
		return 1; //Terminar juego
	}
	else if (square[2] == square[5] && square[5] == square[8]) { //Caso 5 de victoria
		return 1; //Terminar juego
	}
	else if (square[3] == square[6] && square[6] == square[9]) { //Caso 6 de victoria
		return 1; //Terminar juego
	}
	else if (square[1] == square[5] && square[5] == square[9]) { //Caso 7 de victoria
		return 1; //Terminar juego
	}
	else if (square[3] == square[5] && square[5] == square[7]) { //Caso 8 de victoria
		return 1; //Terminar juego
	}
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' //En caso de no existir un ganador 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0; //Retorno de valores a 0, no hay victoria
	else
		return -1; //Retornar -1, el juego continua
}

void board() { //Para obtener el titulo, tablero, instrucciones
	system("cls"); //Limpiar consola
	
	//Imprimir titulo e intrucciones

	cout << "-----------GATO----------" << endl;

	//Impirmir jugadores y simbolo que le corresponde a cada uno
	cout << "    Jugador 1 (X)  -  Jugador 2 (O)   " << endl << endl;
	cout << endl;

	//Imprimir tablero en pantalla
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl; //Espacio para ingresar datos en tablero

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl; //Espacio para ingresar datos en tablero

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl; //Espacio para ingresar datos en tablero

	cout << "     |     |     " << endl << endl;
}
