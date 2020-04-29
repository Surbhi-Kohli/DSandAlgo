/*
You are given a running data stream of n integers. You read all integers from that running data stream and find effective
median of elements read so far in efficient way. All numbers are unique in the datastream. 
Print only the integer part of the median.

Input Format
First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the data stream and next line contains n space separated integers.

Constraints
1 < t < 100
1< n < 10000

Output Format
Print the effective median of running data stream..

Sample Input
1
6
5 15 1 3 2 8
Sample Output
5 10 5 4 3 4
Explanation
Iteration 1 :
Array = {5}
Median = 5

Iteration 2 :
Array = {5,15}
Median = (5+15)/2 = 10

Iteration 3 :
Array = {1,5,15}
Median = 5

Iteration 4 :
Array = {1,3,5,15}
Median = (3+5)/2 = 4

Iteration 5 :
Array = {1,2,3,5,15}
Median = 3

Iteration 6 :
Array = {1,2,3,5,8,15}
Median = (3+5)/2 = 4

*/
#include <iostream>
#include <queue>
using namespace std;

vector<int> medianOfRunningStream(int arr[],int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    maxHeap.push(arr[0]);
     vector<int> median;
    median.push_back(arr[0]);

    int maxTop=0,minTop=0,minSize=0,maxSize=1;
    for(int i=1;i<n;i++)
    {
        if(maxHeap.empty()!=false)
        {
            maxTop=maxHeap.top();
        }
        
        if(minHeap.empty()!=false)
        {
            minTop=minHeap.top();
        }
        if(arr[i]<median.back())
        { 
            maxHeap.push(arr[i]);
            maxSize++;
            if(maxSize-minSize==2)
            {
                int a=maxHeap.top();
                maxHeap.pop();
                maxSize--;
                minHeap.push(a);
                minSize++;
            }
                                                                                                                                                                                  
        }
        else {
            minHeap.push(arr[i]);
            minSize++;
             if(minSize-maxSize==2)
            {
                int a=minHeap.top();
                minHeap.pop();
                minSize--;
                maxHeap.push(a);
                maxSize++;
            }
            
        }
        if(maxSize==minSize)
        {
            median.push_back((maxHeap.top()+minHeap.top())/2);
        }
        else if(maxSize>minSize)
        {
            median.push_back(maxHeap.top());
        }
        else
        median.push_back(minHeap.top());
    }
    return median;
}
int main() {
       int t;
       cin>>t;
       for(int j=0;j<t;j++)
       {
          int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
       vector<int> ans=medianOfRunningStream(arr,n);
        for(int i=0;i<ans.size();i++)
       {
       cout<<ans[i]<<" ";
        }
        cout<<endl; 
       }
      
        return 0;
}
