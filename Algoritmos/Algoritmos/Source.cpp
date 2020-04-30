
#include"Persona.h"

void  main()
{
	/*Lista<Alimento*> lista_alimento;
	lista_alimento.AgregaralInicio(new Contable("Platano",5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola",3,"litros"));
	lista_alimento.Mostrar();*/

	/*ListaAlimento lista_alimento;

	lista_alimento.AgregaralInicio(new Contable("Platano", 5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola", 3, "litros"));
	lista_alimento.Mostrar();*/


	Persona* per = new Persona("Joel", "Alvarado");
	per->AgregarAlimentoaLista_inicio(new Contable("Platano",10));
	per->AgregarAlimentoaLista_inicio(new Incontable("Leche", 2, "Litros"));
	per->AgregarAlimentoaLista_final(new Incontable("Queso", 0.5, "Kilos"));
	per->AgregarAlimentoaLista_pos(new Incontable("Inca Kola", 2, "litros"), 2);
	per->impirmir();

	Persona* per2 = new Persona("Daniel", "Quispe");
	per2->AgregarAlimentoaLista_inicio(new Contable("Mango", 2));
	per2->AgregarAlimentoaLista_inicio(new Incontable("Azucar", 2, "kilos"));
	per2->AgregarAlimentoaLista_final(new Incontable("Arroz", 0.5, "Kilos"));
	per2->AgregarAlimentoaLista_pos(new Incontable("Coca Cola", 2, "litros"), 2);
	per2->impirmir();

	_getch();
}