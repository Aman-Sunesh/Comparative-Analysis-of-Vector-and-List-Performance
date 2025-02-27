#include <iostream>
#include "mylist.h"

using namespace std;

List::List()
{
    head = nullptr;
}

void List::push_front(const Payload& x)
{
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;
}


void List::pop_front()
{
    if (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::push_back(const Payload& x)
{
    Node* temp = new Node(x);

    if (head == nullptr)
    {
        head = temp;
    }

    else
    {
        Node* current = head;

        while(current->next != nullptr)
        {
            current = current->next;
        }

        current->next = temp;   
    }
}


void List::pop_back()
{
    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }

    else
    {
        Node* current = head;

        while(current->next->next != nullptr)
        {
            current = current->next;
        }
    
        delete(current->next);
        current->next = nullptr;
    }
}

bool List::empty() const
{
    return head == nullptr;
}


Payload List::front() const
{
    if (empty())
    {
        cerr << "Error: List is empty!" << endl;
    }

    return head->data;
}


Payload List::back() const
{
    if (empty())
    {
        cout << "Error: List is empty!" << endl;
        return Payload();
    }

    Node* current = head;

    while (current->next != nullptr) 
    {
        current = current->next;
    }

    return current->data;
}


Payload& List::operator[](int i)
{   
    if (i < 0)
    {
        cerr << "Error! Negative index is not allowed" << endl;
        exit(1);
    }

    Node* current = head;
    int counter = 0;

    while (current != nullptr && counter != i)
    {
        current = current->next;
        counter += 1;
    }

    if (current == nullptr)
    {
        cerr << "Error! Index is out of bounds" << endl;
        exit(1);
    }

    return current->data;
}

Payload& List::operator[](int i) const
{   
    if (i < 0)
    {
        cerr << "Error! Negative index is not allowed" << endl;
        exit(1);
    }

    Node* current = head;
    int counter = 0;

    while (current != nullptr && counter != i)
    {
        current = current->next;
        counter += 1;
    }

    if (current == nullptr)
    {
        cerr << "Error! Index is out of bounds" << endl;
        exit(1);
    }

    return current->data;
}


int List::size() const
{
    Node* current = head;
    int count = 0;

    while (current != nullptr)
    {
        current = current->next;
        count++;
    }

    return count;
}

int List::capacity() const
{
    Node* current = head;
    int count = 0;

    while (current != nullptr)
    {
        current = current->next;
        count++;
    }

    return count;
}

void List::print() const
{
    Node* current = head;

    while (current != nullptr)
    {
        current->data.print();
        current = current->next;
    }
}

List::~List()
{
    while (head != nullptr)
    {
        pop_front();
    }
}