#pragma once

#include "List.h"
#include <memory>
#include <iostream>

template<class t_Data>
class LinkedList : public List<t_Data>
{
	struct Node
	{
		t_Data data;
		std::unique_ptr<Node> nextNode;

		Node(const t_Data &_data)
			: data(_data)
		{}
	};

	int sizeCounter = 0;
	std::unique_ptr<Node> root;

public:

	LinkedList() = default;

	void insert(const t_Data &data) override
	{
		++sizeCounter;
		insertDataBeginning(data);
	}
	void remove(const t_Data &data) override
	{
		if (!root)
			return;

		if (root->data == data)
		{
			auto newRoot = std::move(root->nextNode);
			root = std::move(newRoot);
			--sizeCounter;
			return;
		}

		if (!root->nextNode)
		{
			std::cout << data << " is not found in a list";
			return;
		}

		Node *prev = root.get();
		Node *it = root->nextNode.get();

		while (it->data != data)
		{
			prev = it;
			it = it->nextNode.get();
		}

		if (!it)
		{
			std::cout << data << " is not found in a list";
			return;
		}

		std::unique_ptr<Node> temp = std::move(it->nextNode);
		prev->nextNode = std::move(temp);

	}
	void traverseList() const override
	{
		Node *it = root.get();
		while (it)
		{
			std::cout << it->data << ' ';
			it = it->nextNode.get();
		}

		std::cout << '\n';
	}
	int size() const override
	{
		return sizeCounter;
	}

private:

	void insertDataBeginning(const t_Data &data)
	{
		std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
		newNode->nextNode = std::move(root);
		root = std::move(newNode);
	}
};
