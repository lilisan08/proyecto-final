#include <iostream>
#include <vector>
using namespace std;

struct Persona {
    string nombre;
    int edad;
};
void crearPersona(vector<Persona>& personas) {
    Persona nuevaPersona;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nuevaPersona.nombre;
    cout << "Ingrese la edad de la persona: ";
    cin >> nuevaPersona.edad;
    personas.push_back(nuevaPersona);
    cout << "Persona creada exitosamente." << endl;
}
void mostrarPersonas(const vector<Persona>& personas) {
    cout << "Lista de personas:" << endl;
    for (const auto& persona : personas) {
        cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << endl;
    }
}
void actualizarEdad(vector<Persona>& personas, const string& nombre) {
    for (auto& persona : personas) {
        if (persona.nombre == nombre) {
            cout << "Ingrese la nueva edad para " << nombre << ": ";
            cin >> persona.edad;
            cout << "Edad actualizada exitosamente." << endl;
            return;
        }
    }
    cout << "Persona no encontrada." << endl;
}
void eliminarPersona(vector<Persona>& personas, const string& nombre) {
    for (auto it = personas.begin(); it != personas.end(); ++it) {
        if (it->nombre == nombre) {
            personas.erase(it);
            cout << "Persona eliminada exitosamente." << endl;
            return;
        }
    }
    cout << "Persona no encontrada." << endl;
}
int main() {
    vector<Persona> personas;
    int opcion;
    do {
        cout << "CRUD de Personas" << endl;
        cout << "1. Crear Persona" << endl;
        cout << "2. Mostrar Personas" << endl;
        cout << "3. Actualizar Edad" << endl;
        cout << "4. Eliminar Persona" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearPersona(personas);
                break;
            case 2:
                mostrarPersonas(personas);
                break;
            case 3:
                {
                    string nombre;
                    cout << "Ingrese el nombre de la persona a actualizar: ";
                    cin >> nombre;
                    actualizarEdad(personas, nombre);
                }
                break;
            case 4:
                {
                    string nombre;
                    cout << "Ingrese el nombre de la persona a eliminar: ";
                    cin >> nombre;
                    eliminarPersona(personas, nombre);
                }
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 5);
    return 0;
}