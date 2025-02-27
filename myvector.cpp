#include <iostream>
#include "myvector.h"

using namespace std;

Vector::Vector()
{
    vec_size = 0;
    vec_capacity = 1;
    arr = new Payload[vec_capacity];
}

void Vector::push_back(const Payload& x)
{
    if (vec_size == vec_capacity)
    {
        int new_capacity = vec_capacity * 2;
        Payload* new_arr = new Payload[new_capacity];

        for (int i = 0; i < vec_size; i++)
        {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        
        arr = new_arr;
        vec_capacity = new_capacity;
    }

    arr[vec_size] = x;
    vec_size = vec_size + 1;
}

void Vector::pop_back()
{
    if (vec_size == 0)
    {
        cout << "Error: Vector is already empty!" << endl;
    }

    else
    {
        vec_size = vec_size - 1;
    }
}

void Vector::push_front(const Payload& x)
{
    if (vec_size == vec_capacity)
    {
        vec_capacity *=2;
    }

    Payload* new_arr = new Payload[vec_capacity];

    for (int i = 0; i < vec_size; i++)
    {
        new_arr[i + 1] = arr[i];
    }

    delete[] arr;
    
    arr = new_arr;
    arr[0] = x;
    vec_size = vec_size + 1;
}


void Vector::pop_front()
{
    if (vec_size == 0)
    {
        cout << "Error: Vector is already empty!" << endl;
    }

    else
    {
        for (int i = 1; i < vec_size; i++)
        {
            arr[i-1] = arr[i];
        }

        vec_size = vec_size - 1;
    }
}

bool Vector::empty() const
{
    return vec_size == 0;
}


Payload Vector::front() const
{
    if (empty())
    {
        cout << "Error: Vector is empty!" << endl;
        return Payload();
    }

    return arr[0];
}


Payload Vector::back() const
{
    if (empty())
    {
        cout << "Error: Vector is empty!" << endl;
        return Payload();
    }
    return arr[vec_size - 1];
}

Payload& Vector::operator[](int i)
{
    if (i < 0 || i >= vec_size)
    {
        cout << "Error: Index out of range\n";
    }
    
    return arr[i];
}

Payload& Vector::operator[](int i) const
{
    if (i < 0 || i >= vec_size)
    {
        cout << "Error: Index out of range\n";
    }
    
    return arr[i];
}

int Vector::size() const
{
    return vec_size;
}

int Vector::capacity() const
{
    return vec_capacity;
}


void Vector::print() const
{
    for (int i = 0; i < vec_size; i++)
    {
        arr[i].print();
    }
}


Vector::~Vector()
{
    delete[] arr;
}