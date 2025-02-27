#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "myvector.h"
#include "mylist.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

void dual_print(ostream &out1, ostream &out2, const string &str) {
    out1 << str;
    out2 << str;
}

template <class C>
void show(C& v, ostream &out)
{
    out << "Size/Cap: " << v.size() << '/' << v.capacity() << ": ";
    v.print(out);
    out << '\n'; 
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

template <class Func, class C>
long long test_func_with_size(Func F, C& v, int n, int iterations = 1) 
{
    long long total = 0;
    for (int i = 0; i < iterations; i++) {
        auto start = high_resolution_clock::now();
        F(v, n);
        auto stop = high_resolution_clock::now();
        total += duration_cast<nanoseconds>(stop - start).count();
    }
    return total / iterations;
}

template <class Func, class C>
long long test_func(Func F, C& v, int iterations = 1) 
{
    long long total = 0;
    for (int i = 0; i < iterations; i++) 
    {
        auto start = high_resolution_clock::now();
        F(v);
        auto stop = high_resolution_clock::now();
        total += duration_cast<nanoseconds>(stop - start).count();
    }
    return total / iterations;
}

template <class Container>
void run(const string& type, ostream &out, ostream &consoleOut) 
{
    Container c;
    out << fixed << setprecision(0);
    consoleOut << fixed << setprecision(0);
    int sizes[] = {1, 10, 100, 1000, 10000, 100000}; 
    int iterations = 1;

    out << type << " Testing:\n";
    consoleOut << type << " Testing:\n";
    for (int n : sizes) 
    {
        if (n <= 10)
        {
            iterations = 1000;
        }
        else 
        {
            iterations = 1;
        }
        out << "\nSize " << n << ":\n";
        consoleOut << "\nSize " << n << ":\n";

        {
            Container c;
            out << "Time to fill_back: " << test_func_with_size(fill_back<Container>, c, n, iterations) << " nanoseconds\n";
            consoleOut << "Time to fill_back: " << test_func_with_size(fill_back<Container>, c, n, iterations) << " nanoseconds\n";
            
            out << "Time to fill_front: " << test_func_with_size(fill_front<Container>, c, n, iterations) << " nanoseconds\n";
            consoleOut << "Time to fill_front: " << test_func_with_size(fill_front<Container>, c, n, iterations) << " nanoseconds\n";
        }

        {
            Container c;
            fill_back(c, n);
            out << "Time to remove_back: " << test_func(remove_back<Container>, c, iterations) << " nanoseconds\n";
            consoleOut << "Time to remove_back: " << test_func(remove_back<Container>, c, iterations) << " nanoseconds\n";
        }

        {
            Container c;
            fill_back(c, n);
            out << "Time to remove_front: " << test_func(remove_front<Container>, c, iterations) << " nanoseconds\n";
            consoleOut << "Time to remove_front: " << test_func(remove_front<Container>, c, iterations) << " nanoseconds\n";
        }

        {
            Container c;
            fill_back(c, n);
            out << "Time to modify: " << test_func(modify<Container>, c, iterations) << " nanoseconds\n";
            consoleOut << "Time to modify: " << test_func(modify<Container>, c, iterations) << " nanoseconds\n";
        }

        {
            Container src;
            fill_back(src, n);
            Container dest; 

            auto start = high_resolution_clock::now();
            reverse(src, dest);
            auto stop = high_resolution_clock::now();

            long long reverseTime = duration_cast<nanoseconds>(stop - start).count();
            out << "Time to reverse " << n << " elements: " << reverseTime << " ns\n";
            consoleOut << "Time to reverse " << n << " elements: " << reverseTime << " ns\n";
        }

        {
            Container c;
            fill_back(c, n);
            string search = "z5";

            auto start = high_resolution_clock::now();
            const Payload* found = find_in(c, search);
            auto stop = high_resolution_clock::now();

            long long findTime = duration_cast<nanoseconds>(stop - start).count();
            out << "Time to find an element: " << findTime << " ns\n";
            consoleOut << "Time to find an element: " << findTime << " ns\n";
        }

        out << "\n";
        consoleOut << "\n";
    }
}


int main() 
{ 
    ofstream outfile("time_results1.txt");
    if (!outfile.is_open()) 
    {
        cerr << "Error: could not open time_results1.txt for writing.\n";
        return 1;
    }

    run<Vector>("Vector", outfile, cout);
    run<List>("List", outfile, cout);

    outfile.close();
    return 0;
}
