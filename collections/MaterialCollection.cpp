#include "MaterialCollection.h"


MaterialCollection *MaterialCollection::instance = nullptr;

MaterialCollection* MaterialCollection::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MaterialCollection();
    }
    return instance;
}




MaterialCollection::MaterialCollection()
{
}

Material* MaterialCollection::buscarMaterial(string codigo)
{
    map<string, Material*>::iterator it = this->materiales.find(codigo);
    if (it != this->materiales.end())
    {
        return it->second;
    }
    return nullptr;
}

void MaterialCollection::agregarMaterial(Material* material)
{
    this->materiales[material->getCodigo()] = material;
}

void MaterialCollection::actualizarMaterial(Material* material)
{
    Material* existente = this->buscarMaterial(material->getCodigo());
    if (existente != nullptr)
    {
        existente->setTitulo(material->getTitulo());
        existente->setAnioPubli(material->getAnioPubli());
    }
}

void MaterialCollection::eliminarMaterial(string codigo)
{
    Material* material = this->buscarMaterial(codigo);
    if (material != nullptr)
    {
        delete material;
        this->materiales.erase(codigo);
    }
}

bool MaterialCollection::existeMaterial(string codigo)
{
    return this->materiales.find(codigo) != this->materiales.end();
}

MaterialCollection::~MaterialCollection()
{
    for (map<string, Material*>::iterator it = this->materiales.begin(); it != this->materiales.end(); ++it)
    {
        delete it->second;
    }
    this->materiales.clear();
}
