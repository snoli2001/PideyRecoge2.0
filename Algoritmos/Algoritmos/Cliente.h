#ifndef __CLIENTE_H__
#define __CLIENTE_H__
#include <iostream>

using namespace std;
class Cliente
{
public:
	Cliente(string n, string a) { 
	nombre = n;
	apellido = a;
	total = 0;
	}
	~Cliente(){}
	string getNombre() {
		return nombre;
	}
	string getApellido() {
		return apellido;
	}
	double getTotal() {
		return total;
	}
	void  updateTotal(double v) {
		total += v;
	}

private:
	string nombre;
	string apellido;
	double total;

};


#endif // !__CLIENTE_H__
