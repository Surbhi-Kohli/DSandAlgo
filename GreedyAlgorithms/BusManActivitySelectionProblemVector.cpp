/*
You are given n activities (from 0 to n-1) with their start and finish times. Select the maximum number 
of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Input Format
The first line consists of an integer T, the number of test cases. For each test case, the first line consists
of an integer N, the number of activities. Then the next N lines contain two integers m and n, the start and end 
time of each activity.

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

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 bool compare(pair<int,int> p1,pair<int,int> p2)
 {
     if(p1.second<p2.second)
     return true;
     
     return false;
 }
int main() {
	vector <pair<int,int>> v;
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
      v.push_back(make_pair(x,y));
   }
  sort(v.begin(),v.end(),compare);
    count=1;
    int nextStart=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>=nextStart)
        {
            nextStart=v[i].second;
            count++;
        }
    }
    
    cout<<count<<endl;
	//for each test case ,we will clear the vector for next test case
	v.clear();
}


	return 0;
}
