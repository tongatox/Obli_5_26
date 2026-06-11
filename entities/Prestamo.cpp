#include "Prestamo.h"

Prestamo::Prestamo(int id)
{
    this->id = id;
}

int Prestamo::getId()
{
    return this->id;
}

void Prestamo::setId(int id)
{
    this->id = id;
}

Prestamo::~Prestamo()
{
}
