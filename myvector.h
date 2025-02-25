#pragma once

#include "payload.h"

struct Vector
{
    int vec_size;  // Tracks the number of elements in the vector
    int vec_capacity;  // Maximum possible number of elements in the vector
    Payload *arr;  // Dynamically allocated array of payloads

    Vector();
    void push_back(const Payload& x);
    void pop_back();
    void push_front(const Payload& x);
    void pop_front();
    Payload& operator[](int i);
    int size() const;
    int capacity() const;
    void print() const;
    ~Vector();

    struct Iterator
    {
        Payload* ptr;

        Iterator(Payload* ptr)
        {
            this->ptr = ptr;
        }

        Iterator& operator ++()
        {
            ++ptr;
            return *this;
        }

        bool operator !=(const Iterator& ptr2)
        {
            if (this->ptr != ptr2.ptr)
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
            return *ptr;
        }
        
    };

    Iterator begin()
    {
        return Iterator(arr);
    }

    Iterator end()
    {
        return Iterator(arr + vec_size);
    }

}; 