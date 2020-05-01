
#include"Tienda.h"
void  main()
{
	

	//CREACION DEL PEDIDO 1
	Pedido* pe1 = new Pedido("Joel", "Alvarado");
	pe1->AgregarAlimentoaLista_inicio(new Contable("Platano",10));
	pe1->AgregarAlimentoaLista_inicio(new Incontable("Leche", 2, "litros"));
	pe1->AgregarAlimentoaLista_final(new Incontable("Queso", 0.5, "kilos"));
	pe1->AgregarAlimentoaLista_pos(new Incontable("Inca Kola", 2, "litros"), 2);

	//CREACION DEL PEDIDO 2
	Pedido* pe2 = new Pedido("Daniel", "Quispe");
	pe2->AgregarAlimentoaLista_inicio(new Contable("Mango", 2));
	pe2->AgregarAlimentoaLista_inicio(new Incontable("Azucar", 2, "kilos"));
	pe2->AgregarAlimentoaLista_final(new Incontable("Arroz", 0.5, "kilos"));
	pe2->AgregarAlimentoaLista_pos(new Incontable("Coca Cola", 2, "litros"), 2);

	//CREACION DEL PEDIDO 3
	Pedido* pe3 = new Pedido("Jorge", "Aguilar");
	pe3->AgregarAlimentoaLista_inicio(new Contable("Palta", 2));
	pe3->AgregarAlimentoaLista_inicio(new Incontable("Queso", 0.5, "gramos"));
	pe3->AgregarAlimentoaLista_final(new Incontable("Huevo", 0.5, "kilos"));
	pe3->AgregarAlimentoaLista_pos(new Incontable("Fanta", 2, "litros"), 2);

	Tienda* tienda= new Tienda();
	tienda->Agregar_nuevo_pedido(pe1);
	tienda->Agregar_nuevo_pedido(pe2);
	tienda->Agregar_nuevo_pedido(pe3);

	tienda->MostrarColaPedido();
	tienda->MostrarListaRecojo();
	tienda->pedido_completado();
	tienda->pedido_completado();

	tienda->MostrarListaRecojo();
	tienda->MostrarColaPedido();


	////PRUEBA DE LA COLA
	//ColaPedido cola_pedido;
	//cola_pedido.Agregar(pe1);
	//cola_pedido.Agregar(pe2);
	//cola_pedido.Agregar(pe3);
	//cola_pedido.Mostrar();
	//_getch();
	//system("cls");
	////DESENCOLAR EL PRIMER PEDIDO
	//cola_pedido.Desencolar_pedido();

	//_getch();//AL PRESIONAR UNA TECLA SE MUESTRA LOS PEIDOS RESTANTES
	//system("cls");

	////NUEVO COLA DE PEDIDOS RESTANTES
	//cola_pedido.Mostrar();

	//_getch();//AL PRESIONAR UNA TECLA SE MUESTRA EL PEDIDO QUE SE COMPLETO 
	//system("cls");

	////DESENCOLA EL SEGUNDO PEDIDO
	//cola_pedido.Desencolar_pedido();

	//_getch();//AL PRESIONAR UNA TECLA SE MUESTRA EL PEDIDO QUE SE COMPLETO 
	//system("cls");

	////NUEVA COLA DE PEDIDOS RESTANTES
	//cola_pedido.Mostrar();



	_getch();
}