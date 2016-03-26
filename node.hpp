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
	int childCount;
	int keyCount;
	bool root;

  public:
	Node(int order, Node* father = 0);
	~Node();
	vector<Node*>* getChildren();
	Node* getFather();
	vector<int>* getKeys();
	int getOrder();
	int getTree_level();
	int getChildCount();
	int getKeyCount();
	bool isLeaf();
	bool isRoot();
	void addKey(int key);
	void promote();
	void split(int promoted);
	void addChild(Node* newNodo);
	string toString();
};