Given a list of numbers, stop processing input after the cumulative sum of all the input becomes negative.
Input Format:
A list of integers to be processed

Constraints:
All numbers input are integers between -1000 and 1000.
Sample Input      Sample Output
1                    1
2                    2   
88                   88   
-100
49


#include<iostream>
using namespace std;
int main() {
  int n, sum=0;
     while(true)
    { 
      cin>>n;
     sum=sum+n;
     if(sum<0)
     {
       break;
     }
     else
     {
       cout<<n<<endl;
     }
   }
	return 0;
}
