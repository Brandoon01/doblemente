#include <iostream>

struct Node {
    int data;
    Node* ant;
    Node* sig;
};

class DobleEnlazada {
private:
    Node* cabeza;
    Node* cola;

public:
    DobleEnlazada() : cabeza(NULL), cola(NULL) {}

    // Insertar un dato al final de la lista
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->ant = cola;
        newNode->sig = NULL;

        if (cola != NULL) {
            cola->sig = newNode;
        }

        cola = newNode;

        if (cabeza == NULL) {
            cabeza = newNode;
        }
    }

    // Imprimir la posición de un dato
    void printPosicion(int data) {
        int posicion = 0;
        Node* current = cabeza;

        while (current != NULL) {
            if (current->data == data) {
                std::cout << "El dato " << data << " se encuentra en la posicion " << posicion << std::endl;
                return;
            }
            current = current->sig;
            posicion++;
        }

        std::cout << "El dato " << data << " no se encontró en la lista." << std::endl;
    }

    // Buscar un dato en la lista
    bool search(int data) {
        Node* current = cabeza;

        while (current != NULL) {
            if (current->data == data) {
                return true;
            }
            current = current->sig;
        }

        return false;
    }

    // Eliminar un dato de la lista
    void remove(int data) {
        Node* current = cabeza;

        while (current != NULL) {
            if (current->data == data) {
                if (current->ant != NULL) {
                    current->ant->sig = current->sig;
                } else {
                    cabeza = current->sig;
                }

                if (current->sig != NULL) {
                    current->sig->ant = current->ant;
                } else {
                    cola = current->ant;
                }

                delete current;
                std::cout << "El dato " << data << " ha sido eliminado de la lista." << std::endl;
                return;
            }
            current = current->sig;
        }

        std::cout << "El dato " << data << " no se encontró en la lista." << std::endl;
    }

    // Mostrar la lista
    void display() {
        Node* current = cabeza;

        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->sig;
        }

        std::cout << std::endl;
    }
};

int main() {
    DobleEnlazada myList;

    int data;
    std::cout << "Ingrese datos para la lista (0 para detenerse):\n";

    while (true) {
        std::cout << "Ingrese un dato: ";
        std::cin >> data;

        if (data == 0) {
            break;
        }

        myList.insert(data);
    }

    int choice;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Imprimir posicion de un dato\n";
        std::cout << "2. Buscar un dato\n";
        std::cout << "3. Eliminar un dato\n";
        std::cout << "4. Mostrar la lista\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese su eleccion: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Ingrese el dato a buscar: ";
                std::cin >> data;
                myList.printPosicion(data);
                break;
            case 2:
                std::cout << "Ingrese el dato a buscar: ";
                std::cin >> data;
                if (myList.search(data)) {
                    std::cout << "El dato " << data << " se encuentra en la lista." << std::endl;
                } else {
                    std::cout << "El dato " << data << " no se encuentra en la lista." << std::endl;
                }
                break;
            case 3:
                std::cout << "Ingrese el dato a eliminar: ";
                std::cin >> data;
                myList.remove(data);
                break;
            case 4:
                myList.display();
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}
