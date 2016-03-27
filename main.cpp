#include <iostream>
#include "tree.hpp"
#include "node.hpp"

int main(int argc, char const *argv[]){
	Tree arbol(3);
	cout << "arbol creado" << endl;
	for (int i = 0; i < 10; ++i){
		cout << "=============== AGREGANDO " << i << " ============================" << endl;
		arbol.add(i);
		cout << "=============== TERMINE DE AGREGAR " << i << " ===================" << endl;
	}
	arbol.display();
	cout << "imprimi" << endl;
	return 0;
}