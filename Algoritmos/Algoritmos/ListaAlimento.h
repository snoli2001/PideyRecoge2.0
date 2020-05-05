#pragma once
#include"Alimento.h"
#include"ListaSimple.h"

class ListaAlimento :public ListaS<Alimento*>
{
public:
	ListaAlimento() :ListaS() {}
	~ListaAlimento() {}
	void Mostrar();
	Alimento* GetItem() {
		Nodo<Alimento*>* aux = inicio;
		if (lenght > 0) {
			inicio = inicio->siguiente;
			lenght--;
			return aux->valor;
		}
		return NULL;
	}

};

void ListaAlimento::Mostrar()
{
	Nodo<Alimento*>* nodo = inicio;
	while (nodo != NULL)
	{
		Alimento* ali = (Alimento*)(nodo->valor);

		//ali->imprimir();
		//nodo = nodo->siguiente;
		auto f = [&ali, &nodo]() {ali->imprimir();nodo = nodo->siguiente; };
		f();
	}
	cout << endl;
}