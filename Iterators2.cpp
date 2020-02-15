/*    
Output

0
the current position of the iterator after advancing is 4
the position of the new iterator using next() is 4
the position of the new iterator using prev() is 3
the vector elements are
1 2 3 4 5 

*/



#include <iostream>
#include<iterator>
#include<vector>

using namespace std;

int main() {
	// your code goes here
	vector<int>ar={1,2,3,4,5};
	
	//Declaring an iterator to the vector
	vector <int>:: iterator ptr=ar.begin();//ptr points to first index ie 0
	vector<int> :: iterator ftr=ar.end();//ptr points to ar.length(),but our indexes are till 4
	  
	  cout<<*ftr<<endl;
	
	//using advance() to increment iterator position to point to index 4
	advance(ptr,3);//advances by 3
    cout<<"the current position of the iterator after advancing is ";
    cout<<*ptr<<endl;
    
    ptr=ar.begin();
    
    
    //next():the function returns a new iterator that points to the psition that the old pointer 
    //would have pointed to after advancing the position mentioned in the arguments
    auto it=next(ptr,3);// it points to index 4
    cout<<"the position of the new iterator using next() is "<<*it<<endl;
    
    
    //prev():the function returns a new iterator that points to the position that the old pointer 
    //would have pointed too after decrementing the position mentioned in the arguments
    auto it1=prev(ftr,3);
      cout<<"the position of the new iterator using prev() is "<<*it1<<endl;
    
    
    
    
	//display vector elements using begin() and end()
	cout<<"the vector elements are"<<endl;
	for(ptr=ar.begin();ptr<ar.end();ptr++)
	cout<<*ptr<<" ";
	
	return 0;
}
