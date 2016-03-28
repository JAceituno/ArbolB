#pragma once

#include "node.hpp"

using namespace std;

class Tree{
  private:
  	Node* root;
  	vector<int> valores;
  public:
	Tree();
	Tree(int order);
	~Tree();
	void setOrder(int order);
	void add(int key);
	void erase(int key);
	void display();
	void save(const char* filename);
	void load(const char* filename);
};