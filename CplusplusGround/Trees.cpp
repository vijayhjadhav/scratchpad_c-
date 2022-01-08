#include <iostream>
#include <memory>
using namespace std;

using NODE = shared_ptr<class Node>;
class Node
{
public:
	Node(int idata)
	{
		data = idata;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	Node(const Node& otherNode)
		:data(otherNode.data), leftChild(otherNode.leftChild), rightChild(otherNode.rightChild)
	{
		cout << "Copy Constructor call...." << endl;
	}

	Node& operator=(const Node& otherNode)
	{
		cout << "Assignment operator call...." << endl;
		if (this != &otherNode)
		{
			data = otherNode.data;
			leftChild = otherNode.leftChild;
			rightChild = otherNode.rightChild;
		}

    	return *this;
	}

	int data;
	NODE leftChild;
	NODE rightChild;

};

class binaryTree
{
public:
	binaryTree() :root(nullptr) {}
	void insert(int data);
	bool contains(int data);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();

private:
	void insert(NODE currentNode, NODE newNode);
	bool contains(NODE node, int data);
	void printInOrder(NODE node);
	void printPreOrder(NODE node);
	void printPostOrder(NODE node);

private:
	NODE root;
};

void binaryTree::insert(int data)
{
	NODE newNode = make_shared<Node>(data);
	if (root == nullptr)
	{
		root = newNode;
		return;
	}

	insert(root, newNode);	
}

void binaryTree::insert(NODE currentNode, NODE newNode)
{
	if (newNode->data <= currentNode->data)
	{
		if (currentNode->leftChild == nullptr)
		{
			currentNode->leftChild = newNode;
		}
		else
			insert(currentNode->leftChild, newNode);		
	}
	else
	{
		if (currentNode->rightChild == nullptr)
		{
			currentNode->rightChild = newNode;
		}
		else
			insert(currentNode->rightChild, newNode);
	}
}

bool binaryTree::contains(int data)
{
	return contains(root, data);
}

bool binaryTree::contains(NODE node, int data)
{
	if (node == nullptr)
		return false;

	if (data == node->data)
		return true;

	if (data < node->data && node->leftChild != nullptr)
		return contains(node->leftChild, data);
	
	if (data > node->data && node->rightChild != nullptr)
		return contains(node->rightChild, data);

	return false;
}

void binaryTree::printInOrder(NODE node)
{
	if (node == nullptr)
		return;

	if (node->leftChild != nullptr)
		printInOrder(node->leftChild);

	cout << node->data << "\t";
	
	if (node->rightChild != nullptr)
		printInOrder(node->rightChild);

}

void binaryTree::printInOrder()
{
	printInOrder(root);

	cout << endl;
}

void binaryTree::printPreOrder(NODE node)
{
	if (node == nullptr)
		return;

	cout << node->data << "\t";

	if (node->leftChild != nullptr)
		printPreOrder(node->leftChild);

	if (node->rightChild != nullptr)
		printPreOrder(node->rightChild);
}

void binaryTree::printPreOrder()
{
	printPreOrder(root);

	cout << endl;
}

void binaryTree::printPostOrder(NODE node)
{
	if (node == nullptr)
		return;

    if (node->leftChild != nullptr)
		printPostOrder(node->leftChild);

	if (node->rightChild != nullptr)
		printPostOrder(node->rightChild);

	cout << node->data << "\t";
}

void binaryTree::printPostOrder()
{
	printPostOrder(root);

	cout << endl;
}

int main()
{
	binaryTree BT;

	// 4, 5, 2, 9, 1, 3, 12
	BT.insert(4);
	BT.insert(5);
	BT.insert(2);
	BT.insert(9);
	BT.insert(1);
	BT.insert(3);
	BT.insert(12);

	cout << "Inorder Traversal......" << endl;
	BT.printInOrder();

	cout << "Preorder Traversal......" << endl;
	BT.printPreOrder();

	cout << "Postorder Traversal......" << endl;
	BT.printPostOrder();

	return 0;
}