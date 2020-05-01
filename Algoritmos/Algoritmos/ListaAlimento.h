#pragma once
#include"Alimento.h"
#include"ListaPedido.h"

class ListaAlimento:public ListaPedido<Alimento*>
{
public:
	ListaAlimento() :ListaPedido() {}
	~ListaAlimento() {}
	void Mostrar();

};

void ListaAlimento::Mostrar()
{
	Nodo<Alimento*>*nodo = inicio;
		do {
		
 			Alimento* ali = (Alimento*)(nodo->valor);
			
				ali->imprimir();
				nodo = nodo->siguiente;

		} while (nodo != NULL);
		cout << endl;
}
