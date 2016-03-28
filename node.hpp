#pragma once

#include <vector>
#include <string>

using namespace std;

class Node{

  private:
	vector<Node*>* children;
	Node* father;
	vector<int>* keys;
	int order;
	int tree_level;

  public:
	Node(int order, Node* father = NULL);
	~Node();
	Node(const Node& other);
	vector<Node*>* getChildren()const;
	Node* getFather()const;
	vector<int>* getKeys()const;
	int getOrder()const;
	int getTree_level()const;
	int getChildCount()const;
	int getKeyCount()const;
	bool isLeaf()const;
	bool isRoot()const;
	void setFather(Node* father);
	void addKey(int key, bool promotion = false);
	void promote();
	void split(int promoted);
	void addChild(Node* newNodo);
	void toString();
	void sortChildren();
};
bool operator<(const Node &lhs, const Node &rhs);