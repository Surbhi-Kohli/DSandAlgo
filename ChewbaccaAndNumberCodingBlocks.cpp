/*****
Luke Skywalker gave Chewbacca an integer number x.Chewbacca is not good at numbers but he loves inverting digits in them.
Inverting digit t meanns replacing it with digit 9-t.

Help Chewbacca transform the initial number x to the minimum possible +ve integer integer by inverting some (possibly zero) digits.
The decimal representation of the final number shouldn't start with a zero.
Constraints 1<=x<=10^18
The number entered is in char format.

**/
#include<iostream>
using namespace std;
int main(){
char[50];//size should  be greater than or  equal to 18
cin>>a;
int i=0;
if(a[i]=='9')
{
   i++;
}
for(;a[i]!='\0';i++)
{
    int digit=a[i]-'0';
   if(digit>=5)
   {
     digit=9-digit;
     a[i]=digit+'0';
  }

}
cout<<a<<endl;
return 0;
}
