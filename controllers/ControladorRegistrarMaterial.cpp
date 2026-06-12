#include "ControladorRegistrarMaterial.h"

#include "MaterialCollection.h"
#include "Libro.h"
#include "Revista.h"



void ControladorRegistrarMaterial::registrarLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPag)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
    this->autor = autor;
    this->cantPag = cantPag;
}

void ControladorRegistrarMaterial::cancelarLibro()
{
    // Implementación del método para cancelar el registro de un libro
}

void ControladorRegistrarMaterial::confirmarLibro()
{
    MaterialCollection* mc = MaterialCollection::getInstance();
    Libro* l = new Libro(this->codigo, this->titulo, this->anioPublicacion, this->autor, this->cantPag);
    mc->agregarMaterial(l);
}

void ControladorRegistrarMaterial::registrarrevista(string codigo, string titulo, int anioPublicacion, int numEdi , bool esMensual )
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
    this->numEdi = numEdi;
    this->esMensual = esMensual;
}

void ControladorRegistrarMaterial::cancelarRevista()
{
    // Implementación del método para cancelar el registro de una revista
}

void ControladorRegistrarMaterial::confirmarRevista()
{
    MaterialCollection* mc = MaterialCollection::getInstance();
    Revista* r = new Revista(this->codigo, this->titulo, this->anioPublicacion, this->numEdi, this->esMensual);
    mc->agregarMaterial(r);
}

