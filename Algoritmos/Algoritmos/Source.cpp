
#include"Pedido.h"

void  main()
{
	/*ListaPedido<Alimento*> lista_alimento;
	lista_alimento.AgregaralInicio(new Contable("Platano",5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola",3,"litros"));
	lista_alimento.Mostrar();*/

	/*ListaAlimento lista_alimento;

	lista_alimento.AgregaralInicio(new Contable("Platano", 5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola", 3, "litros"));
	lista_alimento.Mostrar();*/
	

	Pedido* pe = new Pedido("Joel", "Alvarado");
	pe->AgregarAlimentoaLista_inicio(new Contable("Platano",10));
	pe->AgregarAlimentoaLista_inicio(new Incontable("Leche", 2, "Litros"));
	pe->AgregarAlimentoaLista_final(new Incontable("Queso", 0.5, "Kilos"));
	pe->AgregarAlimentoaLista_pos(new Incontable("Inca Kola", 2, "litros"), 2);
	//pe->EliminarAlimento_pos(2);
	pe->impirmir();
	pe->EliminarAlimento_pos(0);
	pe->impirmir();

	Pedido* pe2 = new Pedido("Daniel", "Quispe");
	pe2->AgregarAlimentoaLista_inicio(new Contable("Mango", 2));
	pe2->AgregarAlimentoaLista_inicio(new Incontable("Azucar", 2, "kilos"));
	pe2->AgregarAlimentoaLista_final(new Incontable("Arroz", 0.5, "Kilos"));
	pe2->AgregarAlimentoaLista_pos(new Incontable("Coca Cola", 2, "litros"), 2);

	pe2->impirmir();

	_getch();
}