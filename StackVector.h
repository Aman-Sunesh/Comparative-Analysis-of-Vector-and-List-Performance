#pragma once

#include <vector>
#include <stdexcept>
#include "payload.h"

template<typename T>
class StackVector
{
    private:
        std::vector<T> stackvector;

    public:
        bool empty() const
        {
            return stackvector.empty();
        }

        int size() const
        {
            return stackvector.size();
        }

        T& top()
        {
            if (empty())
            {
                throw std::out_of_range("Error! StackVector is empty");
            }

            return stackvector.back();
        }

        void push(const T& value)
        {
            stackvector.push_back(value);
        }


        void pop()
        {
            if (empty())
            {
                throw std::out_of_range("Error! StackVector is empty");
            }
            
            stackvector.pop_back();
        }
};
