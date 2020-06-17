/* You are provided a sequence of number. All numbers of that sequence is in increasing order (including 1) 
and whose only prime factors are 2, 3 or 5 (except 1). You need to find the nth number of that sequence.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n.

Constraints
1<=t<=100 1<=n<=10000

Output Format
Print nth number of that sequence.

Sample Input
2
7
10
Sample Output
8
12
Explanation
Sequence : 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, …..

Sample Input 2                  
11
2
3
4
6
8
9
10
150
250
200
5000
Sample Output 2:
2
3
4
6
9
10
12
5832
38880
16200
50837316566580



*/
#include<iostream>
using namespace std;
long long int findNthUgly(long long int n)
{
	long long int ugly[n];
	long long int i2=0,i3=0,i5=0;
long long int nextMultipleOfTwo=2;
long long int nextMultipleOfThree=3;
   long long int nextMultipleOfFive=5;
	ugly[0]=1;
	long int ans;
	for(long long int i=1;i<n;i++)
	{
	 ans=min(min(nextMultipleOfTwo,nextMultipleOfThree),nextMultipleOfFive);
	     ugly[i]=ans;
	   if(ans==nextMultipleOfTwo)
	   {
		   i2++;
		   nextMultipleOfTwo=ugly[i2]*2;
		   
	   }
	   if(ans==nextMultipleOfThree)
	   {
           i3++;
		   nextMultipleOfThree=ugly[i3]*3;
	   }
	  
	   if(ans==nextMultipleOfFive)
	   {
            i5++;
			nextMultipleOfFive=ugly[i5]*5;
	   }
	   
	  
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		cout<<findNthUgly(n)<<endl;
	}
	return 0;
}
