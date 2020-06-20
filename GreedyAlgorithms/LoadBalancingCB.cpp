/*
Given an array A of size n, In a single operation you can subtract one from A[i] and
add it to either A[i-1] (if i>0) or A[i+1] (if i < n-1).
Find the minimum number of operation required to make all the array elements same.
If it is not possible to do , print -1.

Input Format
The First line contains the size of the array N The Second line contains the N number of elements

Constraints
0 < N < 100000

Output Format
Output Number denoting the minimum number of operations required.

Sample Input
8
16 17 15 0 20 1 1 2
Sample Output
23



*/
#include <iostream>
using namespace std;
int main() {
	       int n;
          cin>>n;
	
	    int arr[n];
	    int loadPerProcessor=0;
	    int transfer=0;
	  
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	          cin>>arr[i];
	          sum=sum+arr[i];
	    }
	
	    if(sum%n!=0)
	    {
	        cout<<-1<<endl;
	        
	    }
	   else{
	        loadPerProcessor=sum/n;
	       int diff=0;
	    for(int i=0;i<n;i++)
	    {
	        diff+=arr[i]-loadPerProcessor;
	         int transferForThisBoundary=max(diff,-diff);
	         transfer=max(transfer,transferForThisBoundary);
	        
	    }
	    cout<<transfer<<endl;
	   }
	
	return 0;
}
