#include <iostream>
#include <string>
#include "myvector.h" // Assuming this header defines a Vector container that holds Payload objects.
#include "mylist.h"   // Assuming this header defines a List container that holds Payload objects.

using namespace std;

// a. Filling a container with push_back() with 10 elements
template <class C>
void fill_back(C & container, int n) {
    for (int i = 0; i < n; ++i) {
        // Here we assume that push_back() accepts a std::string and that Payload is constructible from std::string.
        container.push_back("z" + to_string(i));  // Example: "z0", "z1", ...
    }
}

// b. Filling a container with push_front() with 10 elements
template <class C>
void fill_front(C & container, int n) {
    for (int i = 0; i < n; ++i) {
        container.push_front("z" + to_string(i));  // Example: "z0", "z1", ...
    }
}

// c. Removing all elements from the container with pop_back()
template <class C>
void remove_back(C & container) {
    while (container.size() > 0) {
        container.pop_back();
    }
}

// d. Removing all elements from the container with pop_front()
template <class C>
void remove_front(C & container) {
    while (container.size() > 0) {
        container.pop_front();
    }
}

// e. Removing the first character of the name of each element
template <class C>
void modify(C & container) {
    for (int i = 0; i < container.size(); ++i) {
        // Here, container[i] returns a Payload.
        // We assume that Payload has a method data() that returns a reference to the underlying std::string.
        Payload & element = container[i];
        std::string & str = element.name;
        if (!str.empty()) {
            str.erase(0, 1);  // Removing the first character
        }
    }
}

// f. Printing the size followed by all elements in the container without using print()
template <class C>
void print(C & container) {
    cout << "print: ";
    for (int i = 0; i < container.size(); ++i) {
        // Print the underlying string from the Payload.
        cout << container[i].name << " ";
    }
}

// e. Print Size, Capacity, and Container Elements (using container’s own print() method)
template <class C>
void show(C & v)
{
    cout << "Size/Cap: " << v.size() << '/' << v.capacity() << ": ";
    v.print();
    cout << "\n";
}

template <class Container>
void run(const string & message, int n) {
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
    // These calls assume that Vector and List are defined in your headers and store Payload objects.
    run<Vector>("Vector", 10); 
    run<List>("List", 10); 
    return 0;
}
