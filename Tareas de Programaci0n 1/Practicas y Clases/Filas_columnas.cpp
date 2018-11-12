//hecho por Enrique Antonio Mnedez Caceres
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char** argv) {
	char x [3][3];
	
	for (int i = 0; i <= 2; i++) {
		for (int j = 2; j >= 0; j--) {
			x [i][j] = "-----";
		}
		cout << endl;
	}
	
	/*
	for (int i = 0, i <= 3, i++) {
		x [0][1] = 0;
		
		if (i =3) {
			x [0][0];
			x [3][3];
		}
	}*/
	
	system ("pause");
	return 0;
}
