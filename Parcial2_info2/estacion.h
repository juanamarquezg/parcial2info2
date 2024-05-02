#ifndef ESTACION_H
#define ESTACION_H
#include <string>
using namespace std;

class Estacion {
private:
    int tiempo_anterior;
    int tiempo_siguiente;
    string nombre;

public:
    Estacion(int anterior, int siguiente, string nombre);

    ~Estacion();

    int getTiempoAnterior() const;
    void setTiempoAnterior(int anterior);

    int getTiempoSiguiente() const;
    void setTiempoSiguiente(int siguiente);

    string getNombre() const;
    void setNombre(string nombre);
};

#endif

