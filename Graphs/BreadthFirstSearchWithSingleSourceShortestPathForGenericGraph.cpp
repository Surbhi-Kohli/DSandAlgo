/*
Single Source Shortest Path(SSSP) from src to some other destination.BFS gives us level order traversal 
and distance calculated by level order traversal is the shortest.
Program to share shortest distance of all node from source.

Breadth First Traversal (or Search) for a graph is similar to Breadth First Traversal of a tree (See method 2 of this post). 
The only catch here is, unlike trees, graphs may contain cycles, so we may come to the same node again. 
To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all
vertices are reachable from the starting vertex.

Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
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
   void bfs(T s)
    {
        queue<T> q;
        map<T,int> dist;
        
        for(auto vertex:mp)
        {
          dist[vertex.first]=INT_MAX;  
        }
        dist[s]=0;
        q.push(s);
        while(!q.empty())
        {
            T node=q.front();
            cout<<"distance of "<<node<<"->"<<dist[node]<<endl;
            q.pop();
            for(T nbr:mp[node])
            {   if(dist[nbr]==INT_MAX)
               {
                    dist[nbr]=dist[node]+1;
                     q.push(nbr);
               }
               
            }
        }
    }
};
int main() {
       Graph<int> g;
       g.addEdge(1,2);
       g.addEdge(1,0);
       g.addEdge(3,2);
       g.addEdge(3,0);
       g.addEdge(3,4); 
       g.addEdge(5,4); 
       g.bfs(0);
	    return 0;
}
