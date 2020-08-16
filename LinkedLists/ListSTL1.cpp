/*
STL list is doubly linked list.

Demonstarting functions of linked list:

push_back(g) : Adds a new element ‘g’ at the end of the list.
push_front(g) : Adds a new element ‘g’ at the beginning of the list.
front() : Returns the value of the first element in the list.
back() : Returns the value of the last element in the list.
sort() : Sorts the list in increasing order.
reverse() : Reverses the list.
list::begin() and list::end() in C++ STL: begin() function returns an iterator pointing to the first element of the list
end(): end() function returns an iterator pointing to the theoretical last element which follows the last element.

Output of below program is:
apple -> guava -> mango -> banana -> pineapple -> 
sorted list is 
apple ,banana ,guava ,mango ,pineapple ,

Reversed list is 
pineapple mango guava banana apple 

element popped from front is  mango
element at back of linked list is banana

printing elements using iterators 
kiwi mango guava banana 
*/

#include <iostream>
#include <list>
using namespace std;
int main(){
    
list<int> l{1,3,2,4,10,8,5};


//diff data type
list<string> l2{"apple","guava","mango","banana"};

l2.push_back("pineapple");

for(string s:l2)
{
    cout<<s<<" -> ";
}
cout<<endl;
//ther is a sort function inside list class
l2.sort();
cout<<"sorted list is "<<endl;
for(string s:l2)
{
    cout<<s<<" ,";
}
cout<<endl;

l2.reverse();
cout<<endl<<"Reversed list is "<<endl;
for(string s:l2)
{
    cout<<s<<" ";
}
cout<<endl;
//Poping from front
l2.pop_front();
cout<<endl<<"element popped from front is  ";
cout<<l2.front()<<endl;

l2.push_front("kiwi");
l2.pop_back();
cout<<"element at back of linked list is ";
cout<<l2.back()<<endl;
cout<<endl<<"printing elements using iterators "<<endl;
for(auto it=l2.begin();it!=l2.end();it++)
{
    cout<<(*it)<<" ";
}
cout<<endl;

   return 0;
}
