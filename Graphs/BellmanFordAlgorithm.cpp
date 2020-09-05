/*
 Bellman-Ford works better (better than Dijksra’s) for distributed systems.
 Unlike Dijkstra’s where we need to find the minimum value of all vertices, 
 in Bellman-Ford, edges are considered one by one.
 
 Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs.
 Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. 
 But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.



How does this work? Like other Dynamic Programming Problems, the algorithm calculates shortest 
paths in a bottom-up manner. It first calculates the shortest distances which have at-most one 
edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After
the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. 
There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times.
The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with 
at most i edges,then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges

The relaxation procedure in Bellman-Ford is done V-1 times because that is the max number of 
edges that could form a shortest path.
If this is not true then we are looking at a negative weight cycle in the graph.
*/


#include <iostream>
#define inf 1e9

using namespace std;
class Edge
{
    public:
    int src,dest,weight;
};

class Graph{
    
      public:
      int v,e;
      Edge *edge;
      Graph(int v,int e){
          this->v=v;
          this->e=e;
          edge=new Edge[e];
      }
      
    void addEdge(int u,int v,int wt,int count)
    {
        edge[count].src=u;
        edge[count].dest=v;
        edge[count].weight=wt;
       
    }
    
  // The main function that finds shortest distances from src to 
  // all other vertices using Bellman-Ford algorithm.The function 
  // also detects negative weight cycle 
    void bellmanFord(int src)
    { 
        int count=0;
       int dist[v];
       
        // Step 1: Initialize distances from src to all other vertices 
        // as INFINITE 
       for(int i=0;i<v;i++)
       {
           if(i==src)
           dist[i]=0;
           else
           dist[i]=inf;
           
       }
        //Relaxation code
        // Step 2: Relax all edges |V| - 1 times. A simple shortest 
        // path from src to any other vertex can have at-most |V| - 1 
        // edges 
        for(int i=1;i<=v-1;i++)
        {
            for(int j=0;j<e;j++)
            {
                int src=edge[j].src;
                int dest=edge[j].dest;
                int wt=edge[j].weight;
                if(dist[src]!=inf && dist[src]+wt<dist[dest])
                {
                    dist[dest]=dist[src]+wt;
                }
            }
            count++;
        }
        cout<<"relaxation loop ran "<<count<<" times "<<endl;
        
        
           // Step 3: check for negative-weight cycles.  The above step 
            // guarantees shortest distances if graph doesn't contain 
            // negative weight cycle.  If we get a shorter path, then there 
             // is a cycle. 
        for(int j=0;j<e;j++)
        {
            
            int src=edge[j].src;
            int dest=edge[j].dest;
            int wt=edge[j].weight;
            if(dist[src]!=inf && dist[src]+wt<dist[dest])
            {
              cout<<" Graph  has negative weight cycle "<<endl;
              return ;
            }
        }
        for(int i=1;i<v;i++)
        {
            cout<<i<<" is at distance "<<dist[i]<<endl;
        }
        return ;
    }
};
int main() {
	// your code goes here
int v,e;
cin>>v>>e;

	Graph g(v,e);
	for(int i=0;i<e;i++)
	{
	    int u,v,w;
	    cin>>u>>v>>w;
	    g.addEdge(u,v,w,i);
	}
	g.bellmanFord(0);
	return 0;
}
