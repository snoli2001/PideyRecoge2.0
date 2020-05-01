#pragma once
#include"Cola.h"
#include"Pedido.h"


class ColaPedido:public Cola<Pedido*>
{
public:
	ColaPedido() :Cola() {};
	~ColaPedido() {};
	void Mostrar();
	void Desencolar_pedido();
};
void ColaPedido::Mostrar()
{
	    Nodo<Pedido*>* nodo = head;
		do {

			Pedido* aux = (Pedido*)(nodo->valor);
			aux->impirmir();
			nodo = nodo->siguiente;

		} while (nodo != NULL);
		cout << endl;
	
}
void ColaPedido::Desencolar_pedido() {
	cout << "El pedido de "; Desencolar()->GetNombreCompleto(); cout << " ha sido completado satisfactoriamente y pasará a la cola de recojo \n\n";
}
