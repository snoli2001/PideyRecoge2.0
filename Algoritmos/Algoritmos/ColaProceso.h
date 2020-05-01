#pragma once
#include "Cola.h"
#include "ListaRecojo.h"
#include "ListaStock.h"
#include "ColaReStock.h"
#include "Pedido.h"
#include <functional>

using namespace std;
class Proceso:public Cola<Pedido*>
{
public:
	Proceso():Cola<ListaAlimento*>(){}
	~Proceso(){}
	
	void Procesado(Recojo* r,LStock* stock, ReStock* re) {
		Pedido* actual = Desencolar();
		Pedido* nuevo = new Pedido(actual->GetNombre(),actual->GetApellido());
		Alimento* item = NULL;
		do
		{
			item = actual->ExtraerAlimento();
			if (stock->modificacion(item, re)) {
				nuevo->AgregarAlimentoaLista_inicio(item);
			}
			
			
		} while (item!=NULL);
		Encolar(nuevo);
	}

};



