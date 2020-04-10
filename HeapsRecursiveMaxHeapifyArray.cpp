/*
here we will heapify an array by calling max Heapify.But here we have a recursive implementation of max heapify
*/
#include <iostream>
using namespace std;
void maxHeapify(int arr[],int i,int n)
{
    int left=2*i;
    int right=2*i+1;
    int temp=i;
   
   if(left<n && arr[left]>arr[temp])
     temp=left;
     
     if(right<n&& arr[right]>arr[temp])
     temp=right;
    
    
    if(temp!=i)
    {  swap(arr[i],arr[temp]);
        i=temp;
    maxHeapify(arr,i,n);
        
    }
   
     
}
int main() {
	// your code goes here
	int n;
  cin>>n;  //10
  int arr[n];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];  //4 1 3 2 16 9 10 14 8 7
  }
  for(int i=(n/2)-1;i>=0;i--)
  {
      maxHeapify(arr,i,n);
  }
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" "; //16 14 9 10 8 1 4 2 3 7 
	return 0;
}
