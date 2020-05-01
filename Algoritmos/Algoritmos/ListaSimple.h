#ifndef _ListaSimple_H_
#define _ListaSimple_H_

#include "Nodo.h"
template<class T>
class ListaSimple {
protected:
	Nodo<T>* inicio;
	int longitud;
public:
	ListaSimple() { inicio = NULL; longitud = 0; };
	~ListaSimple() {};
	void AgregaralInicio(T v);
	void AgregaralFinal(T v);
	void AgregarenPosicion(T v, int pos);
	void EliminarenPosicion(int pos);
	void ELiminarInicial();
	T ObtenerenPosicion(int pos);
	/*void Mostrar();*/
	virtual void Mostrar() abstract {};
};

template<class T>
void ListaSimple<T>::AgregaralInicio(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		inicio = nuevo;
	}
	else {
		Nodo<T>* aux = inicio;

		nuevo->siguiente = inicio;

		inicio = nuevo;
		aux = NULL;
	}
	nuevo = NULL;
	longitud++;
}

template<class T>
void ListaSimple<T>::AgregaralFinal(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		AgregaralInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = inicio;

		while (aux->siguiente != NULL) {
			aux = aux->siguiente; //Ultimo de la ListaSimple
		}
		aux->siguiente = nuevo;
		

	}
	longitud++;
}

template<class T>
void ListaSimple<T>::AgregarenPosicion(T v, int pos) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);
	if (pos == 0)
	{
		AgregaralInicio(v);
	}
	else
	{
		int i = 1;
		Nodo<T>* aux = inicio;
		while (i < pos)
		{
			aux = aux->siguiente; //Nodo en la posición POS
			i++;
		}
		nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
	}
	longitud++;
}
template<class T>
void ListaSimple<T>::ELiminarInicial()
{
	Nodo<T>* aux = inicio;
	if (longitud > 0) {
		inicio = inicio->siguiente;
		delete aux;
		longitud--;
	}
}
template<class T>
void ListaSimple<T>::EliminarenPosicion(int pos) {

	if (pos == 0)
	{
		ELiminarInicial();
	}
	else {
		Nodo<T>* aux = inicio;
		int i = 1;
		while (i < pos)
		{
			aux = aux->siguiente;
			i++;
		}
		Nodo<T>* Eliminar = aux->siguiente;
		aux->siguiente = aux->siguiente->siguiente;
		delete Eliminar;
		longitud--;
	}



}
template<class T>
T ListaSimple<T>::ObtenerenPosicion(int pos)
{
	if (pos == 0)
	{
		return inicio->valor;
	}
	int i = 1;
	Nodo<T>* aux = inicio;
	while (i < pos)
	{
		aux = aux->siguiente; //Nodo en la posición POS
		i++;
	}
	return aux->valor;
}
#endif // !_ListaSimple_H_