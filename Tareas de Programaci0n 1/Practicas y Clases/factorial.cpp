//hecho por Enrique Antonio Mnedez Caceres
#include <iostream>

using namespace std;

int factorial (int n) {
	if (n < 0) 
		return 0;
	
	else if (n > 1)
		return n * factorial (n - 1);
	
	return 1;
}

int main(int argc, char** argv) {
	cout << factorial (3) << endl;
	cout << endl;
	
	system ("pause");
	return 0;
}
