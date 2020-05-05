#pragma once
#include "Cola.h"
#include "Alimento.h"
class ReStock :public Cola<Alimento*>
{
public:
	ReStock() :Cola<Alimento*>() {}
	~ReStock() {}
	void imprimir() {
		cout << "Productos que necesitan Restock" << endl;
		Nodo<Alimento*>* aux = tail;
		while (aux != NULL)
		{
			cout << "Producto: "<<aux->valor->getNombre()<<endl<< "Precio: "<<aux->valor->getPrecio() << endl;

			aux = aux->siguiente;
		}
	}
private:

};