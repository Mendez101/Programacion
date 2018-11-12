//Hecho por Enrique Antonio Mendez Caceres
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
	/*srand(time(NULL));
	
	cout << rand() % 100+1;*/
	
	//Para hacer una matriz con srand
	srand(time(NULL));
	
	int matriz [3][3];
	int matriz2 [3][3];
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriz [i][j] = rand () % 101;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matriz [i][j] << "   ";
		}
		cout << endl;
	}
	
	return 0;
}
