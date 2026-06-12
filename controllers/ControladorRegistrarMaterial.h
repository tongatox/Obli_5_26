#ifndef CONTROLADORREGISTRARMATERIAL_H
#define CONTROLADORREGISTRARMATERIAL_H

#include "IControladorRegistrarMaterial.h"

class ControladorRegistrarMaterial : public IControladorRegistrarMaterial
{
    private:
    string codigo;
    string titulo;
    int anioPublicacion;
    string autor;
    int cantPag;
    int numEdi;
    bool esMensual;
public:
    void registrarLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPag) override;
    void cancelarLibro() override;
    void confirmarLibro() override;
    void registrarrevista(string codigo, string titulo, int anioPublicacion, int numEdi , bool esMensual ) override;
    void cancelarRevista() override;
    void confirmarRevista() override;
};

#endif // CONTROLADORREGISTRARMATERIAL_H