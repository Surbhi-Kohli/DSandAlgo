/*
PRINT REVERSE
Take N as input, Calculate it's reverse also Print the reverse.

Input Format:
Constraints:
0 <= N <= 1000000000

Sample Input
123456789
Sample Output
987654321
*/
#include<iostream>
using namespace std;
int main() {
  int n,rem,rev=0;
  cin>>n;
int orig=n;
while(n!=0)
{
  rem=n%10;
  n=n/10;
  rev=rev*10+rem;
  
}
   cout<<rev;
	return 0;
}
