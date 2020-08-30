/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
 which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Input Format
First Line contains single integer n (total courses) Second Line contains single integer
m (total pairs) Next m lines contain m pairs

Constraints
1<=n<=10000

Output Format
print "Yes" or "No" (without quotes)

Sample Input
2
2
1 0
0 1
Sample Output
No
Explanation
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and
to take course 0 you should also have finished course 1. So it is impossible.

*/
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> adj;
    public:
    void addEdge(T u,T v)
    {
       // cout<<"addEdge"<<u<<" "<<v<<endl;
        adj[u].push_back(v);
        
    }
  void topologicalSortOrCycle(int nodes)
  {
      int *indegree=new int[nodes];
      queue<T> q;
      int count=0;
      for(auto nodePair:adj)
      {
          indegree[nodePair.first]=0;
      }
    //  cout<<"Initialised indegrees to 0"<<endl;
      for(auto nodePair:adj)
      {
          T node=nodePair.first;
          for(auto nbr:nodePair.second)
          {
              indegree[nbr]++;
          }
      }
      
        for(auto nodePair:adj)
      {
          if(indegree[nodePair.first]==1)
          {
              q.push(nodePair.first);
          }
      }
      while(!q.empty())
      {
          T nOne=q.front();
          count++;
          q.pop();
          for(auto nbr:adj[nOne])
          {
              indegree[nbr]--;
              if(indegree[nbr]==0)
              q.push(nbr);
          }
      }
      if(count==nodes)
      cout<<"Yes";
      else
      cout<<"No";
  }
};
int main() {
	// your code goes here
	
	int nodes,edges;
	cin>>nodes;
	cin>>edges;
	int included[nodes]={0};
	Graph <int> g;
	for(int i=0;i<edges;i++)
	{
	    int x,y;
	    cin>>x>>y;
	    included[x]=1;
	    
	    g.addEdge(x,y);
	    
	}
  //for  nodes  dependent on any node,We need to have edge starting n ending at there own self,so that the adj does have thise nodes as a key
	for(int i=0;i<nodes;i++)
	{
	    if(included[i]==0)
	    g.addEdge(i,i);
	}

	g.topologicalSortOrCycle(nodes);
	return 0;
}
