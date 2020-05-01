#pragma once
#include "Nodo.h"

template<class T>
class Cola
{
protected:
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
	void Encolar(T v) {
		Nodo<T>* nuevo = new Nodo<T>(v);
		if (tail!=NULL)
		{
			
			nuevo->siguiente = tail;
			tail = nuevo;
			
		}
		else
		{
			tail = head = nuevo;
		}
		lenght++;
		
	}
	T Desencolar() {
		if (head != NULL && tail !=NULL) {
			Nodo<T>* temp = head;
			if (head != tail) {
				Nodo<T>* aux = tail;
				while (aux->siguiente != head)
				{
					aux = aux->siguiente;
				}
				aux->siguiente = NULL;
				head = aux;
				
			}
			else head = tail = NULL;
			lenght--;
			return temp->valor;
			
		}
		return NULL;
		
	}
	
};

