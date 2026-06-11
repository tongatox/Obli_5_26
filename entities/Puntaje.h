#ifndef PUNTAJE
#define PUNTAJE

#include "Lector.h"
#include "Material.h"

class Puntaje
{
private:
    int valor;
    Lector* l;
    Material * m;
public:
    Puntaje(int valor);
    int getValor();
    void setValor(int valor);
    ~Puntaje();

    void setLector(Lector * l);
    void setMaterial(Material * m);
};



#endif