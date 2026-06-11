#ifndef REVISTA
#define REVISTA

#include "Material.h"

class Revista : public Material
{
private:
    int numEdi;
    bool esMensual;
public:
    Revista(string codigo, string titulo, int anioPublicado, int numEdi, bool esMenusal);
    int getNumEdi();
    bool getEsMensual();
    void setNumEdi(int numEdi);
    void setEsMensual(bool esMensual);
    ~Revista();

    string getTipo();
};




#endif