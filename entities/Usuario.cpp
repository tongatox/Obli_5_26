#include "Usuario.h"

Usuario::Usuario(string numid, string nombre, string contraseña)
{
    this->numid = numid;
    this->nombre = nombre;
    this->contraseña = contraseña;
}

string Usuario::getNumid()
{
    return numid;
}

string Usuario::getNombre()
{
    return nombre;
}

string Usuario::getContraseña()
{
    return contraseña;
}

void Usuario::setNumid(string numid)
{
    this->numid = numid;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setContraseña(string contraseña)
{
    this->contraseña = contraseña;
}

Usuario::~Usuario()
{
}

bool Usuario::validarContraseña(string contraseña)
{
    return this->contraseña == contraseña;
}

