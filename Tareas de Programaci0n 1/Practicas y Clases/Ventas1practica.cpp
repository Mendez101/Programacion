//HECHO POR ENRIQUE ANTONIO MENDEZ CACERES
//Ultima fecha de modificación: 10/07/2018

#include <iostream> //Libreria para trabajar las entradas y salidas del programa
#include <iomanip> //Libreria para trabajr con el metodo setprecision
#include <windows.h> //Libreria de funciones de windows / Para usar el system(pause)
#include <stdlib.h> //Libreria para cambiar colores

//PROGRAMA PARA CALCULAR EL SUELDO DE LOS EMPLEADOS SEGUN SUS VENTAS
//TODAS LAS VENTAS MAYORES A CERO

//Utilizar un espacio de nombre / para abreviar variables
using namespace std;

void clear (); //Declaracion de funcion que no retorna, no introduce datos

//Comienzo de la estructura
int main() {
	float v; //Variable para ventas
	float s; //Variable para sueldo
	
	//Cambio de color, primer dato para el fondo, segundo para texto
	system("color F4"); //Fondo balnco y letras negras predeterminados
	
	//Verificar que la cantidad no sea menor a cero
	do {
		cout << "Ingrese cantidad de la venta: $"; //Pedir al usuaro que ingrese la cantidad
		cin >> v; //Agregar dato ingresado a la variable
		
	}
	//Incluir condicion del ciclo
	while (v < 0); //Mientras v < 0 entonces while = false
	
	//Verificacion de condiciones segun casos
	if (v <= 500000 ) { //Ventas entre 0 y 500000
		s = 80000; //Agregar dato a variable sueldo
	}
	
	else if (v <= 1000000) { //Ventas entre 500001 y 1000000
		s = 160000; //Agregar dato a variable sueldo
	}
	
	else if (v <= 1500000) { //Ventas entre 1000001 y 1500000
		s = 320000; //Agregar dato a variable sueldo
	}
	
	else if (v <= 2500000) { //Ventas entre 1500001 y 2500000
		s = 450000; //Agregar dato a variable sueldo
	}
	
	else if (v <= 4000000) { //Ventas entre 2500001 y 4000000
		s = 550000; //Agregar dato a variable sueldo
	}
	
	else if (v > 4000000) { //Ventas desde 4000000 en adelante
		s = v * 0.20; //Calculo para obtener el 20% de las ventas
	}
	
	
	clear (); //Limpiar pantalla
	cout << "El salario es de: $" << fixed << setprecision (2) << s << endl; //Imprimir sueldo en pantalla
	 Beep(523,500);
	cout << endl; //Agregar espacio de linea
	cout << endl; //Agregar espacio de linea
	
	system("pause"); //Pausar pantalla del programa
	return 0; //Retornar el valor a cero
}

void clear () {
	system ("cls");
}
