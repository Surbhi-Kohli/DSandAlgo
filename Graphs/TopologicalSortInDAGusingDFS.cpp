/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such
that for every directed edge u->v, vertex u comes before v in the ordering. Topological Sorting 
for a graph is NOT possible if the graph is not a DAG.
For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than 
one topological sorting for a graph. 
For example, another topological sorting of the following graph is “4 5 2 3 1 0”. The first vertex in topological
sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).

Topological Sorting vs Depth First Traversal (DFS):
In DFS, we print a vertex and then recursively call DFS for its adjacent vertices. In topological sorting,
we need to print a vertex before its adjacent vertices. For example, in the given graph, the vertex ‘5’ should be
printed before vertex ‘0’, but unlike DFS, the vertex ‘4’ should also be printed before vertex ‘0’. So Topological
sorting is different from DFS.

Algorithm to find Topological Sorting:
 We can modify DFS to find Topological Sorting of a graph. In DFS, we start from a vertex, we first print it and
 then recursively call DFS for its adjacent vertices. In topological sorting, we use a temporary stack. We don’t 
 print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then
 push it to a stack. Finally, print contents of stack. Note that a vertex is pushed to stack only when all of its
 adjacent vertices (and their adjacent vertices and so on) are already in stack.
 
 Time Complexity: The above algorithm is simply DFS with an extra stack.
                    So time complexity is the same as DFS which is O(V+E).
 APPLICATIONS:
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. 
In computer science, applications of this type arise in instruction scheduling, ordering of 
formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, 
determining the order of compilation tasks to perform in makefiles, data serialization, and 
resolving symbol dependencies in linkers                    
 
 The Output for below program is 
 Python PyTorch DataSet DataPreProcessing ML DL FaceRecognition 
 We are calling DFS from each node b'coz there may be multiple nodes which don't have dependency on 
 any other node,So starting from a particular node only, might miss such nodes.
*/
#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<queue>
using namespace std;
template<typename T>

class Graph{
	map<T,list<T>> mp;
   
public:
   void addEdge(T u,T v)
   {
          mp[u].push_back(v);
   }
   void dfs_helper(T src,list<T> &orderQueue,map<T,bool> &visited)
   {
       visited[src]=true;
       for(auto nbr:mp[src])
       {
           if(visited[nbr]==false)
           {
               dfs_helper(nbr,orderQueue,visited);
              
           }
       }
      orderQueue.push_front(src);
      return;
   }
  void dfs()
  {
      map<T,bool> visited;
      list<T> orderQueue;
      for(auto p:mp)
      {
          visited[p.first]=false;
      }
      for(auto p:mp)
      {
          T node=p.first;
          //cout<<"node on which dfs is called is "<<node<<endl;
          if(!visited[node])
          {
              dfs_helper(node,orderQueue,visited);
          }
      }
     
     
        for(T p:orderQueue)
        {
        cout<<p<<" ";
         }
      }
};
int main() {

		Graph<string>g;
         g.addEdge("DataSet","FaceRecognition"); 
		 g.addEdge("Python","DataPreProcessing");
		 g.addEdge("Python","PyTorch");
		 g.addEdge("Python","ML");
		 g.addEdge("DataPreProcessing","ML");
		 g.addEdge("PyTorch","DL");
		 g.addEdge("ML","DL");
		 g.addEdge("DL","FaceRecognition");
	
		 g.dfs();
	
	return 0;
}
