#include "tree.hpp"
#include "node.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Tree::Tree(int order){
	root = new Node(order);
}
Tree::~Tree(){

}
void Tree::add(int key){
	cout << "entre al add" << endl;
	root->addKey(key);
	cout << "agregue al nodo" << endl;
	valores.push_back(key);
	cout << "& & & & & & empezando while & & & & & &" << endl;
	while(root->getFather() != NULL){
		cout << "root have father" << endl;
		root = root->getFather();
	}
	cout << "& & & & & & termina while & & & & & &" << endl;
}
void Tree::erase(int key){

}
void Tree::display(){
	cout << root->toString() << endl;
}
void Tree::save(char* filename){

}
void Tree::load(char* filename){

}