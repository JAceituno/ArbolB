#pragma once

#include "node.hpp"

using namespace std;

class Tree{
  private:
  	Node* root;
  public:
	Tree(int order);
	~Tree();
	void add(int key);
	void erase(int key);
	void display();
};