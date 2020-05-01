#pragma once
#include "Cola.h"
#include "ListaRecojo.h"
#include "ListaStock.h"
#include "Pedido.h"
#include <functional>

using namespace std;
class Proceso:public Cola<Pedido*>
{
public:
	Proceso():Cola<ListaAlimento*>(){}
	~Proceso(){}
	
	void Procesado(Recojo* r,LStock* stock) {
		Pedido* actual = Desencolar();
		string nombre = actual->GetNombre();
		string apellido = actual->GetApellido();
		Pedido* nuevo = new Pedido(nombre,apellido);

	}

};



