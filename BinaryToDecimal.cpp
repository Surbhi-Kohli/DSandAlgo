/*
VON NEUMAN LOVES BINARY
Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 
in binary is 7 in decimal.

Input Format:
The first line contains N , the number of binary numbers. Next N lines contain N integers each
representing binary represenation of number.

Constraints:
N<=1000 Digits in binary representation is <=16.
Output Format
N lines,each containing a decimal equivalent of the binary number.

Sample Input     Sample Output
4                 5 
101               15 
1111               6 
00110             63 
111111
*/
#include<iostream>
#include<math.h>
using namespace std;
int main() {
  int n,num=0,dig,rem,ans=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {ans=0;
    cin>>num;
    dig=1;
    while(num!=0)
    {
      rem=num%10;
      ans=ans+rem*dig;
      num=num/10;
      dig=dig*2;
    }
    cout<<ans<<endl;
  }
	return 0;
}
