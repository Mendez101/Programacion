//Hecho por Enrique Antonio Mendez Caceres
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
	float notas [5];
	float suma = 0;
	float promedio;
	
	
	for (int i = 0; i <= 4; i++) {
		do {
			cout << "Ingrese la nota " << i + 1 << endl;
			cin >> notas[i];
		}
		while (notas[i] < 0 || notas[i] > 10);
			
		suma = suma + notas[i]; //Acumular la sumatoria de notas;
	}
	
	system("cls");
	//Salida de datos en pantalla
	cout << "Las notas ingresadas son:" << endl;
	for (int i = 0; i <= 4; i++)
		{
			cout << "N" << i + 1 << " = " << notas[i] << endl;
	}
	cout << endl;
	promedio = suma / 5;
	cout << "El promedio es de: " << promedio << endl;
	cout << endl;
	system("pause");
	return 0;
}
