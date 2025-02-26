#include <iostream> 
#include "myvector.h" 
#include "mylist.h" 
#include <chrono>     


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
void print(C& v)
{
    cout << "print: ";
    v.print();
}


template <class Container>
void run(const std::string& message, int n) {
    cout << message << "\n";
    Container c;
    fill_back(c, n);
    show(c);
    modify(c);
    show(c);
    modify(c);
    show(c);
    modify(c);
    show(c);
    remove_back(c);
    show(c);
    fill_front(c, n);
    show(c);
    print(c);
    remove_front(c);
    cout << "\n";
    show(c);
    cout << "\n";
}

int main() 
{ 
    run<Vector>("Vector", 10); 
    run<List>("List", 10); 
} 