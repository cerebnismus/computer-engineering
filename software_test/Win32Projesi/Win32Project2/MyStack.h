#pragma once

#include <vector>

class MyStack
{
	std::vector<int> _v;
public:
	MyStack(void){}
	~MyStack(void){}
	void push(int);
	int pop();
	size_t size();
	std::string toString();
};

