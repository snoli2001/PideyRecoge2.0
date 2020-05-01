#pragma once
#include"Pedido.h"
#include"ListaSimple.h"
class ListaREcojo:public ListaSimple<Pedido*>
{
public:
	ListaREcojo() :ListaSimple() {};
	~ListaREcojo() {};
	void Mostrar();
};
void ListaREcojo::Mostrar()
{
	if (inicio != NULL)
	{
		Nodo<Pedido*>* nodo = inicio;
		do {

			Pedido* ali = (Pedido*)(nodo->valor);
			auto f = [&ali, &nodo]()->void { ali->impirmir();nodo = nodo->siguiente; };
			f();

		} while (nodo != NULL);
		cout << endl;
	}
	else
	{
		cout<< "========== Vacia ========\n\n";
	}
}