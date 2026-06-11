#ifndef MATERIALCOLLECTION
#define MATERIALCOLLECTION

#include <map>
#include <string>
#include "../entities/Material.h"

using namespace std;

class MaterialCollection
{
private:
    
    map<string, Material*> materiales;

public:
    MaterialCollection();

    Material* buscarMaterial(string codigo);
    void agregarMaterial(Material* material);
    void actualizarMaterial(Material* material);
    void eliminarMaterial(string codigo);
    bool existeMaterial(string codigo);

    ~MaterialCollection();
};

#endif
