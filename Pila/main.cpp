#include <iostream>
using namespace std;

struct nodo {
    int campo;
    struct nodo *anterior, *siguiente;
};

class Pila {
public:
     struct nodo *inicio, *final;
     int indicePila;
     Pila() {
         indicePila = -1;
         inicio = NULL;
         final = NULL;
 };
     void mostrarDatos();
     void entrarDato(int dato);
     ~Pila();
};

 // Esta función sale del cuerpo de la clase porque usa un ciclo.
void Pila::mostrarDatos() {
    cout << endl << "DATOS EN LA PILA" << endl;
    struct nodo *aux = inicio;
    int i = 0;
    while (aux != NULL) {
        cout << "Dato No. " << i << " : " << aux->campo << endl;
        i ++;
        aux = aux->siguiente;
    }
    cout << endl;
}
Pila operator + (Pila m, Pila o) {
    cout << endl << "DATOS EN LA PILA" << endl;
    struct nodo *aux = m.inicio;
    int i = 0;
    while (aux != NULL) {
        cout << "Dato No. " << i << " : " << aux->campo << endl;
        i ++;
        aux = aux->siguiente;
    }
    cout << endl;
    struct nodo *aux2 = o.inicio;
    int j = i;
    while (aux2 != NULL) {
    cout << "Dato No. " << j << " : " << aux2->campo << endl;
    j ++;
    aux2 = aux2->siguiente;
    }
    return m;
}
void Pila::entrarDato(int dato) {
    struct nodo *nuevo = new struct nodo;
    nuevo->campo = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if (final != NULL) {
        final->siguiente = nuevo;
        nuevo ->anterior = final;
    } else
        inicio = nuevo;
        final = nuevo;
        indicePila ++;
}


Pila::~Pila() {
    struct nodo *aux = inicio;
    while (aux != NULL) {
        inicio = inicio->siguiente;
        delete aux;
        aux = inicio;
    }
}

int main () {
    Pila pila1;
    Pila pila2;
    pila1.entrarDato(3);
    pila1.entrarDato(4);
    pila1.entrarDato(7);
    pila2.entrarDato(12);
    pila2.entrarDato(1);
    pila2.entrarDato(8);

    Pila pila3;
    pila3 = pila1+pila2;
    return 0;
}
