#pragma once

#include "payload.h"

struct Node
{
    Payload data;
    Node* next;

    Node(const Payload& data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

struct List
{
    Node* head;

    List();
    void push_front(const Payload& x);
    void pop_front();
    void push_back(const Payload& x);
    void pop_back();
    bool empty() const;
    Payload front() const;
    Payload back() const;
    Payload& operator[](int i);
    Payload& operator[](int i) const;
    int size() const;
    int capacity() const;
    void print() const;
    ~List();

    struct ListIterator
    {
        Node* node;

        ListIterator(Node* node)
        {
            this->node = node;
        }

        ListIterator& operator ++()
        {
            if (node != nullptr)
            {
                node = node->next;
            }
            
            return *this;
        }

        bool operator !=(const ListIterator& node2) const
        {
            if (this->node != node2.node)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        Payload& operator *()
        {
            return node->data;
        }
        
    };

    ListIterator begin()
    {
        return ListIterator(head);
    }

    ListIterator end()
    {
        return ListIterator(nullptr);
    }
};