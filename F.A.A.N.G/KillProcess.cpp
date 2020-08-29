/*
Given a list of processes where each process have a unique id and a unique parent id . Parent id is the id of the process that initiated that process . 
You want to kill a particular process given by an integer kill . Print id of all the processes that will be killed to kill that process.You 
should print them in sorted order by id.
In order to kill a process , all its child processes should be killed as well . Also, only one process have parent id as 0 ie. that process started itself.

Input Format
The first line contains two integer - n (number of process ) and k (id of process to be killed).
Next line contains n integer equal to id of ith process.
Next line contains n integer equal to parent id of ith process.

Constraints
1<=n<=10^5

Output Format
Print id of all the process that will be killed in sorted order.

Sample Input
3 2
1 2 3
0 1 1
Sample Output
2

Explanation
Since , process with id 2 have no child , so it will only be killed.

*/
#include <bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adjList;
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
    }
   void killProcess(int src)
  {
     unordered_map<int,bool> visited;
     set<int> ans;
     for(auto node:adjList)
     {
         visited[node.first]=false;
     }
     //cout<<"over here "<<endl;
     queue<int> q;
     int i=0;
    ans.insert(src);
     q.push(src);
     visited[src]=true;
     while(!q.empty())
     { 
       int t=q.front();
     
       q.pop();
       for(auto nbr:adjList[t])
       {
           if(visited[nbr]==false)
          {
           visited[nbr]=true;
           q.push(nbr);
          ans.insert(nbr);
        }
       }
     }
    for(auto entry:ans)
    cout<<entry<<" ";
    }
};
int main(){
    int processes,killId;
    cin>>processes>>killId;
 
    Graph g;
    int nodes[processes];
    int parents[processes];
    for(int i=0;i<processes;i++)
    {
        cin>>nodes[i];
    }
    for(int i=0;i<processes;i++)
    {
        cin>>parents[i];
    }
 
    for(int i=0;i<processes;i++)
    {   
        g.addEdge(nodes[i],nodes[i]);//it might be that a node is a child node with no 
                                      //further child,so we do need to make its entry in hashmap as a key
        g.addEdge(parents[i],nodes[i]);
    }
  
   g.killProcess(killId);
   
   
return 0;
    
}
