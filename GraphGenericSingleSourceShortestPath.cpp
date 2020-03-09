#include <bits/stdc++.h>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> adjList;
    
    public:Graph(){}
    void addEdge(T u,T v,bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
        
    }
    void sssp(T src)
    {
        queue<T> q;
        map<T,T> parent; 
        map<T,int> dist;
        q.push(src);
        for(auto i:adjList)
        {
            dist[i.first]=INT_MAX;
        }
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbour:adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }
        }
        cout<<endl;
        for(auto i:adjList)
        {
            T node =i.first;
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }
    
    void printAdjList(){
        
        for(auto i:adjList)
        {
            cout<<i.first<<"-> ";
            for(auto vertex:i.second)
            {
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
    
};
int main() {
Graph <string>g;
g.addEdge("Putin","Trump",false);
g.addEdge("Putin","Modi",false);
g.addEdge("Modi","Trump",true);
g.addEdge("Modi","Yogi");
g.addEdge("Yogi","Prabhu",false);
g.addEdge("Prabhu","Modi",false);
g.addEdge("Putin","Pope",false);
g.printAdjList();
cout<<endl;

g.sssp("Putin");

	return 0;
}
