#include <iostream>
#include <climits>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaEnlazadaCircular {
private:
    Nodo* cabeza;
public:
    ListaEnlazadaCircular() {
        cabeza = nullptr;
    }
    ~ListaEnlazadaCircular() {
        if (cabeza != nullptr) {
            Nodo* actual = cabeza;
            Nodo* siguiente = cabeza->siguiente;
            while (siguiente != cabeza) {
                delete actual;
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
            delete actual;
        }
    }
    void agregarElemento(int valor) {
        Nodo* NodoNuevo = new Nodo;
        NodoNuevo->dato = valor;
        if (cabeza == nullptr) {
            cabeza = NodoNuevo;
            cabeza->siguiente = cabeza;
        } else {
            Nodo* ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            NodoNuevo->siguiente = cabeza;
            ultimo->siguiente = NodoNuevo;
        }
    }
    void imprimirLista() {
        if (cabeza != nullptr) {
            Nodo* actual = cabeza;
            do {
                cout << actual->dato << " ";
                actual = actual->siguiente;
            } while (actual != cabeza);
            cout << endl;
        }
    }

    int encontrarMaximo() {
        if (cabeza == nullptr) {
            cout << "La lista está vacia." << endl;
            return INT_MIN;
        }
        Nodo* actual = cabeza;
        int maximo = INT_MIN;
        do {
            if (actual->dato > maximo) {
                maximo = actual->dato;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return maximo;
    }


    int encontrarMinimo() {
        if (cabeza == nullptr) {
            cout << "La lista está vacia." << endl;
            return INT_MAX;
        }
        Nodo* actual = cabeza;
        int minimo = INT_MAX;
        do {
            if (actual->dato < minimo) {
                minimo = actual->dato;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return minimo;
    }

    int calcularSuma() {
        if (cabeza == nullptr) {
            cout << "La lista está vacia." << endl;
            return 0;
        }
        Nodo* actual = cabeza;
        int suma = 0;
        do {
            suma += actual->dato;
            actual = actual->siguiente;
        } while (actual != cabeza);
        return suma;
    }
};

int main() {
    ListaEnlazadaCircular lista;
    int valor;
    cout << "Ingrese valores enteros para agregar a la lista (-1 para terminar):\n";
    cin >> valor;
    while (valor != -1) {
        lista.agregarElemento(valor);
        cin >> valor;
    }
    cout << "Lista enlazada circular:\n" << endl;
    lista.imprimirLista();

    int minimo = lista.encontrarMinimo();
    int maximo = lista.encontrarMaximo();
    int suma = lista.calcularSuma();

    if (minimo != INT_MAX && maximo != INT_MIN) {
        cout << "El valor minimo en la lista es: " << minimo << endl;
        cout << "El valor maximo en la lista es: " << maximo << endl;
        cout << "La suma de todos los valores en la lista es: " << suma << endl;
    }

    return 0;
}
