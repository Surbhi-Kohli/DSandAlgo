/*
PRINT SERIES
Take the following as input.

A number (N1)
A number (N2)
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.

Input Format:
Constraints:
0 < N1 < 100 0 < N2 < 100
Sample Input
10 
4
Sample Output
5 
11 
14 
17 
23 
26 
29 
35 
38 
41

*/
#include <iostream>
using namespace std;
int main() {
    int n1,n2;
    cin>>n1;
    cin>>n2;
    int count=0;
    int ans=1;
    int k=1;
    while(count<n1)
    {
       ans =3*k+2;
       k++;
       if(ans%n2==0)
       {
           continue;
       }
       else
       cout<<ans<<endl;
     count++;  
    }
}
