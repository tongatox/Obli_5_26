#ifndef PRESTAMOCOLLECTION
#define PRESTAMOCOLLECTION

#include <map>
#include "../entities/Prestamo.h"

using namespace std;

class PrestamoCollection
{
private:
    map<int, Prestamo*> prestamos;

public:
    PrestamoCollection();

    Prestamo* buscarPrestamo(int id);
    void agregarPrestamo(Prestamo* prestamo);
    void actualizarPrestamo(Prestamo* prestamo);
    void eliminarPrestamo(int id);
    bool existePrestamo(int id);

    ~PrestamoCollection();
};

#endif
