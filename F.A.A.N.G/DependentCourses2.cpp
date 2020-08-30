/*

Coding blocks has total n courses, labelled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 student has to first take course 1, which is expressed as a pair: [0,1].
Now Elliot wants to complete all the courses from coding blocks.
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses Elliot should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Input Format
First line contains two integers N and M, number of courses and number of prerequisite pairs.Next M lines contains two integers, denoting each prerequisite pair.

Constraints
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. You may assume that there are no duplicate edges in the input prerequisites.

Output Format
A line containing N space separated integers, denoting the correct order to complete N courses.

Sample Input
4 4
1 0   //denotes that 1 is dependent on 0
2 0   //2 is dependent on 0
3 1 
3 2
Sample Output
0 1 2 3 
Explanation
There are a total of 4 courses to take. To take course 3 elliot should have finished both
courses 1 and 2. Both courses 1 and 2 should be taken after elliot finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

*/
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
class Graph{

unordered_map<int,list<int>> adjList;
public:
void addEdge(int u,int v)
{
    adjList[u].push_back(v);
}
void topologicalOrder()
{
    unordered_map<int,int> indegree;
    queue<int> q;
    for(auto entry:adjList)
    {
        indegree[entry.first]=0;
    }
    for(auto entry:adjList)
    {
        for(auto nbr:entry.second)
        {
            indegree[nbr]++;
        }
    }
    for(auto entry:adjList)
    {
        if(indegree[entry.first]==0)
        {   //cout<<entry.first<<" has indegree 0"<<endl;
             q.push(entry.first);
        }
        
    }
    while(!q.empty())
    {
        int node=q.front();
         cout<<node<<" ";
        q.pop();
      
        for(auto nbr:adjList[node])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
}
};
int main(){
    int n,pairs;
    cin>>n>>pairs;
    int x,y;
    Graph g;
    for(int i=0;i<pairs;i++)
    {
        cin>>x>>y;
        g.addEdge(y,x);
    }
    g.topologicalOrder();
}
