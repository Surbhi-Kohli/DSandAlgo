/*
size_t:
size_t is an unsigned integral data type which is defined in various header files such as:
<stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>, <wchar.h>

It’s a type which is used to represent the size of objects in bytes and is therefore used as the return type by the sizeof operator. It is 
guaranteed to be big enough to contain the size of the biggest object the host system can handle. Basically the maximum permissible size is
dependent on the compiler; if the compiler is 32 bit then it is simply a typedef(i.e., alias) for unsigned int but if the compiler is 64 bit
then it would be a typedef for unsigned long long. The size_t data type is never negative.
The hashFunction functor has return type of size_t as we are not sure what will be the size of the key we get from hash function

*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Student{
    
    public:
    string firstName;
    string lastName;
    string rollno;
    
      Student(string f,string l,string no)
      {
        firstName=f;
        lastName=l;
        rollno=no;
      }
      bool operator ==(const Student &s)const{
          cout<<"== operator overloaded"<<endl;
        return rollno==s.rollno;
      }
    
    };
    class HashFn{
        public:
        size_t operator()(const Student &s)const
      {   cout<<"key for "<<s.firstName<<" is  "<<s.firstName.length()+s.lastName.length()<<endl;
          return s.firstName.length()+s.lastName.length();
      }

    };
int main() {
	// your code goes here
	unordered_map<Student,int,HashFn> student_map;
	Student s1("Prateek","Narang","010");
	Student s2("Rahul","Kumar","023");
	Student s3("Prateek","Gupta","030");
	Student s4("Rahul","Kumar","120");
	
	student_map[s1]=100;
	student_map[s2]=120;
	student_map[s3]=11;
	student_map[s4]=45;
	
	//Iterate over all students
	for(auto s:student_map)
	{
	    cout<<s.first.firstName<<" "<<s.first.rollno<<" has marks "<<s.second<<endl;
	}
	
	//Search marks of a student
	cout<<student_map[s4]<<" are markes of searched student";
	return 0;
}
/*
 Output of below code:

key for Prateek is  13
key for Rahul is  10
key for Prateek is  12
key for Rahul is  10
== operator overloaded
Prateek 030 has marks 11
Rahul 120 has marks 45
Rahul 023 has marks 120
Prateek 010 has marks 100
key for Rahul is  10
== operator overloaded
45 are markes of searched student
*/
