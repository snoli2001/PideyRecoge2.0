#pragma once
#include "Nodo.h"


template <class T>
class ListaS
{
protected:
	Nodo<T>* inicio;
	int lenght;

public:
	ListaS() {
		inicio = nullptr;
		lenght = 0;
	}
	~ListaS() {
		while (inicio != nullptr)
		{
			Nodo<T>* aux = inicio->siguiente;
			delete inicio;
			inicio = aux;
		}
		inicio = nullptr;
	}



};

