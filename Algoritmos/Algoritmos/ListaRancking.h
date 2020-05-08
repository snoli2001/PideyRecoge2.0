#ifndef __LISTARANCKING_H__
#define __LISTARANCKING_H__
#include "ListaDoble.h"
#include "Cliente.h"
#include "Pedido.h"

class LRank: public ListaD<Cliente*>
{
public:
	LRank():ListaD<Cliente*>(){}
	~LRank(){}
	bool Existente(string nombre, string apellido,double total) {
		NodoDoble<Cliente*>* aux = inicio;
		bool finded = false;
		while (aux!=NULL&& !finded)
		{
			if (aux->valor->getNombre() == nombre && aux->valor) {
				aux->valor->updateTotal(total);
				finded = true;
			}
			
		}
		
		return finded;
	}
	void ActualizarLista(Pedido* pedido ) {
		if (!Existente(pedido->GetNombre(), pedido->GetApellido(),pedido->TotalPedido())) {
			Cliente* nuevo = new Cliente(pedido->GetNombre(), pedido->GetApellido());
			nuevo->updateTotal(pedido->TotalPedido());
			agregarInicio(nuevo);
			
		}
		OrdenarSeleccion();
	}
	void OrdenarSeleccion() {
		NodoDoble<Cliente*>* aux = inicio;
		for (int i = 0; i < this->lenght-1; i++)
		{
			Cliente* menor = aux->valor;
			NodoDoble<Cliente*>* aux2 = aux->siguiente;
			for (int j = i; j < this->lenght; j++)
			{
				if (menor->getTotal()>aux2->valor->getTotal())
				{
					menor = aux2->valor;
					aux2->valor = aux->valor;
				}
				aux2 = aux2->siguiente;
			}
			aux->valor = menor;
			aux = aux->siguiente;
		}

	}
	void mostrar() {
		cout << "Mayores compradores:\n ";
		NodoDoble<Cliente*>* aux = inicio;
		while (aux!=NULL)
		{
			cout << aux->valor->getNombre()<<" "<< aux->valor->getApellido() << "  " << aux->valor->getTotal() << endl;
			aux = aux->siguiente;
		}
	}

private:

};



#endif // !__LISTARANCKING_H__
