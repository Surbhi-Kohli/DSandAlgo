#include <iostream>
#include<climits>
#include<vector>
using namespace std;
void downheapify(vector<int> &arr,int i)//it is important to have alias of arr ,so that we work on the 
{	                                 //   same vector sent n don't create a copy of it.
    int left=2*i+1;
    int right=2*i+2;
    int temp=i;
    if(left>=arr.size() && right>=arr.size())
    return;
    
    if(left<arr.size() &&arr[left]>arr[temp])
    temp=left;
    
    if(right<arr.size() && arr[right]>arr[temp])
    temp=right;
    
    if(temp==i)
    return;
    swap(arr[i],arr[temp]);
    downheapify(arr,temp);
}
void deleteNodeOtherThanRoot(vector<int> &arr,int del)//alias of arr
{
   
    for(int i=0;i<arr.size();i++)
    {
    
        if(arr[i]==del)
        {
            arr[i]=INT_MAX;
          
        }
        
    }
     for(int i=arr.size()-1;i>=0;i--)//can start loop from arr.size()/2-1
      downheapify(arr,i);
     
 
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
     for(int i=arr.size()-1;i>=0;i--)//can start loop from arr.size()/2-1
      downheapify(arr,i);
      
     
}
int main() {
	// your code goes here
	int n,del;
	cin>>n;//8 
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    arr.push_back(x); //100 40 20 30 10 25 5 7 
	    
	}
	cin>>del; //20
	 for(int i=arr.size()-1;i>=0;i--)//can start loop from arr.size()/2-1
    downheapify(arr,i);
	deleteNodeOtherThanRoot(arr,del);
	 for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";//100 40 25 30 10 7 5 
	return 0;
}
