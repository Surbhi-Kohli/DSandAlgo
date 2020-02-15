#include <iostream>
#include<iterator>
#include<vector>

using namespace std;

int main() {
	// your code goes here
	vector<int>ar={1,2,3,4,5};
	vector <int>:: iterator ptr;
	//display vector elements using begin() and end()
	cout<<"the vector elements are"<<endl;
	for(ptr=ar.begin();ptr<ar.end();ptr++)
	cout<<*ptr<<" ";
	
	return 0;
}
