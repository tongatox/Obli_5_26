#ifndef ICONTROLADORREGISTRARPRESTAMO
#define ICONTROLADORREGISTRARPRESTAMO
#include "Usuario.h"
#include "Material.h"

class IControladorRegistrarPrestamo
{
public:
    virtual void registrarPrestamo(Fecha fechaPres, int diasPermi, string numId, string codigo) = 0;
    virtual void cancelarPrestamo() = 0;
    virtual void confirmarPrestamo() = 0;
    virtual ~IControladorRegistrarPrestamo() = default;
};

#endif