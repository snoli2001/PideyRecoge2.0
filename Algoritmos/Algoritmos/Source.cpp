#include <fstream>
#include "ListaStock.h"
#include"Pedido.h"
#include "ColaProceso.h"
#include "PilaRecogido.h"
#include "ListaRancking.h"

void main()
{
	    string nombre1, apellido1;
		int con=0, inc=0;
		string producto, medida;
		double cant, precio;
		
		Recogido* recogido = new Recogido();
		LRanck* ranking = new LRanck();
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
				archi1 >> nombre1;
				archi1 >> apellido1;
				Pedido* pe = new Pedido(nombre1, apellido1);
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
	int opcion = 0;
	cout << "\t Bienvenido\n\n";
	while (opcion != 10)
	{
		do {

			system("cls");
			cout << "\tPor favor Seleccione una opcion\n\n";
			cout << "1.Armar nuevo pedido\n";
			cout << "2.Ver los pedidos en curso\n";
			cout << "3.ver los pedidos en la lista de recogo\n";
			cout << "4.Ver pila de pedidos recogidos\n";
			cout << "5.Ver mi stock disponible\n";
			cout << "6.Ver mi lista de restock\n";
			cout << "7.Ver el ranking de mis mayores compradores\n";
			cout << "8.Enviar pedido a la lista de recogo\n";
			cout << "9.Confirmar Recogo\n";
			cout << "10.Salir\n";
			cin >> opcion;
			if (opcion < 0 || opcion>10) { cout << "Por favor ingrese una opcion valida\n"; _getch(); }
		} while (opcion < 1 || opcion>10);
		if (opcion == 1)
		{
			int cant; int n=1;
			string nombre; string apellido;
			system("cls");

			cout << "Por favor ingrese el nombre del cliente\n";
			cout << "Nombre: "; cin >> nombre; cout << endl;
			cout << "Apellido: "; cin >> apellido; cout << endl;

			Pedido* pe = new Pedido(nombre, apellido);

			cout << "Cuantos alimentos quieres agregar al pedido?\n";
			cin >> cant;

			while (n!=cant+1)
			{
				cout << "Producto " << n << " de " << cant; cout << endl;
				int op;
				cout << "1.Agregar alimento contable\n";
				cout << "2.Agregar alimento incontable\n";
				cin >> op;
				if (op ==1 ){ 
					string producto; int cantidad;
					cout << "Ingrese el nombre del producto: "; cin >> producto; cout << endl;
					cout << "Ingrese la cantidad de unidades del producto: "; cin >> cantidad; cout << endl;
				
					pe->AgregarAlimentoaLista_inicio(new Contable(producto, cantidad));
					
				}
				else
					if (op == 2) {
						string producto; double cantidad; string medida;
						cout << "Ingrese el nombre del producto: "; cin >> producto; cout << endl;
						cout << "Ingrese la cantidad del producto: "; cin >> cantidad; cout << endl;
						cout << "Ingrese las unidades del producto: "; cin >> medida;cout<< endl;
						pe->AgregarAlimentoaLista_inicio(new Incontable(producto, cantidad,medida));
				
					}
				n++;
				system("cls");
			}
			proceso->Encolar(pe);
		}
		if (opcion == 2) {
			proceso->MostrarPedidos();
			_getch();
		}
		if (opcion == 3) {
			recojo->imprimir();
			_getch();
		}
		if (opcion == 4) {
			recogido->Reporte();
			_getch();
		}
		if (opcion == 5) {
			stock->ActualizarArchivo();
			stock->Imprimir();
			_getch();
		}
		if (opcion == 6) {
			restockeo->imprimir();
			_getch();
		}
		if (opcion == 7) {
			ranking->mostrar();
			_getch();
		}
		if (opcion == 8) {
			proceso->Procesado(recojo, stock, restockeo);
			_getch();
		}
		if (opcion == 9) {
			string nombre, apellido;
			cout << "Ingrese el nombre del cliente: "; cin >> nombre; cout << endl;
			cout << "Ingrese el apellido del cliente: "; cin >> apellido; cout << endl;
			recojo->recoger(recogido, nombre,apellido, ranking);
			_getch();
		}
		if (opcion == 10) {
			cout << "Gracias por utilizar nuestro programa";
			_getch();
		}
	}
	_getch();
}