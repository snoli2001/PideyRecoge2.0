#pragma once
#include<conio.h>
#include<iostream>
#include<string.h>

using namespace std;

class Alimento
{
public:
	Alimento(string nombre):nombre(nombre) {}
	virtual void imprimir() = 0;
protected:
	string nombre;
	
};
class Contable :public Alimento
{
public:
	Contable(string nombre,int cantidad):Alimento(nombre),cantidad(cantidad){}
	void operator=(Contable& Contable)
	{
		nombre = Contable.nombre;
	}
	void imprimir() { cout << nombre <<"---------- "<< cantidad<<endl; }

private:
	int cantidad;
};

class Incontable :public Alimento
{
public:
	Incontable(string nombre, double cantidad,string unidades) :Alimento(nombre), cantidad(cantidad),unidades(unidades) {}
	void operator=(Incontable& Incontable)
	{
		nombre = Incontable.nombre;
	}
	void imprimir() { cout << nombre<<"---------- "<<cantidad<<" "<<unidades<<endl; }
	
private:
	double cantidad;
	string unidades;
};
template<class A>
class AlimentoPlantilla
{
private :
	A Alimento;
public:
	AlimentoPlantilla(){}
	AlimentoPlantilla(A d):Alimento(d){}
	void Mostrar()
	{
		Alimento.imprimir();
	}

};

