#include "Lector.h"

Lector::Lector(string numid, string nombre, string contraseña, Fecha fechRegistro) : Usuario(numid, nombre, contraseña), fechRegistro(fechRegistro)
{

}

Fecha Lector::getFechRegistro()
{
    return fechRegistro;
}

void Lector::setFechRegistro(Fecha fechRegistro)
{
    this->fechRegistro = fechRegistro;
}

Lector::~Lector()
{
}

string Lector::getTipo()
{
    return "Lector";
}