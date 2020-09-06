#include <iostream>
#include <list>
#include <climits>
#define inf 1e9

using namespace std;

class Graph{
    public:
    int V;
    list<pair<int,int>> *adj;
    Graph(int v)
    {
        V=v;
        adj=new list<pair<int,int>>[V]; 
    }
    void addEdge(int u,int v,int w)
    {  //cout<<"V is "<<V<<endl;
        adj[u].push_back(make_pair(v,w));
      //  cout<<"**"<<endl;
        adj[v].push_back(make_pair(u,w));
      

    }
int findMinVertex(int *weight,bool *visited,int V)
{
    int minVertex=-1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void Prims(){
    bool *visited=new bool[V];
    int *parent=new int[V];
    int *weight=new int[V];
    //Initialization
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<V;i++)
    {
        int minVertex=findMinVertex(weight,visited,V);
        visited[minVertex]=true;
     
        for(auto nbr:adj[minVertex])
        {
            if(!visited[nbr.first])
            {
                if(weight[nbr.first]>nbr.second)
                {
                    parent[nbr.first]=minVertex;
                   
                    weight[nbr.first]=nbr.second;
                    
                }
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        cout<<i<<" is the node with parent--"<<parent[i]<<" with weight"<<weight[i]<<endl;
    }
}
};
int main() {
	// your code goes here
	int n,e;
	cin>>n>>e;

	Graph g(n);
	for(int i=0;i<e;i++)
	{
	  
	   int u,v,w;
	   cin>>u>>v>>w;
	  
	   u--;
	   v--;
	   g.addEdge(u,v,w);
	}

	g.Prims();
	return 0;
}
