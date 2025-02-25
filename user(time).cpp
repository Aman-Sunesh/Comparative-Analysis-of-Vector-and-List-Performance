#include <iostream> 
#include <chrono>     
#include <iomanip> 
#include "myvector.h" 
#include "mylist.h" 

using namespace std;

auto start = high_resolution_clock::now();


// Default function for getCapacity(): Will return a value of zero for capacity for the containers that do not have capacity() function.
inline int getCapacity(const List&) 
{
    return 0;
}

// Overloaded function for vector, which has capacity() function.
inline int getCapacity(const Vector& v) 
{
    return v.capacity();
}

template <class C>
void show(C& v)
{
    int capacity = getCapacity(v);

    cout << "Size/Cap: " << v.size() << '/' << capacity << ": ";
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

template <typename F>
long long measureTime(F func)
{
    auto start = high_resolution_clock::now();
    func();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    return duration
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