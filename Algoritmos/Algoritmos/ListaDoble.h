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
		NodoDoble<T>* nuevo = new NodoDoble<T> * (val);
		if (inicio != NULL) {
			
			nuevo->siguiente = inicio;
			inicio->anterior = nuevo;
			inicio = nuevo;
			return;
		}
		inicio = fin = nuevo;
		lenght++;

	}
	T EstraerElemento(int pos) {
		if (lenght > 0) {
			NodoDoble<T>* aux = inicio;
			while (pos-1!=1)
			{
				aux = aux->siguiente;
				pos--;
			}
			NodoDoble<T>* temp = aux->siguiente;
			aux->siguiente = temp->siguiente;
			temp->siguiente->anterior = aux;
			lenght--;
			return temp->valor;
		}
	}
	

protected:
	NodoDoble<T>* inicio;
	NodoDoble<T>* fin;
	int lenght;

	

};
