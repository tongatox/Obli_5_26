#include "Libro.h"

Libro::Libro(string codigo, string titulo, int anioPublicado, string autor, int cantPa) : Material(codigo, titulo, anioPublicado)
{
    this->autor = autor;
    this->cantPag = cantPa;
}

string Libro::getAutor()
{
    return this->autor;
}

int Libro::getCantPag()
{
    return this->cantPag;
}

void Libro::setAutor(string autor)
{
    this->autor = autor;
}

void Libro::setCantPag(int cantPag)
{
    this->cantPag = cantPag;
}

Libro::~Libro()
{
}

string Libro::getTipo()
{
    return "Libro";
}