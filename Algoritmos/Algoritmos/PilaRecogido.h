#pragma once
#include "Pila.h"
#include "Pedido.h"
class Recogido:public Pila<Pedido*>
{
public:
	Recogido():Pila<Pedido*>(){}
	~Recogido(){}
	void Reporte() {
		cout << "Pedidos Recogidos: " << endl;
		while (top != NULL)
		{
			Pop()->impirmir();
		}
	}
private:

};





