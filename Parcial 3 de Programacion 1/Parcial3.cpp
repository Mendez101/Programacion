//Programa creado por: Enrique Antonio Mendez Caceres
//Ultima fecha de modificacion: 28/11/2018


/*El presente programa realiza la serie de Fibonacci y serie de taylor, 
Este Almacena los resultados y los muestra resultados  en consola.*/

//Librerias
#include <iostream>//Libreria de entradas y salidas
#include <cstdlib>//Contiene Funicones y macros
#include <math.h>// Contiene los prototipos de las funciones y otras definiciones para el uso y manipulación de funciones matemáticas
#include <fstream>//Flujos hacia/desde ficheros. Permite la manipulación de archivos desde el programar, tanto leer como escribir en ellos.
#include <string>//contenedores tipo string;
#include <sstream>//Proporciona algunas plantillas
#include <conio.h>//Libreria para comandos
using namespace std; //Simplificar el codigo

//Declaracion de Funciones
void menu();//Declaracion de funcion para el menu
void titulo (); //Declaracion de funcion para el titulo
void fibo(); //Declaracion de funcion fibonachi
void taylor();//Declaracion de funcion para Taylor
double tay(int n, int x);//Ingreso de datos taylor
double factorial(int n);//Ingreso de datos factoriAL
void final();//Declaracion de funcion, mensaje final
int escribir(int o, string n, string d, string r);//Decalracion de datos
void leer();//Declaracion de funcion 6, no retorna, no recibe parametros

//Desarrollo del codigo
int main(){
 system("color 4A");// esto sirve para cambiar el color en pantalla 
   menu();//Uso  de funcion para el menu
  
}
void menu(){//uso de funcion para el menu, no retorna, no recibe parametros

    
    titulo();//Uso de la funcion titulo
	int n;//Variable n
     
     //Presentacion del Menu
	cout<<"-- Menu Principal --"<<endl;//Imprime en pantalla
	cout<<endl;
	cout<<"1. Resolver Bibonacci"<<endl;//Imprime en pantalla
	cout<<"2. Serie de Taylor"<<endl;//Imprime en pantalla
	cout<<"3. Ver resultados"<<endl;//Imprime en pantalla
	cout<<"4. Salir"<<endl;//Imprime en pantalla
	cout<<endl;
	cout<<"Elija una opcion: "; cin>>n;//Imprime en pantalla
	system("cls");//Limpiar Pantalla

	switch(n){//Variable switch

		case 1://Para el caso 1

			fibo();

			break;

		case 2://Para el caso 2

			taylor();

				break;

		case 3://Para el caso 3

		leer();

				break;

		case 4://Para el caso 4

		    final();
			break;

	}

}
void fibo(){//Acciones a ejecutar por la funcion fibo

	string nom = "Fibonacci";
 
    int i, n, cont = 0; 
    long long int a[100];
    
    stringstream ss;   
    a[0] = 0;
    a[1] = 1;
 
    cout << "Digite el Numero de terminos de la serie = ";//Imprime en pantalla
    cin >> n; 
    cout << "\n";
   
    for(i=1; i < n; i++){
 
        a[i+1] = a[i-1] + a[i]; 
    }
 
     for(i=0; i < n; i++){
 
        if (cont == 10){ 
 
            cout << "\n";
            cont = 0;           
        }
        cout << a[i] << " ";
        cont += 1;  
        
        
  	ss<< a[i] << " ";    
   
     }  
    cout << "\n";
     stringstream sq;    
  	sq<<"Terminos de la serie: "<<n;       
    string datos= sq.str();
    string res= ss.str();
    escribir(1, nom, datos, res);
    
    getch();
    menu();
}

void taylor(){//Acciones a ejecutar por la funcion taylor

	int n;
	int x;
	double res;
	string nom = "Serie de Taylor";//Imprime en pantalla
	cout<<"Ingrese valor de n: "; cin>> n;//Imprime en pantalla
	cout<<"Ingrese valor de x: "; cin>> x;//Imprime en pantalla
	cout<<endl;
    res = tay(n,x);
	cout<<"El valor de Taylor para n= "<<n<<" y x= "<<x<<" es igual a: "<<res<<endl;//Imprime en pantalla
	
	
    stringstream ss;    
  	ss<<"n= "<<n <<" y x= "<<x;       
    string datos= ss.str();
     stringstream sr;    
  	sr<<"El resultado es: "<<res;       
    string re= sr.str();
	escribir(2, nom, datos, re);
	
	getch();
	menu();
}

double tay(int n, int x){//Uso de las declaraciones
	
	double t;
	double s;
	
	for (int i = 0; i < n; i++){
		
		t = pow(x, i) / factorial(i);
		s += t;
	}
	return s;
}

double factorial(int n){//Uso de las declaraciones
	
	double fact =1;
	for(int i= 2; i<=n; i++){
		fact*=i;
	}
	return fact;
}
int escribir(int o, string n, string d, string r){
	
	fstream file("registro.txt", ios::in | ios::out | ios::app);//Se almacenaran datos
  
  if (!file.is_open()){
  	
  	cout<<"Error al abrir archivo";//En caso que falle el archivo
  	
  }else{
  	
  	cout<<"Proceso realisado correctamente"<<endl;//En caso que abra correectaente
  	
  	cout<<"Presione enter para regresar al menu"<<endl;//Opcion para regresar al menu
  
    
    
    stringstream sa;
  	sa<<o;
  	string opcion= sa.str();
          
    string nombre = n;
  	string datos = d;
   
  	string resultado=r;
    	
  	file<<opcion<<" - "<<nombre<<" - "<<datos<<" - "<<resultado<<endl;
}
return 0;
}

void leer(){//Acciones a ejecutar por la funcion leer
	system("color F0");// esto sirve para cambiar el color en pantalla 
	
		fstream file("registro.txt", ios::in | ios::out | ios::app);
  
  if (!file.is_open()){
  	
  	cout<<"Error al abrir archivo";
  	
  }else{
  	
  		file.seekg(0);
  	string line;
  	cout<<"-Registro-"<<endl;
  	while(file.good()){
  		
  		getline(file, line);
  		cout << line << endl;
	}
}
getch();
menu();

}
void final(){//Uso de funcion final

cout<<endl;//Espacio de linea
system("pause");
system("cls");

cout<<"----------------------"<<endl;//Imprime en pantalla
cout<<"*  Proceso Finalizado "<<endl;//Imprime en pantalla
cout<<"----------------------"<<endl;//Imprime en pantalla

}
//Acciones a ejecutar por la funcion titulo
void titulo() {
	system ("cls"); //Limpia el contenido en pantalla
	cout << "========================================================" << endl; //Imprime en pantalla
	cout << "-------La sucesiOn de Fibonacci y Serie Taylor----------" << endl; //Imprime en pantalla
	cout << "========================================================" << endl; //Imprime en pantalla
	cout << endl; //Espacio de linea
}
