/*
You are given n activities (from 0 to n-1) with their start and finish times. Select the maximum number
of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input Format
The first line consists of an integer T, the number of test cases. For each test case, the first line consists
of an integer N, the number of activities. Then the next N lines contain two integers m and n, the start and end time of each activity.

Constraints
1<=t<=50
1<=n<=10000
1<=A[i]<=100

Output Format
For each test case find the maximum number of activities that you can do.
Sample Input
1 
3
10 20
12 15
20 30
Sample Output
2

Below implementation passed all test cases on CB
*/
#include <iostream>
#include <algorithm>
using namespace std;
 bool compare(pair<int,int> p1,pair<int,int> p2)
 {
     if(p1.second<p2.second)
     return true;
     
     return false;
 }
int main() {
int t,n;
cin>>t;

while(t--)
{   cin>>n;
int count=0;
     pair<int,int> arr[n];
   for(int i=0;i<n;i++)
   {  
      int x,y;
      cin>>x>>y;
      arr[i]=make_pair(x,y);
   }
  sort(arr,arr+n,compare);
    count=1;
    int nextStart=arr[0].second;
    for(int i=1;i<n;i++)
    {
        if(arr[i].first>=nextStart)
        {
            nextStart=arr[i].second;
            count++;
        }
    }
    
    cout<<count<<endl;
}


	return 0;
}
