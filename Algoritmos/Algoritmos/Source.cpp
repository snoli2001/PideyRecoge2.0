#include <fstream>
#include "ListaStock.h"
#include"Pedido.h"
#include "ColaProceso.h"
#include "PilaRecogido.h"


void  main()
{
	/*ListaS<Alimento*> lista_alimento;
	lista_alimento.AgregaralInicio(new Contable("Platano",5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola",3,"litros"));
	lista_alimento.Mostrar();*/

	/*ListaAlimento lista_alimento;

	lista_alimento.AgregaralInicio(new Contable("Platano", 5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola", 3, "litros"));
	lista_alimento.Mostrar();*/
	LStock* stock = new LStock();
	ifstream arch;



	string nombre, apellido;
	ifstream archi1;
	int con, inc;
	string producto, medida;
	double cant;
	Pedido* pe;
	archi1.open("Pedido1.txt", ios::in);
	if (archi1.is_open()) {
		archi1 >> nombre;
		archi1 >> apellido;
		pe = new Pedido(nombre, apellido);
		archi1 >> con;
		archi1 >> inc;
		for (int i = 0; i < con; i++)
		{
			archi1 >> producto;
			archi1 >> cant;
			pe->AgregarAlimentoaLista_inicio(new Contable(producto, cant));
			
		}
		for (int i = 0; i < inc; i++)
		{
			archi1 >> producto;
			archi1 >> cant;
			archi1 >> medida;
			pe->AgregarAlimentoaLista_inicio(new Incontable(producto, cant, medida));
		}
		archi1.close();
		pe->impirmir();
		pe->EliminarAlimento_pos(0);
		pe->impirmir();
	}
	
	//pe->EliminarAlimento_pos(2);
	

	Pedido* pe2 = new Pedido("Daniel", "Quispe");
	pe2->AgregarAlimentoaLista_inicio(new Contable("Mango", 2));
	pe2->AgregarAlimentoaLista_inicio(new Incontable("Azucar", 2, "kilos"));
	pe2->AgregarAlimentoaLista_final(new Incontable("Arroz", 0.5, "Kilos"));
	pe2->AgregarAlimentoaLista_pos(new Incontable("Coca Cola", 2, "litros"), 2);

	pe2->impirmir();

	_getch();
}