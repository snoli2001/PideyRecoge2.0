#ifndef _Lista_H_
#define _Lista_H_

#include "Nodo.h"
template<class T>
class Lista {
protected:
	Nodo<T>* inicio;
	int longitud;
public:
	Lista() { inicio = NULL; };
	~Lista() {};
	void AgregaralInicio(T v);
	void AgregaralFinal(T v);
	void AgregarenPosicion(T v, int pos);
	/*void Mostrar();*/
	virtual void Mostrar() abstract {};
};

template<class T>
void Lista<T>::AgregaralInicio(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		inicio = nuevo;
		nuevo->siguiente = inicio;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio) {
			aux = aux->siguiente;
		}
		nuevo->siguiente = inicio;
		aux->siguiente = nuevo;
		
		inicio = nuevo;
		aux = NULL;
	}
	nuevo = NULL;
	longitud++;
}

template<class T>
void Lista<T>::AgregaralFinal(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); //T

	if (inicio == NULL) {
		AgregaralInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio) {
			aux = aux->siguiente; //Ultimo de la Lista
		}
		aux->siguiente = nuevo;
		nuevo->siguiente = inicio;
		
	}
	longitud++;
}

template<class T>
void Lista<T>::AgregarenPosicion(T v, int pos) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);

	int i = 1;
	Nodo<T>* aux = inicio;
	while (i < pos)
	{
		aux = aux->siguiente; //Nodo en la posición POS
		i++;
	}
	nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
	longitud++;
}

//template<class T>
//void Lista<T>::Mostrar() {
//	Nodo<T> *nodo = inicio;
//	do {		
//		Alimento* ali = (Alimento*)(nodo->valor);
//		ali->imprimir();
//		nodo = nodo->siguiente;
//	} while (nodo != inicio);
//	cout << endl;
//}

#endif // !_Lista_H_