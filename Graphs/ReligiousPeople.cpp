/*
All the people living in our imaginary world Bitworld are very religious.
There are N cities in Bitworld numbered from 1 to N.
Due to a storm, every road in Bitworld was destroyed and now no temples are left.
There are 2 types of operations :

You can construct a temple by giving away A dollars in ith city.
You can repair an already existing road by giving away B dollars.

Your goal is to make temples such that people of every city have access to some temple.
People of the ith city can visit the temple only if :
A temple exists in that city.
OR
There is a path from that city to a city which contains a temple. ( the path should consist of repaired roads only )
You have to minimize the total cost such that people in every city can go to a temple and output this minimum cost.

NOTE : You can only repair the roads which existed and not build on your own.

Input Format
The first line consists of number of test cases T. Each test case consists of 4 integers N,M,A,B. which 
denote number of cities, number of roads which existed , cost to build a temple , cost to repair a road.
Next M lines contains M pairs denoted by U V which indicates a road existed between U and V.

Constraints
1 <= T <= 10. 1 <= N <= 100000. 0 <= M <= 100000. 1 <= A,B <= 1000000000. 1 <= U,V <= N. Each road connects 2 distinct cities.

Output Format
Total minimum cost in dollars.

Sample Input
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6
Sample Output
4
12
Explanation
For first test case:

build temple in city 1 for 2 dollars.
repair road between 1 and 2 and repair road between 2 and 3 for total cost of 1+1 dollars. hence total cost is 4 dollars.
For second test case: You can build a temple in every city for a total cost of 6*2 = 12 dollars.

Approach :
Count the number of disjoll components (subgraphs which are not connected to each other) and store them 
in a variable , say 'components' Each component must have a single Temple So cost of temple in each component
is A * components Further there are (x-1) roads required in each component where x is no of vertices in that 
component Sum of roads in all components = (n - components) , n is no of nodes in adjacency list Multiply that
with B , cost to repair each road Cost so far , cost = A*component + B * (n-components)

But there are some vertices that do not form any edges Some vertices which stand alone and each of these vertices 
must have a temple of its own Since they do not form any edge , there count is not included in the adjacency list 
No of such nodes is (V - n) …where V is total no of nodes and n is no of nodes that form an edge and are part of 
previously counted components Since each of these nodes must have a temple Total cost = Acomponents + B(n-component) + A*(V-n)

Do not forget to consider the base case when A<=B. If cost of constructing temples in each city is less than 
repairing roads , simply build temples in all cities and return V*A .



*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int

class Graph
{
private:
    ll V;
    map<ll, list<ll>> adjList;

public:
    Graph(ll v)
    {
        V = v;
    }
    void addEdge(ll u, ll v)
    {
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(ll node, map<ll, bool> &visited)
    {

        visited[node] = true;

        for (ll child : adjList[node])
        {
            if (!visited[child])
            {
                dfsHelper(child, visited);
            }
        }
    }

    ll dfsReligiousPeople(ll src, ll a, ll b)
    {

        //If cost of constructing temples in each city is less than repairing roads , simply build temples in all cities
        if (a <= b)
        {
            return V * a;
        }

        map<ll, bool> visited;
        ll components = 1;
        dfsHelper(src, visited);

        for (auto i : adjList)
        {
            ll city = i.first;
            if (!visited[city])
            {
                dfsHelper(city, visited);
                components++;
            }
        }

        ll n = adjList.size();
        ll totalCost = a * components + b * (n - components) + a * (V - n);

        return totalCost;
    }
};

int main()
{
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll n; //No of cities (nodes)
        ll m; //No of roads  (edges)
        ll a; //Cost to construct a temple
        ll b; //Cost to repair a road

        cin >> n >> m >> a >> b;

        Graph g(n);
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        //  g.printAdjList();

        cout << g.dfsReligiousPeople(1, a, b) << endl;
    }

    return 0;
}
