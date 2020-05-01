#pragma once
#include"ListaAlimento.h"

class Pedido
{
public:
	Pedido(string nombre, string apellido) :nombre(nombre), apellido(apellido) {}
	~Pedido(){}
	void impirmir();
	void AgregarAlimentoaLista_inicio(Alimento* a);
	void AgregarAlimentoaLista_final(Alimento* a);
	void AgregarAlimentoaLista_pos(Alimento* a,int pos);
	void EliminarAlimento_pos(int pos);
private:
	string nombre;
	string apellido;
	ListaAlimento lista_alimento;

};

void Pedido::impirmir()
{
	cout << "========= " + nombre << "  " + apellido<<" =========="<<"\n";
	cout << endl;
	cout << endl;
	lista_alimento.Mostrar();
}

void Pedido::AgregarAlimentoaLista_inicio(Alimento* a)
{
	lista_alimento.AgregaralInicio(a);
}

void Pedido::AgregarAlimentoaLista_final(Alimento* a)
{
	lista_alimento.AgregaralFinal(a);
}
void Pedido::AgregarAlimentoaLista_pos(Alimento* a,int pos)
{
	lista_alimento.AgregarenPosicion(a,pos);
}
void Pedido::EliminarAlimento_pos(int pos) {
	lista_alimento.EliminarenPosicion(pos);
}

