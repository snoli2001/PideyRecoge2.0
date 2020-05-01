#pragma once

#include "NodoDoble.h"


template<class T>
class ListaD
{
public:
	ListaD() {
		inicio = fin = nullptr;
		lenght = 0;
	}
	~ListaD() {
		while (inicio != fin)
		{
			NodoDoble<T>* aux = inicio->siguiente;
			delete inicio;
			inicio = aux;
		}
		delete inicio;
		inicio =fin = nullptr;
	}
	void agregarInicio(T val) {
		Nodo<T>* nuevo = new Nodo<T> * (val);
		if (inicio != NULL) {
			
			nuevo->siguiente = inicio;
			inicio->anterior = nuevo;
			inicio = nuevo;
			return;
		}
		inicio = fin = nuevo;
		lenght++;

	}


protected:
	NodoDoble<T>* inicio;
	NodoDoble<T>* fin;
	int lenght;

	

};
