//Creador Enrique Antonio Mendez Caceres
//Carnet: MC18082
//Ultima Actualizacion 17/11/2018.

//Indicacion: Realizar una aplicacion en consola que permita ver los clientes,
//las cotizaciones realizadas y generar automaticamente 5 productos*/

//Librerias que se Utilisaran
#include <cstdlib>
#include <stdio.h> 
#include <iostream> 
#include <winsock2.h> 
#include <windows.h> 
#include <mysql.h> 
#include <mysqld_error.h> 

using namespace std; //Simplificacion del codigo

//Funciones del entorno
void bienvenida(); //Funcion de mensaje de bienvenida
void menu(); //Funcion de menu de seleccion
void retorno(); //Funcion para posibles salidas
void hcotizacion(); //Funcion para imprimir cabecera de la tabla cotizaciones
void hclientes(); //Funcion para imprimir cabecera de la tabla de clientes
void gendatos(); //Funcion para mensaje de datos generados

//Funciones de error
void errormysql(); //Funcion para error de objeto
void errorhost(); //Funcion para error de host
void errorconsulta(); //Funcion de error en consulta
void novalido(); //Funcion de mensaje de dato no valido

//Desarrollo del codigo
int main(int argc, char *argv[]) {  
	int opc; //Variable de opciones
	int ret; //Variable de opciones de retorno
	MYSQL * _mysql; //Agregar objeto de tipo puntero _mysql
	char soundi[] = "C:\\Windows\\media\\ring07.wav"; //Variable de audio de bienvenida
	char soundf[] = "C:\\Windows\\media\\ring02.wav"; //Variable de audio de cierre
	char sounde[] = "C:\\Windows\\media\\chord.wav"; //Variable de audio de error
	string insertar1;
	string insertar2;
	string insertar3;
	string insertar4;
	string insertar5;
     
    // Intentar iniciar un objeto MySQL
    if(!(_mysql = mysql_init(0))) { //Si resulta que no se ha creado el proceso
    	errormysql(); //Ejecutar funcion de error de objeto
    }
    else { //Si se ha inicializado el proceso
    	//Imprimir mensaje de confirmacion de objeto creado
    	cout << "Objeto mysql creado correctamente, conectando al servidor ..." << endl;
    	Sleep(1000); //Mantener en pantalla por un segundo
      	
		//Intentar conectar al servidor, si se ha conectado al host local, con el usuario y base indicados
      	if(!mysql_real_connect(_mysql, "localhost", "root", "", "practica2", 3306, NULL, 0)) {
        	void errorhost(); //Ejecutar funcion para error de host
    	}
      	else { //Si encontro el servidor con los ajustes indicados
        	cout << "Conectado al servidor ..." << endl; //Imprimir mensaje de confirmacion de coneccion
        	Sleep(1000); //Mantener en pantalla por un segundo
        
        	bienvenida(); //Ejecutar funcion de mensaje de bienvenida
        	cout << PlaySound((LPCSTR)soundi, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio de bienvenida
        	Sleep(2100); //Mantener mensaje en pantalla por tres segundos
        	retmenu: //Punto de redireccion
        	menu(); //Ejecutar menu de opciones
        	//Comprobar los flags de error con la referencia que devuelve el operador >>
        	while((cin >> opc).fail() || opc < 1 || opc > 4) {
		        cin.clear(); //reseteamos los flags
		        fflush(stdin); //limpio buffer de entrada
		        novalido(); //Ejecutar funcion de mensaje de dato no valido
		    }
        	
        	system("cls"); //Limpiar consola
        	system("color 1F"); //Cambiar colores, fondo azul, texto blanco
        	//Ejecutar una consulta de selección en una tabla de la base de datos
        	const char * sql; //Variable de puntero para almacenar consultas
        	int query; //Introducir query para visualizar datos
        	
        	switch(opc) { //Funcion switch para activar las opciones del menu
        		case 1: //Caso uno, mostrar clientes que han cotizado
        			sql = "SELECT * FROM clientes"; //Asignar a veriable de donde surge la consulta
        			query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
		        	if (query != 0) { //Si la consulta es diferente de cero existe un error
						errorconsulta(); //Ejecutar funcion de error en consultas  
		        	}
		        	else { //Si la consulta es correcta
		        		//Imprimir mensaje de confirmacion
		          		cout << "Consulta correcta, extrayendo filas ..." << endl << endl << endl;
		          		MYSQL_RES * resultado = mysql_store_result(_mysql); // Obteniendo el resultado de la consulta
		          		
		          		//Obteniendo el número de filas afectadas
		          		unsigned long columnas_afectadas = mysql_num_rows(resultado);
		          		MYSQL_ROW columna; // Recorrer fila a fila
		          		hclientes(); //Ejecutar funcion de cabecera de tabla de clientes
		          		for (int x = 0; x < columnas_afectadas; x++) { //Obtener filas por medio de ciclo
		            	  	//Obtenemos la fila
		              		columna = mysql_fetch_row(resultado);
		              		//Mostrando el valor de los campos de la fila
		              		cout << "\t\t\t\t|" << columna[0] << "\t|" << columna[1];
							cout << "\t\t|" << columna[2] << "\t\t|" << columna[3] << "|" <<  endl;
		          		}
		          		//Imprimir terminacion de la tabla
		          		cout << "\t\t\t\t ------------------------------------------------ " << endl;
		          		//Liberar el resultado de la consulta
		          		mysql_free_result(resultado);
		        	}
		        	retorno(); //Ejecutar funcion de posibles retornos
		        	//Comprobar los flags de error con la referencia que devuelve el operador >>
		        	while((cin >> ret).fail() || ret < 1 || ret > 2) {
				        cin.clear(); //Reseteamos los flags
				        fflush(stdin); //Limpio buffer de entrada
				        novalido(); //Ejecutar funcion de mensaje de dato no valido
				    }
		        	switch(ret) { //Switch de posibles retornos
		        		case 1: //Opcion 1
		        			goto retmenu; //Redireccionar a menu
		        			
		        		case 2: //Opcion 2
		        			break; //Terminar proceso
					}
					break; //Terminar caso
				
				case 2:
					sql = "SELECT * FROM cotizacion"; //Asignar a veriable de donde surge la consulta
					query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
		        	if (query != 0) { //Si la consulta es diferente de cero existe un error
						errorconsulta(); //Ejecutar funcion de error en consultas  
		        	}
		        	else { //Si la consulta es correcta
		        		//Imprimir mensaje de confirmacion
		          		cout << "Consulta correcta, extrayendo filas ..." << endl << endl << endl;
		          		//Obteniendo el resultado de la consulta
		          		MYSQL_RES * resultado = mysql_store_result(_mysql);
		          		
		          		//Obteniendo el número de filas afectadas
		          		unsigned long columnas_afectadas = mysql_num_rows(resultado);
		          		MYSQL_ROW columna; // Recorrer fila a fila
		          		hcotizacion(); //Imprime cabecera de la tabla de cotizaciones
		          		for (int x = 0; x < columnas_afectadas; x++) { //Obtener filas por medio de ciclo
		            	  	//Obtenemos la fila
		              		columna = mysql_fetch_row(resultado);
		              		//Mostrando el valor de los campos de la fila
		              		cout << "\t\t\t|" << columna[0] << "\t|" << columna[1];
							cout << "\t\t|" << columna[2] << "\t|" << columna[3] << "\t\t|" << columna[4];
							cout << "\t\t|" <<  endl;
		          		}
		          		//Imprimir terminacion de la tabla
		          		cout << "\t\t\t ----------------------------------";
		          		cout << "----------------------------- " << endl;
		          		mysql_free_result(resultado); //Liberar el resultado de la consulta
		        	}
		        	retorno(); //Ejecutar funcion de posibles retornos
		        	//Comprobar los flags de error con la referencia que devuelve el operador >>
		        	while((cin >> ret).fail() || ret < 1 || ret > 2) {
				        cin.clear(); //Reseteamos los flags
				        fflush(stdin); //Limpio buffer de entrada
				        novalido(); //Ejecutar funcion de mensaje de dato no valido
				    }
		        	switch(ret) { //Switch de posibles retornos
		        		case 1: //Opcion 1
		        			goto retmenu; //Redireccionar a menu
		        		case 2: //Opcion 2
		        			break; //Terminar caso
					}
					break; //Terminar caso
					
				case 3: //Para generar nuevos productos he incluirlos a la tabla de productos
					if (query != 0) { //Si la consulta es diferente de cero existe un error
						errorconsulta(); //Ejecutar funcion de error en consultas  
		        	}
		        	else { //Si la consulta es correcta
						//LLamar a la tabla he insertar datos de productos
						sql = "INSERT INTO productos(codpro,nombre,precio,existencias,fechaingreso) VALUES(codpro,'DORITOS','0.85','400',fechaingreso)";
						query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
						sql = "INSERT INTO productos(codpro,nombre,precio,existencias,fechaingreso) VALUES(codpro,'CHEETOS','0.75','300',fechaingreso)";
						query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
						sql = "INSERT INTO productos(codpro,nombre,precio,existencias,fechaingreso) VALUES(codpro,'DR PEPPER','0.75','500',fechaingreso)";
						query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
						sql = "INSERT INTO productos(codpro,nombre,precio,existencias,fechaingreso) VALUES(codpro,'BIG COLA','0.35','600',fechaingreso)";
						query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
						sql = "INSERT INTO productos(codpro,nombre,precio,existencias,fechaingreso) VALUES(codpro,'PRINGLES','1.25','400',fechaingreso)";
						query = mysql_query(_mysql, sql); //Introducir query para visualizar datos
						gendatos(); //Ejecutar funcion de mensaje de datos generados
					}
					retorno(); //Ejecutar funcion de posibles retornos
		        	//Comprobar los flags de error con la referencia que devuelve el operador >>
		        	while((cin >> ret).fail() || ret < 1 || ret > 2) {
				        cin.clear(); //Reseteamos los flags
				        fflush(stdin); //Limpio buffer de entrada
				        novalido(); //Ejecutar funcion de mensaje de dato no valido
				    }
		        	switch(ret) { //Switch de posibles retornos
		        		case 1: //Opcion 1
		        			goto retmenu; //Redireccionar a menu
		        		case 2: //Opcion 2
		        			break; //Terminar caso
		        	}
					
				case 4:
					break; //Terminar proceso
			}
    	}
	}
	cout << PlaySound((LPCSTR)soundf, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio de cierre
	system ("cls"); //Limpiar consola
    system("color 1F"); //Cambiar colores, fondo azul, texto blanco
    mysql_close(_mysql); //Cerrar la conexión al servidor
    system("pause"); //Pausar pantalla el sistema
    return 0;
}

void bienvenida() {
	system("color 02"); //Cambiar color de consola, fondo negro, letras turquesa
	cout << endl << endl << endl << endl << endl; //Espacios de linea
	//Imprimir mensaje de bienvenida en pantalla de consola
	cout << "\t\t\t\t111111111111111111111111111111111111111111111111"<< endl;
		cout << "\t\t\t\---------------BIENBENIDO-------------------" << endl;
	cout << "\t\t\t\t11111111111111111111111111111111111111111111111";
}

void menu() { //Funcion para menu de opciones
	system("cls"); //Limpiar pantalla de consola
	system("color 1F"); //Cambiar colores, fondo azul, texto blanco
    cout << endl << endl << endl << endl << endl; //Espacios de linea
    //Imprimir menu de opciones en pantalla
	cout << "\t\t\t\t ------------------------------------------------- " << endl;
    cout << "\t\t\t\t|         [[MENU DE BASE DE COTIZACIONES]]        |" << endl;
    cout << "\t\t\t\t|-------------------------------------------------|" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t|     1. Mostrar clientes que han cotizado        |" << endl;
    cout << "\t\t\t\t|     2. Mostrar cotizaciones                     |" << endl;
    cout << "\t\t\t\t|     3. Generar productos                        |" << endl;
    cout << "\t\t\t\t|     4. Salir                                    |" << endl;
    cout << "\t\t\t\t|                                                 |" << endl;
    cout << "\t\t\t\t -------------------------------------------------\n\n";
    cout << "\t\t\t\t\t\tDigite la opcion: "; //Mensaje para pedir ingreso de opcion
}

void errormysql() { //Funcion para error de objeto
	cout << "### Error al crear el objeto mysql ###" << endl; //Imprimir mensaje de error
    cout << "!!! Revise que se ha creado el proceso !!!" << endl; //Imprimir indicacion
    Sleep(1000); //Mantener en pantalla por un segundo
}

void errorhost() { //Funcion para error de host
	cout << " No es posible conectarse al servidor " << endl; //Imprimir mensaje de error
    Sleep(1000); //Mantener en pantalla por un segundo
    //Imprimir indicaciones al usuario para hacer revision
    cout << "!!! Revise nombre del host, usuario, contrasena y nombre de la base !!!" << endl;
    Sleep(1000); //Mantener en pantalla por un segundo
}

void errorconsulta() { //Funcion de error en consulta
	char sounde[] = "C:\\Windows\\media\\chord.wav"; //Variable de audio de error
	cout << PlaySound((LPCSTR)sounde, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio de error
	//Imprimir mensaje de error
	cout << "\t\t\t\t ----------------------------- " << endl;
	cout << "\t\t\t\t|                             |" << endl;
	cout << "\t\t\t\t|      Error de  consulta     |" << endl;
	cout << "\t\t\t\t|                             |" << endl;
	cout << "\t\t\t\t ---------------------------- " << endl << endl;
}

void retorno() { //Funcion para posibles salidas
	//Imprimir mensaje para preguntar si desea regresar al menu o salir
    cout << "\t\t\t\t\t       Que desea hacer?:" << endl;
	cout << "\t\t\t\t\t1. Ir a menu               2. Salir" << endl << endl;
}

void novalido() {
	char sounde[] = "C:\\Windows\\media\\chord.wav"; //Variable de audio de error
	cout << PlaySound((LPCSTR)sounde, NULL, SND_FILENAME | SND_ASYNC); //Reproducir audio de error
	system("color 04"); //Cambiar colores de consola, fondo negro, texto rojo
	//imprimir mensaje de errar en caso de estar vacia la cola
	cout << "\t\t\t\t ---------------------------------- ---- " << endl;
	cout << "\t\t\t\t|                                       |" << endl;
	cout << "\t\t\t\t|            Opcion no valida           |" << endl;
	cout << "\t\t\t\t|                                       |" << endl;
	cout << "\t\t\t\t -------------------------------------- " << endl << endl;
	cout << "\t\t\t\t\t    Ingrese Otro valor : "; //Pedir al usauario otro dato
}

void hcotizacion() { //Funcion para imprimir cabecera de la tabla cotizaciones
	//Imprimir cabecera
	cout << "\t\t\t ----------------------------------";
	cout << "----------------------------- " << endl;
	cout << "\t\t\t|Codcot" << "\t|Codclient" << "\t|Codpro" << "\t|Cantidad";
	cout << "\t|Total\t\t|" << endl;
	cout << "\t\t\t ----------------------------------";
	cout << "----------------------------- " << endl;
}

void hclientes() { //Funcion para imprimir cabecera de la tabla de clientes
	//Imprimir cabecera
	cout << "\t\t\t\t ------------------------------------------------ " << endl;
	cout << "\t\t\t\t|Codigo" << "\t|Nombre" << "\t\t|Apellido" << "\t|Telefono|" << endl;
	cout << "\t\t\t\t ------------------------------------------------ " << endl;
}

void gendatos() { //Funcion para mensaje de datos generados
	//Imprimir mensaje de datos generados correctamente
	cout << "\t\t\t\t --------------------------------------- " << endl;
	cout << "\t\t\t\t|                                       |" << endl;
	cout << "\t\t\t\t|      Los Datos son correctamente      |" << endl;
	cout << "\t\t\t\t|                                       |" << endl;
	cout << "\t\t\t\t --------------------------------------- " << endl << endl;
}
