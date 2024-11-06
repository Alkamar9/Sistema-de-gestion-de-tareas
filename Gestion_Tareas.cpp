#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

// Estructura para una tarea
struct Tarea {
    string nombre;
    int prioridad;
    time_t fechaVencimiento;

    Tarea(string n, int p, time_t fecha) : nombre(n), prioridad(p), fechaVencimiento(fecha) {}

    // Operador para comparar prioridades en la cola
    bool operator<(const Tarea& otra) const {
        return prioridad < otra.prioridad; // Menor prioridad primero
    }

    // Función para mostrar la fecha de vencimiento en formato bonito
    string fechaFormato() const {
        char buffer[80];
        struct tm* timeinfo = localtime(&fechaVencimiento);
        strftime(buffer, sizeof(buffer), "%d/%m/%Y", timeinfo);
        return string(buffer);
    }   
};

// Clase para el sistema de gestión de tareas
class SistemaGestionTareas {
private:
    priority_queue<Tarea> colaPrioridad;
    list<Tarea> listaTareas;

public:
    // Agregar tarea
    void agregarTarea(const string& nombre, int prioridad, time_t fechaVencimiento) {
        Tarea nuevaTarea(nombre, prioridad, fechaVencimiento);
        colaPrioridad.push(nuevaTarea);
        listaTareas.push_back(nuevaTarea);
        cout << "✅ Tarea agregada: " << nombre << " (Prioridad: " << prioridad << ")\n";
    }

    // Mostrar tareas ordenadas por prioridad
    void mostrarTareasPorPrioridad() const {
        cout << "\n📋 Tareas ordenadas por prioridad:\n";
        auto tempCola = colaPrioridad;
        while (!tempCola.empty()) {
            Tarea t = tempCola.top();
            tempCola.pop();
            cout << "- " << t.nombre << " | Prioridad: " << t.prioridad << " | Vence: " << t.fechaFormato() << "\n";
        }
    }

    // Eliminar una tarea específica
    void eliminarTarea(const string& nombre) {
        for (auto it = listaTareas.begin(); it != listaTareas.end(); ++it) {
            if (it->nombre == nombre) {
                listaTareas.erase(it);
                cout << "❌ Tarea eliminada: " << nombre << "\n";
                return;
            }
        }
        cout << "⚠️ Tarea no encontrada: " << nombre << "\n";
    }

    // Mostrar todas las tareas
    void mostrarTodasLasTareas() const {
        cout << "\n📚 Lista de todas las tareas:\n";
        for (const auto& tarea : listaTareas) {
            cout << "- " << tarea.nombre << " | Prioridad: " << tarea.prioridad << " | Vence: " << tarea.fechaFormato() << "\n";
        }
    }

    // Menú principal para la gestión de tareas
    void menuPrincipal() {
        int opcion;
        do {
            cout << "\n=== Menú de Gestión de Tareas ===\n";
            cout << "1. Agregar tarea\n";
            cout << "2. Mostrar tareas por prioridad\n";
            cout << "3. Eliminar tarea\n";
            cout << "4. Mostrar todas las tareas\n";
            cout << "0. Salir\n";
            cout << "Seleccione una opción: ";
            cin >> opcion;

            string nombre;
            int prioridad;
            time_t fechaVencimiento;
            switch (opcion) {
                case 1:
                    cout << "Ingrese el nombre de la tarea: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Ingrese la prioridad (1 = Alta, 3 = Baja): ";
                    cin >> prioridad;
                    fechaVencimiento = time(0) + 86400 * prioridad; // Solo como ejemplo de fecha futura
                    agregarTarea(nombre, prioridad, fechaVencimiento);
                    break;
                case 2:
                    mostrarTareasPorPrioridad();
                    break;
                case 3:
                    cout << "Ingrese el nombre de la tarea a eliminar: ";
                    cin.ignore();
                    getline(cin, nombre);
                    eliminarTarea(nombre);
                    break;
                case 4:
                    mostrarTodasLasTareas();
                    break;
                case 0:
                    cout << "👋 Saliendo del sistema de gestión de tareas.\n";
                    break;
                default:
                    cout << "⚠️ Opción no válida.\n";
                    break;
            }
        } while (opcion != 0);
    }
};

int main() {
    SistemaGestionTareas sistema;
    sistema.menuPrincipal();
    return 0;
}
