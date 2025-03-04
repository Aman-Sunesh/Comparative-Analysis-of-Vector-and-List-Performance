#include <iostream> 
#include "myvector.h" 
#include "mylist.h" 

using namespace std;

template <class C>
void show(C& v)
{
    cout << "Size/Cap: " << v.size() << '/' << v.capacity() << ": ";
    v.print();
    cout << '\n'; 
}

template <class C>
void fill_back(C& v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v.push_back(Payload("z" + std::to_string(i)));
    }
}

template <class C>
void fill_front(C& v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v.push_front(Payload("z" + std::to_string(i)));
    }
}

template <class C>
void remove_back(C& v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        v.pop_back();
    }
}

template <class C>
void remove_front(C& v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        v.pop_front();
    }
}

template <class C>
void modify(C& v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        string data = v[i].name;

        if (!data.empty()) 
        {  
            v[i].name = data.substr(1);
        }
    }
}

template <class C>
void modify_it(C& v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        string data = (*it).name;

        if (!data.empty())
        {
            (*it).name += '!';
        }
    }
}



template <typename Src, typename Dest>
void reverse(const Src& src, Dest& dest)
{
    int size_ = src.size();

    for (int i = size_ - 1; i >= 0; i--)
    {
        dest.push_back(src[i]);
    }
}


template <typename Container>
const Payload* find_in(const Container& c, string name)
{
    int size_ = c.size();

    for (int i = 0; i < size_; i++)
    {
        if (c[i].name == name)
        {
            return &c[i];
        }
    }

    return nullptr;
}

template <class C> void print(C & v) 
{ 
    cout << "print:"; 

    for ( auto & i : v )  
        cout << ' ' << i.name;
    
    cout << '\n'; 
}

int main() 
{ 
    Vector v; 
    for(int i=0; i<10; i++) 
        v.push_back(std::to_string(i));  
    modify_it(v);
    print(v); 

    List s; 
    for(int i=0; i<10; i++) 
        s.push_front(std::to_string(i));  
    modify_it(s);
    print(s); 
}