#ifndef USUARIOCOLLECTION
#define USUARIOCOLLECTION

#include <map>
#include <string>
#include "../entities/Usuario.h"

using namespace std;

class UsuarioCollection
{
private:
    static UsuarioCollection *instance;
    map<string, Usuario *> usuarios;
    UsuarioCollection();

public:
    static UsuarioCollection *getInstance();
    Usuario *buscarUsuario(string numid);
    void agregarUsuario(Usuario *usuario);
    void actualizarUsuario(Usuario *usuario);
    void eliminarUsuario(string numid);
    bool existeUsuario(string numid);

    virtual ~UsuarioCollection();
};

#endif