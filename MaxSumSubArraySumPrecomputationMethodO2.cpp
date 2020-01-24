#include<bits/stdc++.h> 
using namespace std;

int main() {

	int n,left=0,right=0,currSum=INT_MIN,maxSum=INT_MIN;//we do INT_MIN so that if our maxSum is a -ve number ,then its valuee gets updated
	cin>>n;
	int arr[n];
	int cumSum[n+1]={0};
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	cumSum[0]=0;
	cumSum[1]=arr[0];

	for(int j=2;j<=n;j++)
	{
	    cumSum[j]=cumSum[j-1]+arr[j-1];
	}

	currSum=cumSum[1];

	for(int i=1;i<=n;i++)
	{
	    for(int j=i;j<=n;j++)
	    {
	         currSum=cumSum[j]-cumSum[i-1];
	        cout<<"currSum is "<<currSum<<endl;
	        if(currSum>maxSum)//for this condition we hv maxSum as int_min coz if we initialize
	       {               //  it with 0 n hv our currSum(which if it is max possible sum )
	                        // as negative,then maxSum's value does not get correctly updated
	                        //n will remain as zero
	           maxSum=currSum;
	           left=i-1;
	           right=j-1;
	       }
	       
	       
	        
	    }
	}
	cout<<maxSum<<" "<<left<<" "<<right;
	
	return 0;
}
