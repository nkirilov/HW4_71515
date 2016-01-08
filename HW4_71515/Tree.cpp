#include<iostream>
#include"Tree.h"
///
///Deletes tree
///
void Tree::treeDel(Node* dN)
{
	std::vector<Node*> temp=dN->children;
	delete dN;
	for (size_t i = 0; i < temp.size(); i++)
	{
		treeDel(temp[i]);
	}
}

Tree::~Tree()
{
	treeDel(root);
}
///
///Adds Child
///
void Node::addChild(int nC)
{
	Node* pNode = new Node;
	pNode->data = nC;
	pNode->parent = this;
	children.push_back(pNode);
}
///
///Adds a Node
///
void Tree::addNode(int nN,Node& parentN)
{
	

	if (&parentN==NULL)
	{
		Node* pNode = new Node(nN);
		parentN = *pNode;
	}
	else
	{
		parentN.addChild(nN);
	}
}
