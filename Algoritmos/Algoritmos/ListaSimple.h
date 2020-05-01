#ifndef __LISTASIMPLE_H__
#define __LISTASIMPLE_H__
#include"Nodo.h"


template<class T>
class ListaS  {

protected:
	Nodo<T>* inicio;
	int lenght;

public:
	ListaS() {
		inicio = nullptr;
		lenght = 0;
	}
	~ListaS() {}
	void AgregaralInicio(T v);
	void AgregaralFinal(T v);
	void AgregarenPosicion(T v, int pos);
	void EliminarenPosicion(int pos);
	void ELiminarInicial();

	/*void Mostrar();*/
	//irtual void Mostrar() abstract {};
};

template<class T>
void ListaS<T>::AgregaralInicio(T v) {
	Nodo<T>* nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		inicio = nuevo;
	}
	else {
		nuevo->siguiente = inicio;
		inicio = nuevo;
	}
	lenght++;
}

template<class T>
void ListaS<T>::AgregaralFinal(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		AgregaralInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != NULL) {
			aux = aux->siguiente; //Ultimo de la ListaS
		}
		aux->siguiente = nuevo;
	
		
	}
	lenght++;
}

template<class T>
void ListaS<T>::AgregarenPosicion(T v, int pos) {
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
	lenght++;
}
template<class T>
void ListaS<T>::ELiminarInicial()
{
	Nodo<T>* aux = inicio;
	if (lenght > 0) {
		inicio = inicio->siguiente;
		delete aux;
		lenght--;
	}
}
template<class T>
void ListaS<T>::EliminarenPosicion(int pos) {
	
	if (pos == 1)
	{
		ELiminarInicial();
	}
	else {
		Nodo<T>* aux = inicio;
	
		while (1 < pos-1)
		{
			aux = aux->siguiente;
			pos--;
		}
		Nodo<T>* Eliminar = aux->siguiente;
		aux->siguiente= aux->siguiente->siguiente;
		delete Eliminar;
		lenght--;
	}
	

	
}

//template<class T>
//void ListaS<T>::Mostrar() {
//	Nodo<T> *nodo = inicio;
//	do {		
//		Alimento* ali = (Alimento*)(nodo->valor);
//		ali->imprimir();
//		nodo = nodo->siguiente;
//	} while (nodo != inicio);
//	cout << endl;
//}

#endif // !_Lista_H_