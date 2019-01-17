/**
* @file implement.hpp
* @description Circular Doubly Linked List Implementation
* @course II. Ogretim D Grubu
* @assignment Odev-II
* @date 05.12.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/
#ifndef IMPLEMENT_HPP
#define IMPLEMENT_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <manage.hpp>
#include <stacker.hpp>


struct Node  
{
	int data;
	struct Node* next;
	struct Node* prev;
};
// Circular ?????????
typedef struct Node n;
n *first = NULL, *last = NULL;

class implement
{
public:
implement() // constructor
	{
	/* Set head as NULL. */
	//head = NULL;  
	}

void InsertAtHead(int x); // insert an element to head.
void InsertAtTail(int x);  // insert an element to tail.
void Print(); // to show the Circular Doubly Linked List memory 'forward'.
void ReversePrint(); // to show the Circular Doubly Linked List memory 'backward'.
void ShiftLeft(); // to show the Circular Doubly Linked List memory 'backward'.
void ShiftRight(); // to show the Circular Doubly Linked List memory 'backward'.
void OneNode(); // statements of a specific node.
void AllNodes(); // statements of a all nodes.
};

/* Global Variables */
struct Node* head;
unsigned int val;
unsigned int tmp;
unsigned int imp;
unsigned int num_of_node;

//Creates a new Node and returns pointer to it. 
struct Node* GetNewNode(int x) 
{
	struct Node* newNode
		= (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void implement::InsertAtHead(int x) 
{
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) 
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head; 
	head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void implement::InsertAtTail(int x) 
{
	struct Node* temp = head;
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) 
	{
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void implement::Print() 
{
	struct Node* temp = head;
	while(temp != NULL) 
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void implement::ReversePrint() 
{
	struct Node* temp = head;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) 
	{
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	printf("Reverse: ");
	while(temp != NULL) 
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void implement::ShiftLeft()
{
	head = head->prev;
	system("clear");
}

void implement::ShiftRight()
{
	head = head->next;
	system("clear");
}

void implement::OneNode()
{
	int m_node;
	std::cout << "Dugum Konumu: ";
	std::cin >> m_node;
	// ????

	system("clear");
}

void implement::AllNodes()
{
	// ????
	system("clear");
}

#endif //IMPLEMENT_HPP