#pragma once
#include "Node.h"
typedef Node* NodeP;
class AVL
{
public:
	AVL();
	AVL(int val);
	void Insert(int val);
	bool InsertUtility(NodeP head, int val);
	void Delete(int val);
	void DeleteUtility(NodeP head, int val);
	~AVL();
private:
	NodeP root;
};

