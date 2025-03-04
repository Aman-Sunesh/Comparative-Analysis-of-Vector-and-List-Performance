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
    Payload& operator[](int i) const;
    int size() const;
    int capacity() const;
    bool empty() const;
    Payload front() const;
    Payload back() const;
    void print() const;
    ~Vector();

    struct VectorIterator
    {
        Payload* ptr;

        VectorIterator(Payload* ptr)
        {
            this->ptr = ptr;
        }

        VectorIterator& operator ++()
        {
            ++ptr;
            return *this;
        }

        bool operator !=(const VectorIterator& ptr2)
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

    VectorIterator begin()
    {
        return VectorIterator(arr);
    }

    VectorIterator end()
    {
        return VectorIterator(arr + vec_size);
    }

}; 