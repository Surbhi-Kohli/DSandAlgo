/*
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and
Y denoting road between X and Y.

Constraints
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.

Sample Input
5 3
0 1
2 3
0 4
Sample Output
6
Explanation
0 1 4 cannot be reached by 2 hence (2,0) (2,1) (2,4) and also 0 1 4 cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.

Sample Input
1000 1
1 10
Sample Output
499499


*/
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> *arr,bool *mark,int node)
{
if(mark[node])
return 0;
mark[node]=1;
int ans=1;
for(auto it=arr[node].begin();it!=arr[node].end();it++)
ans+=dfs(arr,mark,*it);
return ans;
}
int main() {
// your code goes here
int N,M;
cin>>N>>M;
vector<int> arr[N];
for(int i=0;i<M;i++)
{
int x,y;
cin>>x>>y;
arr[x].push_back(y);
arr[y].push_back(x);
}
vector<int> component;
bool mark[N];
for(int i=0;i<N;i++)
mark[i]=0;
for(int i=0;i<N;i++)
if(!mark[i])
component.push_back(dfs(arr,mark,i));
long long ans=0;
for(int i=0;i<component.size();i++)
for(int j=i+1;j<component.size();j++)
ans+=component[i]*component[j];
cout<<ans;
return 0;
}
