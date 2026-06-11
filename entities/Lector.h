#ifndef LECTOR
#define LECTOR

#include <string>
using namespace std;

#include "Usuario.h"
#include "Fecha.h"

class Lector : public Usuario
{
private:
    Fecha fechRegistro;

public:
    Lector(string numid, string nombre, string contraseña, Fecha fechRegistro);
    Fecha getFechRegistro();
    void setFechRegistro(Fecha fechRegistro);
    ~Lector();

    string getTipo();
};

#endif