#pragma once

#include <list>
#include <stdexcept>
#include "payload.h"

template<typename T>
class QueueList
{
    private:
        std::list<T> queuelist;

    public:
        bool empty() const
        {
            return queuelist.empty();
        }

        int size() const
        {
            return queuelist.size();
        }


        void push(const T& value)
        {
            queuelist.push_back(value);
        }


        void pop()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueList is empty");
            }
            
            queuelist.pop_front();
        }

        T& front()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueList is empty");
            }

            return queuelist.front();
        }

        T& back()
        {
            if (empty())
            {
                throw std::out_of_range("Error! QueueList is empty");
            }

            return queuelist.back();
        }
};
