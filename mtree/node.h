#include <string>
using std::string;

class Node
{
public:
	Node()
	{
		name = "";
		value = "";
		pChild = NULL;
		pSibling = NULL;
	}
	Node(string new_name, string new_value)
	{
		name = new_name;
		value = new_value;
		pChild = NULL;
		pSibling = NULL;
	}
	string name;
	string value;
	Node *pChild;
	Node *pSibling;
};
