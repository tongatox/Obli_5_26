#include "UsuarioCollection.h"

UsuarioCollection* UsuarioCollection::instance = nullptr;

UsuarioCollection::UsuarioCollection()
{
}


UsuarioCollection* UsuarioCollection::getInstance()
{
    if (instance == nullptr)
    {
        instance = new UsuarioCollection();
    }
    return instance;
}

Usuario* UsuarioCollection::buscarUsuario(string numid)
{
    map<string, Usuario*>::iterator it = this->usuarios.find(numid);
    if (it != this->usuarios.end())
    {
        return it->second;
    }
    return nullptr;
}

void UsuarioCollection::agregarUsuario(Usuario* usuario)
{
    this->usuarios[usuario->getNumid()] = usuario;
}

void UsuarioCollection::actualizarUsuario(Usuario* usuario)
{
    Usuario* existente = this->buscarUsuario(usuario->getNumid());
    if (existente != nullptr)
    {
        existente->setNombre(usuario->getNombre());
        existente->setContraseña(usuario->getContraseña());
    }
}

void UsuarioCollection::eliminarUsuario(string numid)
{
    Usuario* usuario = this->buscarUsuario(numid);
    if (usuario != nullptr)
    {
        delete usuario;
        this->usuarios.erase(numid);
    }
}

bool UsuarioCollection::existeUsuario(string numid)
{
    return this->usuarios.find(numid) != this->usuarios.end();
}

UsuarioCollection::~UsuarioCollection()
{
    for (map<string, Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        delete it->second;
    }
    this->usuarios.clear();
}