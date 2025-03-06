#pragma once

#include <list>
#include <stdexcept>
#include "payload.h"

template<typename T>
class StackList 
{
    private:
        std::list<T> stacklist;

    public:
        bool empty() const
        {
            return stacklist.empty();
        }

        int size() const
        {
            return stacklist.size();
        }

        T& top()
        {
            if (empty())
            {
                throw std::out_of_range("Error! StackList is empty");
            }

            return stacklist.front();
        }


        void push(const T& value)
        {
            stacklist.push_front(value);
        }


        void pop()
        {
            if (empty())
            {
                throw std::out_of_range("Error! StackList is empty");
            }
            
            stacklist.pop_front();
        }
    };
