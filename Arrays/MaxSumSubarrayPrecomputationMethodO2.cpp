#include <iostream>
#include <climits>
using namespace std;
void findMaxSumSubarray(int arr[],int n)
{
    int cumSum[n];
    int left=0,right=0;
    cumSum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        cumSum[i]=cumSum[i-1]+arr[i];
    }
    
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(cumSum[j]-cumSum[i-1]>maxSum)
            {
                maxSum=cumSum[j]-cumSum[i-1];
                left=i;
                right=j;
            }
        }
    }
    cout<<"Max sum is "<<maxSum;
    cout<<" between indexes "<<left<<" and "<<right<<endl;
    
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	findMaxSumSubarray(arr,n);
	return 0;
}
