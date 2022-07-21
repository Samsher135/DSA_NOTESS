//vector:-
//vector is a dynamic array Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted
//i.e when a new element is pushed the vector will double its capacity.

//Time Complexity:-
// Random access – constant O(1)
// Insertion or removal of elements at the end – constant O(1)
// Insertion or removal of elements – linear in the distance to the end of the vector O(N)
// Knowing the size – constant O(1)
// Resizing the vector- Linear O(N)

//vector functions examples:-
#include <bits/stdc++.h>
using namespace std;

void vectors(){
    //insert, erase and find operations
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    v.insert(v.begin()+5,100);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    v.erase(v.begin()+5);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    it=find(v.begin(),v.end(),100);
    if(it!=v.end()){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return;
}

//Output:-
// 0 1 2 3 4 5 6 7 8 9 
// 0 1 2 3 4 100 5 6 7 8 9 
// 0 1 2 3 4 5 6 7 8 9 
// Element not found
 

//Deque:-
//Double ended queue is a container that allows to insert and remove elements from both ends.
//They are similar to vectors, but are more efficient in case of insertion and deletion of elements. 
//Unlike vectors, contiguous storage allocation may not be guaranteed.

//Time Complexity:-
//same as vectors


//List:-
//List is a sequence container which takes constant time in inserting and removing elements.
//List in STL is implemented as Doubly Link List
//random access is not possible we have iterate through the list to the particular element
//element can be inserted or removed from both ends

//Time Complexity:-
//random Insertion or removal of elements – constant O(1)
//random access of element – constant O(n)

//List functions examples:-

void lists()
{
    list <int> LI;
    list <int>::iterator it;
    //inserts elements at end of list
    LI.push_back(4);
    LI.push_back(5);

    //inserts elements at beginning of list
    LI.push_front(3);
    LI.push_front(5);

    //returns reference to first element of list
    it = LI.begin();

    //inserts 1 before first element of list
    LI.insert(it,1);

    cout<<"All elements of List LI are: " <<endl;
    for(it = LI.begin();it!=LI.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //reverse elements of list
    LI.reverse();

    cout<<"All elements of List LI are after reversing: " <<endl;
    for(it = LI.begin();it!=LI.end();it++)
    {
         cout<<*it<<" ";
    }
    cout<<endl;

    //removes all occurences of 5 from list
    LI.remove(5);

    cout<<"Elements after removing all occurence of 5 from List"<<endl;
    for(it = LI.begin();it!=LI.end();it++)
    {
         cout<<*it<<" ";
    }
    cout<<endl;

    //removes last element from list
    LI.pop_back();
    //removes first element from list
    LI.pop_front();
    return;
}

//output:-
// All elements of List LI are: 
// 1 5 3 4 5 
// All elements of List LI are after reversing: 
// 5 4 3 5 1 
// Elements after removing all occurrence of 5  from List
// 4 3 1

//Stack:-
//Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, 
//where a new element is added at one end (top) and an element is removed from that end only.
//random access is not possible we have access the top element and pop for next element.

//only below operations are possible:-
// The functions associated with stack are: 
// empty() – Returns whether the stack is empty – Time Complexity : O(1) 
// size() – Returns the size of the stack – Time Complexity : O(1) 
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
// pop() – Deletes the top most element of the stack – Time Complexity : O(1)

//to print the stack:-
void printStack(stack<int> s){
    stack<int> temp=s;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

//Queue:-
//Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement.
//Elements are inserted at the back (end) and are deleted from the front.
//random access is not possible we have access the front element and pop for next element.

//only below operations are possible:-
// push( ): inserts an element in queue at one end(rear ). Its time complexity is O(1).
// pop( ): deletes an element from another end if queue(front). Its time complexity is O(1).
// front( ): access the element on the front end of queue. Its time complexity is O(1).
// empty( ): checks if the queue is empty or not. Its time complexity is O(1).
// size( ): returns the size of queue. Its time complexity is O(1).

//to print queue:-
void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
    cout << '\n';
}

//priority_queue:-
//priority queue is a container adaptor that store elements in accending order in case of max heap decending order in case of min heap.
//A priority queue is a container that provides constant time extraction of the largest element, at the expense of logarithmic insertion
//random access is not possible we have access the top element and pop for next element.

//only below operations are possible:-
// empty(): Returns true if the priority queue is empty and false if the priority queue has at least one element. Its time complexity is O(1).
// pop(): Removes the largest element from the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
// push(): Inserts a new element in the priority queue. Its time complexity is O(logN) where N is the size of the priority queue.
// size(): Returns the number of element in the priority queue. Its time complexity is O(1).
// top(): Returns a reference to the largest element in the priority queue. Its time complexity is O(1).

//priority queue for min heap:-
//priority_queue<int, vector<int>, greater<int> > pq;

//set:-
//Sets are a type of associative containers in which each element has to be unique because 
//the value of the element identifies it. The values are stored in a specific order. 
//The value of the element cannot be modified once it is added to the set, 
//though it is possible to remove and then add the modified value of that element. Thus, the values are immutable
//The values in a set are unindexed.
//to access the element in set we have to use iterator

// Some Basic Functions Associated with Set: 

// begin() – Returns an iterator to the first element in the set.
// end() – Returns an iterator to the theoretical element that follows the last element in the set.
// size() – Returns the number of elements in the set.
// max_size() – Returns the maximum number of elements that the set can hold.
// empty() – Returns whether the set is empty.
// count(): Returns 1 or 0 if the element is in the set or not respectively. Its time complexity is O(logN) where N is the size of the set.
// The time complexities for doing various operations on sets are –

// Insertion of Elements – O(log N)
// Deletion of Elements – O(log N)

//maps:-
//maps are associative containers that store elements in a mapped fashion. 
//Each element has a key value and a mapped value. No two mapped values can have the same key values.
//The keys are always shorted.

// at( ): Returns a reference to the mapped value of the element identified with key.Its time complexity is O(logN).
// count( ): searches the map for the elements mapped by the given key and returns the number of matches.As map stores each element with unique key, then it will return 1 if match if found otherwise return 0.Its time complexity is O(logN).
// clear( ): clears the map, by removing all the elements from the map and leaving it with its size 0.Its time complexity is O(N).
// begin( ): returns an iterator(explained above) referring to the first element of map.Its time complexity is O(1).
// end( ): returns an iterator referring to the theoretical element(doesn’t point to an element) which follows the last element.Its time complexity is O(1).
// empty( ): checks whether the map is empty or not. It doesn’t modify the map.It returns 1 if the map is empty otherwise returns 0.Its time complexity is O(1).
// erase( ): removes a single element or the range of element from the map.
// find( ): Searches the map for the element with the given key, and returns an iterator to it, if it is present in the map otherwise it returns an iterator to the theoretical element which follows the last element of map.Its time complexity is O(logN).
// insert( ): insert a single element or the range of element in the map.Its time complexity is O(logN), when only element is inserted and O(1) when position is also given.


//Algorithms:-

void algorithms(){
    vector<int> v={1,2,3,4,5,6,8,9,10};

    //binary search:-
    cout << "finding 6 ->" << binary_search(v.begin(), v.end(), 6) << endl;

    //upper_bound and lower_bound
    cout << "upper_bound of 7 ->" << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    cout << "lower_bound of 7 ->" << lower_bound(v.begin(), v.end(), 9) - v.begin() << endl;

    string s="photosysthesis";

    //reverse string:-
    reverse(s.begin(), s.end());
    cout << "reversed string " << s << endl;

    //rotate string:-
    rotate(s.begin(), s.begin()+3, s.end());
    cout << "rotated string " << s << endl;

    return;
}

int main(){
    algorithms();
    return 0;
}

