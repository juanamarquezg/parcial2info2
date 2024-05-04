#ifndef LINEA_H
#define LINEA_H
#include <string>
#include <estacion.h>
using namespace std;

class linea
{
private:
    Estacion** Estaciones;
    string NombreLinea;
    Estacion EstacionTransferencia;
    int ContadorEstaciones;
    int Capacidad;
public:
    linea(Estacion** _estaciones,string NombreLin,Estacion EstTransferencia,int MaxCapacidad);

    ~linea();

};

#endif // LINEA_H
