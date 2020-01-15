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
        end++;
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
