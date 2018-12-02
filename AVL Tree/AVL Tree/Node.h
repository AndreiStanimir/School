#pragma once
class Node
{
public:
	Node();
	Node(int val, int balance);
	~Node();
	int val;
	int balance;
	Node* left;
	Node* right;
};

