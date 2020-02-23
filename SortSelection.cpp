#include <iostream>
using namespace std;

int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int small=arr[0];
int pos=0;
for(int i=0;i<6;i++)
{
      small=arr[i];
      pos=i;
      for(int j=i+1;j<6;j++)
      { 
          if(arr[j]<small)
          {
              small=arr[j];
              pos=j;
          }
      }
       swap(arr[i],arr[pos]);
}
for(int i=0;i<6;i++)
cout<<arr[i]<<" ";
	return 0;
}
