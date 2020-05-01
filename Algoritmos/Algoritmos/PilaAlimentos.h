#pragma once
#include "Pila.h"
#include "Alimento.h"
class Pedido:public Pila<Alimento>
{
public:
	Pedido();
	~Pedido();

private:

};

