/*
Detect Cycle in a Directed Graph using BFS
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true 
if the given graph contains at least one cycle, else return false. For example, the following graph contains
two cycles 0->1->2->3->0 and 2->4->2, so your function must return true.
The idea is to simply use Kahn’s algorithm for Topological Sorting

Steps involved in detecting cycle in a directed graph using BFS.

Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the graph and initialize the count of visited nodes as 0.

Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

Step-3: Remove a vertex from the queue (Dequeue operation) and then.

Increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty.

Step 5: If count of visited nodes is not equal to the number of nodes in the graph has cycle, otherwise not.

*/
// A C++ program to check if there is a cycle in 
// directed graph using BFS. 
#include <bits/stdc++.h> 
using namespace std; 

// Class to represent a graph 
class Graph { 
	int V; // No. of vertices' 

	// Pointer to an array containing adjacency lisr 
	list<int>* adj; 

public: 
Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void addEdge(int u, int v) 
{ 
	adj[u].push_back(v); 
} 

// This function returns true if there is a cycle 
// in directed graph, else returns false. 
bool isCycle() 
{ 
	// Create a vector to store indegrees of all 
	// vertices. Initialize all indegrees as 0. 
	vector<int> in_degree(V, 0); 

	// Traverse adjacency lists to fill indegrees of 
	// vertices. This step takes O(V+E) time 
	for (int u = 0; u < V; u++) { 
		for (auto v : adj[u]) 
			in_degree[v]++; 
	} 

	// Create an queue and enqueue all vertices with 
	// indegree 0 
	queue<int> q; 
	for (int i = 0; i < V; i++) 
		if (in_degree[i] == 0) 
			q.push(i); 

	// Initialize count of visited vertices 
	int cnt = 0; 

	// Create a vector to store result (A topological 
	// ordering of the vertices) 
	vector<int> top_order; 

	// One by one dequeue vertices from queue and enqueue 
	// adjacents if indegree of adjacent becomes 0 
	while (!q.empty()) { 

		// Extract front of queue (or perform dequeue) 
		// and add it to topological order 
		int u = q.front(); 
		q.pop(); 
		top_order.push_back(u); 
	     cnt++; 
		// Iterate through all its neighbouring nodes 
		// of dequeued node u and decrease their in-degree 
		// by 1 
		
		for (auto nbr:adj[u]) 
     {
			// If in-degree becomes zero, add it to queue 
        in_degree[nbr]--;
			if (in_degree[nbr] == 0) 
				q.push(nbr); 
      }
	
	} 
cout<<"count is "<<cnt<<endl;//3 ase the component of the graph that
                              //has cycle does not have a node with indegree 0
	// Check if there was a cycle 
	if (cnt != V) 
		return true; 
	else
		return false; 
}
};

// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(6); 
	g.addEdge(0, 1); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(3, 4); 
	g.addEdge(4, 5); 

	if (g.isCycle()) 
		cout << "Yes"; 
	else
		cout << "No"; 

	return 0; 
} 
