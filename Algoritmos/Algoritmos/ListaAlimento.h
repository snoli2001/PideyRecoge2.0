#pragma once
#include"Alimento.h"
#include"Lista.h"

class ListaAlimento:public Lista<Alimento*>
{
public:
	ListaAlimento() :Lista() {}
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
