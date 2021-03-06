#pragma once
#include "Cola.h"
#include "ListaRecojo.h"
#include "ListaStock.h"
#include "ColaReStock.h"
#include "Pedido.h"
#include <functional>

using namespace std;
class Proceso :public Cola<Pedido*>
{
public:
	Proceso() :Cola() {}
	~Proceso() {}

	void Procesado(Recojo* r, LStock* stock, ReStock* re) {

		Pedido* actual = Desencolar();
		if (actual != NULL) {
			Pedido* nuevo = new Pedido(actual->GetNombre(), actual->GetApellido());
			Alimento* item = NULL;
			do
			{
				item = actual->ExtraerAlimento();
				double b=0;
				auto f = [&item, &stock, &re](double& b) {if (item != NULL) b = stock->modificacion(item, re); };
				f(b);
				if (/*item != NULL && stock->modificacion(item, re)*/b) {
					item->setPrecio(b);
					nuevo->AgregarAlimentoaLista_inicio(item);
					
				}

			} while (item != NULL);
			r->agregarInicio(nuevo);
		}

	}
	void MostrarPedidos() {
		Nodo<Pedido*>* aux = tail;
		while (aux != NULL)
		{
			//aux->valor->impirmir();
			//aux = aux->siguiente;
			auto f = [&aux]()->void {aux->valor->impirmir(); aux = aux->siguiente; };
			f();
		}
	}
};