/*
Given an undirected graph, print all connected components line by line.
Finding connected components for an undirected graph is an easier task. We simple need to do either 
BFS or DFS starting from every unvisited vertex, and we get all strongly connected components. 
Below are steps based on DFS.

1) Initialize all vertices as not visited.
2) Do following for every vertex 'v'.
       (a) If 'v' is not visited before, call DFSUtil(v)
       (b) Print new line character

DFSUtil(v)
1) Mark 'v' as visited.
2) Print 'v'
3) Do following for every adjacent 'u' of 'v'.
     If 'u' is not visited, then recursively call DFSUtil(u)
    
    
Time complexity of above solution is O(V + E) as it does simple DFS for given graph.
output of the below program is 
Component 1->0 1 2 3 4 5
Component 2->6 8 9
Component 3->7
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
   int count=1;
   for(auto p:mp)
   {
       T node=p.first;
       if(!visited[node])
       {
           cout<<"Component "<<count<<"->";
           dfs_helper(node,visited);
           cout<<endl;
           count++;
       }
   }
   
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
       g.addEdge(7,7);
       g.addEdge(6,8);
       g.addEdge(9,8);
       
g.dfs(0);
	return 0;
}
