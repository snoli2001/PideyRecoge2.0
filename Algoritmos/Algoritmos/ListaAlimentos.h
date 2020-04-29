#ifndef _ListaAlimentos_H_
#define _ListaAlimentos_H_

#include "Nodo.h"
#include"Alimento.h"
template<class T>
class ListaAlimentos {
private:
	Nodo<T>* inicio;
	int longitud;
public:
	ListaAlimentos() { inicio = NULL; };
	~ListaAlimentos() {};
	void AgregaralInicio(T v);
	void AgregaralFinal(T v);
	void AgregarenPosicion(T v, int pos);
	void Mostrar();

};

template<class T>
void ListaAlimentos<T>::AgregaralInicio(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		inicio = nuevo;
		nuevo->siguiente = inicio;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio) {
			aux = aux->siguiente;
		}
		nuevo->siguiente = inicio;
		aux->siguiente = nuevo;
		
		inicio = nuevo;
		aux = NULL;
	}
	nuevo = NULL;

}

template<class T>
void ListaAlimentos<T>::AgregaralFinal(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		AgregaralInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio) {
			aux = aux->siguiente; //Ultimo de la ListaAlimentos
		}
		aux->siguiente = nuevo;
		nuevo->siguiente = inicio;
		
	}
}

template<class T>
void ListaAlimentos<T>::AgregarenPosicion(T v, int pos) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);

	int i = 1;
	Nodo<T>* aux = inicio;
	while (i < pos)
	{
		aux = aux->siguiente; //Nodo en la posición POS
		i++;
	}
	nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
	
}

template<class T>
void ListaAlimentos<T>::Mostrar() {
	Nodo<T> *nodo = inicio;
	do {		
		Alimento* ali = (Alimento*)(nodo->valor);
		ali->imprimir();
		nodo = nodo->siguiente;
	} while (nodo != inicio);
	cout << endl;
}

#endif // !_ListaAlimentos_H_