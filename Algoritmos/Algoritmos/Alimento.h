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
	string getNombre() { return nombre; }
	virtual void updateCantidad(int v) = 0;
	virtual double getCantidad() = 0;
protected:
	string nombre;
	
};
class Contable :public Alimento
{
private:
	int cantidad;
public:
	Contable(string nombre,int cantidad):Alimento(nombre),cantidad(cantidad){}
	void operator=(Contable& Contable)
	{
		nombre = Contable.nombre;
	}
	void imprimir() { cout << nombre << "     "<<"\t" << cantidad  <<endl; }
	
	void updateCantidad(int v) {
		cantidad -= v;
	}
	double getCantidad() {
		return cantidad;
	}

};

class Incontable :public Alimento
{
public:
	Incontable(string nombre, double cantidad,string unidades) :Alimento(nombre), cantidad(cantidad),unidades(unidades) {}
	void operator=(Incontable& Incontable)
	{
		nombre = Incontable.nombre;
	}
	void imprimir() { cout <<  nombre<<"     "<<"\t"<<cantidad<<" "<<unidades<<endl; }
	void updateCantidad(int v) {
		cantidad -= v;
	}
	double getCantidad() {
		return cantidad;
	}
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

