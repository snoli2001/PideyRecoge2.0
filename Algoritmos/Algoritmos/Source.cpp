
#include"ListaPedido.h"
#include"Cola.h"
#include"ColaPedido.h"
void  main()
{
	

	//CREACION DEL PEDIDO 1
	Pedido* pe1 = new Pedido("Joel", "Alvarado");
	pe1->AgregarAlimentoaLista_inicio(new Contable("Platano",10));
	pe1->AgregarAlimentoaLista_inicio(new Incontable("Leche", 2, "Litros"));
	pe1->AgregarAlimentoaLista_final(new Incontable("Queso", 0.5, "Kilos"));
	pe1->AgregarAlimentoaLista_pos(new Incontable("Inca Kola", 2, "litros"), 2);

	//CREACION DEL PEDIDO 2
	Pedido* pe2 = new Pedido("Daniel", "Quispe");
	pe2->AgregarAlimentoaLista_inicio(new Contable("Mango", 2));
	pe2->AgregarAlimentoaLista_inicio(new Incontable("Azucar", 2, "kilos"));
	pe2->AgregarAlimentoaLista_final(new Incontable("Arroz", 0.5, "Kilos"));
	pe2->AgregarAlimentoaLista_pos(new Incontable("Coca Cola", 2, "litros"), 2);

	//CREACION DEL PEDIDO 3
	Pedido* pe3 = new Pedido("Jorge", "Aguilar");
	pe3->AgregarAlimentoaLista_inicio(new Contable("Palta", 2));
	pe3->AgregarAlimentoaLista_inicio(new Incontable("Mantequilla", 50, "gramos"));
	pe3->AgregarAlimentoaLista_final(new Incontable("Huevo", 0.5, "Kilos"));
	pe3->AgregarAlimentoaLista_pos(new Incontable("Fanta", 2, "litros"), 2);


	//PRUEBA DE LA COLA
	ColaPedido cola_pedido;
	cola_pedido.Agregar(pe1);
	cola_pedido.Agregar(pe2);
	cola_pedido.Agregar(pe3);
	cola_pedido.Mostrar();

	//DESENCOLAR EL PRIMER PEDIDO
	cola_pedido.Desencolar_pedido();

	//NUEVO COLA DE PEDIDOS RESTANTES
	cola_pedido.Mostrar();

	//DESENCOLA EL SEGUNDO PEDIDO
	cola_pedido.Desencolar_pedido();

	//NUEVA COLA DE PEDIDOS RESTANTES
	cola_pedido.Mostrar();



	_getch();
}