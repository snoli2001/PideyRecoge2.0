#pragma once
#include"Pedido.h"
#include"ListaSimple.h"
class ListaPedido:public ListaSimple<Pedido*>
{
public:
	ListaPedido() :ListaSimple() {};
	~ListaPedido() {};
	void Mostrar();
private:

};
void ListaPedido::Mostrar()
{
	Nodo<Pedido*>* nodo = inicio;
	do {

		Pedido* ali = (Pedido*)(nodo->valor);

		ali->impirmir();
		nodo = nodo->siguiente;

	} while (nodo != NULL);
	cout << endl;
}