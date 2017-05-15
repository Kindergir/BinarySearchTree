#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>


class human
{
public:
	string name;
	int age;

	friend ostream& operator << (ostream& os, const human& dt);

	bool operator == (human& h)
	{
		return name == h.name && age == h.age;
	}

};


ostream& operator << (ostream& os, const human& data)
{
	cout << data.name << ", " << data.age;
	return os;
}


class compareHuman
{
public:
	bool operator () (const human& Left, const human& Right) const
	{
		if (Left.name != Right.name)
			return Left.name < Right.name;
		return Left.age < Right.age;
	}
};


int main()
{
	BinarySearchTree <int> treeInt;

	ifstream fileInp;
	fileInp.open("input.txt");
	
	for (int i = 0; i < 16; ++i)
	{
		int current;
		fileInp >> current;
		treeInt.add_element(current);
	}
	fileInp.close();

	cout << "Tree of integer, created using comparator less (by default): " << endl;
	treeInt.print();

	//работа с компаратором greater
	ifstream fileInp2;
	fileInp2.open("inp2.txt");

	BinarySearchTree <int, greaterCompare<int>> treeIntGreater;

	for (int i = 0; i < 16; ++i)
	{
		int current;
		fileInp2 >> current;
		treeIntGreater.add_element(current);
	}
	fileInp2.close();

	cout << "Tree created using comparator greater: " << endl;
	treeIntGreater.print();

	//дерево с классом human
	ifstream fileInpNuman;
	fileInpNuman.open("inp3.txt");

	BinarySearchTree <human, compareHuman> treeHuman;

	for (int i = 0; i < 6; ++i)
	{
		string currentName;
		int currentAge;
		fileInpNuman >> currentName >> currentAge;
		human currentHuman;
		currentHuman.name = currentName;
		currentHuman.age = currentAge;
		treeHuman.add_element(currentHuman);
	}
	fileInpNuman.close();

	cout << "Tree of human: " << endl;
	treeHuman.print();

	cout << "What do you want to do?" << endl;

	while (true)
	{
		cout << "1 - add some node to the tree.\n"
			"2 - find node by key.\n"
			"3 - delete some node from the tree.\n"
			"4 - find a max element.\n"
			"5 - find a min element.\n"
			"6 - show contents of the tree.\n"
			"7 - exit.\n" << endl;

		int selectedAction, currentAge;
		string currentName;
		human currentHuman;

		cin >> selectedAction;

		if (selectedAction == 7)
			break;

		switch (selectedAction)
		{
		case 1:
			cout << "Enter name: \n";
			cin >> currentName;
			cout << "Enter age: \n";
			cin >> currentAge;
			currentHuman.name = currentName;
			currentHuman.age = currentAge;
			treeHuman += currentHuman;
			cout << "Added!" << endl;
			break;
		case 2:
			cout << "Enter name: \n";
			cin >> currentName;
			cout << "Enter age: \n";
			cin >> currentAge;
			currentHuman.name = currentName;
			currentHuman.age = currentAge;
			if (treeHuman.search_element(currentHuman))
				cout << "Element exists." << endl;
			else
				cout << "Not found." << endl;
			break;
		case 3:
			cout << "Enter name: \n";
			cin >> currentName;
			cout << "Enter age: \n";
			cin >> currentAge;
			currentHuman.name = currentName;
			currentHuman.age = currentAge;
			try
			{
				treeHuman.delete_element(currentHuman);
				cout << "Deleted" << endl;
			}
			catch (NotFoundException)
			{
				cout << "This element does not exist." << endl;
			}
			break;
		case 4:
			try
			{
				currentHuman = treeHuman.max();
				cout << "Max name is: " << currentHuman.name << endl;
			}
			catch (EmptyExeption)
			{
				cout << "Tree is empty.";
			}
			break;
		case 5:
			try
			{
				currentHuman = treeHuman.min();
				cout << "Min name is: " << currentHuman.name << endl;
			}
			catch (EmptyExeption)
			{
				cout << "Tree is empty.";
			}
			break;
		case 6:
			if (treeHuman.is_empty())
				cout << "Tree is empty" << endl;
			else
				treeHuman.print();
			cout << endl;
			break;
		default:
			cout << "Are you slowpoke?" << endl;
			break;
		}
	}

	system("pause");
	
	return 0;
}