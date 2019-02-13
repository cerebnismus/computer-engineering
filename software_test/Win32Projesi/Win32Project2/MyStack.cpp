
#include "MyStack.h"
#include <sstream>

void MyStack::push(int data) {
	this->_v.push_back(data);
}

int MyStack::pop() {
	int ret = _v.back();
	_v.pop_back();
	return ret;
}

size_t MyStack::size()
{
	return _v.size();
}

std::string MyStack::toString() {
	std::string ret = "";
	std::stringstream sm;
	for (size_t i=0; i < _v.size(); i++) {
		sm << _v[i] << " ";
	}
	return sm.str();
}


