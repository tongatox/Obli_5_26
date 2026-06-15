#ifndef USUARIO
#define USUARIO

#include <string>
using namespace std;

class Usuario
{
private:
    string numid;
    string nombre;
    string contraseña;
public:
    Usuario(string numid, string nombre, string contraseña);
    string getNumid();
    string getNombre();
    string getContraseña();
    void setNumid(string numid);
    void setNombre(string nombre);
    void setContraseña(string contraseña);
    virtual ~Usuario();

    bool validarContraseña(string contraseña);
    virtual string getTipo() = 0;

};

#endif