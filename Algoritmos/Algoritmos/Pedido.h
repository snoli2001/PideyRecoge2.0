
#ifndef __PEDIDO_H__
#define __PEDIDO_H__

#include"ListaAlimento.h"

class Pedido
{
private:
	string nombre;
	string apellido;
	ListaAlimento lista_alimento;
	double total;
public:
	Pedido(string nombre, string apellido) :nombre(nombre), apellido(apellido) { total = 0; }
	~Pedido() {}
	void impirmir();
	void AgregarAlimentoaLista_inicio(Alimento* a);
	void AgregarAlimentoaLista_final(Alimento* a);
	void AgregarAlimentoaLista_pos(Alimento* a, int pos);
	void EliminarAlimento_pos(int pos);
	Alimento* ExtraerAlimento();
	string GetNombre() { return nombre; }
	string GetApellido() { return apellido; }

	double TotalPedido() {
		return total;
	}
};

void Pedido::impirmir()
{
	cout << "========= " + nombre << "  " + apellido << " ==========" << "\n";
	cout << endl;
	cout << endl;
	lista_alimento.Mostrar();
}

void Pedido::AgregarAlimentoaLista_inicio(Alimento* a)
{
	lista_alimento.AgregaralInicio(a);
	total += a->getPrecio() * a->getCantidad();
}

void Pedido::AgregarAlimentoaLista_final(Alimento* a)
{
	lista_alimento.AgregaralFinal(a);
	total += a->getPrecio() * a->getCantidad();
}
void Pedido::AgregarAlimentoaLista_pos(Alimento* a, int pos)
{
	lista_alimento.AgregarenPosicion(a, pos);
}
void Pedido::EliminarAlimento_pos(int pos) {
	lista_alimento.EliminarenPosicion(pos);
}
Alimento* Pedido::ExtraerAlimento() {
	return lista_alimento.GetItem();
}



#endif // !__Pedido_H__
