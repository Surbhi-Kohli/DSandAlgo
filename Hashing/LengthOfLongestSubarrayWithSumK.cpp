#include <iostream>
#include <unordered_map>
using namespace std;
int checkSubarrayWithSumZero(int arr[],int n,int k)
{
    unordered_map<int,int> prefixSum;
    int sum=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        // if(arr[i]==0 && len==0)
        // len=1;
        if(sum==k)
        len=max(i+1,len);
        if(prefixSum.find(sum-k)!=prefixSum.end())
        { cout<<"if condition "<<sum-k<<"and sum is "<<sum<<endl;
           len=max(len,i-prefixSum[sum-k]);  
        }
       
       else{
           prefixSum[sum]=i;
       } 
        
        
    }
    return len;
    
    
}
int main() {
int n,k;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cin>>k;
cout<<checkSubarrayWithSumZero(arr,n,k);
	return 0;
}
