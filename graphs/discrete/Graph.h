#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <stack>

using namespace std; 

class Graph {

	int verts;
	vector<int> *adj;
	void DFSUtil(int s, bool *visited);
	bool hasCycleUtil(int s, bool *visited, bool *onStack);
	void topologicalUtil(int v, bool *visited, stack<int> &s); 

	public:
		Graph(int V);
		void addEdge(int v, int w); 
		void BFS(int s);
		void DFS(int s);
		bool hasCycle();
		void topologicalSort(); 
};

Graph::Graph(int V) : verts(V) 
{	
	//Array of vectors
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) 
{
	adj[v].push_back(w);
}

void Graph::BFS(int s) 
{ 
	bool *visited = new bool[verts];
	for(int i = 0; i < verts; i++)
		visited[i] = false;
	
	list<int> queue;
	queue.push_back(s);
	visited[s] = true;
	
	vector<int>::iterator i; 

	while(!queue.empty()) { 
	
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 

		for(i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if(!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i); 
			}
		}
	}
	std::cout << std::endl;
}

void Graph::DFS(int s) {

	bool *visited = new bool[verts];
	for(int i = 0; i < verts; i++)
		visited[i] = false;

	DFSUtil(s, visited);
	std::cout << std::endl;
}


void Graph::DFSUtil(int s, bool *visited) {

	visited[s] = true;
	cout << s << " "; 
	vector<int>::iterator i;

	for(i = adj[s].begin(); i != adj[s].end(); ++i) {
		if(!visited[*i]) 
			DFSUtil(*i, visited); 

	}
}


bool Graph::hasCycle() { 

	bool *visited = new bool[verts];
	bool *onStack = new bool[verts]; 

	for(int i = 0; i < verts; ++i) {
		visited[i] = false;
		onStack[i] = false;
	}
	
	for(int i = 0; i < verts; i++) {
		if (hasCycleUtil(i, visited, onStack))
			return true;
	}

	return false;
}

	
bool Graph::hasCycleUtil(int v, bool *visited, bool *onStack) {

	visited[v] = true; 
	onStack[v] = true;
	
	vector<int>::iterator i;

	for(i = adj[v].begin(); i != adj[v].end(); ++i) {
		
		//Visit Recursively
		if (!visited[*i]) {
			if (hasCycleUtil(*i, visited, onStack))
				return true;
		}
		
		//If the node we have reached from v (which is *i) is already on the recursion stack
		//It indicates that there is a cycle
		if (onStack[*i])
			return true;
	}
	
	onStack[v] = false;
	return false; 
}

void Graph::topologicalSort() {

	bool *visited = new bool[verts];

	for(int i = 0; i < verts; i++)
		visited[i] = false; 

	stack<int> s;

	for(int i = 0; i < verts; i++) {

		if(!visited[i])
			topologicalUtil(i, visited, s);

	}

	while(!s.empty()) {
	
		std::cout <<  s.top() << " "; 
		s.pop();
	}

	cout << std::endl; 
}

void Graph::topologicalUtil(int v, bool *visited, stack<int> &s) {


	visited[v] = true;
	vector<int>::iterator i; 

	for(i = adj[v].begin(); i != adj[v].end(); i++) 
		if (!visited[*i])
			topologicalUtil(*i, visited, s);

	//Now that we have visited all the neighbours AKA dependencies of 
	//the vertex v, it can be added to the topological sort
	s.push(v); 

}
#endif
