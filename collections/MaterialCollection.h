#ifndef MATERIALCOLLECTION
#define MATERIALCOLLECTION

#include <map>
#include <string>
#include "../entities/Material.h"

using namespace std;

class MaterialCollection
{
private:
    static MaterialCollection *instance;
    map<string, Material *> materiales;
    MaterialCollection();

public:
    static MaterialCollection *getInstance();
    Material *buscarMaterial(string codigo);
    void agregarMaterial(Material *material);
    void actualizarMaterial(Material *material);
    void eliminarMaterial(string codigo);
    bool existeMaterial(string codigo);

    ~MaterialCollection();
};

#endif
