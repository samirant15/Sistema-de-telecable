#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

//Funcion Buscar la posicion del administrador.
int BuscarAdministrador(string loginadmin, int adminsLength, string admins[]){
	for(int i=0; i<adminsLength; i++){
	    if(loginadmin == admins[i]){
	        return i;
	    }
	}
}

//Funcion Buscar la posicion del administrador.
int BuscarCliente(string loginCliente, int clientesLength, string clientes[]){
	for(int i=0; i<clientesLength; i++){
	    if(loginCliente == clientes[i]){
	        return i;
	    }
	}
}

int CalcularMensualidad(string name, int pos, int planesLength, string planRegistrado[], string Planes[], int precioBase[], int precioPorCaja[], int paqueteDeCanales[], int cantCajas[])
{
    int total, pBase,pCaja, pCanales;
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
int logeoAdmin(string admins[], string adminspass[], int adminsLength, int &session_logged, string &logged){
	string loginadmin;
	string loginadminpass;
	cout << "> Nombre: ";
    cin >> loginadmin;
    cout << "> Contraseña: ";
    cin >> loginadminpass;

    int pos = BuscarAdministrador(loginadmin, adminsLength, admins);
	if(loginadmin == admins[pos] && loginadminpass == adminspass[pos]){
			session_logged = 1;
			logged = loginadmin;
			return 1;
	} else {
		cout << endl << "ERROR: Su contraseña o nombre de usuario es incorrecto!" << endl << endl;
		system("pause");
		return 0;
	}
}

int CalcularIngresos(int clientesLength, int mensualidad[]){
    int ingresos = 0;
    for(int i=0; i<clientesLength; i++){
        ingresos+=mensualidad[i];
    }
    return ingresos;
}

string VerMensaje(int n, int msjLength, string mensajes[])
{
    n--;
    for(int i=0; i<msjLength; i++){
        if(n==i)
            return mensajes[i];
    }
}

//Funcion Logueo
int logeoCliente(int clientesLength, string clientes[], int &session_logged, string &logged){
	string loginCliente;
	cout << "> Cliente: ";
    cin >> loginCliente;
	int pos = BuscarCliente(loginCliente, clientesLength, clientes);

	if(loginCliente == clientes[pos]){
			session_logged = 2;
			logged = loginCliente;
			return 1;
	} else {
		cout << endl << "ERROR: Cliente no encontrado!" << endl << endl;
		system("pause");
		return 0;
	}
}

string EscribirMensaje(string logged, int clientesLength, string clientes[], string cedula[], string planRegistrado[])
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
    int pos = BuscarCliente(logged, clientesLength, clientes);
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


#endif // FUNCIONES_H_INCLUDED
