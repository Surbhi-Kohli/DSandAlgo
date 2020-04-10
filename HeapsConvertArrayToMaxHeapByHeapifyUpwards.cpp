/*
We use maxHeapify in a bottom-up manner to convert an array arr[0...n-1] to a max heap.
The elements in subarray arr[(n/2)....n-1] are all leaves of the tree(without children),so we don't have anythng down 
to compare with.Also they are all 1 element heap to begin with.The procedure maxHeap goes through the remaining nodes
of the tree and max heapifies them. 
*/
#include <iostream>
using namespace std;
void maxHeapify(int arr[],int i,int n)
{
    int left=2*i;
    int right=2*i+1;
    int temp=i;
    while(true)
    {
        left=2*i;
        right=2*i+1;
        
     if(left<n && arr[left]>arr[temp])
     temp=left;
     
     if(right<n&& arr[right]>arr[temp])
     temp=right;
     
     if(temp==i)
     break;
     
     swap(arr[i],arr[temp]);
     i=temp;
    }
     
}
int main() {
	// your code goes here
	int n;
  cin>>n;  //10
  int arr[n];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];//4 1 3 2 16 9 10 14 8 7
  }
  for(int i=(n/2)-1;i>=0;i--)
  {
      maxHeapify(arr,i,n);
  }
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";   //16 14 9 10 8 1 4 2 3 7 
	return 0;
}
