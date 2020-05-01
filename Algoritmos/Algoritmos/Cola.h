#pragma once
#pragma once
#include "Nodo.h"
#include <functional>
using namespace std;
template<class T>
class Cola
{
protected:
	Nodo<T>* head;
	Nodo<T>* tail;
	int lenght;
public:
	Cola() {
		head = tail = NULL;
		lenght = 0;
	}
	~Cola() {
		while (head != tail)
		{
			Nodo<T>* aux = tail->siguiente;
			delete tail;
			tail = aux;
		}
		delete head;
		head = tail = nullptr;
	}
	bool Encolar(T v, function<bool(T)>comprobador)
	{
		if (comprobador) {
			Nodo<T>* nuevo = new Nodo<T>(v);
			nuevo->siguiente = tail;
			tail = nuevo;
			lenght++;
			return true;
		}
		return false;
	}

	T Desencolar() {
		Nodo<T>* aux = head;
		T temp = head->valor;
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->siguiente;
		}
		delete aux;
		lenght--;
		return temp;

	}
	void Agregar(T v)
	{
		Nodo<T>* nuevo = new Nodo<T>(v);
		nuevo->siguiente = NULL;

		bool b;
		auto f = [this](bool& b)->void {(head == NULL) ? b = true : b = false;};
		f(b);
	
		if(b) {
			head = nuevo;
		}
		else {
			tail->siguiente = nuevo;
		}
		tail = nuevo;
	}
	
	int Size() { return lenght; }
};