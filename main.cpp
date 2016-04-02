#include <iostream>

using namespace std;

int main()
{
    //Administradores
    int adminsLength = 3;
    string admins[20] = {"JuanDi", "Cristian", "Samir"};

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

}
