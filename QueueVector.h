#pragma once

#include <vector>
#include <stdexcept>
#include "payload.h"

template<typename T>
class QueueVector
{
    private:
        T* queuevector;
        int _front;
        int _back;
        int _size;
        int _capacity;

        void resize(int newCapacity)
        {
            T* newVector = new T[newCapacity];

            for (int i = 0; i < _size; i++)
            {
                int index = (_front + i) % _capacity;
                newVector[i] = queuevector[index];
            }

            delete[] queuevector;
            queuevector = newVector;
            _capacity = newCapacity;
            _front = 0;
            _back = _size;
        }

    public:
        QueueVector()
        {
            _front = 0;
            _back = 0;
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
            
            queuevector[_back] = value;
            _back = (_back + 1) % _capacity;
            _size += 1;
        }


        void pop()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueVector is empty");
            }
            
            _front = (_front + 1) % _capacity;
            _size--;
        }

        T& front()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueVector is empty");
            }

            return queuevector[_front];
        }

        T& back()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueVector is empty");
            }

            int pos = (_back - 1 + _capacity) % _capacity;
            return queuevector[pos];
        }

        T& operator[](int i) 
        {
            if (i < 0 || i >= _size)
                throw std::out_of_range("Error! QueueVector index out of range");

            int pos = (_front + i) % _capacity;

            return queuevector[pos];
        }

        ~QueueVector()
        {
            delete[] queuevector;
        }
};
