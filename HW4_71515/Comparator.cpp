#include<iostream>
#include"Comparator.h"

Comparator::Comparator()
{

}

Comparator::~Comparator()
{
	
}
///
///Transforms from text to Tree
///
void Comparator::transformInput(Tree& tree)
{
	
	char buffer[1024];
	Node* current;
	std::cout << "Input Tree : ";
	std::cin.getline(buffer, 1024, '\n');
	for (size_t i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] >= '0' && buffer[i] <= '9')
		{

			int num = 0;
			while (isdigit(buffer[i]))
			{
				num = 10 * num + (buffer[i] - '0');
				i++;
			}
			if (tree.getRoot()==NULL)
			{
				Node* temp = new Node(num);
				tree.setRoot(temp);
				 current= tree.getRoot();
			}
			tree.addNode(num, *current);
			
			i--;

		}
		if (buffer[i] == '{')
		{
			current = current->children[current->children.size()-1];
		}
		if (buffer[i] == '}')
		{
			current = current->parent;
		}
		
	}
	

}
///
///Check if the trees are isomorphic
///
bool Comparator::isIsomorphic(Node* left, Node* right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}

	for (size_t i = 0; i < left->children.size(); i++)
	{
		int isMet = 0;
		bool isomorphic = false;

		for (size_t j = 0; j < right->children.size(); j++)
		{
			if (left->children[i]->children.size() == right->children[j]->children.size())
			{
				isomorphic = isIsomorphic(left->children[i], right->children[j]);
				if (isomorphic)
				{
					isMet++;
					break;
				}
			}
		}

		if (isomorphic == false || isMet == 0)
		{
			return false;
		}
			

	}

	return true;
}

void Comparator::Compare()
{
	transformInput(firstTree);
	transformInput(secondTree);
	if (isIsomorphic(firstTree.getRoot(), secondTree.getRoot()))
	{
		std::cout << "YES!" << std::endl;
	}
	else
	{
		std::cout << "NO!" << std::endl;
	}
	
}
