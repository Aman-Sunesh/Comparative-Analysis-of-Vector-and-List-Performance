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
    Payload& operator[](int i);
    int size() const;
    void print() const;
    ~List();
};