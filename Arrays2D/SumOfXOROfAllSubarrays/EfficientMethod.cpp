/*
Sum of XOR of all subarrays
Given an array containing N positive integers, the task is to find the sum of XOR of all sub-arrays of the array.

Simple solution : A simple solution will be to generate all the sub-arrays and then iterate through them all to find the required XOR values
and then sum them up. The time complexity of this approach will be O(n3).

Better solution : A better solution will be using a prefix array i.e. for every index ‘i’ of the array ‘arr[]’, 
create a prefix array to store the XOR of all the elements from left end of the array ‘arr[]’ up to the ith element of ‘arr[]’.
Creating a prefix array will take a time of O(N).

Now, using this prefix array, we can find the XOR value of any sub-array in O(1) time.
if l is not zero 
    XOR = prefix[r] ^ prefix[l-1]
else 
    XOR = prefix[r].
After this, all we have to do is, to sum up the XOR values of all the sub-arrays.

Since, total number of sub-arrays are of the order (N^2), the time-complexity of this approach will be O(N^2).
*/
#include <iostream>
using namespace std;
void precomputeXor(int arr[],int xorArray[],int n)
{
    xorArray[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        xorArray[i]=xorArray[i-1]^arr[i];
    }
}
int sumOfXOROfSubarray(int arr[],int xorArray[],int n)
{ int sum=0,xorVal=0;
for(int i=0;i<n;i++)
cout<<xorArray[i]<<" ";
cout<<endl;
    for(int i=0;i<n;i++)
    { xorVal=0;
        for(int j=0;j<=i;j++)
        {
            cout<<arr[j]<<" - "<<arr[i]<<endl;
            if(i!=0)
            {
                  xorVal=xorArray[j]^xorArray[i-1];
            }
          
            else
            xorVal=xorArray[j];
            cout<<"xor for this subarray is "<<xorVal<<endl;
            sum=sum+xorVal;
        }
    }
    return sum;
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
	int xorArray[n];
	precomputeXor(arr,xorArray,n);
	cout<<sumOfXOROfSubarray(arr,xorArray,n);
	
	return 0;
}
