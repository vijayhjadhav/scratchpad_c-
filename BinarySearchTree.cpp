#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class Node
{
	int m_Key;
	shared_ptr<Node> m_Left, m_Right;
public:
	Node(int key, shared_ptr<Node> left, shared_ptr<Node> right)
		:m_Key(key), m_Left(left), m_Right(right) {}
	~Node(){}
	Node& operator=(Node &other);
	int Key() { return m_Key; }
	auto &Left() { return m_Left; }
	auto &Right() { return m_Right; }		
};

Node& Node::operator=(Node &other)
{
	if (this != &other)
	{
		m_Key = other.Key();
		m_Left = other.Left();
		m_Right = other.Right();
	}

	return *this;
}

class BinarySearchTree
{
	shared_ptr<Node> m_root;

public:
	void insertNode(int key);
	shared_ptr<Node> searchNode(int key);
	void printTreeTraversals();

private:
	shared_ptr<Node> insertNode(shared_ptr<Node> currentNode, shared_ptr<Node> newNode);
	shared_ptr<Node> searchNode(shared_ptr<Node> node, int key);
	void InOrderTraversal(shared_ptr<Node> currentNode);
	void PreOrderTraversal(shared_ptr<Node> currentNode);
	void PostOrderTraversal(shared_ptr<Node> currentNode);	
	shared_ptr<Node> getNewNode(int key);
};

shared_ptr<Node> BinarySearchTree::searchNode(int key)
{
	return searchNode(m_root, key);
}

shared_ptr<Node> BinarySearchTree::searchNode(shared_ptr<Node> node, int key)
{
	if(node == nullptr || node->Key() == key)
		return node;
	
	if (key < node->Key())
		return searchNode(node->Left(), key);
	else 
		return searchNode(node->Right(), key);
}

void BinarySearchTree::printTreeTraversals()
{
	cout << "Preorder" << endl;
	PreOrderTraversal(m_root);

	cout << "Inorder" << endl;
	InOrderTraversal(m_root);

	cout << "Postorder" << endl;
	PostOrderTraversal(m_root);
}

void BinarySearchTree::PreOrderTraversal(shared_ptr<Node> node)
{
	if (node != nullptr)
	{
		cout << node->Key() << endl;
		PreOrderTraversal(node->Left());
		PreOrderTraversal(node->Right());
	}
}

void BinarySearchTree::InOrderTraversal(shared_ptr<Node> node)
{
	if (node != nullptr)
	{
		InOrderTraversal(node->Left());
		cout << node->Key() << endl;
		InOrderTraversal(node->Right());
	}
}

void BinarySearchTree::PostOrderTraversal(shared_ptr<Node> node)
{
	if (node != nullptr)
	{
		PostOrderTraversal(node->Left());
		PostOrderTraversal(node->Right());
		cout << node->Key() << endl;
	}
}

shared_ptr<Node> BinarySearchTree::getNewNode(int key)
{
	auto node = make_shared<Node>(key, nullptr, nullptr);
	return node;
}

void BinarySearchTree::insertNode(int key)
{
	auto node = getNewNode(key);
	if (m_root == nullptr)
	{
		m_root = node;
		return;
	}

	insertNode(m_root, node);
}

shared_ptr<Node> BinarySearchTree::insertNode(shared_ptr<Node> currentNode, shared_ptr<Node> newNode)
{
	if (currentNode == nullptr)
		return newNode;

	if (newNode->Key() < currentNode->Key())
		currentNode->Left() = insertNode(currentNode->Left(), newNode);
		
	if (newNode->Key() > currentNode->Key())
		currentNode->Right() = insertNode(currentNode->Right(), newNode);

	return currentNode;
}

int main()
{
	BinarySearchTree obj;
	obj.insertNode(50);
	obj.insertNode(30);
	obj.insertNode(20);
	obj.insertNode(40);
	obj.insertNode(70);
	obj.insertNode(60);
	obj.insertNode(80);
	obj.printTreeTraversals();
	auto node = obj.searchNode(70);
	return 0;
}