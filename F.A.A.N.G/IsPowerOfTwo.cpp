/*
Monu is very weak in maths so kartik bhaiya gave him a simple task to check whether a given number n 
is a power of two.Help Monu and return boolean answer.

Input Format
Input a number n

Constraints
None

Output Format
Return true if n is is a power of two,else return false

Sample Input
218
Sample Output
false
Explanation
None

*/
#include<iostream>
using namespace std;
bool isPowerOfTwo(int n)
{
    int count=0;
    while(n)
    {
        count+=(n&1);
        n=n>>1;
    }
    if(count==1)
    return true;

    return false;

}
int main()
{
    int n;
    cin>>n;
    if(isPowerOfTwo(n))
    cout<<"true";
    else
    cout<<"false";
 return 0;

}
