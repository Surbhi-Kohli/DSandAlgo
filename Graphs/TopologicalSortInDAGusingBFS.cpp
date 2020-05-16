/*
In this article we will see another way to find the linear ordering of vertices in a directed acyclic graph (DAG).
The approach is based on the below fact :

A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
Proof: There’s a simple proof to the above fact is that a DAG does not contain a cycle which 
means that all paths will be of finite length. Now let S be the longest path 
from u(source) to v(destination). Since S is the longest path there can be no incoming edge to u 
and no outgoing edge from v, if this situation had occurred then S would not have been the longest path
=> indegree(u) = 0 and outdegree(v) = 0

Algorithm:
Steps involved in finding the topological ordering of a DAG:

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in 
         the DAG and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

     a.Increment count of visited nodes by 1.
     b.Decrease in-degree by 1 for all its neighboring nodes.
     c.If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty.
Step 5: If count of visited nodes is not equal to the number of nodes in the graph then 
        the topological sort is not possible for the given graph.

How to find in-degree of each node?
There are 2 ways to calculate in-degree of every vertex:
Take an in-degree array which will keep track of
1) Traverse the array of edges and simply increase the counter of the destination node by 1.

for each node in Nodes
    indegree[node] = 0;
for each edge(src,dest) in Edges
    indegree[dest]++
Time Complexity: O(V+E)

2) Traverse the list for every node and then increment the in-degree of all the nodes connected to it by 1.

    for each node in Nodes
        If (list[node].size()!=0) then
        for each dest in list
            indegree[dest]++;

Time Complexity: The outer for loop will be executed V number of times and the inner for loop will 
                  be executed E number of times, Thus overall time complexity is O(V+E).

The overall time complexity of the algorithm is O(V+E)

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
  void topologicalSort()
  {
     map<T,int> indegree;
    queue<T>q;
    map<T,bool> visited;
     for(auto p:mp)
     {
         T node=p.first;
        indegree[node]=0;
     }
       for(auto p:mp)
     {
         T node=p.first;
        
         for(auto vertices:p.second)
         {
             indegree[vertices]++;
         }
     }
     for(auto p:mp)
     {
           T node=p.first;   
         if(indegree.at(node) ==0)
         {  //cout<<"node with indegree 0 is "<<node<<endl;
               q.push(node);
         }
        
     }
     while(!q.empty())
     {
         T node=q.front();
         cout<<node<<" ";
         q.pop();
         for(auto nbr:mp[node])
         {
             indegree[nbr]--;
             if(indegree.at(nbr)==0)
             q.push(nbr);
         }
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
	
		 g.topologicalSort(); //Output-  DataSet Python DataPreProcessing PyTorch ML DL FaceRecognition 
	
	return 0;
}
