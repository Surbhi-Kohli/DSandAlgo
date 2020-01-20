#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[1000];
	int maxSum=0;
	int currSum=0;
	int left=-1,right=-1;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
	    for(int j=i;j<n;j++)
	    {
	        currSum=0;
	        for(int k=i;k<=j;k++)
	        {
	            currSum+=a[k];
	        }
	       
	        if(currSum>maxSum)
	        {
	            maxSum=currSum;
	            left=i;
	            right=j;
	        }
	    }
	}
	cout<<"Max sum is "<<maxSum<<"left is"<<left<<" and right is "<<right<<endl;
	return 0;
}
