/* 
Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we use a boolean visited array.


*/
#include <iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> adjList;
  public:
  void addEdge(T u,T v,bool bidir=true)
  {
      
      adjList[u].push_back(v);
      if(bidir==true)
      {
          adjList[v].push_back(u);
      }
  }
  void dfsHelper(T src,map<T,bool> &visited)
  {
      visited[src]=true;
      cout<<src<<" ";
      for(auto i:adjList[src])
       {
           if(!visited[i])          
           {
               dfsHelper(i,visited);
           }
       }
      
  }
  void dfs(T src)
  {
      map<T,bool> visited;
      dfsHelper(src,visited);
  }
    
  
  
    
};

int main() {
	// your code goes here
	Graph <int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(5,3);
	g.addEdge(2,3);
	g.dfs(0);
	return 0;
}
