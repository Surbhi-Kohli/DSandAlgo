/***
How to sort in particular order?
We can also write our own comparator function and pass it as a third parameter. This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a ,int b)
{
   return a>b;
}
int main() {

    int a[]={1,5,4,3,2,6,8,-1};
    int n=sizeof(a)/sizeof(int);
    sort(a,a+n,compare);//compare here is a reference to the function n not a call
    for(int i=0;i<n;i++)
    {
       cout<<a[i]<<" ";//descending order  sort is obtained now: 8 6 5 4 3 2 1 -1
    }
	return 0;
}
