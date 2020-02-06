/*
Apoorva has created an elevated rooff.She wants to know how much water can she save during rain.Given n non -ve integers 
representing the elevation map where width of every bar is 1.Find the max water that she can save.
Sample Input                         Output
10                                    5
0 2 1 3 0 1 2 1 2 1
Hint:Find left-most n right-most largest number.(Important concept)
 */
 #include<bits/stc++.h>
 using namespace std;
 int main(){
 int n;
 cin>>n;
 int *arr=new int[n];
 for(int i=0;i<n;i++)
 cin>>arr[i];
 int left[n];
 int rigt[n];
 right[n-1]=arr[n-1];
 int rHigh=right[n-1];
 for(int i=n-2;i>=0;i--)
{  rHigh=max(rHigh,arr[i]);
  right[i]=rHigh; 
 }
 int lHigh=arr[0];
 left[0]=arr[0];
 for(int i=1;i<n;i++)
 {
 lHigh=max(lHigh,arr[i]);
 left[i]=
 }
 
