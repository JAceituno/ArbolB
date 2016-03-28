#include "node.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Node::Node(int order, Node* father): order(order), father(father){
	keys = new vector<int>();
	children = new vector<Node*>();
}

Node::Node(const Node& other): order(other.getOrder()), father(other.getFather()), tree_level(other.getTree_level()){
	this->children = other.getChildren();
	this->keys = other.getKeys();
}

Node::~Node(){
	delete[] keys;
	/*for (int i = 0; i < childCount; ++i){
		delete children[i];
	}*/
	delete[] children;
}

vector<Node*>* Node::getChildren()const{
	return children;
}

Node* Node::getFather()const{
	return father;
}

vector<int>* Node::getKeys()const{
	return keys;
}

int Node::getOrder()const{
	return order;
}

int Node::getTree_level()const{
	if(father == NULL)
		return 0;
	return father->getTree_level() + 1;
}

int Node::getChildCount()const{
	return children->size();
}
int Node::getKeyCount()const{
	return keys->size();
}
bool Node::isLeaf()const{
	if(getChildCount() == 0)
		return true;
	return false;
}
bool Node::isRoot()const{
	if(father == NULL)
		return true;
	return false;
}
void Node::setFather(Node* father){
	this->father = father;
}
void Node::addKey(int key, bool promotion){
	if(isRoot()){
		cout << "soy root" << endl;
		cout << "############## Root values ############################" << endl;
		for (int i = 0; i < keys->size(); ++i){
			cout << keys->at(i) << endl;
		} 
		cout << "############### End values ############################" << endl;

	}
	if(!promotion){
		cout << "validando hoja" << endl;
		cout << "child count: " << children->size() << endl;
		if(isLeaf()){
			cout << "entre al if" << endl;
			keys->push_back(key);
			cout << "agregue " << key << endl;
			sort(keys->begin(),keys->end());
			if(keys->size() > order-1){
				cout << "hice un promote" << endl;
				promote();
			}
		}
		else{
			cout << "| | | | | | | | Hijos de los hijos | | | | | | | |" << endl;
			for (int i = 0; i < children->size(); ++i)	{
				cout << "child at " << i << endl;
				cout << "child count: " << children->at(i)->getChildCount() << endl;
				cout << "key count:   " << children->at(i)->getKeyCount() << endl;
			}
			cout << "| | | | | | | |  Fin de los hijos  | | | | | | | |" << endl;
			cout << "entre al else" << endl;
			cout << "keys size: " << keys->size() << endl;
			for (int i = 0; i < keys->size(); ++i)	{
				if(key < keys->at(0)){
					cout << "menor que la primera llave nodo intermedio" << endl;
					children->at(0)->addKey(key);
					break;
				}
				if(key > keys->at(keys->size()-1)){
					cout << "mayor que la ultima llave en nodo intermedio" << endl;
					children->at(children->size()-1)->addKey(key);
					break;
				}
				if(key > keys->at(i) && key < keys->at(i+1)){
					cout << "el otro caso" << endl;
					children->at(i+1)->addKey(key);
					break;
				}
			}
		}
		cout << "fin validacion hoja" << endl;
	}
	else{
		cout << "VIP ACCESS. Promoting" << endl;
		keys->push_back(key);
		cout << "agregue " << key << endl;
		sort(keys->begin(),keys->end());
		if(keys->size() > order-1){
			cout << "hice un promote" << endl;
			promote();
		}
	}
}
void Node::promote(){
	if(father == NULL){	
		cout << "soy la raiz (promote)" << endl;
		Node* newNodo = new Node(order); 
		father = newNodo;
		father->addChild(this);
		cout << "ahora tengo papa" << endl;
	}
	if(order%2 == 0){
		cout << "orden par" << endl;
		int promoted = keys->at(order/2);
		cout << "voy a promote " << promoted << endl;
		father->addKey(promoted, true);
		cout << "se la mande al padre" << endl;
		keys->erase(keys->begin() + order/2);
		cout << "borre tranquilo" << endl;
		cout << "me voy a split" << endl;
		split(promoted);
		cout << "me split correctly" << endl;
	}
	else{
		cout << "orden impar" << endl;
		int promoted = keys->at((order-1)/2);
		cout << "voy a promote " << promoted << endl;
		father->addKey(promoted, true);
		cout << "se la mande al padre" << endl;
		keys->erase(keys->begin() +((order-1)/2));
		cout << "**************Tengo estos valores*********************" << endl;
		for (int i = 0; i < keys->size(); ++i){
			cout << keys->at(i) << endl;
		} 
		cout << "**************Fin valores*****************************" << endl;
		cout << "borre tranquilo" << endl;
		cout << "me voy a split" << endl;
		split(promoted);
		cout << "me split correctly" << endl;
	}
}
void Node::split(int promoted){
	cout << "en split" << endl;
	Node* temp = new Node(order, father);
	cout << "nuevo nodo creado" << endl;
	for (int i = order-1; i > 0; --i){
		if(keys->at(i-1) >= promoted){
			temp->addKey(keys->at(i-1));
			cout << "agregando mayores que yo al nodo nuevo" << endl;
			keys->pop_back();
			cout << "borrando del viejo nodo" << endl;
		}
	}
	sortChildren();
	if(!isLeaf()){
		cout << "ENTRE AL NUEVO IF ----------------------------" << endl;
		int numTemporalParaSplit = getChildCount() +1;
		cout << numTemporalParaSplit << endl;
		if(numTemporalParaSplit%2 == 0){
			for (int i = numTemporalParaSplit-1; i > (numTemporalParaSplit)/2; --i){
				temp->addChild(children->at(i-1));
				children->pop_back();
			}
		}
		else{
			for (int i = numTemporalParaSplit-1; i > (numTemporalParaSplit-1)/2; --i){
				temp->addChild(children->at(i-1));
				children->pop_back();
			}
		}
	}
	father->addChild(temp);
}
void Node::addChild(Node* newNodo){
	newNodo->setFather(this);
	children->push_back(newNodo);
	cout << "agregue nuevo nodo al padre" << endl;
	sortChildren();
	cout << "hijos sorted" << endl;
}
void Node::toString(){
	for (int i = 0; i < getTree_level(); ++i){
		cout << "| " << i << " |";
	}
	for (int i = 0; i < getKeyCount(); ++i)	{
		cout << keys->at(i) << " ";
	}
	cout << endl;
	if(!isLeaf()){
		for (int i = 0; i < getChildCount(); ++i){
			children->at(i)->toString();
		}
	}
}

void Node::sortChildren(){
	//asumiendo que todo está en orden menos el último elemento
	for(int i = 0; i < getChildCount()-1; ++i){
		if(children->at(getChildCount()-1) < children->at(i)){
			children->insert(children->begin()+i, children->at(getChildCount()-1));
			children->pop_back();
			break;
		}
	}
}

bool operator<(const Node &lhs, const Node &rhs){
    if(lhs.getKeys()->at(lhs.getKeys()->size()-1) < rhs.getKeys()->at(0))
        return true;
    return false;
}