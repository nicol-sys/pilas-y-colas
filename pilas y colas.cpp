#include <iostream>
#include <stack>
#include <queue>
#include <set> 

using namespace std;


void mostrarPila(stack<int> pila) {
    cout << "Elementos de la pila: ";
    while (!pila.empty()) {
        cout << pila.top() << " "; //top imprime el recien agregado
        pila.pop();
    }
    cout << endl;
}

void mostrarCola(queue<int> cola) {
    cout << "Elementos de la cola: ";
    while (!cola.empty()) {
        cout << cola.front() << " ";//Imprime el primero que entro
        cola.pop();
    }
    cout << endl;
}
int main() {
    int opcion;

    while (true) {
        cout << "Menu principal" << endl;
        cout << "1. Pila" << endl;
        cout << "2. Cola" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        if (opcion == 1) { 
            stack<int> pila;
            set<int> numunico;

            while (true) {
                cout << "1. Ingresar elemento" << endl;
                cout << "2. Atender elemento" << endl;
                cout << "3. Mostrar pila" << endl;
                cout << "4. Volver al menu" << endl;
                cin >> opcion;

                if (opcion == 1) {
                    int valor;
                    cin >> valor;
                    

                    if (numunico.find(valor) == numunico.end()) {
                        pila.push(valor); //para agregar
                        numunico.insert(valor); 
                        cout << "Se agrego el elemento a la pila"<< endl;
                    } else {
                        cout << "El valor ya existe en la pila." << endl;
                    }
                } else if (opcion == 2) {
                    if (!pila.empty()) { //verificar si esta vacia
                        cout << "Se atendió el elemento " << pila.top() << endl;
                        numunico.erase(pila.top()); //acceder al elemento 1  
                        pila.pop();//Ultimo que entro,primero en atender
                    } else {
                        cout << "La pila está vacía." << endl;
                    }
                } else if (opcion == 3) {
                    mostrarPila(pila);
                } else if (opcion == 4) {
                    break;  
                } else {
                    cout << "Opción no válida." << endl;
                }
            }
        } else if (opcion == 2) {  
            queue<int> cola;
            set<int> numunico;

            while (true) {
                cout << "1. Ingresar elemento" << endl;
                cout << "2. Atender elemento" << endl;
                cout << "3. Mostrar cola" << endl;
                cout << "4. Volver al menu" << endl;
                cin >> opcion;

                if (opcion == 1) {
                    int valor;
                    cin >> valor;

                    if (numunico.find(valor) == numunico.end()) {
                        cola.push(valor);
                        numunico.insert(valor);
                        cout << "Se agrego el elemento a la cola"<< endl;
                    } else {
                        cout << "El valor ya existe en la cola." << endl;
                    }
                } else if (opcion == 2) {
                    if (!cola.empty()) {
                        cout << "Se atendió el elemento " << cola.front() << endl; //acceder al elemneto frontal de la cola
                        numunico.erase(cola.front());  
                        cola.pop();//el primero que entro se atende primero
                    } else {
                        cout << "La cola está vacía." << endl;
                    }
                } else if (opcion == 3) {
                    mostrarCola(cola);
                } else if (opcion == 4) {
                    break;  
                } else {
                    cout << "Opción no válida." << endl;
                }
            }
        } else if (opcion == 3) {
            break;  
        } else {
            cout << "Opción no válida." << endl;
        }
    }

    return 0;
}
