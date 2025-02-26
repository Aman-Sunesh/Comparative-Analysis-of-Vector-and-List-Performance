#include <iostream> 
#include <fstream> 
#include <iomanip>
#include "myvector.h" 
#include "mylist.h" 
#include <chrono>     

using namespace std;
using namespace std::chrono;

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

template <class C>
void print(C& v)
{
    cout << "print: ";
    v.print();
}

template <class Func, class C>
long long test_func_with_size(Func F, C& v, int n, int iterations = 1) {
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
void run(const string& type, ostream &out) {
    Container c;
    out << fixed << setprecision(0);
    int sizes[] = {1, 10, 100, 1000, 10000, 100000}; 
    int iterations = 1;

    out << type << " Testing:\n";
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

        {
            Container c;
            out << "Time to fill_back: " << test_func_with_size(fill_back<Container>, c, n, iterations) << " nanoseconds\n";
            out << "Time to fill_front: " << test_func_with_size(fill_front<Container>, c, n, iterations) << " nanoseconds\n";
        }

        {
            Container c;
            fill_back(c, n);
            out << "Time to remove_back: " << test_func(remove_back<Container>, c, iterations) << " nanoseconds\n";
        }

        {
            Container c;
            fill_back(c, n);
            out << "Time to remove_front: " << test_func(remove_front<Container>, c, iterations) << " nanoseconds\n";
        }

        {
            Container c;
            fill_back(c, n);
            out << "Time to modify: " << test_func(modify<Container>, c, iterations) << " nanoseconds\n";
        }

        out << endl;
    }
}


int main() 
{ 
    ofstream outfile("time_resuflts.txt");

    if (!outfile.is_open()) 
    {
        cerr << "Error: could not open results.txt for writing.\n";
        return 1;
    }

    run<Vector>("Vector", outfile);
    run<List>("List", outfile);

    outfile.close();
    return 0;
} 