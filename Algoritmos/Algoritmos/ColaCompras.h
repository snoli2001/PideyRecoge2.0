#pragma once
#include "Nodo.h"
#include <algorithm>
#include <functional>
using namespace std;
template<typename T>
class ColaPendiente
{
private:
	Nodo<T>* head;
	Nodo<T>* tail;
	int lenght;
public:
	ColaPendiente(Nodo<T>* h = nullptr,Nodo<T>* = nullptr, int l=0):( head=h, tail=t, lenght=l){}
	~ColaPendiente() {

	}
	bool Encolar(T v, function<bool(T)>comprobador);
	T Desencolar();
	int Size():
};

template<typename T>
bool  ColaPendiente<T>::Encolar(T v, function<bool(T)>comprobador) {
	if (comprobador) {
		Nodo<T>* nuevo = new Nodo<T>(v);
		nuevo->siguiente = tail;
		tail = nuevo;
		lenght++;
		return true;
	}
	return false;
	
}

template<typename T>
T ColaPendiente<T>::Desencolar() {
	Nodo<T>* aux = tail;
	while (aux->siguiente!=head)
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
int ColaPendiente<T>::Size() { return lenght; }

