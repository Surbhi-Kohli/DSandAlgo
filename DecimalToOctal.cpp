/*
DECIMAL TO OCTAL
Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

Input Format:
Constraints:
0 < N <= 1000000000

Output Format
Sample Input
63
Sample Output
77
*/
#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int rem=0,ans=0,multi=1;
    while(n!=0)
    {
        ans=ans+(n%8)*multi;
        n/=8;
        multi*=10;
    }
    cout<<ans;
	return 0;
}
