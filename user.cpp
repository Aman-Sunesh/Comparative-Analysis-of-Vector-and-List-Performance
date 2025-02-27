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

template <class C>
void print(C& v)
{
    cout << "print: ";
    v.print();
}


template <class Container>
void run(const string& message, int n) {
    cout << message << "\n";
    Container c;
    
    cout << ("\n", c.empty() ? "Yes, it's empty." : "No, it's not empty.") << "\n";
    

    fill_back(c, n);
    show(c);
    
    cout << "\nTesting front() and back() functions:\n";
    cout << "Front element: ";
    c.front().print();
    cout << "\nBack element: ";
    c.back().print();
    cout << "\n";
    
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
    cout << ("\n", c.empty() ? "Yes, it's empty." : "No, it's not empty.") << "\n";

    Container rev;
    reverse(c, rev);
    cout << "\nReversed container:\n";
    show(rev);
    
    string search = "z1";
    const Payload* found = find_in(c, search);
    if (found) 
    {
        cout << "\nFound element with name \"" << search << "\": "; found->print();
        cout << "\n";
    } 
    
    else 
    {
        cout << "\nElement with name \"" << search << "\" not found.\n";
    }

    remove_front(c);
    cout << "\nAfter remove_front:\n";
    show(c);
    cout << "\n";
}

int main() 
{ 
    run<Vector>("Vector", 10); 
    run<List>("List", 10); 

    return 0;
} 