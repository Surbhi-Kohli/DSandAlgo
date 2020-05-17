/*
Detect cycle in an undirected graph using BFS
Given an undirected graph, how to check if there is a cycle in the graph? For example, 
the following graph has a cycle 1-0-2-1.
We do a BFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’
such that u is already visited and u is not parent of v, then there is a cycle in graph. If we don’t 
find such an adjacent for any vertex, we say that there is no cycle. The assumption of this approach is 
that there are no parallel edges between any two vertices.
We use a parent array to keep track of parent vertex for a vertex so that we do not consider visited parent as cycle.

Time Complexity: The program does a simple BFS Traversal of graph and graph is represented using adjacency list.
    So the time complexity is O(V+E)
    
Output of below program:cycle is present so the graph is not a tree    
*/
#include <iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
    map<T,list<T>> mp;
  public:  
   void  addEdge(T u,T v)
    {
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
   int  is_tree(T src)
    {
        map<T,T> parent;
        map<T,bool> visited;
        queue<T> q;
        int flag=0;
        for(auto p:mp)
        {
            T node=p.first;
            visited[node]=false;
            parent[node]=node;
        }
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(T nbr:mp[node])
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                    parent[nbr]=node;
                    visited[nbr]=true;
                }
                else{
                    if(parent[node]!=nbr)
                    {  
                       return 1;
                    }
                 }
            }
        }
      return 0;   
    } 
};
int main() {
  Graph<int> g;
  g.addEdge(0,1);
   g.addEdge(3,2);
   g.addEdge(1,2);
   g.addEdge(0,3);
 int ans= g.is_tree(0);
 if(ans==1)
 cout<<"cycle is present so the graph is not a tree";
 else
 cout<<"cycle is not present, so the graph is Tree";
	return 0;
}
