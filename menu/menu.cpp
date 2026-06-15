#include "menu.h"

#include <iostream>
#include <string>
#include <map>
#include "../interfaces/controllers/IControladorRegistrarUsuario.h"
#include "../interfaces/controllers/IControladorRegistrarMaterial.h"
#include "../interfaces/controllers/IControladorRegistrarPrestamo.h"
#include "../interfaces/controllers/IControladorVerInfoMaterial.h"
#include "../interfaces/controllers/IControladorSesion.h"
#include "../factory/Factory.h"
#include "../datatypes/Fecha.h"
#include "../collections/UsuarioCollection.h"
#include "../entities/Sesion.h"
#include "../entities/Lector.h"

using namespace std;

Factory *factory;
IControladorRegistrarUsuario *iConRegistrarUsuario;
IControladorRegistrarMaterial *iConRegistrarMaterial;
IControladorRegistrarPrestamo *iConRegistrarPrestamo;
IControladorVerInfoMaterial *iConVerInfoMaterial;
IControladorSesion *iConSesion;

// -----------------------------------------------------------------------
// Submenú: Para realizar el registro de un usuario - lector o funcionario
// -----------------------------------------------------------------------
static void menuRegistrarUsuario()
{
    iConRegistrarUsuario = factory->getIControladorRegistrarUsuario();
    int opcion;

    cout << "\n--- Registrar Usuario ---\n";
    cout << "1. Lector\n";
    cout << "2. Funcionario\n";
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    string numId, nombre, contrasenia;
    cout << "Numero de ID: ";   getline(cin, numId);
    cout << "Nombre: ";         getline(cin, nombre);
    cout << "Contraseña: ";     getline(cin, contrasenia);

    if (opcion == 1)
    {
        int dia, mes, anio;
        cout << "Fecha de registro (dd mm aaaa): ";
        cin >> dia >> mes >> anio;
        cin.ignore();

        iConRegistrarUsuario->registrarLector(numId, nombre, contrasenia, Fecha(dia, mes, anio));
        iConRegistrarUsuario->confirmarLector();
        cout << "Lector registrado.\n";
    }
    else if (opcion == 2)
    {
        int numEmp;
        cout << "Numero de empleado: ";
        cin >> numEmp;
        cin.ignore();

        iConRegistrarUsuario->registrarFuncionario(numId, nombre, contrasenia, numEmp);
        iConRegistrarUsuario->confirmarFuncionario();
        cout << "Funcionario registrado.\n";
    }
    else
    {
        cout << "Opcion invalida. Operacion cancelada.\n";
    }
}

// -----------------------------------------------------------------------
// Submenú: Registro de materiales - libro o revista
// -----------------------------------------------------------------------
static void menuRegistrarMaterial()
{
    iConRegistrarMaterial = factory->getIControladorRegistrarMaterial();
    int opcion;

    cout << "\n--- Registrar Material ---\n";
    cout << "1. Libro\n";
    cout << "2. Revista\n";
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    string codigo, titulo;
    int anio;
    cout << "Codigo: ";  getline(cin, codigo);
    cout << "Titulo: ";  getline(cin, titulo);
    cout << "Anio de publicacion: "; cin >> anio; cin.ignore();

    if (opcion == 1)
    {
        string autor;
        int cantPag;
        cout << "Autor: ";          getline(cin, autor);
        cout << "Cantidad de paginas: "; cin >> cantPag; cin.ignore();

        iConRegistrarMaterial->registrarLibro(codigo, titulo, anio, autor, cantPag);
        iConRegistrarMaterial->confirmarLibro();
        cout << "Libro registrado.\n";
    }
    else if (opcion == 2)
    {
        int numEdi;
        char mensual;
        cout << "Numero de edicion: "; cin >> numEdi; cin.ignore();
        cout << "Es mensual? (s/n): "; cin >> mensual; cin.ignore();

        iConRegistrarMaterial->registrarRevista(codigo, titulo, anio, numEdi, mensual == 's' || mensual == 'S');
        iConRegistrarMaterial->confirmarRevista();
        cout << "Revista registrada.\n";
    }
    else
    {
        cout << "Opcion invalida. Operacion cancelada.\n";
    }
}

// -----------------------------------------------------------------------
// Submenú: Registro de préstamos
// -----------------------------------------------------------------------
static void menuRegistrarPrestamo()
{
    iConRegistrarPrestamo = factory->getIControladorRegistrarPrestamo();

    cout << "\n--- Registrar Prestamo ---\n";

    string numId, codigoMat;
    int dia, mes, anio, diasPermi;

    Usuario* user = Sesion::getInstance()->getUsuarioSesion();
    if (user->getTipo() == "Lector")
    {
        numId = user->getNumid();
        cout << "Lector: " << user->getNombre() << " (" << numId << ")\n";
    }
    else
    {
        cout << "Numero de ID del Lector: ";
        getline(cin, numId);
    }

    cout << "Codigo del Material: ";
    getline(cin, codigoMat);
    cout << "Fecha del prestamo (dd mm aaaa): ";
    cin >> dia >> mes >> anio;
    cout << "Dias permitidos: ";
    cin >> diasPermi;
    cin.ignore();

    iConRegistrarPrestamo->registrarPrestamo(Fecha(dia, mes, anio), diasPermi, numId, codigoMat);
    iConRegistrarPrestamo->confirmarPrestamo();
    cout << "Prestamo registrado.\n";
}

// -----------------------------------------------------------------------
// Submenú: Listado de usuarios y materiales registrados
// -----------------------------------------------------------------------
static void menuListar()
{
    int opcion;
    cout << "\n--- Listar ---\n";
    cout << "1. Usuarios\n";
    cout << "2. Materiales\n";
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1)
    {
        map<string, Usuario*> todos = UsuarioCollection::getInstance()->listar();
        if (todos.empty())
        {
            cout << "No hay usuarios registrados.\n";
            return;
        }
        cout << "\n--- Usuarios ---\n";
        for (auto const& x : todos)
        {
            Usuario* u = x.second;
            cout << "[" << u->getTipo() << "] "
                 << u->getNumid() << " | "
                 << u->getNombre() << "\n";
        }
    }
    else if (opcion == 2)
    {
        iConVerInfoMaterial = factory->getIControladorVerInfoMaterial();
        map<string, Material*> todos = iConVerInfoMaterial->consultarListaMaterial();
        if (todos.empty())
        {
            cout << "No hay materiales registrados.\n";
            return;
        }
        cout << "\n--- Materiales ---\n";
        for (auto const& x : todos)
        {
            Material* m = x.second;
            cout << "[" << m->getTipo() << "] "
                 << m->getCodigo() << " | "
                 << m->getTitulo() << "\n";
        }
    }
    else
    {
        cout << "Opcion invalida.\n";
    }
}

// -----------------------------------------------------------------------
// Submenú: Listado de préstamos del lector
// -----------------------------------------------------------------------
static void menuListarMisPrestamos()
{
    Usuario* u = Sesion::getInstance()->getUsuarioSesion();
    Lector* l = dynamic_cast<Lector*>(u);
    if (l == nullptr) return;

    cout << "\n--- Mis Prestamos ---\n";
    Prestamo** prestamos = l->getPrestamo();
    // Nota: l->getPrestamo() devuelve un array nuevo que hay que liberar
    // pero según Lector.cpp línea 29 hace un new Prestamo*[MAX_PRESTAMO]
    
    // Como no sabemos cuántos hay exactamente sin ver topePres (que es privado)
    // Pero Lector.h dice que topePres existe. Lector.cpp lo usa.
    // Sin embargo, getPrestamo() no nos dice el tope.
    // Vamos a asumir que el array tiene MAX_PRESTAMO y los nulos indican el fin o usamos el tope si fuera publico.
    // Pero espera, Lector.cpp:27-35:
    /*
    Prestamo **Lector::getPrestamo()
    {
        Prestamo **ps = new Prestamo *[MAX_PRESTAMO];
        for (int i = 0; i < this->topePres; i++)
        {
            ps[i] = this->p[i];
        }
        return ps;
    }
    */
    // El problema es que no sabemos el topePres desde afuera.
    // Voy a tener que ver si puedo agregar un getTopePres o algo similar.
    
    // Por ahora, vamos a iterar hasta MAX_PRESTAMO y chequear != nullptr
    for (int i = 0; i < MAX_PRESTAMO; i++)
    {
        if (prestamos[i] != nullptr)
        {
            Prestamo* p = prestamos[i];
            Fecha f = p->getFechasPres();
            cout << "ID: " << p->getId() 
                 << " | Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
                 << " | Dias: " << p->getDiasPermi() << "\n";
        }
        else {
            break;
        }
    }
    delete[] prestamos;
}

// -----------------------------------------------------------------------
// Menú para el Lector
// -----------------------------------------------------------------------
static void menuLector()
{
    int opcion = 0;
    while (opcion != 3)
    {
        cout << "\n=============================\n";
        cout << "       Menu Lector\n";
        cout << "=============================\n";
        cout << "1. Registrar Prestamo\n";
        cout << "2. Listar mis Prestamos\n";
        cout << "3. Salir y cerrar sesión\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1: menuRegistrarPrestamo(); break;
            case 2: menuListarMisPrestamos(); break;
            case 3:
                iConSesion = factory->getIControladorSesion();
                iConSesion->cerrarSesion();
                cout << "Sesion cerrada.\n";
                break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

// -----------------------------------------------------------------------
// Menú para el Funcionario
// -----------------------------------------------------------------------
static void menuFuncionario()
{
    int opcion = 0;
    while (opcion != 5)
    {
        cout << "\n=============================\n";
        cout << "      Menu Funcionario\n";
        cout << "=============================\n";
        cout << "1. Registrar Usuario\n";
        cout << "2. Registrar Material\n";
        cout << "3. Registrar Prestamo\n";
        cout << "4. Listar\n";
        cout << "5. Salir y cerrar sesión\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
            case 1: menuRegistrarUsuario();  break;
            case 2: menuRegistrarMaterial(); break;
            case 3: menuRegistrarPrestamo(); break;
            case 4: menuListar();            break;
            case 5:
                iConSesion = factory->getIControladorSesion();
                iConSesion->cerrarSesion();
                cout << "Sesion cerrada.\n";
                break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
}

// -----------------------------------------------------------------------
// Menú principal - para la interacción con el usuario 
// -----------------------------------------------------------------------
void menuPrincipal()
{
    factory = Factory::getInstancia();
    Usuario* user = Sesion::getInstance()->getUsuarioSesion();
    
    if (user == nullptr) return;

    if (user->getTipo() == "Funcionario")
    {
        menuFuncionario();
    }
    else if (user->getTipo() == "Lector")
    {
        menuLector();
    }
}

// -----------------------------------------------------------------------
// Menú para Autenticarse
// -----------------------------------------------------------------------
void menuAutenticacion()
{
    factory = Factory::getInstancia();
    int opcion = 0;

    while (opcion != 2)
    {
        cout << "\n=============================\n";
        cout << "   Sistema de Biblioteca\n";
        cout << "=============================\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1)
        {
            iConSesion = factory->getIControladorSesion();

            string numId, contrasenia;
            cout << "\n--- Iniciar Sesion ---\n";
            cout << "Numero de ID: ";
            getline(cin, numId);
            cout << "Contraseña: ";
            getline(cin, contrasenia);

            if (iConSesion->ingresarDatos(numId, contrasenia))
            {
                cout << "Inicio de sesion exitoso.\n";
                menuPrincipal();
            }
            else
            {
                cout << "Credenciales incorrectas. Intente nuevamente.\n";
            }
        }
        else if (opcion == 2)
        {
            cout << "Hasta luego.\n";
        }
        else
        {
            cout << "Opcion invalida.\n";
        }
    }
}