/* 
RECURSIVE PROGRAM to generate subarrays  O(n^2)
Approach: We use two pointers start and end to maintain the starting and ending point of the array and follow the steps given below:

Stop if we have reached the end of the array
Increment the end index if start has become greater than end
Print the subarray from index start to end and increment the starting index  */


#include <iostream>
using namespace std;

void subArray(int arr[],int start,int end,int len)
{
    if(end==len)
    {
        return;
    }
    else if(start>end)
    {
        
        subArray(arr,0,end+1,len);
    }
    else{
        cout << "["; 
        for (int i = start; i < end; i++){ 
            cout << arr[i] << ", "; 
        } 
          
        cout << arr[end] << "]" << endl; 
        subArray(arr, start + 1, end,len); 
    }
    
    
}
int main() {
int n;
cin>>n;
int a[1000];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}

subArray(a,0,0,4);
	return 0;
}
