#include <iostream> 
#include "StackVector.h" 
#include "StackList.h" 
#include "QueueVector.h" 
#include "QueueList.h" 
#include "payload.h" 

using std::cout; 

template <class C> void testStack(C && s) 
{ 
    cout<< (s.empty()?"is":"not") << " empty; "; 
    s.push("apple"); 
    s.push("pear"); 
    s.pop(); 
    cout << "size=" << s.size() << " top=" << s.top().name << '\n'; 
} 

template <class C> void testQueue(C && s) 
{ 
    cout<< (s.empty()?"is":"not") << " empty; "; 
    s.push("apple"); 
    s.push("pear"); 
    s.pop(); 
    cout << "size=" << s.size() << " front=" << s.front().name << " back=" << s.back().name << '\n'; 
} 

int main() 
{ 
    testStack(StackList<Payload>()); 
    testStack(StackVector<Payload>()); 
    testQueue(QueueList<Payload>()); 

    QueueVector<Payload> qv; 
    qv.push("banana"); 
    testQueue(qv); 
    cout<<qv[0].name<<'\n'; 

    return 0;
}