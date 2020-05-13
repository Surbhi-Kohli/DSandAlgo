/*
Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch 
here is, unlike trees, graphs may contain cycles, a node may be visited twice.
To avoid processing a node more than once, use a boolean visited array.

Complexity Analysis:
Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V).
Since, an extra visited array is needed of size V.

Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent
unmarked node and continue this loop until there is no unmarked adjacent node. Then backtrack and check for other
unmarked nodes and traverse them. Finally print the nodes in the path.

Algorithm:
Create a recursive function that takes the index of node and a visited array.
Mark the current node as visited and print the node.
Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.

*/

#include <iostream>
#include <climits>
#include <queue>
#include <map>
#include <list>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> mp;
    public:
    void addEdge(T u,T v)
    {
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
    void dfs_helper(T s,map<T,bool> &visited)
    {
        cout<<s<<" ";
        visited[s]=true;
        for(auto nbr:mp[s])
        {
            if(visited[nbr]==false)
            {
                
                dfs_helper(nbr,visited);
            }
        }
    }
void dfs(T s)
{
    map<T,bool> visited;
    for(auto node:mp)
    {
        visited[node.first]=false;
    }
   
    dfs_helper(s,visited);
}
};
int main() {
    Graph<int> g;
    g.addEdge(1,2);
      g.addEdge(3,2);
     g.addEdge(1,0);
    
       g.addEdge(3,0);
       g.addEdge(3,4); 
       g.addEdge(5,4); 
g.dfs(0);
	return 0;
}
