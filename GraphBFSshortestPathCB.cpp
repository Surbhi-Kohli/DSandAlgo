/*
Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node 's' to be the starting position for a BFS.

Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to all the other nodes in the graph. Then print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.

Input Format
The first line contains an integer,q , denoting the number of queries. The subsequent lines describe each query in the following format:

Each line contains N and M, the number of nodes and edges respectively.

The next m lines contains u and v means that there is edge between u and v .

The last line contains 's', the starting node.

Constraints
1 <= q <= 10 2 <= n <= 1000 1 <= m <= (n*(n-1))/2 1 <= u,s,v <= n

Output Format
You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself.

Sample Input
2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output
6 6 -1
-1 6

*/
#include<iostream>
#include<list>
#include<queue>
#include<map>
#include <limits>
using namespace std;
template<typename T> 
class Graph 
{
	map<T,list<T>> adjList;
	public:
   void	addEdge(T u,T v,bool dir=true)
	{
        adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void shortestPath(T s)
	{
      map<T,int> dist;

	 queue<T> q;
	  for(auto i:adjList)
	  {
		  dist[i.first]=-1;
	  }
	  dist[s]=0;
	  
	  q.push(s);
    while(!q.empty())
	{
       T node=q.front();
	//    if(node!=s)
	//   {
	// 	  cout<<dist[node]<<" ";
	//   }

	   q.pop();
	   for(T neighbour:adjList[node])
	   {
		   if(dist[neighbour]==-1)
		   {
			   q.push(neighbour);
			   dist[neighbour]=dist[node]+6;
		   }
	   }
	}
	for(auto i:adjList)
	{
		T node=i.first;
		if(node==s)
		continue;
		cout<<dist[node]<<" ";
	}
	} 

};
int main() {
	int q;
	cin>>q;
	
	int m,n,u,v,s;
	for(int i=0;i<q;i++)
	{
		cin>>n>>m;
		Graph <int> g;
		map<int,bool> connected;
		for(int j=0;j<m;j++)
		{
			cin>>u>>v;
			connected[u]=true;
			connected[v]=true;
           g.addEdge(u,v);
		}
		for(int i=1;i<=n;i++)
		{
			if(connected[i]==false)
			g.addEdge(i,i);
		}

		cin>>s;
		g.shortestPath(s);
		cout<<endl;
	}
	return 0;
}
