/* REVISING QUADRATIC EQUATIONS
Given coefficients of a quadratic equation , you need to print the nature of the roots (real and distinct , real and equal , imaginary).

Input Format:
First contains three coefficients a,b,c from the equation ax^2 + bx + c = 0.

Constraints:
-100 <= a, b, c <= 100

Output Format
Output contains one/two lines.First line contains nature of the roots .The next line contains roots separated by a 
space if they exist. If roots are imaginary do not print the roots.

Sample Input
1 -11 28
Sample Output
Real and Distinct
4 7

*/
#include<iostream>
#include<math.h>
using namespace std;
int main() {
  int a,b,c;
  int d;
  cin>>a>>b>>c;
  d=(b*b)-(4*a*c);
  if(d<0)
  {
    cout<<"imaginary";
  }
 else if(d>0)
  {
    float r1=(float)((-b)+sqrt(d))/(2*a);
    float r2=(float)((-b)-sqrt(d))/(2*a);
    cout<<"Real and Distinct";
    cout<<endl;
    cout<<r2<<" "<<r1;
    }
    else
    {
      float r=(-b)/(float)(2*a);
      cout<<"Real and Equal"<<endl;
      cout<<r<<" "<<r;
    }
	return 0;
}
