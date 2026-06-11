#ifndef SESION
#define SESION

#include "Usuario.h"

class Sesion
{
private:
    bool sesion;
    Usuario * u;
public:
    Sesion(bool sesion);
    bool getSesion();
    ~Sesion();

    Usuario * getUsuarioSesion();
    void setUsuarioSesion(Usuario * u);

};



#endif