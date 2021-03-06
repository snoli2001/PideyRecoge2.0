#pragma once

#include "NodoDoble.h"


template<class T>
class ListaD
{
public:
	ListaD() {
		inicio = fin = nullptr;
		lenght = 0;
	}
	~ListaD() {
		while (inicio != fin)
		{
			NodoDoble<T>* aux = inicio->siguiente;
			delete inicio;
			inicio = aux;
		}
		delete inicio;
		inicio = fin = nullptr;
	}
	void agregarInicio(T val) {
		NodoDoble<T>* nuevo = new NodoDoble<T>(val);
		if (inicio != NULL) {
			auto f = [&nuevo,this]()->void {nuevo->siguiente = inicio; inicio->anterior = nuevo; inicio = nuevo; return; };
			f();
			/*nuevo->siguiente = inicio;
			inicio->anterior = nuevo;
			inicio = nuevo;
			return;*/
		}
		inicio = fin = nuevo;
		lenght++;

	}
	T ExtraerElemento(int pos) {
		if (lenght > 0) {
			NodoDoble<T>* aux = inicio;
			if (pos!= 1)
			{
				while (pos - 1 != 1)
				{
					aux = aux->siguiente;
					pos--;
				}
				NodoDoble<T>* temp = aux->siguiente;

				aux->siguiente = temp->siguiente;
				if (temp->siguiente != NULL)
					temp->siguiente->anterior = aux;
				lenght--;
				return temp->valor;
			}
			else
			{
				inicio = fin = NULL;
				return aux->valor;
			}
			
		}
	}


protected:
	NodoDoble<T>* inicio;
	NodoDoble<T>* fin;
	int lenght;



};