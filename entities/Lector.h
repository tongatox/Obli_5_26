#ifndef LECTOR
#define LECTOR

#define MAX_PRESTAMO 10

#include <string>
using namespace std;

#include "Usuario.h"
#include "Fecha.h"
#include "Prestamo.h"

class Lector : public Usuario
{
private:
    Fecha fechRegistro;
    Prestamo * p[MAX_PRESTAMO];
    int topePres;
public:
    Lector(string numid, string nombre, string contraseña, Fecha fechRegistro);
    Fecha getFechRegistro();
    void setFechRegistro(Fecha fechRegistro);
    ~Lector();

    string getTipo();

    Prestamo ** getPrestamo();
    void agregarPrestamo(Prestamo *prestamo);

};

#endif