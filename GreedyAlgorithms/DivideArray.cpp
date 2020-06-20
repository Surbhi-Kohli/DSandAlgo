#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{  int max_sum=0;
	int min_sum=0;
		cin>>n;
       int arr[n];
	   for(int i=0;i<n;i++)
	   {
		   cin>>arr[i];
	   }
	   sort(arr,arr+n);
	   int arr2[n/2];
	   int k=0;
	   for(int i=n/2;i<n;i++)
	   {
		   arr2[k++]=arr[i];
	   }
      for(int i=0;i<n/2;i++)
      {
        if(arr[i]>arr2[i])
		{
			max_sum=max_sum+(arr[i]-arr2[i]);
		}
		else
		{
				max_sum=max_sum+(arr2[i]-arr[i]);
		}

      }
	  int k=0;
	  for(int i=1;i<n;i+=2)
	  {
		  arr2[k++]=arr[i];
	  }
	  

	}
	return 0;
}
