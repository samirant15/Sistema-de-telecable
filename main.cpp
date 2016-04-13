#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

string EscribirMensaje();

string loginadmin;
string loginadminpass;
int session_logged = 0;
string mensajes[20];
int msjLength = 0;
string logged;

//Administradores
int adminsLength = 3;
string admins[20] = {"JuanDi", "Cristian", "Samir"};
string adminspass[20] = {"lolo123","cristian123", "samir123"};

//Planes
int planesLength = 4;
string Planes[10] = {"Sencillo", "Normal", "Bueno", "Premium"};
int precioBase[10] = {200, 300, 500, 800};
int paqueteDeCanales[10] = {5, 10, 15, 20};
int precioPorCaja[10] = {100, 150, 200, 300};

//Clientes
int clientesLength = 4;
string clientes[50] = {"Pedro", "Jose", "Estephany", "Saul"};
string cedula[50] = {"13520314789", "51234756932", "13604893265", "635586901275"}; //las cedulas tienen 11 numeros
string planRegistrado[50] = {"Normal", "Bueno", "Premium", "Normal"};
int cantCajas[50] = {2, 1, 3, 5};
int mensualidad[50] = {};//Hay que calcularla con el plan y la cantidad de cajas

void Menu();
string VerMensaje(int n);

//Funcion Buscar la posicion del administrador.
int BuscarAdministrador(string loginadmin){
	for(int i=0; i<adminsLength; i++){
	    if(loginadmin == admins[i]){
	        return i;
	    }
	}
}

//Funcion Buscar la posicion del administrador.
int BuscarCliente(string loginCliente){
	for(int i=0; i<clientesLength; i++){
	    if(loginCliente == clientes[i]){
	        return i;
	    }
	}
}

int CalcularMensualidad(string name)
{
    int total, pBase,pCaja, pCanales;
    int pos;
    pos = BuscarCliente(name);

    for(int i=0; i<planesLength; i++){
            if(planRegistrado[pos]==Planes[i]){
                pBase = precioBase[i];
                pCaja = precioPorCaja[i];
                pCanales = paqueteDeCanales[i]*100;
            }
    }

    total = pBase + (cantCajas[pos]*pCaja) + (pCanales);
    return total;
}

//Funcion Logueo
void logeoAdmin(){
	string loginadmin;
	cout << "> Nombre: ";
    cin >> loginadmin;
    cout << "> Contraseña: ";
    cin >> loginadminpass;
	int pos = BuscarAdministrador(loginadmin);

	if(loginadmin == admins[pos] && loginadminpass == adminspass[pos]){
			session_logged = 1;
			logged = loginadmin;
	} else {
		cout << endl << "ERROR: Su contraseña o nombre de usuario es incorrecto!" << endl << endl;
		system("pause");
		Menu();;
	}
}

int CalcularIngresos(){
    int ingresos = 0;
    for(int i=0; i<clientesLength; i++){
        ingresos+=mensualidad[i];
    }
    return ingresos;
}

void loggedAsAdmin(){
	if(session_logged == 1){
        char opcion;
        do{
            system("cls");
            cout << "----------------------------------------------" << endl;
            cout << "|*Administrador                              |" << "   -----------------------------" << endl;
            cout << "-------------------Menu-----------------------" << "   |Cant. de clientes: \t" << clientesLength << "    |" << endl;
            cout << "|a. Agregar clientes.                        |" << "   |Mensajes:          \t" << msjLength << "    |" << endl;
            cout << "|b. Borrar Clientes.                         |" << "   |Ingresos bruto:\t" << CalcularIngresos() << " |" << endl;
            cout << "|c. Ver quejas/sugerencias.                  |" << "   -----------------------------" << endl;
            cout << "|d. Agregar un plan.                         |" << endl;
            cout << "|e. Modificar un plan.                       |" << endl;
            cout << "|f. Salir del Administrador.                 |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "\nOpcion: ";
            cin >> opcion;
            string msj;
            char op;
            string nombEl;
            string plan="";
            switch(opcion){
                case 'a':
                    //Colocar Funcion de Agregar Clientes
                    cout << "Inserte el nombre del cliente" <<endl;
                    cin >> clientes[clientesLength];
                    cout << endl;
                    for (int i=0; i<clientesLength+1; i++){
                    	cout << clientes[i] << endl;
                    }
                    //JuanDiego - AgregarCedulaDelCliente//
                    cout << "Inserte la cedula del cliente" <<endl;
                    cin >> cedula[clientesLength];
                    cout << endl;

					for(int i=0; i<clientesLength+1; i++){
                    	cout << clientes[i] << " - " << cedula[i] << endl;
					}


					//Agregar Plan del Cliente
					while(plan==""){
                        cout << "Inserte plan del cliente" <<endl;
                        cin >> plan;
                        cout << endl;
                        for(int i=0; i<planesLength; i++){
                            if(Planes[i] == plan){
                                planRegistrado[clientesLength]=plan;
                                for(int j=0; j<clientesLength+1; j++){
                                    cout << clientes[j] << " - " << planRegistrado[j] << endl;
                                }
                                break;
                            }
                            if(i==planesLength-1)
                                plan="";
                        }
					}


					//
					//Agregar Cajitas del Cliente
					cout << "Inserte cantidad de cajitas" <<endl;
                    cin >> cantCajas[clientesLength];
                    cout << endl;

					for(int i=0; i<clientesLength+1; i++){
                    	cout << clientes[i] << " - " << cantCajas[i] << endl;
					}
                    cout << endl;

					mensualidad[clientesLength] = CalcularMensualidad(clientes[clientesLength]);

					clientesLength++;
                    cout << endl;
                    system("pause");
                    break;
                case 'b':
                    //Colocar Funcion de Borrar Clientes
                    cout << "Inserte el nombre del cliente que desee borrar" <<endl;
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
                             clientesLength--;
                         }
                }
                            cout <<endl;
                    for (int i=0; i<clientesLength; i++){
                                    cout << clientes[i]<< " , ";
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
                        msj = VerMensaje(n);
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
                    cout << "Inserte el nombre del plan" <<endl;
                    cin >> Planes[planesLength];
                    cout << endl;

                    cout << "Inserte el precio base del plan" <<endl;
                    cin >> precioBase[planesLength];
                    cout << endl;

                    cout << "Inserte la cantidad de canales del plan" <<endl;
                    cin >> paqueteDeCanales[planesLength];
                    cout << endl;

                    cout << "Inserte el precio por caja" <<endl;
                    cin >> precioPorCaja[planesLength];
                    cout << endl;

                    planesLength++;

                    for (int i=0; i<planesLength+1; i++){
                    	cout << Planes[i] << endl;
                    }
                    system("pause");
                    break;

                case 'e':
                    //Modificar un Plan
                    cout << "Planes disponibles: ";
                    for(int i=0; i<planesLength; i++){
                        cout << Planes[i];
                        if(i!=planesLength-1)
                            cout << ", ";
                        else
                            cout << "." << endl;
                    }

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
                                        mensualidad[i]=CalcularMensualidad(clientes[i]);
                                    }
                                    system("pause");
                                    break;
                                }
                                if(i==planesLength-1)
                                plan="";
                            }

                        }
                    break;
                case 'f':
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
    while(opcion != 'f');
        }
}

string VerMensaje(int n)
{
    n--;
    for(int i=0; i<msjLength; i++){
        if(n==i)
            return mensajes[i];
    }
}

//Funcion Logueo
void logeoCliente(){
	string loginCliente;
	cout << "> Cliente: ";
    cin >> loginCliente;
	int pos = BuscarCliente(loginCliente);

	if(loginCliente == clientes[pos]){
			session_logged = 2;
			logged = loginCliente;
	} else {
		cout << endl << "ERROR: Cliente no encontrado!" << endl << endl;
		system("pause");
		Menu();
	}
}

void loggedAsCliente(){
	if(session_logged == 2){
    char opcion;
        do{
            system("cls");
            cout << "----------------------------------------------" << endl;
            cout << "|*Cliente                                    |" << endl;
            cout << "-------------------Menu-----------------------" << endl;
            cout << "|a. Hacer una queja/sugerencia.              |" << endl;
            cout << "|b. Ver informacion y datos de sus  planes   |" << endl;
            cout << "|c. ----------                               |" << endl;
            cout << "|d. Salir de sesion                          |" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "\nOpcion: ";
            cin >> opcion;
            switch(opcion){
            case 'a':
                    mensajes[msjLength]=EscribirMensaje();
                    msjLength++;
                    break;

            case 'b':
                    cout << "Informacion de los clientes"<<endl;
                    cout <<endl;
                    for (int i=0; i< clientesLength+1; i++){
                        if (logged== clientes[i]){
                        cout << "*Cliente: "<< clientes[i] << endl;
                        cout << "*Cedula: " << cedula[i] << endl;
                        cout << "*Cantidad de cajas: " << cantCajas[i] << endl;
                        cout << "*Plan: " << planRegistrado[i] << endl;
                        cout << "*Mensualidad: " << mensualidad[i] << endl;
                        }


                    }
                    system("pause");
                    break;

            case 'd':{
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
    while(opcion != 'd');
    }
}

string EscribirMensaje()
{
    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "|*Escribir queja/sugerencia                  |" << endl;
    cout << "----------------------------------------------" << endl << endl;
    cout << "*Usted tiene disponible 20 lineas para escribir su mensaje\n";
    cout << "*Tambien puede finalizar el mensaje escribiendo el simbolo: !\n\n\n";
    cout << "-Dijite su mensaje:\n";
    cout <<"----------------------------------------------------------------------\n";
    string temp = "", msj = "";
    int lines = 0;
    int pos = BuscarCliente(logged);
    msj+= "*Escrito por:";
    msj+= logged;
    msj+= "\n*Cedula:";
    msj+= cedula[pos];
    msj+= "\n*Plan:";
    msj+= planRegistrado[pos];
    msj+= "\n\n";
    while(lines<=20 && temp!="!"){
        getline(cin, temp);
        if(temp!="!")
            msj+=temp;
        msj+="\n";
        lines+=1;
    };
    cout <<"\n----------------------------------------------------------------------\n";
    cout << "Su mensaje fue enviado exitosamente a los administradores del sistema.\nGracias por su colaboracion.\n\n";
    system("pause");
    return msj;
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
    case 'a':   logeoCliente();
                loggedAsCliente();
                break;
    case 'b':
                logeoAdmin();
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
        mensualidad[i]=CalcularMensualidad(clientes[i]);
    }

	Menu();
}
