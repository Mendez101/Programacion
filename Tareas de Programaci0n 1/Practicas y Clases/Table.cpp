//Hecho por Enrique Antonio Mendez Caceres
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char** argv) {
	int n[10];
	int m;
	int acum;
	
	//cout << "Tabla del 10" << endl;
	
	for (int x = 1; x <= 10; x++) {
		cout << "TABLA DEL " << x << endl;
		
		for (int i = 1; i <= 10; i++) {
			cout << i << " x 10 = ";
			m = x * i;
			cout << m << endl;
			acum = acum + n[i];
		}
	cout << endl;
	}
	
	cout << endl;
	
	system("pause");
	return 0;
}
