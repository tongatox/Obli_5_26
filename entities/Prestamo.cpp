#include "Prestamo.h"

Prestamo::Prestamo(Fecha fechasPres, int diasPermi) : fechasPres(fechasPres)
{
    this->diasPermi = diasPermi;
    this->material = NULL;
}

Fecha Prestamo::getFechasPres()
{
    return this->fechasPres;
}

int Prestamo::getDiasPermi()
{
    return this->diasPermi;
}

void Prestamo::setFechaPres(Fecha fechaPres)
{
    this->fechasPres = fechaPres;
}

void Prestamo::setDiasPermi(int diasPermi)
{
    this->diasPermi = diasPermi;
}

Prestamo::~Prestamo()
{
}

Material * Prestamo::getMaterial()
{
    return this->material;
}

void Prestamo::agregarMaterial(Material * material)
{
    this->material = material;
}
