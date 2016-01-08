#pragma once
#include<iostream>
#include<vector>

struct Node
{
	Node* parent;
	int data;
	std::vector<Node*> children;
	Node() :parent(NULL),data(0) {}
	Node(int nD)
	{
		parent = NULL;
		data = nD;
	}
	void addChild(int nC);
};
class Tree
{
public:
	Tree() :root(NULL) {}
	void addNode(int nN,Node& parentN);
	void setRoot(Node* n)
	{
		this->root = n;
	}
	Node* getRoot() const
	{
		return root;
	}
	~Tree();


private:
	Node* root;
	void treeDel(Node* dN);

};

