#ifndef LINEA_H
#define LINEA_H
#include <string>
#include <estacion.h>
#include <globals.h>
using namespace std;

class linea
{
private:
    Estacion** Estaciones;
    string NombreLinea;
    int ContadorEstaciones;
    int Capacidad;

public:
    linea();
    linea(Estacion** _estaciones, string NombreLin, int NumEstaciones, int MaxCapacidad);
//    ~linea();

    void mostrarLinea() const;
    static linea crearLinea();
    void agregarEstacion(const Estacion& nuevaEstacion, int indice);
    void eliminarEstacion(const string& nombreEstacion);
    int getContadorEstaciones()const;
    void setEstaciones(Estacion** _estaciones);
    Estacion**getEstaciones() const;
    void seleccionarEstacionTransferencia(const string& nombreEstacion);
    string getNombreLinea() const;
    int calcularTiempoEntreEstaciones(const string& nombreEstacionInicio, const string& nombreEstacionFin) const;

};

#endif // LINEA_H
