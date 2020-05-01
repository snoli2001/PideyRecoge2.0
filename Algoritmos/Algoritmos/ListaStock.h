#ifndef __LISTASTOCK_H__
#define __LISTASTOCK_H__
#include <fstream>
#include "Alimento.h"
#include "ListaSimple.h"
#include "ColaReStock.h"


class LStock :public ListaS<Alimento*>
{
private: 
	int contable, incontable;
public:
	LStock() :ListaS() { contable = 0; incontable = 0; }
	~LStock() {}

	bool modificacion(Alimento* v, ReStock* cola) {
		bool encontrado = false;
		Nodo<Alimento*>* aux = inicio;
		while (!encontrado && aux != NULL)
		{

			if (aux->valor->getNombre() == v->getNombre())
			{
				encontrado = true;
				if (aux->valor->getCantidad()-v->getCantidad() >= 0) {
					aux->valor->updateCantidad(v->getCantidad());
					
					if (aux->valor->getCantidad() == 0) {
						if (sizeof(aux->valor) == sizeof(Contable*))
						{
							contable--;
						}
						else
						{
							incontable--;
						}
						EliminarDeLista(aux, cola);
					}
				}
				else 
				{
					v->updateCantidad(v->getCantidad()- aux->valor->getCantidad());
					
				}
				return encontrado;
			}
			aux = aux->siguiente;
		}
		return encontrado;
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
	void ActualizarArchivo() {
		ofstream arch;
		arch.open("NStock.txt", ios::out);
		if (arch.is_open()) {
			arch << contable;
			arch << incontable;
			arch.close();
		}
		
	}
	void StockInicial(int c, int i) {
		contable = c;
		incontable = i;
	}

};









#endif // !__ListaStock_H__



