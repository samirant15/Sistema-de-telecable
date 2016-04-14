#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "funciones.h"
using namespace std;

int session_logged = 0;
string mensajes[20];
int msjLength = 0;
string logged;

//Administradores
int adminsLength = 3;
string admins[20] = {"JuanDi", "Cristian", "Samir"};
string adminspass[20] = {"lolo123","cristian123", "s"};

//Planes
int planesLength = 4;
string Planes[10] = {"Sencillo", "Normal", "Bueno", "Premium"};
int precioBase[10] = {200, 300, 500, 800};
int paqueteDeCanales[10] = {5, 10, 15, 20};
int precioPorCaja[10] = {100, 150, 200, 300};

//Clientes
int clientesLength = 4;
string clientes[50] = {"Pedro", "Jose", "Estephany", "Saul"};
string cedula[50] = {"13520314789", "51234756932", "13604893265", "63558690127"}; //las cedulas tienen 11 numeros
string planRegistrado[50] = {"Normal", "Bueno", "Premium", "Normal"};
int cantCajas[50] = {2, 1, 3, 5};
int mensualidad[50] = {};//Hay que calcularla con el plan y la cantidad de cajas

void Menu();
string VerMensaje(int n);

//Funcion Buscar la posicion del administrador.
int BuscarAdministrador(string loginadmin, int adminsLength, string admins[]);

//Funcion Buscar la posicion del administrador.
int BuscarCliente(string loginCliente, int clientesLength, string clientes[]);

int CalcularMensualidad(string name, int pos, int planesLength, string planRegistrado[], string Planes[], int precioBase[], int precioPorCaja[], int paqueteDeCanales[], int cantCajas[]);

//Funcion Logueo
int logeoAdmin(string admins[], string adminspass[], int adminsLength, int &session_logged, string &logged);

int CalcularIngresos(int clientesLength, int mensualidad[]);

void loggedAsAdmin(){
	if(session_logged == 1){
        char opcion;
        do{
            system("cls");
            cout << "----------------------------------------------" << endl;
            cout << "|*Administrador                              |" << "  -----------------------------" << endl;
            cout << "-------------------Menu-----------------------" << "  |Clientes:       " << clientesLength << "\t    |" << endl;
            cout << "|a. Agregar clientes.                        |" << "  |Mensajes:       " << msjLength << "\t    |" << endl;
            cout << "|b. Borrar Clientes.                         |" << "  |Ingresos bruto: " << CalcularIngresos(clientesLength, mensualidad) << "\t    |" << endl;
            cout << "|c. Ver quejas/sugerencias.                  |" << "  -----------------------------" << endl;
            cout << "|d. Agregar un plan.                         |" << endl;
            cout << "|e. Modificar un plan.                       |" << endl;
            cout << "|f. Tabla de informacion de clientes.        |" << endl;
            cout << "|g. Salir del Administrador.                 |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "\nOpcion: ";
            cin >> opcion;
            string msj;
            char op;
            string nombEl;
            string plan="";
            int pos;
            switch(opcion){
            case 'a':
                    system("cls");
                    cout << "----------------------------------------------" << endl;
                    cout << "|*Agregar un cliente                         |" << endl;
                    cout << "----------------------------------------------" << endl;
                    //Agregar Clientes
                    cout << "*Inserte el nombre del cliente" <<endl;
                    cin >> clientes[clientesLength];
                    cout << endl;
                    //AgregarCedulaDelCliente
                    cout << "*Inserte la cedula del cliente" <<endl;
                    cin >> cedula[clientesLength];
                    cout << endl;
					//Agregar Plan del Cliente
					while(plan==""){
                        cout << "*Inserte plan del cliente" <<endl;
                        cin >> plan;
                        cout << endl;
                        for(int i=0; i<planesLength; i++){
                            if(Planes[i] == plan){
                                planRegistrado[clientesLength]=plan;
                                break;
                            }
                            if(i==planesLength-1){
                                plan="";
                                cout << "ERROR: Inserte un plan valido" << endl;
                            }
                        }
					}
					//Agregar Cajitas del Cliente
					cout << "Inserte cantidad de cajitas" <<endl;
                    cin >> cantCajas[clientesLength];
                    cout << endl;
                    pos = BuscarCliente(clientes[clientesLength], clientesLength, clientes);
                    mensualidad[clientesLength] = CalcularMensualidad(clientes[clientesLength], pos, planesLength, planRegistrado, Planes, precioBase, precioPorCaja, paqueteDeCanales, cantCajas);
					clientesLength++;
                    cout << endl << "***Cliente agregado exitosamente***" << endl;
                    system("pause");
                    break;
                case 'b':
                    //Funcion de Borrar Clientes
                    system("cls");
                    cout << "----------------------------------------------" << endl;
                    cout << "|*Borrar un cliente                          |" << endl;
                    cout << "----------------------------------------------" << endl;
                    cout << "*Inserte el nombre del cliente que desee borrar:" <<endl;
                    cin >> nombEl;
                    for (int i=0; i<clientesLength; i++){
                        if (nombEl == clientes[i]){
                            for(int j=i; j<clientesLength; j++){
                                clientes[j] = clientes[j+1];
                                cedula[j] = cedula[j+1];
                                planRegistrado[j] = planRegistrado[j+1];
                                cantCajas[j] = cantCajas[j+1];
                                mensualidad[j] = mensualidad[j+1];
                            }
                            cout << endl << "***Cliente borrado***" << endl;
                            clientesLength--;
                            cout << endl << "Clientes restantes: ";
                            for (int i=0; i<clientesLength; i++){
                                if(i!=clientesLength-1)
                                    cout << clientes[i]<< ", ";
                                else
                                    cout << clientes[i]<< ".";
                            }
                            break;
                         }
                         if(i==clientesLength-1){
                            cout << "ERROR: Cliente no encontrado" << endl;
                         }
                }

                    cout <<endl;
                    system("pause");
                    break;
                case 'c':
                        int n;
                        system("cls");
                        cout << "----------------------------------------------" << endl;
                        cout << "|*Ver quejas/sugerencias                     |" << endl;
                        cout << "----------------------------------------------" << endl;
                        cout << endl << "*Usted tiene " << msjLength << " mensajes." << endl;
                        cout << "*Mostrar mensaje #";
                        cin >> n;
                        if (n>msjLength || n<1){
                            cout << endl << "ERROR: Mensaje no encontrado" << endl << endl;
                            system("pause");
                            loggedAsAdmin();
                        }
                        msj = VerMensaje(n, msjLength, mensajes);
                        cout << "El mensaje fue:" << endl;
                        cout <<"----------------------------------------------------------------------\n";
                        cout << msj << endl;
                        cout <<"----------------------------------------------------------------------\n";
                        cout << "a. Borrar\nb.Volver" << endl;
                        cout << "Opcion: ";
                        cin >> op;
                        while(op!='a' && op !='b'){
                            cout << "ERROR: Opcion no valida!\nOpcion: ";
                            cin >> op;
                        }
                        if(op=='a'){
                            for (int i=n-1; i<=msjLength; i++){
                                mensajes[i] = mensajes[i+1];
                                }
                                msjLength--;
                                cout << "\nMensaje borrado!\n\n";
                                system("pause");
                            }
                        break;

                case 'd':
                    //Agregar un Plan
                    system("cls");
                    cout << "----------------------------------------------" << endl;
                    cout << "|*Agregar un plan                            |" << endl;
                    cout << "----------------------------------------------" << endl;
                    cout << "*Inserte el nombre del plan" <<endl;
                    cin >> Planes[planesLength];
                    cout << endl;

                    cout << "*Inserte el precio base del plan" <<endl;
                    cin >> precioBase[planesLength];
                    cout << endl;

                    cout << "*Inserte la cantidad de canales del plan" <<endl;
                    cin >> paqueteDeCanales[planesLength];
                    cout << endl;

                    cout << "*Inserte el precio por caja" <<endl;
                    cin >> precioPorCaja[planesLength];
                    cout << endl;
                    cout << "***Plan Agregado***" << endl;
                    planesLength++;
                    cout << "----------------------------------------------" << endl;
                    cout << "Planes disponibles: ";
                    for (int i=0; i<planesLength; i++){
                    	if(i!=planesLength-1)
                                cout << Planes[i]<< ", ";
                            else
                                cout << Planes[i]<< ".";
                    }
                    cout << endl << endl;
                    system("pause");
                    break;

                case 'e':
                    //Modificar un Plan
                    system("cls");
                    cout << "----------------------------------------------" << endl;
                    cout << "|*Modificar un plan                          |" << endl;
                    cout << "----------------------------------------------" << endl;
                    cout << "Planes disponibles: ";
                    for(int i=0; i<planesLength; i++){
                        cout << Planes[i];
                        if(i!=planesLength-1)
                            cout << ", ";
                        else
                            cout << "." << endl;
                    }
                    cout << "----------------------------------------------" << endl;
                    plan="";
                    while(plan==""){
                        cout << "*Inserte el nombre del plan que desea modificar:" <<endl;
                        cin >> plan;
                        cout << endl;
                        for(int i=0; i<planesLength; i++){
                            if(Planes[i] == plan){
                                cout << "*Inserte el precio base:" <<endl;
                                cin >> precioBase[i];
                                cout << "*Inserte la cantidad de canales:" <<endl;
                                cin >> paqueteDeCanales[i];
                                cout << "*Inserte el precio por caja:" <<endl;
                                cin >> precioPorCaja[i];
                                cout << endl << "***Datos guardados exitosamente***\n*Nota: Las mensualidades de los usuarios cambiaran" << endl;
                                for(int i=0; i<clientesLength; i++){
                                    int pos = BuscarCliente(clientes[i], clientesLength, clientes);
                                    mensualidad[i] = CalcularMensualidad(clientes[i], pos, planesLength, planRegistrado, Planes, precioBase, precioPorCaja, paqueteDeCanales, cantCajas);
                                }
                                system("pause");
                                break;
                            }
                            if(i==planesLength-1){
                                plan="";
                                cout << "ERROR: Inserte un plan valido" << endl;
                                cout << "----------------------------------------------" << endl;
                                }
                            }

                        }
                    break;

                case 'f':
                    system("cls");
                    cout << "----------------------------------------------" << endl;
                    cout << "|*Tabla de informacion de clientes           |" << endl;
                    cout << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "----------------------------------------------------------------------------" << endl;
                    cout << "|Cliente    \t|Cedula\t\t|Plan    \t|Cajas\t|Mensualidad\t   |" << endl;
                    cout << "----------------------------------------------------------------------------";
                    for(int i=0; i<clientesLength; i++){
                        cout << endl << "|" << clientes[i] << "    \t|" << cedula[i] << "   \t|" << planRegistrado[i] << "   \t|" << cantCajas[i] << "\t|" << mensualidad[i] << "\t\t   |";
                    }
                    cout << endl << "----------------------------------------------------------------------------" << endl;
                    cout << endl;
                    system("pause");
                    break;

                case 'g':
                    //Salir del Administrador
                    session_logged = 0;
                    Menu();
                    break;
                default:{
                    cout << endl << "Error 404 -> Selecciona la opcion correctamente." << endl << endl;
                    system("pause");
                    loggedAsAdmin();
                    cout <<endl;
                    }
                    break;
                }
            }
    while(opcion != 'g');
        }
}

string VerMensaje(int n, int msjLength, string mensajes[]);

string EscribirMensaje(string logged, int clientesLength, string clientes[], string cedula[], string planRegistrado[]);

//Funcion Logueo
int logeoCliente(int clientesLength, string clientes[], int &session_logged, string &logged);

void loggedAsCliente(){
	if(session_logged == 2){
    char opcion;
        do{
            system("cls");
            cout << "----------------------------------------------" << endl;
            cout << "|*Cliente                                    |" << endl;
            cout << "-------------------Menu-----------------------" << endl;
            cout << "|a. Ver informacion y datos de sus  planes.  |" << endl;
            cout << "|b. Hacer una queja/sugerencia.              |" << endl;
            cout << "|c. Salir de sesion                          |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "\nOpcion: ";
            cin >> opcion;
            switch(opcion){
            case 'a':
                    cout << endl << "----------------------------------------------" << endl;
                    cout <<  "Informacion del cliente:"<<endl;
                    cout << endl;
                    for (int i=0; i< clientesLength+1; i++){
                        if (logged== clientes[i]){
                        cout << "*Cliente: "<< clientes[i] << endl;
                        cout << "*Cedula: " << cedula[i] << endl;
                        cout << "*Cantidad de cajas: " << cantCajas[i] << endl;
                        cout << "*Plan: " << planRegistrado[i] << endl;
                        cout << "*Mensualidad: " << mensualidad[i] << endl;
                        cout << "----------------------------------------------" << endl;
                        }


                    }
                    system("pause");
                    break;
            case 'b':
                    mensajes[msjLength]=EscribirMensaje(logged, clientesLength, clientes, cedula, planRegistrado);
                    msjLength++;
                    break;

            case 'c':{
                    session_logged = 0;
                    Menu();
                        }
                    break;
			default:{
                    cout << endl << "Error 404 -> Selecciona la opcion correctamente." << endl << endl;
                    system("pause");
                    loggedAsCliente();
                    cout <<endl;
                    }
                    break;
                }
            }
    while(opcion != 'c');
    }
}

//Funcion menu
void Menu()
{
    system("cls");
    cout << "----------------Menu Principal-----------------" << endl;
    cout << "|a. Iniciar sesion como usuario.              |" << endl;
    cout << "|b. Iniciar sesion como administrador.        |" << endl;
    cout << "|c. Cerrar programa.                          |" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "\nOpcion: ";
    char opcion;
    cin >> opcion;
    switch(opcion){
    case 'a':   if(logeoCliente(clientesLength, clientes, session_logged, logged)==0)
                    Menu();
                else
                    loggedAsCliente();
                break;
    case 'b':
                if(logeoAdmin(admins, adminspass, adminsLength, session_logged, logged)==0)
                    Menu();
                else
                    loggedAsAdmin();
                break;
    case 'c':
                cout << "\n\nVuelva pronto!";
                break;
    default:
                cout << endl << "Error 404 -> Selecciona la opcion correctamente." << endl << endl;
                system("pause");
                Menu();
                break;
    }

}

int main()
{
    for(int i=0; i<clientesLength; i++){

        int pos = BuscarCliente(clientes[i], clientesLength, clientes);
        mensualidad[i] = CalcularMensualidad(clientes[i], pos, planesLength, planRegistrado, Planes, precioBase, precioPorCaja, paqueteDeCanales, cantCajas);
    }

	Menu();
}
