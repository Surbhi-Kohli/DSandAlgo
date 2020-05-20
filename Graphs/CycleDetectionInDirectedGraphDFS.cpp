/*
Detect Cycle in a Directed Graph
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true 
if the given graph contains at least one cycle, else return false.
Approach: Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (self-loop) or one of its ancestor in the tree produced by DFS.
For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by checking back edges.

To detect a back edge, keep track of vertices currently in recursion stack of function for DFS traversal. If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. The edge that connects current vertex to the vertex in the recursion stack is a back edge. Use recStack[] array to keep track of vertices in the recursion stack.

Algorithm:
Create the graph using the given number of edges and vertices.
Create a recursive function that that current index or vertex, visited, and recusrsion stack.
Mark the current node as visited and also mark the index in recursion stack.
Find all the vertices which are not visited and are adjacent to current node. Recursively call the function for those vertices, If the recursive function returns true return true.
If the adjacent vertices are already marked in the recursion stack then return true.
Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true return true. Else if for all vertices the function returns false return false.

Complexity Analysis:
Time Complexity: O(V+E).
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
Space Complexity: O(V).
To store the visited and recursion stack O(V) space is needed.
*/
#include <iostream>
#include <map>
#include <list>

using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> mp;
    public:
    void addEdge(T u,T v,bool bidir=true){
        mp[u].push_back(v);
        if(bidir)
        {
            mp[v].push_back(u);
        }
    }
    
    bool isCycleHelper(T node, map<T,bool> visited,map<T,bool> inStack)
    {
        visited[node]=true;
        inStack[node]=true;
        for(auto nbr:mp[node])
        {
            if(inStack[nbr]==true)
            return true;
            
            else if(visited[nbr]==false)
            {
                bool cycle_mila=isCycleHelper(nbr,visited,inStack);
                if(cycle_mila==true)
                {
                    return true;
                }
            }
        }
        inStack[node]=false;
        return false;
    }
    
    bool isCycle(){
        map<T,bool> visited;
        map<T,bool> inStack;
        //To check for cycle in each dfs tree
        for(auto i:mp)
        {
            T node=i.first;
            if(!visited[node])
            {
                bool cyclePresent=isCycleHelper(node,visited,inStack);
                if(cyclePresent)
                return true;
            }
        }
        return false;
    }
    
};
int main() {

	Graph <int>g;
	g.addEdge(0,1,false);
	g.addEdge(1,2,false);
	g.addEdge(2,3,false);
	g.addEdge(3,4,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5,false);
	g.addEdge(5,6,false);
	g.addEdge(4,2,false);
	
	if(g.isCycle())
	cout<<"Contains a cycle";
	else
	cout<<"Does not contain a cycle";
	
	return 0;
}
//output:Contains a cycle
