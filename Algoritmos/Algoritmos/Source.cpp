#include <fstream>
#include "ListaStock.h"
#include"Pedido.h"
#include "ColaProceso.h"
#include "PilaRecogido.h"


void  main()
{
	string nombre, apellido;
	int con=0, inc=0;
	string producto, medida;
	double cant, precio;
	
	/*ListaS<Alimento*> lista_alimento;
	lista_alimento.AgregaralInicio(new Contable("Platano",5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola",3,"litros"));
	lista_alimento.Mostrar();*/

	/*ListaAlimento lista_alimento;

	lista_alimento.AgregaralInicio(new Contable("Platano", 5));
	lista_alimento.AgregaralInicio(new Incontable("Inca Kola", 3, "litros"));
	lista_alimento.Mostrar();*/
	LStock* stock = new LStock();
	Recojo* recojo = new Recojo();
	ReStock* restockeo = new ReStock();
	Proceso* proceso = new Proceso();
	ifstream archstock;
	archstock.open("NStock.txt", ios::in);
	if (archstock.is_open()) {
		archstock >> con;
		archstock >> inc;
		archstock.close();
	}
	stock->StockInicial(con, inc);
	ifstream stockeo;
	stockeo.open("Stock.txt", ios::in);
	if (stockeo.is_open()) {
		
		for (int i = 0; i < con; i++)
		{
			stockeo >> producto;
			stockeo >> cant;
			stockeo >> precio;
			Contable* nuevo = new Contable(producto, cant);
			nuevo->setPrecio(precio);
			stock->AgregaralInicio(nuevo);
		}
		for (int i = 0; i < inc; i++)
		{
			stockeo >> producto;
			stockeo >> cant;
			stockeo >> medida;
			stockeo >> precio;
			Incontable* nuevo = new Incontable(producto, cant,medida);
			nuevo->setPrecio(precio);
			stock->AgregaralInicio(nuevo);
		}
		stockeo.close();
	}

	
	ifstream archi1;
	
	
	archi1.open("Pedidos.txt", ios::in);
	if (archi1.is_open()) {
		while (!archi1.eof())
		{
			archi1 >> nombre;
			archi1 >> apellido;
			Pedido* pe = new Pedido(nombre, apellido);
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
			proceso->Encolar(pe);
		}
	
		archi1.close();
	
	}
	proceso->MostrarPedidos();
	proceso->Procesado(recojo,stock,restockeo);
	proceso->Procesado(recojo, stock, restockeo);
	proceso->MostrarPedidos();
	recojo->imprimir();
	restockeo->imprimir();
	stock->ActualizarArchivo();
	

	_getch();
}