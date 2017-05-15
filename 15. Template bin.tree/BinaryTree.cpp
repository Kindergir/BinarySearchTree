/*#include "BinaryTree.h"

//добавление элемента
template <typename T>
void BinaryTree<T>::insert_element(T num)
{
	BinaryTree<T>* p = NULL;
	BinaryTree<T>* y = NULL;
	BinaryTree<T>* x = this;
	while (x != NULL)
	{
		y = x;
		if (x->data > num)
			x = x->left;
		else
			x = x->right;
	}

	if (y != NULL)
	{
		if (num < y->data)
			y->left = new (BinaryTree<T>)(num, NULL, NULL, y);
		else
			y->right = new (BinaryTree<T>)(num, NULL, NULL, y);
	}
}


//удаление элемента по ключу
template <typename T>
int BinaryTree <T>::_delete_element(T num)
{
	BinaryTree <T>* child = NULL;
	BinaryTree <T>* sub_tree = NULL;
	BinaryTree <T>* sub_el = NULL;
	BinaryTree <T>* element_del = this->search(num);
	if (element_del == NULL)
		return 0;

	if (element_del->left != NULL && element_del->right != NULL)
	{
		child = element_del->right;
		while (child->left != NULL)
			child = child->left;
		element_del->data = child->data;
		if (child->right != NULL)
		{
			sub_el = child->right;
			if (child->parent->left == child)
				child->parent->left = child->right;
			else
				child->parent->right = child->right;
			child->right->parent = child->parent;
			child->left = child->right = NULL;
		}
		else
		{
			if (child->parent->left == child)
				child->parent->left = NULL;
			else
				child->parent->right = NULL;
		}
		delete child;
		return 1;
	}
	if (element_del->left != NULL)
	{
		child = element_del->left;
		if (element_del->parent != NULL)
		{
			if (element_del->parent->left == element_del)
				element_del->parent->left = child;
			else
				element_del->parent->right = child;
			child->parent = element_del->parent;

			element_del->left = element_del->right = NULL;
			delete element_del;
			return 1;
		}
		else
		{
			element_del->data = child->data;
			element_del->left = child->left;
			if (child->left != NULL)
				child->left->parent = element_del;
			element_del->right = child->right;
			if (child->right != NULL)
				child->right->parent = element_del;
			child->left = child->right = NULL;
			delete child;
			return 1;
		}
	}
	if (element_del->right != NULL)
	{
		child = element_del->right;
		if (element_del->parent != NULL)
		{
			if (element_del->parent->left == element_del)
				element_del->parent->left = child;
			else
				element_del->parent->right = child;
			child->parent = element_del->parent;

			element_del->left = element_del->right = NULL;
			delete element_del;
			return 1;
		}
		else
		{
			element_del->data = child->data;
			element_del->left = child->left;
			if (child->left != NULL)
				child->left->parent = element_del;
			element_del->right = child->right;
			if (child->right != NULL)
				child->right->parent = element_del;
			child->left = child->right = NULL;
			delete child;
			return 1;
		}
	}
	if (element_del->parent != NULL)
	{
		if (element_del->parent->left == element_del)
			element_del->parent->left = NULL;
		else
			element_del->parent->right = NULL;
		delete element_del;
		return 1;
	}
	else
		return -1;
}


//печать всего дерева
template <typename T>
void BinaryTree <T>::print_tree(BinaryTree <T> *p, int level)
{
	if (p)
	{
		print_tree(p->left, level + 1);
		for (int i = 0; i < level; ++i)
			cout << "   ";
		cout << p->data << endl;
		print_tree(p->right, level + 1);
	}
}


//поиск элемента по ключу
template <typename T>
BinaryTree <T>* BinaryTree<T>::search(T num)
{
	BinaryTree<T>* current;
	for (current = this; current != NULL; current = current->data > num ? current->left : current->right)
	{
		if (current->data == num)
			return current;
	}
	return NULL;
}


//поиск максимального элемента
template <typename T>
BinaryTree<T>* BinaryTree<T>::search_max_element()
{
	BinaryTree<T>* node = this;
	while (node->right != NULL)
		node = node->right;
	return node;
}


//поиск мминимального элемента
template <typename T>
BinaryTree<T>* BinaryTree<T>::search_min_element()
{
	BinaryTree<T>* node = this;
	while (node->left != NULL)
		node = node->left;
	return node;
}*/


//конструктор по умолчанию
/*template <class T>
BinaryTree<T>::BinaryTree<T>(BinaryTree<T>* h)
{
	this->data = h->data;
	this->left = h->left;
	this->right = h->right;
	this->parent = h->parent;
}


//деструктор
template <class T>
BinarySearchTree::~BinarySearchTree()
{
	BinaryTree<T> *cur = root, *par;

	do
	{
		if (cur->left != NULL)
		{
			par = cur;
			cur = cur->left;
			par->left = NULL;
		}
		else
		{
			if (cur->right != NULL)
			{
				par = cur;
				cur = cur->right;
				par->right = NULL;
			}
			else
			{
				par = cur->parent;
				delete cur;
				cur = par;
			}
		}
	} while (cur != root);

	delete root;
}*/