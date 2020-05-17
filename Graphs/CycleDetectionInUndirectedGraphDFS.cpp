/*
Approach: Run a DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph.
DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in
the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the 
tree produced by DFS.
To find the back edge to any of its ancestor keep a visited array and if there is a back edge to any visited
node then there is a loop and return true.

Algorithm:

1.Create the graph using the given number of edges and vertices.
2.Create a recursive function that that current index or vertex, visited and recursion stack.
3.Mark the current node as visited and also mark the index in recursion stack.
4.Find all the vertices which are not visited and are adjacent to the current node. 
  Recursively call the function for those vertices, If the recursive function returns true return true.
5.If the adjacent vertices are already marked in the recursion stack then return true.
6.Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true, return true.
7.Else if for all vertices the function returns false .


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
    
    bool cycle_helper(T node,map<T,bool> visited,T parent){
        visited[node]=true;
        for(auto nbr:mp[node])
        {
            if(!visited[nbr])
            {
                bool cycle_mila=cycle_helper(nbr,visited,node);
                
                if(cycle_mila)
                return true;
            
            else 
            {
                if(nbr!=parent)
                return true;
                
            }
        }
        return false;
        
    }
    
   bool is_tree(T src)
    {
      
     map<T,bool> visited;
     for(auto p:mp)
     {
         T node=p.first;
         visited[node]=false;
     }
     return cycle_helper(src,visited,-1);
        
    }
    
};
int main() {
  Graph<int> g;
  g.addEdge(0,1);
   g.addEdge(3,2);
   g.addEdge(1,2);
   g.addEdge(0,3);
 bool ans= g.is_tree(0);
 if(ans==true)
 cout<<"cycle is present so the graph is not a tree";
 else
 cout<<"cycle is not present, so the graph is Tree";
	return 0;
}
