#pragma once
#include "Alimento.h"
#include "ListaSimple.h"
#include "ColaReStock.h"

class LStock:public ListaS<Alimento*>
{
public:
	LStock():ListaS<Alimento*>(){}
	~LStock() {}
	
	int modificacion(Alimento* v, ReStock* cola) {
		bool encontrado= false;
		Nodo<Alimento*>* aux= inicio;
		while (!encontrado && aux!= NULL)
		{
			
			if (aux->valor->getNombre()== v->getNombre() )
			{
				if (aux->valor->getCantidad() > 0) {
					aux->valor->updateCantidad(v->getCantidad());
					encontrado = true;
					return 1;
				}
				else
				{
					EliminarDeLista(aux, cola);
					return 0;
				}
				
			}
			aux = aux->siguiente;
		}
	}
	void EliminarDeLista(Nodo<Alimento*>* v, ReStock* cola) {
		Nodo<Alimento*>* aux = inicio;
		while (aux->siguiente->valor!=v->valor)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = v->siguiente;
		cola->Encolar(v->valor);
		
	}


};

