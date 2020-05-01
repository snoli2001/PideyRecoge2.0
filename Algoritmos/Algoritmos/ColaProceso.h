#pragma once
#include "Cola.h"
#include "ListaAlimento.h"
#include <functional>

using namespace std;
class Proceso:public Cola<ListaAlimento*>
{
public:
	Proceso():Cola<ListaAlimento*>(){}
	~Proceso(){}
	bool  Encolar(ListaAlimento* v, function<bool(ListaAlimento*)>comprobador) {
		if (comprobador) {
			Nodo<ListaAlimento*>* nuevo = new Nodo<ListaAlimento*>(v);
			nuevo->siguiente = tail;
			tail = nuevo;
			lenght++;
			return true;
		}
		return false;

	}

	template<typename T>
	T Desencolar() {
		Nodo<T>* aux = tail;
		while (aux->siguiente != head)
		{
			aux = aux->siguiente;
		}
		T temp = head->valor;
		delete aux->siguiente;
		head = aux;
		lenght--;
		return temp;

	}
	template<typename T>
	int Size() { return lenght; }


};



