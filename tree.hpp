#pragma once

#include "node.hpp"

using namespace std;

class Tree{
  private:
  	Node* root;
  	vector<int> valores;
  public:
	Tree(int order);
	~Tree();
	void add(int key);
	void erase(int key);
	void display();
	void save(char* filename);
	void load(char* filename);
};