#pragma once
#include "Nodo.h"
#include <algorithm>
#include <functional>
using namespace std;
template<typename T>
class Cola
{
private:
	Nodo<T>* head;
	Nodo<T>* tail;
	int lenght;
public:
	Cola(Nodo<T>* h = nullptr,Nodo<T>* = nullptr, int l=0):( head=h, tail=t, lenght=l){}
	~Cola() {

	}
	bool Encolar(T v, function<bool(T)>comprobador);
	T Desencolar();
	int Size():
};

template<typename T>
bool  Cola<T>::Encolar(T v, function<bool(T)>comprobador) {
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
T Cola<T>::Desencolar() {
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
int Cola<T>::Size() { return lenght; }

