/*
Output:
New vector after insertion
1 2 3 10 20 30 4 5 
*/
#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(){
vector<int> ar={1,2,3,4,5};
vector<int> ar1={10,20,30};

//declaring iterator to a vector
vector<int>:: iterator ptr=ar.begin();

//using advance to set position
advance(ptr,3);

//copying 1 vector elements in other usig inserter() 
//inserts ar1 after 3rd position in ar
copy(ar1.begin(),ar1.end(),inserter(ar,ptr));

cout<<"New vector after insertion"<<endl;

for(int &x:ar)
cout<<x<<" ";


return 0;
}
