#include "stdafx.h"
#include "Node.h"


Node::Node(int val,int balance)
{
	this->val = val;
	this->balance = balance;
	left = right = nullptr;
}


Node::~Node()
{
}
