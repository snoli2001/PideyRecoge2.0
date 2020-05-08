#pragma once
#include "ListaDoble.h"
#include "Pedido.h"
#include "PilaRecogido.h"
#include "ListaRancking.h"

class Recojo :public ListaD<Pedido*>
{
public:
	Recojo() :ListaD() {}
	~Recojo() {}
	void recoger(Recogido* recogido, string nombre, string apellido,LRank* ranking) {
		int pos = Busqueda(nombre, apellido);

		if (pos) {
			Pedido* despachado = ExtraerElemento(pos);
			recogido->Push(despachado);
			ranking->ActualizarLista(despachado);
		}
		else
		{
			cout << "Cliente no encontrado";
		}
	}
	int Busqueda(string nombre, string apellido) {
		NodoDoble<Pedido*>* aux = inicio;
		int pos = 1;
		while (lenght >= pos)
		{
			if (aux->valor->GetNombre() == nombre && aux->valor->GetApellido() == apellido) {
				return pos;
			}
			pos++;
			aux = aux->siguiente;
		}
		return 0;
	}
	void imprimir() {
		cout << "Pedidos por recoger\n";
		NodoDoble<Pedido*>* aux = inicio;
		while (aux != NULL)
		{
			aux->valor->impirmir();
			aux = aux->siguiente;
		}
	}
};


