// LinkedList.cpp : Defines the exported functions for the DLL application.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

ILinkedList::ILinkedList() : m_count(0)
{

}

/** Returns true  if list is empty, otherwise true */
bool ILinkedList::isEmpty() const
{
	return m_count == 0;
}

Node::Node() : m_value(-1), m_next(nullptr)
{

}
Node::Node(int val) : m_value(val), m_next(nullptr)
{

}
Node::Node(int val, Node * nextNode) : m_value(val), m_next(nextNode)
{

}
void Node::setItem(const int& val)
{
	m_value = val;
}
void Node::setNext(Node* nextNodePtr)
{
	m_next = nextNodePtr;
}
int Node::getItem() const
{
	return m_value;
}
Node * Node::getNext() const
{
	return m_next;
}
Node::~Node()
{
	// Recursively delete the next node if it's present.
	delete m_next;
}

PointerBasedLinkedList::PointerBasedLinkedList() : ILinkedList(), m_head(nullptr)
{

}

/** Adds a value to the LinkedList.  Return true if able to, otherwise false */
bool PointerBasedLinkedList::add(int val)
{
	Node * newNode = new Node(val, nullptr);

	// We should always be able to add a value
	m_count++;

	// If there is no head, make this new entry the head.
	if (m_head == nullptr){
		m_head = newNode;
	}
	else {

		// Loop through all of the elements until we get to the final one
		Node * temp = m_head;
		while (temp->getNext() != nullptr){
			temp = temp->getNext();
		}

		// Create it and set the previous node to point here!
		temp->setNext(newNode);

	}
	// :)
	return true;
}
/** Remove a value to the LinkedList.  Return true if able to, otherwise false.
Will only remove one entry if there are multiple entries with the same value */
bool PointerBasedLinkedList::remove(int val)
{

	// Initialize temporary iteration variable and keep track of the previous
	Node *temp = m_head;
	Node *prev = nullptr;
	bool found = false;

	if (temp == nullptr){
		return false;
	}

	// Search for item
	while (temp != nullptr){
		if (temp->getItem() == val){
			found = true;
			break;
		}

		prev = temp;
		temp = temp->getNext();
	}

	// If we didn't find anything, return false
	if (!found) return false;

	m_count--;

	// If we're removing the first element
	if (temp == m_head){
		// Set the previous element to the head so we can delete without messing up our array
		prev = m_head;

		// Set the head to the following element of the one we're deleting
		m_head = temp->getNext();

		// Free the memory and return
		free(prev);
		return true;
	}

	// If we're just somewhere in the middle or the end, delete the element and link the previous to the next.
	prev->setNext(temp->getNext());

	// Free the memory and return.
	free(temp);
	return true;

}

/** Remove  all elements from LinkedList */
void PointerBasedLinkedList::clear()
{
	m_count = 0;
	Node * next = nullptr;
	Node * temp = m_head;

	// Loop through all elements and free up that memory.
	while (temp != nullptr){
		next = temp->getNext();
		free(temp);
		temp = next;
	}

	m_head = nullptr;
}
PointerBasedLinkedList::~PointerBasedLinkedList()
{
	// Maybe not!
	delete m_head;
}

std::string PointerBasedLinkedList::toString() const
{
	string str = "";
	Node * temp = m_head;

	while (temp != nullptr){
		// Add the number to the string
		str += to_string(temp->getItem());
		
		// If we're not at the end, add a space!
		temp = temp->getNext();
		if (temp != nullptr){
			str += " ";
		}
	}

	return str;
}





ArrayBasedLinkedList::ArrayBasedLinkedList() : ILinkedList()
{
    m_count = 0; // thank you :)
}

bool ArrayBasedLinkedList::add(int val)
{
	// The array is fixed to a static size of ten
	if (m_count >= 10) return false;

	// Add the value and increase the tally
	m_values[m_count++] = val;
	return true;

}
bool ArrayBasedLinkedList::remove(int val)
{
	// Loop through all array elements
	for(int i = 0; i < m_count; i++){

		// If this array element is what we're looking for...
		if (m_values[i] == val){

			// Loop through all numbers from the one we're on to the end
			for(int j = i; j < m_count; j++){
				// Shift all elements by 1 to the left
				m_values[j] = m_values[j+1];
			}

			// Set the last number to 0. This doesn't really matter, just keeps our array pretty.
			m_values[m_count-1] = 0;

			m_count--;
			return true;

		}
    }
	return false;
}
void ArrayBasedLinkedList::clear()
{
	// Loop through the array and set all values to 0
	for(int i = 0; i < m_count; i++){
		m_values[i] = 0;
	}
	// Set the count to 0
	m_count = 0;
}
ArrayBasedLinkedList::~ArrayBasedLinkedList()
{

}

std::string ArrayBasedLinkedList::toString() const
{
	string str = "";
	
	// Loop through the array
	for(int i = 0; i < m_count; i++){

		// Add the current number
		str += to_string(m_values[i]);

		// If we are not on the last iteration, add a space.
		if (i < m_count-1){
			str+=" ";
		}
	}
	return str;
}
