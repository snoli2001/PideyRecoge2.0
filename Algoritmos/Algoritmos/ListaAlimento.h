#pragma once
#include"Alimento.h"
#include"ListaSimple.h"

class ListaAlimento:public ListaS<Alimento*>
{
public:
	ListaAlimento() :ListaS() {}
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
