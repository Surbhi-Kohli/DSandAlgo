/*
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination 
or last cell from source or 1st cell. The player has total control over outcome of dice throw and wants 
to find out minimum number of throws required to reach last cell.

Input Format
First line contains integer t as number of test cases. Each test case contains following input. First line 
contains three integers n, l, s which represents the number of cell of board, number of ladders and number 
of snakes. Following l lines contains the description of ladders and next s lines contains description of snakes.

Constraints
1 < t < 20 1< n,l,s < 50

Output Format
For each test case you have to print the number which is equal to the minimum number of dice throws to reach the last cell.
Also tell the path to reach the destination from source.

Sample Input
1
30 4 4
3 22
5 8
11 26
20 29
17 4
19 7
21 9
27 1
Sample Output
3
Explanation
Player start from the first cell. It goes to 1st 3 (then reach at 22) and then 28 and then 30. Total number of dice thrown is 3.

*/
#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;
template<typename T>

class Graph{
	map<T,list<T>> mp;
    map<T,T> parent;
public:
   void addEdge(T u,T v)
   {
          mp[u].push_back(v);
   }
   void bfs(T src,T dest)
   {
      queue<T> q;
	  map<T,int> dist;
	  for(auto node_pair:mp)
	  {
		  T node=node_pair.first;
		  dist[node]=INT_MAX;

	  }
      q.push(src);
	  dist[src]=0;
	  parent[src]=src;
	  while(!q.empty())
	  {
		  T node=q.front();
		  q.pop();
		  for(T nbr:mp[node])
		  {
			  if(dist[nbr]==INT_MAX)
			  {
				  q.push(nbr);
				  dist[nbr]=dist[node]+1;
				  parent[nbr]=node;
			  }
		  }
	  }
	  cout<<dist[dest]<<" is the minimum no. of throws to reach the destination"<<endl;
	  cout<<"The path followed is "<<endl;
	  T temp=dest;
	  while(temp!=src)
	  {
	      cout<<temp<<"->";
	      temp=parent[temp];
	  }
	  cout<<src;
   }


};
int main() {
	int t,n,l,s;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>l>>s;
		int board[n]={0};
	
		for(int j=0;j<l;j++)
		{
           int start,end;
		   cin>>start>>end;
		   board[start]=end-start;
		}
		for(int j=0;j<s;j++)
		{
			int start,end;
			cin>>start>>end;
			board[start]=end-start;
		}
		Graph<int>g;
         for(int u=0;u<n;u++)
		 {
			 for(int dice=1;dice<=6;dice++)
			 {
				 int v=u+dice;
				 v+=board[v];
				 if(v<n)
				 {
					 g.addEdge(u,v);
				 }
			 }
		 }
		 g.addEdge(n-1,n-1);
		 g.bfs(0,n-1);
	}
	return 0;
}
