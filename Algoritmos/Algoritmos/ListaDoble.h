#pragma once

#include "NodoDoble.h"


template<class T>
class ListaD
{
public:
	ListaD() {
		inicio = final = nullptr;
		lenght = 0;
	}
	~ListaD() {
		while (inicio != final)
		{
			NodoDoble<T>* aux = inicio->siguiente;
			delete inicio;
			inicio = aux;
		}
		delete inicio;
		inicio =final = nullptr;
	}
	

protected:
	NodoDoble<T>* inicio;
	NodoDoble<T>* final;
	int lenght;

	

};
