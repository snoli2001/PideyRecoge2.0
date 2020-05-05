#ifndef __LISTARANCKING_H__
#define __LISTARANCKING_H__
#include "ListaDoble.h"
#include "Cliente.h"

class LRanck: ListaD<Cliente*>
{
public:
	LRanck():ListaD<Cliente*>(){}
	~LRanck(){}
	void OrendarSeleccion() {
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
		cout << "Mejores ventas";
		NodoDoble<Cliente*>* aux = inicio;
		while (aux!=NULL)
		{
			cout << aux->valor->getNombre << "  " << aux->valor->getTotal() << endl;
			aux = aux->siguiente;
		}
	}

private:

};



#endif // !__LISTARANCKING_H__
