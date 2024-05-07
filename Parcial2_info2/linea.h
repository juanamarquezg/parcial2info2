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
    ~linea();

    //     Fruta() : nombre("Desconocida"), color("Desconocido"), precio(0.0) {}
//    linea() : Estaciones(NULL),NombreLinea("desconocido"),ContadorEstaciones(0),Capacidad(0){} ;//prueba



    void mostrarLinea() const;
    static linea crearLinea();
    void agregarEstacion(const Estacion& nuevaEstacion, int indice);
    void eliminarEstacion(const string& nombreEstacion);


    /*static linea crearLinea(const linea& lineaAnterior, const string& nombreEstacionTransferencia);*///xd

public:
    // Declaración de la función seleccionarEstacionTransferencia
   void seleccionarEstacionTransferencia(const string& nombreEstacion);

};

#endif // LINEA_H
