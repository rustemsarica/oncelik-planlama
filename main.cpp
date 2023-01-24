#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <stack>
using namespace std;

class Komsuluk {
    // No. of vertices'
    int V;
 
    // Pointer to an array containing adjacency listsList
    list<int>* adj;
 
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
 
public:
    // Constructor
    Komsuluk(int V);
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints a Topological Sort of
    // the complete graph
    void topologicalSort();
};
 
Komsuluk::Komsuluk(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Komsuluk::addEdge(int v, int w)
{
    // Add w to v�s list.
    adj[v].push_back(w);
}
 
// A recursive function used by topologicalSort
void Komsuluk::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Komsuluk::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Print contents of stack
    cout<<"komsuluk listesi:";
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    
}

int main(){
	
	ifstream infile("text.txt");
	int a, b;
	Komsuluk g(13);
	while (infile >> a >> b)
	{
    	g.addEdge(a, b);
	}
	g.topologicalSort();
	

}

