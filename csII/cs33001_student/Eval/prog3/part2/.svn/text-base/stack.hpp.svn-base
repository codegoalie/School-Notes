/* Stack Implementation
 * Chris Marshall
 * 4.4.2010
 */

#include <cstdlib>
#include <iostream>
#include "node.hpp"

#ifndef _STACK_HPP_
#define _STACK_HPP_

template <typename T>
class Stack
{
  public:
            Stack();
            Stack(T);
           ~Stack();
            Stack(const Stack&);
    void    operator=(Stack);
    void    swap(Stack&);
    T     pop();
    void    push(T);
    bool    is_empty();

    Node<T> *tos;

};


template <typename T>
Stack<T>::Stack()
{
  tos = 0; // defaults tos to NULL pointer
}

template <typename T>
Stack<T>::Stack(T data)
{
  tos = new Node<T>(data); // defaults a stack with one node and passed data
}

template <typename T>
Stack<T>::~Stack()
{
  while(tos != 0) // while the stack is no empty, pop and item
    pop();
}

template <typename T>
Stack<T>::Stack(const Stack &rhs)
{
  tos = 0;
  Node<T> *temp = rhs.tos; // generate a pointer to the top of rhs
  Node<T> *our_temp;
  while(temp != 0) // while there are still items we haven't processed in rhs
  {
    if(tos == 0) // if this is the first item we've added
    {
      our_temp = new Node<T>(temp->data); // create a new node with the data from rhs
      tos = our_temp; // put the new node as the top of stack
    }
    else // if we've added items before
    {
      our_temp->next = new Node<T>(temp->data); // create an ttem off the bottom of the stack
      our_temp = our_temp->next; // move the bottom pointer to the bottom of the stack
    }
    temp = temp->next; // move to the next node in rhs
  }
}

template <typename T>
void Stack<T>::operator=(Stack actual)
{
  this->swap(actual); // swap with actual (copy) then let destructor clean up old this
}

template <typename T>
void Stack<T>::swap(Stack &rhs)
{
  Node<T> *temp = rhs.tos; // basic swap
  rhs.tos = tos;
  tos = temp;
}

template <typename T>
T Stack<T>::pop()
{
  if(tos != 0) // if stack is not empty
  {
    T result = tos->data; // get the data from the top of stack
    Node<T> *temp = tos->next; // make a pointer to the next node in the stack (so we don't lose the stack)
    delete tos; // deallocate the top of stack
    tos = temp; // move tos to the new top of stack
    return result; // return the previously retreived data
  }
  else
  {
    std::cout << "Stack is Empty\n";
    std::exit(1); // if stack is empty, punt
  }
}

template <typename T>
void Stack<T>::push(T data)
{
  Node<T> *temp = new Node<T>(data); // created new node with the passed data
  temp->next = tos; // maked the new node the top of stack
  tos = temp; // moves the tos pointer to the new top of stack
}

#endif
