#include <iostream>

using namespace std;

string loginadmin;
string loginadminpass;
int session_logged = 0;
int cl=4;

//Administradores
int adminsLength = 3;
string admins[20] = {"JuanDi", "Cristian", "Samir"};
string adminspass[20] = {"lolo123","cristian123", "samir123"};

//Planes
int planesLength = 4;
string Planes[10] = {"Sencillo", "Normal", "Bueno", "Premium"};
int precioBase[10] = {200, 300, 500, 800};
int precioPorCaja[10] = {100, 150, 200, 300};
int paqueteDeCanales[10] = {5, 10, 15, 20};

//Clientes
int clientesLength = 5;
string clientes[50] = {"Pedro", "Jose", "Estephany", "Saul", "Anabel"};
int cedula[50] = {13520314789, 51234756932, 13604893265, 635586901275}; //las cedulas tienen 11 numeros
string planRegistrado[50] = {"Normal", "Bueno", "Premium", "Normal"};
int cantCajas[50] = {2, 1, 3, 5};
int mensualidad[50] = {};//Hay que calcularla con el plan y la cantidad de cajas

//Funcion Buscar la posicion del administrador.
int BuscarAdministrador(string loginadmin){
	for(int i=0; i<3; i++){
	    if(loginadmin == admins[i]){
	        return i;
	    }
	}
}

//Funcion Logueo
void logeo(){
	string loginadmin;
	cout << "> Nombre: ";
    cin >> loginadmin;
    cout << "> Contraseña: ";
    cin >> loginadminpass;
	int pos = BuscarAdministrador(loginadmin);

	if(loginadmin == admins[pos] && loginadminpass == adminspass[pos]){
			session_logged = 1;
	} else {
		cout << "Su contraseña o nombre de usuario es incorrecto!";
	}
}

void logged(){
	if(session_logged == 1){
            char opcion;
            do{
		cout << "a. Agregar clientes." << endl;
		cout << "b. Borrar Clientes." << endl;
		cout << "c. Agregar mas cajitas" << endl;
		cout << "d. Salir del Administrador" << endl;

		cin >> opcion;
		switch(opcion){
			case 'a':{
				//Colocar Funcion de Agregar Clientes
				cout << "Inserte el nombre del cliente" <<endl;
				cl++;
				cin >> clientes[cl];
				cout <<endl;
				for (int i=0; i<cl+1; i++){
                    			cout << clientes[i]<< " , ";
				}
				cout <<endl;
			}
				break;
			case 'b':{
				//Colocar Funcion de Borrar Clientes
				cout << "Inserte el nombre del cliente que desee borrar" <<endl;
				string nombEl;
				cin >> nombEl;
				for (int i=0; i<cl+1; i++){
                			if (nombEl == clientes[i]){
                       				for(int j=i; j<cl; j++){
                				 clientes[j] = clientes[j+1];
                       		}
                		 cl--;
                	 }
			}
                		cout <<endl;
				for (int i=0; i<cl+1; i++){
                    			cout << clientes[i]<< " , ";
				}
				cout <<endl;
				}
				break;
			case 'c':{
				//Colocar Funcion de Agregar Mas Cajitas
			}
				break;
			case 'd':{
				//Salir del Administrador
				session_logged = 0;
				logeo();
        		 }
				break;
			default:{
				cout << "Error 404 -> Selecciona la opcion correctamente." << endl;
				logged();
				cout <<endl;
				}
				break;

		}
        }
    while(opcion != 'd');

        }

}


int main()
{
	logeo();
	logged();
	cout <<endl;
	cout << "Programa Cerrado"<<endl;
	return 0;

}
