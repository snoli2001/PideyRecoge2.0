#pragma once
#include "Nodo.h"

template<class T>
class Cola
{
private:
	Nodo<T>* head;
	Nodo<T>* tail;
	int lenght;
public:
	Cola() {
		head = tail = nullptr;
		lenght = 0;
	}
	~Cola() {
		while (head!=tail)
		{
			Nodo<T>* aux = tail->siguiente;
			delete tail;
			tail = aux;
		}
		delete head;
		head =tail = nullptr;
	}
	
};

