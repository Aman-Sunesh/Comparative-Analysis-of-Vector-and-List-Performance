#include <iostream>
#include <string>
using std::cout;
using std::string;

// Payload class
struct Payload {
    string name;
    Payload() : name("") {}
    Payload(const string& n) : name(n) {}
};

// Vector Class with Iterator
struct Vector {
    int vec_size;
    int vec_capacity;
    Payload *arr;

    Vector() : vec_size(0), vec_capacity(10), arr(new Payload[10]) {}

    void push_back(const Payload& x) {
        if (vec_size == vec_capacity) {
            vec_capacity *= 2;
            Payload* new_arr = new Payload[vec_capacity];
            for (int i = 0; i < vec_size; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[vec_size++] = x;
    }

    void pop_back() {
        if (vec_size > 0) --vec_size;
    }

    Payload& operator[](int i) { return arr[i]; }

    int size() const { return vec_size; }

    int capacity() const { return vec_capacity; }

    bool empty() const { return vec_size == 0; }

    Payload front() const { return arr[0]; }

    Payload back() const { return arr[vec_size - 1]; }

    void print() const {
        for (int i = 0; i < vec_size; ++i) {
            cout << arr[i].name << " ";
        }
    }

    ~Vector() { delete[] arr; }

    // Iterator for Vector
    struct VectorIterator {
        Payload* ptr;
        VectorIterator(Payload* p) : ptr(p) {}
        VectorIterator& operator++() { ++ptr; return *this; }
        bool operator!=(const VectorIterator& other) const { return ptr != other.ptr; }
        Payload& operator*() { return *ptr; }
    };

    VectorIterator begin() { return VectorIterator(arr); }
    VectorIterator end() { return VectorIterator(arr + vec_size); }
};

// List Class with Iterator
struct Node {
    Payload data;
    Node* next;
    Node(const Payload& data) : data(data), next(nullptr) {}
};

struct List {
    Node* head;

    List() : head(nullptr) {}

    void push_front(const Payload& x) {
        Node* new_node = new Node(x);
        new_node->next = head;
        head = new_node;
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty() const { return head == nullptr; }

    Payload front() const { return head ? head->data : Payload(); }

    Payload back() const {
        Node* temp = head;
        while (temp && temp->next) {
            temp = temp->next;
        }
        return temp ? temp->data : Payload();
    }

    int size() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data.name << " ";
            temp = temp->next;
        }
    }

    // Iterator for List
    struct ListIterator {
        Node* ptr;
        ListIterator(Node* p) : ptr(p) {}
        ListIterator& operator++() { if (ptr) ptr = ptr->next; return *this; }
        bool operator!=(const ListIterator& other) const { return ptr != other.ptr; }
        Payload& operator*() { return ptr->data; }
    };

    ListIterator begin() { return ListIterator(head); }
    ListIterator end() { return ListIterator(nullptr); }

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Modify using iterator
template <class C>
void modify_it(C& container) {
    for (auto& element : container) {
        element.name += '!';
    }
}

// Print function
template <class C>
void print(C& container) {
    cout << "print:";
    for (auto& element : container) {
        cout << ' ' << element.name;
    }
    cout << '\n';
}

int main() {
    Vector v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(std::to_string(i));
    }
    modify_it(v);
    print(v);

    List s;
    for (int i = 0; i < 10; ++i) {
        s.push_front(std::to_string(i));
    }
    modify_it(s);
    print(s);

    return 0;
}
