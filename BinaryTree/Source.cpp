//Jay Rosen
//This program utilizes a Binary Search Tree to find a number

#include <iostream>
#include <vector>
using namespace std;

// Node for binary trees items.
class BTreeNode
{
public:
	BTreeNode(double x, BTreeNode *leftp = NULL,
		BTreeNode *rightp = NULL)
	{
		value = x;
		left = leftp;
		right = rightp;
	}
private:
	double value;
	BTreeNode *left, *right;
	friend class BST;  // BST has friend status	
};

// Binary tree class itself
class BST
{
public:

	void display();
	bool search(double x)
	{
		return search(x, tree);
	}
	void insert(double x);
	void inorder(vector<double> & v)
	{
		inorder(v, tree);
	}
	BST()
	{
		tree = NULL;
	}
private:
	bool search(double x, BTreeNode *t);
	void inorder(vector<double>&tlist, BTreeNode *t);
	BTreeNode *tree;


};


//****************************************************
//              BST::search                          *
// Given a value x and a pointer to the root of a    *
// binary search tree, this function returns true    *
// is x is in the tree, and false otherwise.         *
//****************************************************
bool BST::search(double x, BTreeNode *t)
{
	if (t == NULL)
	{
		cout << "  \t was not found in the Binary Tree.   ";
		return false;
	}
	if (t->value == x)
	{
		cout << " \t is located in the Binary Tree.         ";
		return true;
	}
	if (t->value > x) return search(x, t->left);
	else
		return search(x, t->right);
}

//*****************************************
//         BST::display                    *
// User inputs numbers into binary tree,   *
// makes a search query, and sees results  *
//*****************************************
void BST::display()
{
	// Tell user what program does
	// Tell user to enter numbers
	cout << "\a";
	cout << "\n\n\n\t+------------------------------------------------------------+";
	cout << "\n\t|                                                            |";
	cout << "\n\t|       This program allows you to insert numbers            |";
	cout << "\n\t|       into a Binary Search Tree                            |";
	cout << "\n\t|                                                            |";
	cout << "\n\t+------------------------------------------------------------+";
	cout << "\n\t|              Enter 5 Numbers to Continue . . .             |";
	cout << "\n\t+------------------------------------------------------------+\n\t";

	// User input is inserted into binary tree
	for (int k = 1; k <= 5; k++)
	{
		double x;
		cin >> x;
		insert(x);
	}

	// Compute the inorder list from the binary search tree
	vector<double> orderedList;
	orderedList.clear();
	inorder(orderedList);

	// Print values in inorder
	cout << "\n\n\n\t+------------------------------------------------------------+";
	cout << "\n\t|                                                            |";
	cout << "\n\t|        The items in the tree inorder are:                  |";
	cout << "\n\t|                                                            |";
	cout << "\n\t+------------------------------------------------------------+";
	cout << "\n\t\t";
	for (unsigned int k = 0; k < orderedList.size(); k++)
		cout << orderedList[k] << "  \t";

	cout << "\n\t+------------------------------------------------------------+\n\t";


	cout << "\n\n\n\t+------------------------------------------------------------+";
	cout << "\n\t|                                                            |";
	cout << "\n\t|        Enter a value to search:                            |";
	cout << "\n\t|                                                            |";
	cout << "\n\t+------------------------------------------------------------+";
	cout << "\n\t";

	//User input a search value
	double searchValue;
	cin >> searchValue;
	search(searchValue);

	cout << "\b\n\t+------------------------------------------------------------+\n\n\t";

	


}

//*****************************************
//         BST::insert                    *
// Insert x into the binary search tree.  *
// Must be non-recursive.                 *
//*****************************************
void BST::insert(double x)
{
	if (tree == NULL)
	{
		tree = new BTreeNode(x);
		return;
	}

	// Use p  to search for right place to insert
	// p will point to the node that will be the parent
	// of the node being added
	BTreeNode *p = tree;
	while (p != NULL)
	{
		if (x <= p->value)
		{
			// x goes to left of p
			if (p->left == NULL)
			{
				p->left = new BTreeNode(x);
				return;
			}
			else
				p = p->left;
		}
		else
		{
			// x goes to right of p
			if (p->right == NULL)
			{
				p->right = new BTreeNode(x);
				return;
			}
			else
				p = p->right;
		}
	}
}

//********************************************************************
//                 BST::inorder                                      *
// This call to inorder appends all nodes in subtree rooted at t     *
// to the ordered list passed in as parameters.                      *
//********************************************************************
void BST::inorder(vector<double> & orderedList, BTreeNode *t)
{
	if (t == NULL) return;
	inorder(orderedList, t->left);
	orderedList.push_back(t->value);
	inorder(orderedList, t->right);
}

/**************************************************************
*                                                               *
* 							Main		   			            *
*                                                               *
*                                                               *
**************************************************************/

int main()
{

	BST tree1;
	tree1.display();

	system("pause");

	return 0;
}