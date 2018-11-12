//Hecho por Enrique Antonio Mendez Caceres

//Ultima fecha de modificacion: 20/09/2018

#include <iostream> //Libreria de entradas y salidas
#include <windows.h> //Libreria de comandos del systema en consola

using namespace std; //Simplificar el codigo

void clear(); //Declaracion de la funcion, no retorna, no recibe parametro
//int sumar(int s, int aux);

//Cuerpo del codigo
int main(int argc, char** argv) {
	int p = 1; //Variable de contador
	int vn; //Su valor cambiara de 2 a 4
	int suma = 0; //Variable acumulador
	int aux; //Intercambio de valores temporales
	
	do {
	clear();
	cout << "¿Cuantos numeros desea sumar? (2-4): "; //Preguntar cuantos numeros se requieren sumar
	cin >> vn; //Agrgar dato a variable n
	clear();
	}
	while (vn < 2 || vn >4); //Condicion mientras sea menor que 2 y mayor a 4
	
	while (p<=vn) { //Condicion mientras sea menor o igual a 4
		clear();
		cout << "Ingrese el numero " << p << endl; //Pedir que ingrese los numeros a sumar
		cin >> aux; //Agragar datos a la variable
		suma = suma + aux; //Acumulador
		//suma = sumar(suma, aux); 
		p++;
	}
	
	clear();
	cout << "La suma es de: " << suma << endl;
	cout << endl;
	
	system("pause");
	return 0;
}

//Acciones a realizar en el vacio
void clear() { //Implementacionde la funcion 1
	system("cls");
	cout << "-------------------------------------------------------" << endl;
	cout << "-------------------SUMA DE P NUMEROS-------------------" << endl;
	cout << "-------------------------------------------------------" << endl;
}

//int sumar(int s, int aux);

//{
	//return s+aux;
//}
