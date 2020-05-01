#ifndef _ListaPedido_H_
#define _ListaPedido_H_

#include "ListaSimple.h"

template<class T>
class ListaPedido:public ListaS<T>  {

public:
	ListaPedido() :ListaS<T>() {}
	~ListaPedido() {}
	void AgregaralInicio(T v);
	void AgregaralFinal(T v);
	void AgregarenPosicion(T v, int pos);
	void EliminarenPosicion(int pos);
	void ELiminarInicial();

	/*void Mostrar();*/
	virtual void Mostrar() abstract {};
};

template<class T>
void ListaPedido<T>::AgregaralInicio(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (ListaS<T>::inicio == NULL) {
		ListaS<T>::inicio = nuevo;
		nuevo->siguiente = ListaS<T>::inicio;
	}
	else {
		Nodo<T>* aux = ListaS<T>::inicio;
		while (aux->siguiente != ListaS<T>::inicio) {
			aux = aux->siguiente;
		}
		nuevo->siguiente = ListaS<T>::inicio;
		aux->siguiente = nuevo;
		
		ListaS<T>::inicio = nuevo;
		aux = NULL;
	}
	nuevo = NULL;
	ListaS<T>::lenght++;
}

template<class T>
void ListaPedido<T>::AgregaralFinal(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (ListaS<T>::inicio == NULL) {
		AgregaralInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = ListaS<T>::inicio;
		while (aux->siguiente != ListaS<T>::inicio) {
			aux = aux->siguiente; //Ultimo de la ListaPedido
		}
		aux->siguiente = nuevo;
	
		
	}
	ListaS<T>::lenght++;
}

template<class T>
void ListaPedido<T>::AgregarenPosicion(T v, int pos) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);
	if (pos == 0)
	{
		AgregaralInicio(v);
	}
	else
	{
		int i = 1;
		Nodo<T>* aux = ListaS<T>::inicio;
		while (i < pos)
		{
			aux = aux->siguiente; //Nodo en la posición POS
			i++;
		}
		nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
	}
	ListaS<T>::lenght++;
}
template<class T>
void ListaPedido<T>::ELiminarInicial()
{
	Nodo<T>* aux = ListaS<T>::inicio;
	if (ListaS<T>::lenght > 0) {
		ListaS<T>::inicio = ListaS<T>::inicio->siguiente;
		delete aux;
		ListaS<T>::lenght--;
	}
}
template<class T>
void ListaPedido<T>::EliminarenPosicion(int pos) {
	
	if (pos == 0)
	{
		ELiminarInicial();
	}
	else {
		Nodo<T>* aux = ListaS<T>::inicio;
		int i = 1;
		while (i < pos)
		{
			aux = aux->siguiente;
			i++;
		}
		Nodo<T>* Eliminar = aux->siguiente;
		aux->siguiente = aux->siguiente->siguiente;
		delete Eliminar;
		ListaS<T>::lenght--;
	}
	

	
}

//template<class T>
//void ListaPedido<T>::Mostrar() {
//	Nodo<T> *nodo = inicio;
//	do {		
//		Alimento* ali = (Alimento*)(nodo->valor);
//		ali->imprimir();
//		nodo = nodo->siguiente;
//	} while (nodo != inicio);
//	cout << endl;
//}

#endif // !_Lista_H_