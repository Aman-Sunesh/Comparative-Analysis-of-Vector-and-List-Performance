#pragma once

#include <vector>
#include <stdexcept>
#include "payload.h"

template<typename T>
class QueueVector
{
    private:
        T* queuevector;
        int front;
        int back;
        int _size;
        int _capacity;

        void resize(int newCapacity)
        {
            T* newVector = new T[newCapacity];

            for (int i = 0; i < _size; i++)
            {
                int index = (front + i) % _capacity;
                newVector[i] = queuevector[index];
            }

            delete[] queuevector;
            queuevector = newVector;
            _capacity = newCapacity;
            front = 0;
            back = _size;
        }

    public:
        QueueVector()
        {
            front = 0;
            back = 0;
            _size = 0;
            _capacity = 4;
            queuevector = new T[_capacity];
        }

        bool empty() const
        {
            return _size == 0;
        }

        int size() const
        {
            return _size;
        }

        int capacity() const
        {
            return _capacity;
        }

        void push(const T& value)
        {
            if (_size == _capacity)
            {
                resize(_capacity * 2);
            }
            
            queuevector[back] = value;
            back = (back + 1) % _capacity;
            _size += 1;
        }


        void pop()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueVector is empty");
            }
            
            front = (front + 1) % _capacity;
            _size--;
        }

        T& front()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueVector is empty");
            }

            return queuelist[front];
        }

        T& back()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueVector is empty");
            }

            return queuelist[back];
        }

        T& operator[](int i) 
        {
            if (i < 0 || i >= _size)
                throw std::out_of_range("Error! QueueVector index out of range");

            int pos = (front + i) % _capacity;

            return queuevector[pos];
        }

        ~QueueVector()
        {
            delete[] queuevector;
        }

};
