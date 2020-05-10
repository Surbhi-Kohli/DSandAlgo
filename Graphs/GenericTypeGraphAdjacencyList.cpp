#include <iostream>
#include<list>
#include<map>

using namespace std;
template <typename T>
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
  void printAdjlist(){
      for(auto i:adjList)//auto will automatically determine the data type
      {
          cout<<i.first<<" -> ";
	      //i.second is Linked List
          for(auto entry:i.second)
          {
           cout<<entry<<",";   
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
  
   g.printAdjlist();
	return 0;
}
