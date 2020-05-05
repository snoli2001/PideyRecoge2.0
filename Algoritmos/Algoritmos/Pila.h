
#pragma once
#include "Nodo.h"

template<class T>
class Pila
{
protected:
	Nodo<T>* top;
	int lenght;

public:
	Pila() {
		top = nullptr;
		lenght = 0;
	}
	~Pila() {
		while (top != nullptr)
		{
			Nodo<T>* aux = top->siguiente;
			delete top;
			top = aux;
		}
		top = nullptr;
	}
	void Push(T v) {
		Nodo<T>* nuevo = new Nodo<T>(v);
		if (top != NULL) {
			nuevo->siguiente = top;
		}
		
		top = nuevo;
	}
	T Pop() {
		Nodo<T>* temp = top;
		top = top->siguiente;
		lenght--;
		return temp->valor;

	}


};
