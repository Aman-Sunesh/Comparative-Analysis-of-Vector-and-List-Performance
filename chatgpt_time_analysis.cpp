#include <iostream>
#include <chrono>
#include <string>
#include "myvector.h"  // Assumes this defines a class named Vector.
#include "mylist.h"    // Assumes this defines a class named List.

using namespace std;
using namespace std::chrono;

// Function to fill the container using push_back.
template <class C>
void fill_back(C & container, int n) {
    for (int i = 0; i < n; ++i) {
        container.push_back("z" + to_string(i)); // Assumes push_back accepts a string.
    }
}

// Function to fill the container using push_front.
template <class C>
void fill_front(C & container, int n) {
    for (int i = 0; i < n; ++i) {
        container.push_front("z" + to_string(i));
    }
}

// Function to remove n elements using pop_back.
template <class C>
void remove_back(C & container, int n) {
    for (int i = 0; i < n; ++i) {
        container.pop_back();
    }
}

// Function to remove n elements using pop_front.
template <class C>
void remove_front(C & container, int n) {
    for (int i = 0; i < n; ++i) {
        container.pop_front();
    }
}

// Function to measure the time taken by an operation.
template <class Container>
void measure_time(const string & message, void (*operation)(Container&, int), Container & container, int n) {
    auto start = high_resolution_clock::now();
    operation(container, n);
    auto end = high_resolution_clock::now();
    duration<double> dur = end - start;
    cout << message << ": " << dur.count() << " seconds\n";
}

int main() {
    const int values[] = {10, 100, 1000, 10000, 100000};

    for (int n : values) {
        cout << "\nFor n = " << n << ":\n";
        
        cout << "\nVector Testing:\n";
        // Declare a Vector container (without template parameters).
        Vector vectorContainer;
        measure_time("Fill back", fill_back, vectorContainer, n);
        measure_time("Fill front", fill_front, vectorContainer, n);
        measure_time("Remove back", remove_back, vectorContainer, n);
        measure_time("Remove front", remove_front, vectorContainer, n);
        
        cout << "\nList Testing:\n";
        // Declare a List container.
        List listContainer;
        measure_time("Fill back", fill_back, listContainer, n);
        measure_time("Fill front", fill_front, listContainer, n);
        measure_time("Remove back", remove_back, listContainer, n);
        measure_time("Remove front", remove_front, listContainer, n);
    }

    return 0;
}
