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
    linea(Estacion** _estaciones, string NombreLin, Estacion EstTransferencia, int NumEstaciones, int MaxCapacidad);
    ~linea();

    void mostrarLinea() const;

    void agregarEstacion(const Estacion& nuevaEstacion, int indice);
    void eliminarEstacion(const string& nombreEstacion);

    static linea crearLinea();
     static linea crearLinea(const linea& lineaAnterior);

public:
    // Declaración de la función seleccionarEstacionTransferencia
    static Estacion seleccionarEstacionTransferencia(const linea& lineaAnterior);


};

#endif // LINEA_H
