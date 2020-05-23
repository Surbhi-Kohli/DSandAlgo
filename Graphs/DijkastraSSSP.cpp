/*
Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node 'S' represents the starting position 
and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node 'S') to all of the other nodes in the graph.

If a node is unreachable, the distance is assumed as -1.

Input Format
The first line contains T, denoting the number of test cases. First line of each test case has two integers N, M 
denoting the number of nodes in the graph and, denoting the number of edges in the graph.

The next M lines each consist of three space-separated integers x,y,r where x and y denote the two nodes between
which the undirected edge exists, 'r' denotes the length of edge between these corresponding nodes.

The last line has an integer, 'S' denoting the starting position.

Constraints
1 <= N <= 3000 1 <= M <= (N*(N-1))/2 1 <= x,y <= N 1 <= r <= 10^5

Output Format
For each of the T test cases, print a single line consisting N-1 space separated integers denoting the shortest 
distance of N-1 nodes other than from starting position S in increasing order of their labels.

For unreachable nodes, print -1.

Sample Input
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

Sample Output
24 3 15
*/
#include<iostream>
#include<climits>
#include<set>
#include<map>
#include<list>
using namespace std;
class Graph{
    int V;
    map<int,list<pair<int,int>>> adj;
    public:
      Graph(int v)
      {
        V=v;
      }
 
     void addEdge(int x,int y,int wt)
    { 
	    adj[x].push_back(make_pair(y,wt));
	    adj[y].push_back(make_pair(x,wt));
    }
  void dijkastra(int src)
  {
	   map<int,int> dist;//to store shortest distance from the given src
	
	 for(int i=1;i<=V;i++)
	 {
      dist[i]=INT_MAX;
	 }
	 set<pair<int,int>> s;//in the set sorting is done based on 1st part of pair.Set stores values in sorted order
	 dist[src]=0;
	 s.insert(make_pair(0,src));
	 while(!s.empty()){
   
		 auto p=*(s.begin());//s.begin() returns a pointer.* does derefrencing 
		 int node=p.second;
		 int nodeDist=p.first;
		 s.erase(s.begin());
     
		 for(auto childPair:adj[node])
		 {
			  if(nodeDist+childPair.second<dist[childPair.first])//a node gets re-inserted in set only if current parent's wt+current                  {                                                    //   edge<dist[child]
			
			       auto f =s.find(make_pair(dist[childPair.first],childPair.first));
		     	  if(f!=s.end())
			     {
				     s.erase(f);
			      }
             dist[childPair.first]=nodeDist+childPair.second;
			       s.insert(make_pair(dist[childPair.first],childPair.first));
			    }
		  }
	 }
	 for(pair<int,int> d:dist)
	 {
		 if(d.first==src)
		 continue;
		 else if(d.second==INT_MAX)
		 cout<<-1<<" ";
		 else
		 cout<<d.second<<" ";
	 }
  }


};
int main() {
	int t,nodes,edges;
	int x,y,wt,src;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>nodes>>edges;
		Graph g(nodes);
	
		for(int j=0;j<edges;j++)
		{  
		    cin>>x>>y>>wt;
	     	g.addEdge(x,y,wt);
		    
		}
        cin>>src;
	    g.dijkastra(src);
    cout<<endl;
	}
	return 0;
}

