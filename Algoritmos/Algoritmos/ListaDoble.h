#pragma once

#include "NodoDoble.h"


template<class T>
class ListaD
{
public:
	ListaD() {
		inicio = final = nullptr;
		lenght = 0;
	}
	~ListaD() {
		while (inicio != final)
		{
			NodoDoble<T>* aux = inicio->siguiente;
			delete inicio;
			inicio = aux;
		}
		delete inicio;
		inicio =final = nullptr;
	}
	virtual void AgregarInicio()= 0;
	virtual void AgregarFinal()= 0;
	virtual void Mostrar()=0;

protected:
	NodoDoble<T>* inicio;
	NodoDoble<T>* final;
	int lenght;

	

};
