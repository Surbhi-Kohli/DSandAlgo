/*
Given an array, print all subarrays in the array which has sum 0.

Examples:

Input:  arr = [6, 3, -1, -3, 4, -2, 2,
             4, 6, -12, -7]
Output:  
Subarray found from Index 2 to 4
Subarray found from Index 2 to 6          
Subarray found from Index 5 to 6
Subarray found from Index 6 to 9
Subarray found from Index 0 to 10
A simple solution is to consider all subarrays one by one and check if sum of every subarray is equal to 0 or not. 
The complexity of this solution would be O(n^3)
A better approach is to use Hashing.

Do following for each element in the array

1.Maintain sum of elements encountered so far in a variable (say sum).
2.If current sum is 0, we found a subarray starting from index 0 and ending at index current index
3.Check if current sum exists in the hash table or not.
4.If current sum already exists in the hash table then it indicates that this sum was the sum of some sub-array 
elements arr[0]…arr[i] and now the same sum is obtained for the current sub-array arr[0]…arr[j] which means that 
the sum of the sub-array arr[i+1]…arr[j] must be 0.
5.Insert current sum into the hash table

Input:
2
5
1 -4 4 3 -7
9
4 5 -3 1 -3 2 -6 4 11 
Output:
-4 4 
4 3 -7 
5 -3 1 -3 
1 -3 2 
4 5 -3 1 -3 2 -6 
5 -3 1 -3 2 -6 4 
2 -6 4 

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void tellNoOfZeroSumSubarray(int arr[],int n)
{
    int sum=0;
    // create an empty vector of pairs to store 
    // subarray starting and ending index 
    vector <pair<int, int>> out; 
	unordered_map<int,vector<int>> mp;
	for(int i=0;i<n;i++)
	{
	    sum=sum+arr[i];
      // if sum is 0, we found a subarray starting 
      // from index 0 and ending at index i 
	    if(sum==0)
	    {
	        out.push_back(make_pair(0,i));
	    }            
                          //The order of the 2 ifs has to be like first sum==0 if and 
                         //then the 2nd one(coz ,0 also might be occurring more than once)
      // If sum already exists in the map there exists 
      // at-least one subarray ending at index i with 
      // 0 sum 
      if(mp.find(sum)!=mp.end())
      {
          vector<int> vc = mp[sum]; 
           for (auto it = vc.begin(); it != vc.end(); it++) 
                out.push_back(make_pair(*it + 1, i)); 
      }
       // Important - no else 
       mp[sum].push_back(i);
	}
	for(int j=0;j<out.size();j++)
	{
	   for(int i=out[j].first;i<=out[j].second;i++)
	   cout<<arr[i]<<" ";
	   cout<<endl;
	}

	
}
int main() {
	int t,n;
	cin>>t;
  
   while(t--)
   {
	   cin>>n;
	   int arr[n];
	   for(int i=0;i<n;i++)
	   cin>>arr[i];
	   tellNoOfZeroSumSubarray(arr,n);s

   }
	return 0;
}
