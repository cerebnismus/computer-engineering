/**
* @file stacker.hpp
* @description Stack & Linked List Implementation
* @course II. Ogretim D Grubu
* @assignment Odev-II
* @date 05.12.2018
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
*/
#ifndef STACKER_HPP
#define STACKER_HPP

#include <manage.hpp>
#include <implement.hpp>

struct node
{
    int data;
    struct node *next;
};

class stack
{
    struct node *top;
    public:
    stack() // constructor
    {
        /* Set top as NULL. */
        top=NULL;
    }
    void push(int s); // to insert an element
    void pop();  // to delete an element
    void show(); // to show the stack
};

void stack::push(int s)
{
    struct node *ptr;
    ptr=new node;
    ptr->data=s;
    ptr->next=NULL;
    if(top!=NULL) {ptr->next=top;}
    top=ptr;
}

void stack::pop()
{
    struct node *temp;
    if(top==NULL) { std::cout<<"\n [ ERROR ] Yigit bos."; }
    temp=top;
    top=top->next;
    // poped value is temp->data
    delete temp;
}

void stack::show()
{
    struct node *ptr1=top;
    while(ptr1!=NULL)
    {
        std::cout<<ptr1->data<<" ";
        ptr1=ptr1->next;
    }
}

#endif // STACKER_HPP
