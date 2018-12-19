#ifndef NODE1_HPP
#define NODE1_HPP

#include <iostream>

using namespace std;

/*	if we need to change the type of items in the nodes, then
*	we will change only the value_type in the typedef statement.
*	whenever a program needs to refer to the item type, we can use the
*	expression node::value_type
*/

/*	Data - contains the data/value to be stored.
*	Link - contains address of the next node.
*/

class node
{
public:
	typedef double value_type;
	//CONSTRUCTOR
	node(
		const value_type& init_data = value_type(),
		node* init_link = NULL
	)
	{ data_field = init_data; link_field = init_link; }

	// Member functions to set the data and link fields:
	void set_data(const value_type& new_data) { data_field = new_data; }
	void set_link(node* new_link)			  { link_field = new_link; }

	// Constant member function to retrieve the current data:
	value_type data() const { return link_field; }

	// Two slightly different member functions to retrieve the current link:
	const node* link() const { return link_field; }
	node* link()			 { return link_field; }
private:
	value_type data_field;
	node *link_field;
};


#endif //NODE1_HPP