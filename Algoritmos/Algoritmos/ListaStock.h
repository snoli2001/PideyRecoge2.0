#ifndef __LISTASTOCK_H__
#define __LISTASTOCK_H__
#include "Alimento.h"
#include "ListaSimple.h"
#include "ColaReStock.h"

class LStock :public ListaS<Alimento*>
{
public:
	LStock() :ListaS() {}
	~LStock() {}

	bool modificacion(Alimento* v, ReStock* cola) {
		bool encontrado = false;
		Nodo<Alimento*>* aux = inicio;
		while (!encontrado && aux != NULL)
		{

			if (aux->valor->getNombre() == v->getNombre())
			{
				if (aux->valor->getCantidad() > 0) {
					aux->valor->updateCantidad(v->getCantidad());
					encontrado = true;
					return true;
				}
				else
				{
					EliminarDeLista(aux, cola);
					return false;
				}

			}
			aux = aux->siguiente;
		}
	}
	void EliminarDeLista(Nodo<Alimento*>* v, ReStock* cola) {
		Nodo<Alimento*>* aux = inicio;
		while (aux->siguiente->valor != v->valor)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = v->siguiente;
		cola->Encolar(v->valor);

	}
	

};









#endif // !__ListaStock_H__



