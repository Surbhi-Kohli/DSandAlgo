/*
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And
he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of
the given permutation. Help him to find the final permutation.

Input Format
First line contains an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1
Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.

*/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
void unlock(int arr[],int n,int k)
{  int count=0;
   unordered_map<int,int> mp;
   for(int i=0;i<n;i++)
   {
	   mp[arr[i]]=i;
   }	
    if (n <= k) { 
        sort(arr, arr + n, greater<int>()); 
    }
	else{
      for(int i=0;i<n;i++)
      {
	    
	     if(count<k)
	     {   int ithLargest=n-i;
          //if ith largest number is not at its correct position
		      if(mp[ithLargest]!=i)
		     { //swap the ithLargest number with another num that is there at ithLargest number's place
           //also change entry in map
			     int oldPos=mp[ithLargest];
			     mp[ithLargest]=i;
			     mp[arr[i]]=oldPos;
			     swap(arr[i],arr[oldPos]);
			     count++;
		     }
	     }
      }
	}
  
   for(int i=0;i<n;i++)
   {
	   cout<<arr[i]<<" ";
   }
}
int main() {
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	unlock(arr,n,k);
	return 0;
}
