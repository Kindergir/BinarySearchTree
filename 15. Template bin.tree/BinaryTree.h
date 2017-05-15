#pragma once

#include <iostream>

using namespace std;


template <class T>
class lessCompare
{
public:
	bool operator () (const T& Left, const T& Right) const
	{
		return Left < Right;
	}
};


template <class T>
class greaterCompare
{
public:
	bool operator () (const T& Left, const T& Right) const
	{
		return Left > Right;
	}
};


template <class T, class compare = lessCompare <T>>
class TreeNode
{
private:
	TreeNode <T, compare>* left;
	TreeNode <T, compare>* right;
	TreeNode <T, compare>* parent;
public:
	T data;
	//����� ���������� ��������
	void insert_element(T num);

	//����� �������� �������� �� �����
	int _delete_element(T num);

	//����� ������ �������� �� �����
	TreeNode <T, compare>* search(T num);

	//����� ������ �� �������
	void print();

	//������ ������
	void print_tree(TreeNode <T, compare> *p, int level);

	//����� ������ ������������� ��������
	TreeNode <T, compare>* search_max_element();

	//����� ������ ������������ ��������
	TreeNode <T, compare>* search_min_element();

	//����������� �� ��������� (� main ������������ ��� ��������� ����)
	TreeNode (T data)
		: data(data), left(NULL), right(NULL), parent(NULL) {}

	//����������� � �����������
	TreeNode(T data, TreeNode <T, compare>* left, TreeNode <T, compare>* right, TreeNode <T, compare>* parent)
		: data(data), left(left), right(right), parent(parent) {}

	//����������� �����������
	TreeNode(TreeNode <T, compare>* h);

	//�������� ����� ������
	void free_tree();
};


class NotFoundException {};
class EmptyExeption {};


template <class T, class compare = lessCompare <T>>
class BinarySearchTree
{
private:
	(TreeNode <T, compare>)* root; //��������� �� ������ 
public:
	//����������� �� ���������
	BinarySearchTree()
	{
		root = NULL;
	}

	//����������
	void add_element(T num)
	{
		if (root == NULL)
			root = new TreeNode<T, compare>(num);
		else
			root->insert_element(num);
	}

	//��������
	void delete_element(T num)
	{
		int result = root->_delete_element(num);
		if (result == -1)
			root = NULL;
		if (!result)
			throw NotFoundException();
	}

	//�������� �������� �� �������������
	bool search_element(T num)
	{
		if (root->search(num) == NULL)
			return false;
		else
			return true;
	}

	//������������ �������
	T max()
	{
		TreeNode<T, compare>* a = root->search_max_element();

		if (a != NULL)
			return a->data;
		else
			throw EmptyExeption();
	}

	//����������� �������
	T min()
	{
		TreeNode <T, compare>* a = root->search_min_element();

		if (a != NULL)
			return a->data;
		else
			throw EmptyExeption();
	}

	//������ ����� ������
	void print()
	{
		root->print_tree(root, 1);
	}

	//������ �� ������
	bool is_empty()
	{
		return (root == NULL);
	}

	//���������� +=
	void operator+= (T number)
	{
		add_element(number);
	}

	//���������� -=
	void operator-= (T number)
	{
		delete_element(number);
	}

	//����������
	~BinarySearchTree()
	{
		root->free_tree();
		delete root;
	}
};

//���������� ��������
template <class T, class compare = lessCompare <T>>
void TreeNode <T, compare>::insert_element(T num)
{
	TreeNode<T, compare>* p = NULL;
	TreeNode<T, compare>* y = NULL;
	TreeNode<T, compare>* x = this;
	while (x != NULL)
	{
		y = x;
		if (compare()(num, x->data))
			x = x->left;
		else
			x = x->right;
	}

	if (y != NULL)
	{
		if (compare()(num, y->data))
			y->left = new (TreeNode<T, compare>)(num, NULL, NULL, y);
		else
			y->right = new (TreeNode<T, compare>)(num, NULL, NULL, y);
	}
}


//�������� �������� �� �����
template <class T, class compare = lessCompare <T>>
int TreeNode <T, compare>::_delete_element(T num)
{
	TreeNode <T, compare>* child = NULL;
	TreeNode <T, compare>* sub_tree = NULL;
	TreeNode <T, compare>* sub_el = NULL;
	TreeNode <T, compare>* element_del = this->search(num);
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


//������ ����� ������
template <class T, class compare = lessCompare <T>>
void TreeNode <T, compare>::print_tree(TreeNode <T, compare> *p, int level)
{
	if (p)
	{
		print_tree(p->right, level + 1);
		for (int i = 0; i < level; ++i)
			cout << "   ";
		cout << p->data << endl;
		print_tree(p->left, level + 1);
	}
}


//����� �������� �� �����
template <class T, class compare = lessCompare <T>>
TreeNode <T, compare>* TreeNode <T, compare>::search(T num)
{
	TreeNode <T, compare> *current = this;
	while (current != NULL)
	{
		if (num == current->data)
			return current;
		if (compare()(num, current->data))
			current = current->left;
		else
			current = current->right;
	}
	return NULL;
}


//����� ������������� ��������
template <class T, class compare = lessCompare <T>>
TreeNode <T, compare>* TreeNode <T, compare>::search_max_element()
{
	TreeNode<T, compare>* node = this;
	while (node->right != NULL)
		node = node->right;
	return node;
}


//����� ������������� ��������
template <class T, class compare = lessCompare <T>>
TreeNode <T, compare>* TreeNode <T, compare>::search_min_element()
{
	TreeNode<T, compare>* const node = this;
	TreeNode<T, compare>* newNode = node;
	while (newNode->left != NULL)
		newNode = newNode->left;
	return newNode;
}

//����������� �����������
template <class T, class compare = lessCompare <T>>
TreeNode <T, compare>::TreeNode(TreeNode <T, compare>* h)
{
	this->data = h->data;
	this->left = h->left;
	this->right = h->right;
	this->parent = h->parent;
}


//�������� ����� ������
template <class T, class compare = lessCompare <T>>
void TreeNode <T, compare>::free_tree()
{
	if (this->left)
	{
		left->free_tree();
	}
	if (this->right)
	{
		right->free_tree();
	}
}