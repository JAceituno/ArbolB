#include "node.hpp"
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Node::Node(int order, Node* father): order(order), father(father){
	if(father != NULL){
		tree_level = father->getTree_level() + 1;
	}
	else{
		tree_level = 0;
	}
}

Node::~Node(){
	delete[] keys;
	/*for (int i = 0; i < childCount; ++i){
		delete children[i];
	}*/
	delete[] children;
}

vector<Node*>* Node::getChildren(){
	return children;
}

Node* Node::getFather(){
	return father;
}

vector<int>* Node::getKeys(){
	return keys;
}

int Node::getOrder(){
	return order;
}

int Node::getTree_level(){
	return tree_level;
}

int Node::getChildCount(){
	return childCount;
}
int Node::getKeyCount(){
	return keyCount;
}
bool Node::isLeaf(){
	if(childCount == 0)
		return true;
	return false;
}
bool Node::isRoot(){
	if(father == NULL)
		return true;
	return false;
}
void Node::addKey(int key){
	if(isLeaf()){
		keys->push_back(key);
		sort(keys->begin(),keys->end());
		if(keys->size() > order-1){
			promote();
		}
	}
	else{
		for (int i = 0; i < keys->size()-1; ++i)	{
			if(key < keys->at(0)){
				children->at(0)->addKey(key);
				break;
			}
			if(key > keys->at(keys->size()-1)){
				children->at(children->size()-1)->addKey(key);
			}
			else if(key > keys->at(i) && key < keys->at(i+1)){
				children->at(i+1)->addKey(key);
			}
		}
	}
}
void Node::promote(){
	if(father != NULL){	
		father = new Node(order);
		father->addChild(this);
	}
	if(order%2 == 0){
		int promoted = keys->at(order/2);
		father->addKey(promoted);
		keys->erase(keys->begin() + order/2);
		split(promoted);

	}
	else{
		int promoted = keys->at((order-1)/2);
		father->addKey(promoted);
		keys->erase(keys->begin() +((order-1)/2));
		split(promoted);
	}
}
void Node::split(int promoted){
	Node* temp = new Node(order);
	for (int i = 0; i < order-1; ++i){
		if(keys->at(i) >= promoted){
			temp->addKey(keys->at(i));
			children->erase(children->begin() + i);
			--i;
		}
	}
	father->addChild(temp);
}
void Node::addChild(Node* newNodo){
	children->push_back(newNodo);
}
string Node::toString(){
	stringstream ss;
	for (int i = 0; i < tree_level; ++i)	{
		ss << "\t";
	}
	for (int i = 0; i < keys->size(); ++i) {
		ss << keys->at(i) << " ";
	}
	if(!isLeaf()){
		for (int i = 0; i < children->size(); ++i)	{
			children->at(i)->toString();
		}
	}
	return ss.str();
}