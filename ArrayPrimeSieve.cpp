/* Program to print prime numbers in range 1 to n  in O(NloglogN) time

Input:100
Output:2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 

*/
#include <iostream>
using namespace std;
void prime_sieve(int *p,int n)
{
    p[2]=1;
    p[0]=p[1]=0;
    for(int i=3;i<=n;i+=2)
    {
        p[i]=1;
    }
    for(int i=3;i<=n;i+=2)
    {
        for(int j=i*i;j<=n;j+=i)
        {
            p[j]=0;
        }
    }
}
int main() {
	// your code goes here
   	int n;
	cin>>n;
	int p[n]={0};
	prime_sieve(p,n);
	for(int i=0;i<n;i++)
	{
	    if(p[i]==1)
	    cout<<i<<" ";
	}
	return 0;
}
