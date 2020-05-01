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
		while (top!=nullptr)
		{
			Nodo<T>* aux = top->siguiente;
			delete top;
			top = aux;
		}
		top = nullptr;
	}



};

