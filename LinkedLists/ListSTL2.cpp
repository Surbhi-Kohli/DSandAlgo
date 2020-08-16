/*

remove() : Removes all the elements from the list, which are equal to given element.
erase() : Removes a single element or a range of elements from the list.
insert() : Inserts new elements in the list before the element at a specified position.
*/


#include <iostream>
#include <list>
using namespace std;
int main(){
    


//diff data type
list<string> l2{"kiwi","mango","guava","banana","guava"};

l2.push_back("orange");
l2.push_back("lemon");


for(string s:l2)
{
    cout<<s<<" -> ";
}


cout<<endl;

//Remove all occurences of a fruit by value
l2.remove("guava");

cout<<"list after removing guava is "<<endl;
for(string s:l2)
{
    cout<<s<<" ,";
}
cout<<endl;
//Direct access of elements in list is not possible
//i.e l2[2] is incorrect
auto it=l2.begin();
it++;
it++;
l2.erase(it);//to erase 2nd element of the linked list
cout<<endl;
cout<<"List after erasing the 3rd element of the linked list"<<endl;
for(string s:l2)
{
    cout<<s<<" ,";
}
cout<<endl;

//Inserting at a particular position
it=l2.begin();
it++;
l2.insert(it,"fruit juice");
cout<<"linked list after inserting fruit juice at element b4 2nd element"<<endl;
for(string s:l2)
{
    cout<<s<<" ,";
}
   return 0;
}
