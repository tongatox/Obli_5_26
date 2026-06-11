#include "Puntaje.h"

Puntaje::Puntaje(int valor)
{
    this->valor = valor;
    this->l = NULL;
    this->m = NULL;
}

int Puntaje::getValor()
{
    return this->valor;
}

void Puntaje::setValor(int valor)
{
    this->valor = valor;
}

Puntaje::~Puntaje()
{
}

void Puntaje::setLector(Lector *l)
{
    this->l = l;
}

void Puntaje::setMaterial(Material *m)
{
    this->m = m;
}
