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
		int pos = 1;
		Nodo<Alimento*>* aux = inicio;
		while (!encontrado && aux != NULL)
		{

			if (aux->valor->getNombre() == v->getNombre())
			{

				encontrado = true;
				if (aux->valor->getCantidad() - v->getCantidad() >= 0) {
					aux->valor->updateCantidad(v->getCantidad());


					if (aux->valor->getCantidad() == 0) {
						auto f = [&aux, this]()->void {(sizeof(aux->valor) == sizeof(Contable)) ? contable-- : incontable--; };
						f();
						
						/*if (sizeof(aux->valor) == sizeof(Contable))
						{
							contable--;
						}
						else
						{
							incontable--;
						}*/
						EliminarDeLista(aux, cola, pos);
					}
				}
				else
				{
					v->updateCantidad(v->getCantidad() - aux->valor->getCantidad());

				}
				return encontrado;
			}
			aux = aux->siguiente;
			pos++;
		}
		return encontrado;
	}
	void EliminarDeLista(Nodo<Alimento*>* v, ReStock* cola, int pos) {
		cola->Encolar(v->valor);
		EliminarenPosicion(pos);

	}
	void ActualizarArchivo() {
		ofstream arch;
		arch.open("NuevoNStock.txt", ios::out);
		if (arch.is_open()) {
			arch << contable << endl;
			arch << incontable << endl;
			arch.close();
		}
		ofstream archs;
		archs.open("NuevoStock.txt", ios::out);
		if (archs.is_open())
		{
			Nodo<Alimento*>* aux = inicio;
			while (aux != NULL)
			{
				archs << aux->valor->getNombre() << endl;
				archs << aux->valor->getCantidad() << endl;
				archs << aux->valor->getPrecio() << endl;
				aux = aux->siguiente;
			}
			archs.close();
		}

	}
	void StockInicial(int c, int i) {
		contable = c;
		incontable = i;
	}
	void Imprimir()
	{
		Nodo<Alimento*>* aux = inicio;
		if (inicio != NULL)
		{
			cout << "\tMi stock\n\n";

			while (aux != NULL)
			{
				aux->valor->imprimir();
				aux = aux->siguiente;
			}
		
			cout << endl;
		}
		else cout << "La lista de stock esta vacia\n";

	}

};









#endif // !__ListaStock_H__


