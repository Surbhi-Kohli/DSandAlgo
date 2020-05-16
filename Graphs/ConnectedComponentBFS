
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
    
    void bfs_helper(T s,map<T,bool> &visited)
    {
      
        queue<T> q;
        q.push(s);
        visited[s]=true;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
           
            cout<<node<<" ";
            for(auto nbr:mp[node])
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                     visited[nbr]=true;
                   
                }
            }
        }
        
    }
void bfs(T s)
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
           bfs_helper(node,visited);
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
       
       g.bfs(0);
	return 0;
}
