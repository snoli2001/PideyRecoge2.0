#pragma once
#include"ListaRecojo.h"
#include"ColaPedido.h"

class Tienda
{
private:
	ListaREcojo list_recojo;
	ColaPedido  cola_pedido;
public:
	Tienda() {};
	~Tienda() {};
	void Agregar_nuevo_pedido(Pedido* p) { cola_pedido.Agregar(p); };
	void pedido_completado() { 
		Pedido* temp = cola_pedido.GetHead_valor();
		list_recojo.AgregaralInicio(cola_pedido.Desencolar());
		cout << "El pedido "; temp->GetNombreCompleto(); cout << " ha sido completado satisfactoriamente y ha pasado a la cola de recojo \n\n";
	}
	void MostrarListaRecojo()
	{
		cout << "\t Lista de Recojo\n\n";
		list_recojo.Mostrar();
	}
	void MostrarColaPedido()
	{
		cout << "\t Cola de Pedidos\n\n";
		cola_pedido.Mostrar();
	}

};

