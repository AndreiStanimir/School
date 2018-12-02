#include "stdafx.h"
#include "AVL.h"
#include <algorithm>

using namespace std;

AVL::AVL(int val)
{
	root = new Node(val, 0);
}

void AVL::Insert(int val)
{
	NodeP head = root;
	InsertUtility(head, val);
}
bool AVL::InsertUtility(NodeP head, int val)
{
	if (val < head->val)
		if (head->left)
			if (InsertUtility(head->left, val))
				head->balance--;
			else
				return false;
		else {
			head->left = new Node(val, 0);
			return true;
		}
	else if (val > head->val)
		if (head->right)
			if (InsertUtility(head->right, val))
				head->balance++;
			else
				return false;
		else
		{
			head->right = new Node(val, 0);
			return true;
		}
	Echilibreaza(head);
}

void RotatieDreapta(NodeP &nod)
{
	NodeP arboreStang = nod->left;
	nod->left = arboreStang->right;
	arboreStang->right = nod;
	nod->balance = nod->balance + (1 - min(arboreStang->balance, 0));
	arboreStang->balance = arboreStang->balance + (1 + max(nod->balance, 0));
	nod = arboreStang;
}

void RotatieStanga(NodeP &nod)
{
	NodeP t = nod->right;
	nod->right = t->left;
	t->left = nod;
	nod->balance = nod->balance - (1 + max(t->balance, 0));
	t->balance = t->balance - (1 - min(nod->balance, 0));
	nod = t;
}

void RotatieDreaptaStanga(NodeP &nod)
{
	RotatieDreapta(nod->right);
	RotatieStanga(nod);
}

void RotatieStangaDreapta(NodeP &nod)
{
	RotatieStanga(nod->left);
	RotatieDreapta(nod);
}

void Echilibreaza(NodeP &nod)
{
	if (nod->balance == -2)
		if (nod->left->balance == 1)
			RotatieStangaDreapta(nod);
		else
			RotatieDreapta(nod);

	else if (nod->balance == -2)
		if (nod->right->balance == -1)
			RotatieDreaptaStanga(nod);
		else
			RotatieStanga(nod);
}
void AVL::Delete(int val)
{
	NodeP head = root;
	DeleteUtility(head, val);
	Ech
}
void AVL::DeleteUtility(NodeP head, int val)
{

}
void DeleteNode(NodeP nod)
{

}
AVL::~AVL()
{
}
