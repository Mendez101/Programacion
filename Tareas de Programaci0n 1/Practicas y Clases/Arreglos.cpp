//Hecho por Enrique Antonio Mendez Caceres

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int a [5][2] {{0,9},
				  {1,2},
				  {2,4}};
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; i < 2; j++) {
			cout << "a[" << i << "][" << j << "]";
			cout << a [i][j] << endl;
		}
	}
	
	return 0;
}
