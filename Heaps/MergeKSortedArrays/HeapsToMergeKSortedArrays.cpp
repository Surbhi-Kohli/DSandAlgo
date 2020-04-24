/*
The idea is to use Min Heap. This MinHeap based solution has the same time complexity which is O(NK log K).
But for a different and particular sized array, this solution works much better. The process must start
with creating a MinHeap and inserting the first element of all the k arrays. Remove the root element
of Minheap and put it in the output array and insert the next element from the array of removed element.
To get the result the step must continue until there is no element in the MinHeap left.

MinHeap: A Min-Heap is a complete binary tree in which the value in each internal node is 
smaller than or equal to the values in the children of that node. Mapping the elements of a heap 
into an array is trivial: if a node is stored at index k, then its left child is stored at index 2k + 1
and its right child at index 2k + 2.


Given K sorted arrays each with N elements merge them and output the sorted array

Input Format
First line contains 2 space separated integers K and N.
K is number of arrays.
N is number of elements in each array.
Next K lines contain N space separated integers each where ith line denotes the element of ith sorted array.

Constraints
Elements of array <= |10^15|
N <= 10^5
K <= 10

Output Format
Single line consisting of space separated numbers

Sample Input
3 4
1 3 5 7
2 4 6 8
0 9 10 11
Sample Output
0 1 2 3 4 5 6 7 8 9 10 11


*/
// C++ program to merge k sorted arrays of size n each. 
// C++ program to merge k sorted arrays of size n each. 
#include<bits/stdc++.h> 
using namespace std; 
typedef pair<int,pair<int,int>> customPair;

vector<int> mergeKSortedArrays(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<customPair,vector<customPair>,greater<customPair>> pq;
    
    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    while(pq.empty()==false)
    {
        customPair curr=pq.top();
        pq.pop();
        int x=curr.second.first;
        int y = curr.second.second;
        result.push_back(curr.first);
        if(y+1<arr[x].size())
        {
            pq.push({arr[x][y+1],{x,y+1}});
        }
    }
    return result;
}




// Driver program to test above functions 
int main() {
	int n,k;
	cin>>k>>n;
	  vector<vector<int> > arr( k,vector<int> (n)); //creating a 2d vector based on input values of n and k
	//It will be vector with k rows and n cols
	  for(int i=0;i<k;i++)
	  {
		  for(int j=0;j<n;j++)
		  {
			  cin>>arr[i][j];
		  }
	  }
	vector<int> ans=  mergeKSOrtedArrays(arr);
	  for(int i=0;i<n*k;i++)
	  {
		cout<<ans[i]<<" ";
	  }
	  cout<<endl;
	return 0;
}
