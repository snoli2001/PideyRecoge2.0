#pragma once
#include"ListaAlimento.h"

class Persona
{
public:
	Persona(string nombre, string apellido) :nombre(nombre), apellido(apellido) {}
	~Persona(){}
	void impirmir();
	void AgregarAlimentoaLista_inicio(Alimento* a);
	void AgregarAlimentoaLista_final(Alimento* a);
	void AgregarAlimentoaLista_pos(Alimento* a,int pos);
private:
	string nombre;
	string apellido;
	ListaAlimento lista_alimento;

};

void Persona::impirmir()
{
	cout << "========= " + nombre << "  " + apellido<<" =========="<<"\n";
	cout << endl;
	cout << endl;
	lista_alimento.Mostrar();
}

void Persona::AgregarAlimentoaLista_inicio(Alimento* a)
{
	lista_alimento.AgregaralInicio(a);
}

void Persona::AgregarAlimentoaLista_final(Alimento* a)
{
	lista_alimento.AgregaralFinal(a);
}
void Persona::AgregarAlimentoaLista_pos(Alimento* a,int pos)
{
	lista_alimento.AgregarenPosicion(a,pos);
}

