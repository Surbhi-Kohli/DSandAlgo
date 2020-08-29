/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Input Format
First Line contains single integer n (total courses) Second Line contains single integer m (total pairs) Next m lines contain m pairs

Constraints
1<=n<=10000

Output Format
print "Yes" or "No" (without quotes)

Sample Input
2
2
1 0
0 1
Sample Output
No
Explanation
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also
have finished course 1. So it is impossible.


*/
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    unordered_map<int,list<int>> adjList;
    public:
    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
    }
  bool dfs_helperToDetectCycle(int src,unordered_map<int,bool> &visited,bool instack[])
  {
      visited[src]=true;
       instack[src]=true;
    //cout<<instack[src]<<"instack["<<src<<"]"<<endl;
       for(auto nbr:adjList[src])
       { 
           if(instack[nbr]==1)
           {  //  cout<<"in if"<<endl;
               return true;
           }
           else if(visited[nbr]==false)
           {
               bool cycle_mila=dfs_helperToDetectCycle(nbr,visited,instack);
               if(cycle_mila)
               return true;
           }
       }
       instack[src]=false;
       return false;
  }
    void checkCompletionPossible(){
        unordered_map<int,bool> visited;
        bool instack[adjList.size()];
  bool ans;
        for(auto entry:adjList)
        {
            visited[entry.first]=false;
            instack[entry.first]=false;
        }
        for(auto entry:adjList)
        { // cout<<entry.first<<" is src"<<endl;
            if(visited[entry.first]==false)
            {
                ans=dfs_helperToDetectCycle(entry.first,visited,instack);
               // cout<<"ans returned by dfs helper is "<<ans<<endl;
                if(ans)
                {
                    break;
                }
            }
        }
        if(ans)
        cout<<"No";
        else
        cout<<"Yes";
    }
};
int main(){
    int n,pairs;
    cin>>n>>pairs;
    pair<int,int> arr[pairs];
    int x,y;
    Graph g;
    for(int i=0;i<pairs;i++)
    {
        cin>>x>>y;
       g.addEdge(x,y);
    }
    g.checkCompletionPossible();
    return 0;
}
