#ifndef ESTACION_H
#define ESTACION_H
#include <string>
#include <globals.h>
using namespace std;

class Estacion {
private:
    int tiempo_anterior;
    int tiempo_siguiente;
    string nombre;
    bool transferencia;

public:
    Estacion(int anterior, int siguiente, string nombre,bool esttransferencia);

    ~Estacion();

    int getTiempoAnterior() const;
    void setTiempoAnterior(int anterior);

    int getTiempoSiguiente() const;
    void setTiempoSiguiente(int siguiente);

    string getNombre() const;
    void setNombre(string nombre);

    bool getTransferencia() const;
    void setTransferencia(bool esttranferencia);
};

#endif

