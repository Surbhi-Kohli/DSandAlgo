/*   Take N as input(siz of array) .take N more inputs and store that in an array .Take as input 'targetSum'.
 *  Write a program which prints all pairs of numbers with sum equal to targetSum.
*/
#include <bits/stdc++.h> 
using namespace std;
void targetSum(int arr[],int n,int targetSum)
{
    int left=0;
    int right=n-1;
    sort(arr,arr+n);
    while(left<right)
    {  cout<<arr[left]+arr[right]<<endl;
        if(arr[left]+arr[right]==targetSum)
        {
            cout<<arr[left]<<" + "<<arr[right]<<" = Target Sum of "<<targetSum<<endl;
            left++;
            right--;
        }
        else if(arr[left]+arr[right]<targetSum)
        {
           left++ ;
        }
        else
        {
            right--;
        }
    }
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    
	}
	int sum=0;
	cin>>sum;
	targetSum(arr,n,sum);
	return 0;
}
