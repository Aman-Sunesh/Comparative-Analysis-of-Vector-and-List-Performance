#include <iostream>
#include "mylist.h" 

using namespace std;

int main()
{
    auto showList = [](const List & l)
    {
        cout << "List size: " << l.size() << '\n';
        l.print();
        cout << '\n';
    };

    {
        cout << "=== Testing push_back() ===" << endl;
        List l;
        l.push_back("apple");
        l.push_back("banana");
        l.push_back("cherry");
        showList(l);
        cout << "\n" << endl;
    
        cout << "=== Testing pop_back() ===" << endl;
        l.pop_back();
        showList(l);
        cout << "\n" << endl;

        cout << "=== Popping all Elements ===" << endl;
        l.pop_back();
        l.pop_back();
        cout << "\n" << endl;

        cout << "=== Pushing New Elements ===" << endl;
        l.push_back("kiwi");
        l.push_back("pineapple");
        l.push_back("orange");
        showList(l);
        cout << "\n" << endl;
    
        cout << "=== Testing operator[] ===" << endl;
        cout << "Accessing element at index 2:" << endl;
        l[2].print();
        cout << "\n" << endl;
    
        cout << "Setting element at index 1 to a different value:" << endl;
        l[1] = Payload("mango");
        showList(l);
        cout << "\n" << endl;
    
        cout << "Attempting to set element at index 10:" << endl;
        // This will print an error message because the index is out of bounds
        l[10] = Payload("tomato");
        cout << "\n" << endl;
    }
    
    return 0;
}
