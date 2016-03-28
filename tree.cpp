#include "tree.hpp"
#include "node.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Tree::Tree(){

}
Tree::Tree(int order){
	root = new Node(order);
}
Tree::~Tree(){
	delete root;
}
void Tree::setOrder(int order){
	root = new Node(order);
	//cout << "QUEEEE PEEEEDOS" << endl;
}
void Tree::add(int key){
	//cout << "entre al add" << endl;
	root->addKey(key);
	//cout << "agregue al nodo" << endl;
	valores.push_back(key);
	//cout << "& & & & & & empezando while & & & & & &" << endl;
	while(root->getFather() != NULL){
		//cout << "root have father" << endl;
		root = root->getFather();
	}
	//cout << "& & & & & & termina while & & & & & &" << endl;
}
void Tree::erase(int key){
	//cout << "Not implemented yet" << endl;
}
void Tree::display(){
	root->toString();
}
void Tree::save(const char* filename){
	ofstream tree(filename, ios::binary|ios::out);
	int order = root->getOrder();
	tree.write((char*)&order,sizeof(int));
	for (int i = 0; i < valores.size(); ++i)	{
		tree.write((char*)&valores[i],sizeof(int));
	}
	tree.flush();
	tree.close();
}
void Tree::load(const char* filename){
	ifstream tree(filename, ios::binary|ios::in);
	int order;
	tree.read(reinterpret_cast<char*>(&order),sizeof(int));
	setOrder(order);
	if(tree.good()){
		while(!tree.eof()){
			int agregar;
			tree.read(reinterpret_cast<char*>(&agregar),sizeof(int));
			add(agregar);
		}
	}
	tree.close();
}