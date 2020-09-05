#include <iostream>
using namespace std;
class Node
{
	int m_Data;
	Node *m_Left, *m_Right;
	int m_Height;
public:
	Node() :m_Left(nullptr), m_Right(nullptr), m_Height(0) {}
	Node(int data):m_Data(data), m_Left(nullptr), m_Right(nullptr), m_Height(0) {}
	Node *LeftChild() { return m_Left; }
	Node *RightChild() { return m_right; }
	int Height() { return m_Height; }
	void setLeftChild(Node *child) { m_Left = child; }
	void setRightChild(Node *child) { m_Right = child; }
	void setHeight(int height) { m_Height = height; }
};

class AVLTree
{
	Node *m_root;

public:
	AVLTree() :m_root(nullptr) {}
	void insertNode(int value);
	void deleteNode(int value);
	bool searchNode(int value);

private:
	void LeftRotate(Node *currentRoot);
	void RightRotate(Node *currentRoot);
	int max(int a, int b) { return (a > b) ? a : b; }
	int Height(Node *node) { return (node == nullptr) ? 0 : node->Height(); }

};

void AVLTree::LeftRotate(Node *currentRoot)
{
	Node *newRoot = currentRoot->RightChild();
	currentRoot->setRightChild(newRoot->LeftChild());
	newRoot->setLeftChild(currentRoot);
	currentRoot = newRoot;
	currentRoot->setHeight(max(Height(currentRoot->LeftChild()), Height(currentRoot->RightChild())) + 1);
	Node *oldRoot = currentRoot->LeftChild();
	oldRoot->setHeight(max(Height(oldRoot->LeftChild()), Height(oldRoot->RightChild())) + 1);
}

void AVLTree::RightRotate(Node *currentRoot)
{
	Node *newRoot = currentRoot->LeftChild();
	currentRoot->setLeftChild(newRoot->RightChild());
	newRoot->setRightChild(currentRoot);
	currentRoot = newRoot;
	currentRoot->setHeight(max(Height(currentRoot->LeftChild()), Height(currentRoot->RightChild())) + 1);
	Node *oldRoot = currentRoot->RightChild();
	oldRoot->setHeight(max(Height(oldRoot->LeftChild()), Height(oldRoot->RightChild())) + 1);
}

int main()
{
	return 0;
}