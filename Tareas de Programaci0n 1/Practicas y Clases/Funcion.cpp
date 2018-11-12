//hecho por Enrique Antonio Mnedez Caceres

#include <iostream> //Libreria de entradas y salidas
#include <stdlib.h>

using namespace std; //Simplificar codigo

//Para declarar, todo el tiempo se ejecutara en este orden
float sumar (float x, float y);
void pedirNumero ();

int main(int argc, char** argv) {
	
	pedirNumero ();
	system ("pause");
	return 0;
}

float sumar (float x, float y) { //
	return x + y; //Retorno
}

void pedirNumero () {
	float x;
	float y;
	float res;
	cout << "Ingrese un numero: ";
	cin >> x;
	cout << "Posicion " << &x << endl;
	cout << "Ingrese otro numero: ";
	cin >> y;
	cout << "Posicion " << &y << endl;
	res = sumar (x, y);
	cout << "El resultado es: " << res << endl;
}
