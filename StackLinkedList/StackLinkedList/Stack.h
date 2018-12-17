#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

template<class t_Data>
class Stack
{
	struct Node
	{
		t_Data data;
		unique_ptr<Node> nextNode;

		Node (const t_Data &_data)
			: data(_data)
		{}
	};

	unique_ptr<Node> root;
	int count = 0;

public:
	void push(const t_Data &newData) {
		if (!root)
		{
			root = make_unique<Node>(newData);
		}
		else
		{
			unique_ptr<Node> oldRoot = std::move(root);
			root = make_unique<Node>(newData);
			root->nextNode = std::move(oldRoot);
		}

		++count;
	}

	t_Data pop() {

		if (isEmpty())
			throw std::out_of_range("Stack is empty.");

		t_Data itemToPop = root->data;
		unique_ptr<Node> temp = std::move(root->nextNode);
		root = std::move(temp);

		--count;
		return itemToPop;
	}

	bool isEmpty() const {
		return !root;
	}

	int size() const {
		return count;
	}
};
