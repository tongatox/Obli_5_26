#ifndef USUARIOCOLLECTION
#define USUARIOCOLLECTION

#include <map>
#include <string>
#include "../entities/Usuario.h"

using namespace std;

class UsuarioCollection
{
private:
    map<string, Usuario*> usuarios;

public:
    UsuarioCollection();

    Usuario* buscarUsuario(string numid);
    void agregarUsuario(Usuario* usuario);
    void actualizarUsuario(Usuario* usuario);
    void eliminarUsuario(string numid);
    bool existeUsuario(string numid);

    ~UsuarioCollection();
};

#endif
