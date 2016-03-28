#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "tree.hpp"
#include "node.hpp"

using namespace std;

int menu();

int main(int argc, char const *argv[]){
	//cout << argc << endl;
	if(argc == 4){
		Tree arbol;
		arbol.setOrder(atoi(argv[2]));
		cout << "Por favor espere..." << endl;
		for (int i = 0; i < atoi(argv[3]); ++i)	{
			arbol.add(i);
		}
		arbol.save(argv[1]);
		exit(0);
	}
	if(argc == 3){
		//cout << "aqui" << endl;
		Tree arbol;
		//cout << "no puedo hacer esto" << endl;
		if(argv[2][0] == 'd'){
			//cout << "entre" << endl;
			cout << "Por favor espere..." << endl;
			arbol.load(argv[1]);
			arbol.display();
			exit(0);
		}
	}
	if(argc == 2){
		Tree arbol;
		int selec = menu();
		while(true){
			if(selec == 1){
				cout << "Ingrese grado del arbol: ";
				int order;
				cin >> order;
				arbol.setOrder(order);
			}
			if(selec == 2){
				cout << "Ingrese elemento: ";
				int toadd;
				cin >> toadd;
				arbol.add(toadd);
			}
			if(selec == 3){
				arbol.display();
			}
			if(selec == 4){
				arbol.save(argv[1]);
			}
			if(selec == 5){
				arbol.load(argv[1]);
			}
			if(selec == 6){
				exit(0);
			}
			selec = menu();
		}
	}
	else{
		cerr << "Missing or too much arguments" << endl;
		exit(1);
	}
	return 0;
}

int menu(){
	cout << "*-~.~-*-~.~-*-~.~-*MENU*-~.~-*-~.~-*-~.~-*\n"
		 << "1. Crear arbol\n"
		 << "2. Agregar elemento\n"
		 << "3. Display btree\n"
		 << "4. Guardar arbol\n"
		 << "5. Cargar arbol\n"
		 << "6. Salir\n"
		 << "Ingrese opcion: ";
	int ans = 0;
	cin >> ans;
	while(ans < 1 || ans > 6){
		cout << "Opcion no valida, ingrese de nuevo: ";
		cin >> ans;
	}
	return ans;
}