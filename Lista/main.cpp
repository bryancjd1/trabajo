#include <iostream>
using namespace std;

struct Nodo {
	int valor;
	Nodo *siguiente;
};

class Lista {
private:
	Nodo *_primero;
public:
	Lista();
	~Lista();
	void agregar( int );
	Nodo * primero();
};

Lista::Lista() {
	_primero = NULL;
}

Lista::~Lista() {
	Nodo *nodo_actual = _primero;
	while( nodo_actual != NULL ) {
		Nodo *siguiente = nodo_actual->siguiente;
		delete nodo_actual;
		nodo_actual = siguiente;
	}
}

void Lista::agregar( int nuevo_valor ) {
	Nodo *nuevo_nodo = new Nodo;
	nuevo_nodo->valor = nuevo_valor;
	nuevo_nodo->siguiente = NULL;
	if( _primero == NULL ) {
		_primero = nuevo_nodo;
	} else {
		Nodo *nodo_actual = _primero;
		while( nodo_actual->siguiente != NULL ) nodo_actual = nodo_actual->siguiente;
		nodo_actual->siguiente = nuevo_nodo;
	}
}

Nodo * Lista::primero() {
	return _primero;
}
    Lista operator + (Lista m, Lista o) {
	Nodo * it = m.primero();
	while( it != NULL ) {
		cout << it->valor << endl;
		it = it->siguiente;
	}
	Nodo * it2 = o.primero();
	while( it2 != NULL ) {
		cout << it2->valor << endl;
		it2 = it2->siguiente;
	}
    return o;
}
int main() {
	Lista lista;
    Lista lista2;

	lista.agregar( 17 );
	lista.agregar( 21 );
	lista.agregar( 12 );

	lista2.agregar( 15 );
	lista2.agregar( 16 );
	lista2.agregar( 28 );

	Lista lista3;
	lista3 = lista + lista2;
	return 0;
}
