#ifndef FUNCIONARIO
#define FUNCIONARIO

#include "Usuario.h"
#include <string>

using namespace std;


class Funcionario : public Usuario
{
private:
    int numEmp;
public:
    Funcionario(string numId, string nombre, string contraseña, int numEmp);
    int getNumEmp();
    void setNumEmp(int numEmp);
    ~Funcionario();

    string getTipo();
};

#endif