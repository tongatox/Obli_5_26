#ifndef PRESTAMO
#define PRESTAMO

#include "Material.h"
#include "Fecha.h"

class Prestamo
{
private:
    Fecha fechasPres;
    int diasPermi;
    Material * material;
public:
    Prestamo(Fecha fechasPres, int diasPermi);
    Fecha getFechasPres();
    int getDiasPermi();
    void setFechaPres(Fecha fechaPres);
    void setDiasPermi(int diasPermi);
    ~Prestamo();

    Material *getMaterial();
    void agregarMaterial(Material * material);
    
};

#endif