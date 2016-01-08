#pragma once
#include<iostream>
#include"Tree.h"

class Comparator
{
public:
	Comparator();
	~Comparator();
	void Compare();
private:
	Tree firstTree;
	Tree secondTree;
	void transformInput(Tree& tree);
	bool isIsomorphic(Node* left, Node* right);

};

