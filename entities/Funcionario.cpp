#include "Funcionario.h"

Funcionario::Funcionario(string numId, string nombre, string contraseña, int numEmp) : Usuario(numId, nombre, contraseña)
{
    this->numEmp = numEmp;
}


int Funcionario::getNumEmp()
{
    return this->numEmp;
}

void Funcionario::setNumEmp(int numEmp)
{
    this->numEmp = numEmp;
}

Funcionario::~Funcionario()
{

}


string Funcionario::getTipo()
{
    return "Funcionario";
}