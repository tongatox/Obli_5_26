#ifndef CONTROLADORREGISTRARUSUARIO_H
#define CONTROLADORREGISTRARUSUARIO_H

#include "IControladorRegistrarUsuario.h"
#include "UsuarioCollection.h"
#include "Usuario.h"
#include "Fecha.h"

class ControladorRegistrarUsuario : public IControladorRegistrarUsuario
{
private:
    string numId;
    string nombre;
    string contraseña;
    Fecha fechaRegistro;
    int numEmp;

public:
    void registrarLector(string numId, string nombre, string contraseña, Fecha fechaRegistro);
    void cancelarLector();
    void confirmarLector();
    void registrarFuncionario(string numId, string nombre, string contraseña, int numEmp);
    void cancelarFuncionario();
    void confirmarFuncionario();
};

#endif