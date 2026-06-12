#ifndef CONTROLADORREGISTRARPRESTAMO
#define CONTROLADORREGISTRARPRESTAMO

#include "IControladorRegistrarPrestamo.h"

class ControladorRegistrarPrestamo : public IControladorRegistrarPrestamo
{
private:
    Fecha fechaPres;
    int diasPermi;   
    string numId;
    string codigo; 
public:
    void registrarPrestamo(Fecha fechaPres, int diasPermi, string numId, string codigo);
    void cancelarPrestamo();
    void confirmarPrestamo();
};

#endif
