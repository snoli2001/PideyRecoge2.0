#include"Alimento.h"
#include"ListaAlimentos.h"


void  main()
{
	ListaAlimentos<Alimento*> lista_alimento;
	lista_alimento.AgregaralInicio(new Contable("Platano",5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola",3,"litros"));
	lista_alimento.Mostrar();

	cin.get();

	_getch();
}