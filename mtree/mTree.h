#include "node.h"
#include <iostream>
using std::cout;
using std::endl;

class MTree
{
public:
	MTree()
	{
		root = NULL;
	}
	MTree(string scrpt)
	{
		root = parse(string scrpt);
	}

	Node *root;
private:
	/*e.g. scrpt
		<root>value_root
			<node1>value1</node1>
			<node2>value2</node2>
				<node3>value3</node3>
		</root>
	*/
	Node *parse(string scrpt)
	{
		int i = 0;
		int index_lt = 0;
		int index_gt = 0;
		// get name
		for(;scrpt[i] != '<' && scrpt[i] != 0; i++);
		index_lt = i;
		for(;script[i] != '>' && scrpt[i] !=0; i++);
		index_gt = i;

		if(scprt[index_lt] == 0 || scprt[index_gt] ==0)
			cout << "Error, scrpt not valid..." << endl;
		
		string name = script.substr(index_lt+1, index_gt);

		// get value
		for(;scrpt[i] != '<' && scrpt[i] != 0; i++);
		index_lt = i;

		if(scprt[index_lt] == 0 || scprt[index_gt] ==0)
			cout << "Error, scrpt not valid..." << endl;
		
		string value = script.substr(index_gt+1, index_lt);
		
		Node *pNode = new Node(name, value);
		Node *pCurChild = NULL;
		// insert any children
		// i is currently at '<'
		for(; scrpt[i] != '<' && scrpt[i+1] != '/'; i++)
		{
			if(scrpt[i] == '<')
			{
				if(pNode->pChild == NULL)
				{
					pNode->pChild = parse(scrpt.substr(i, scrpt.length);
					pCurChild = pNode->pChild;
				}
				else
				{
					pCurChild->sibling = parse(scrpt.substr(i, 
				}
			}
		}
	}
};
