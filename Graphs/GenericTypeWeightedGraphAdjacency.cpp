#include <iostream>
#include<list>
#include<map>
using namespace std;
template <typename T>
 class Graph{
    map<T,list<pair<T,int>>> adjList;
    public:
    Graph(){
        
    }
    void addEdge(T u,T v,int wt,bool bidir=true)
    {
        adjList[u].push_back(make_pair(v,wt));
        if(bidir)
        {
            adjList[v].push_back(make_pair(u,wt));
        }
    }
    void print(){
        //Iterate over the map
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            for(auto entry:i.second)
            {
                int wt=entry.second;
                T node=entry.first;
                cout<<"("<<node<<","<<wt<<")";
            }
            cout<<endl;
        }
    }
};
int main() {
	// your code goes here
	Graph <string> g;
	g.addEdge("Putin","trump",10,false);
	g.addEdge("Putin","modi",2,false);
	g.addEdge("Modi","trump",50,true);
	g.addEdge("Modi","Yogi",60);
	g.addEdge("Yogi","Prabhu",5,false);
	g.print();
	
	return 0;
}
//Output
//Modi->(trump,50)(Yogi,60)
//Putin->(trump,10)(modi,2)
//Yogi->(Modi,60)(Prabhu,5)
//trump->(Modi,50)
