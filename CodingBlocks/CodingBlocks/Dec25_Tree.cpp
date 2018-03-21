#include "stdafx.h"
#include <queue>
//template <T>
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int a)
	{
		data = a;
		left = NULL;
		right = NULL;
	}
};

Node* BuildTree(Node* root)
{
	int d;
	cin >> d;
	cin.ignore();

	if (d == -1)
		return NULL;
	root = new Node(d);

	root->left = BuildTree(root->left);
	root->right = BuildTree(root->right);

	return root;
}


int countNodes(Node * root)
{
	if (root == NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int DetermineHeight(Node* root)
{
	if (root == NULL)
		return 0;

	return 1 + max(DetermineHeight(root->left), DetermineHeight(root->right));
}

int TODO_LevelOrder_Recursively()
{
	return 0;
}

// O(n^2) as each level means repeatedly recursing over the top tree upto the Kth level.
void PrintLevelK(Node* root, int K)
{
	if (K <= 0 || root == NULL)
		return;
	if (K == 1)
	{
		cout << root->data << " ";
	}

	PrintLevelK(root->left, K - 1);
	PrintLevelK(root->right, K - 1);
}

void PrintLevelOrder_Recursive(Node* root)
{
	int height = DetermineHeight(root);
	for (int i = 0; i < height; i++)
		PrintLevelK(root, i);
}

void PrintLevelOrder_UsingQ(Node* root)
{
	queue<Node*> q;
	if (root != NULL)
	{
		q.push(root);
		q.push(NULL);
		while (!q.empty())
		{
			Node* f = q.front();
			if (f == NULL) {
				cout << endl;
				q.pop();
				if (!q.empty())
					q.push(NULL);
			}
			else
			{
				cout << f->data << " ";
				q.pop();

				if (f->left)
					q.push(f->left);
				if (f->right)
					q.push(f->right);
			}
		}
		cout << endl;
	}
}

// TODO from array or interactive input
void BuildLevelOrderTree(int *arr, int n)
{
	int level = 0;
	queue<Node*> q;
	int idx = 0;
	Node* nd = new Node(arr[idx++]);

	q.push(nd);
	level++;
	while (!q.empty())
	{
		int  levelNodeCount = 2 ^ level++;
		for (int i = 0; i < levelNodeCount; i++)
		{

		}
		Node* temp = q.front();
		q.pop();
	}
}

ostream& operator << (ostream& os, Node*root)
{
	PrintLevelOrder_UsingQ(root);
	return os;
}


// O(n^2)
int DetermineDiameterOfATree_Recursive(Node* root)
{
	if (root == NULL)
		return 0;

	int op1 = DetermineHeight(root->left) + DetermineHeight(root->right) ;
	int op2 = DetermineDiameterOfATree_Recursive(root->left);
	int op3 = DetermineDiameterOfATree_Recursive(root->right);

	return max(op1, max(op2, op3)) + 1;
}

pair<int, int> Diameter_BottomUp(Node* root)
{
	// Avoid repeated calls to determine height.
	// Bubbleup pair<height, diameter> from bottom-up, which makes it O(n)
	// Since we are storing pairs at the node level based on kids, do post-order
	pair<int, int> p;
	if (root == NULL)
	{
		p.first = 0;
		p.second = 0;
	}
	else 
	{
		// post order :left, right
		pair<int, int> leftTree = Diameter_BottomUp(root->left);
		pair<int, int> rightTree = Diameter_BottomUp(root->right);

		// now traverse root.
		
		// Build height.
		p.first = max(leftTree.first, rightTree.first) + 1; // height
	
		// Build diameter. 
		int op1 = leftTree.first + rightTree.first;
		int op2 = leftTree.second;
		int op3 = leftTree.second;

		p.second = max(op1, max(op2, op3));
	}
	return p;
}

// HW1 -- works for both post and pre-order
void MirrorTree(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	MirrorTree(root->left);
	MirrorTree(root->right);

	swap(root->left, root->right);
}

bool areIdentical(Node* root1, Node* root2)
{
	if (root1 != NULL && root2 != NULL)
	{
		return (root1->data == root2->data) &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right);
	}
	else if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Exec_Tree()
{

}