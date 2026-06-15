#include "Lector.h"

Lector::Lector(string numid, string nombre, string contraseña, Fecha fechRegistro) : Usuario(numid, nombre, contraseña), fechRegistro(fechRegistro)
{
    this->topePres = 0;
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

Prestamo **Lector::getPrestamo()
{
    Prestamo **ps = new Prestamo *[MAX_PRESTAMO];
    for (int i = 0; i < this->topePres; i++)
    {
        ps[i] = this->p[i];
    }
    return ps;
}

void Lector::agregarPrestamo(Prestamo *prestamo)
{
    this->p[this->topePres] = prestamo;
    this->topePres++;
}