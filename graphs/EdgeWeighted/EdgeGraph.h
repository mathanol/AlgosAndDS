#ifndef _EDGE_GRAPH_H 
#define _EDGE_GRAPH_H

#include <list>
#include <stack>

#include "IndexMinPQ.h"

using namespace std; 

class Edge {

	public:
		Edge(int v, int w, int weight); 
		int from(); 
		int to();
		int weight();
	private:
		int _weight; 
		int v;
		int w;
}; 

Edge::Edge(int v, int w, int weight) {
	this->v = v; 
	this->w = w; 
	this->_weight = weight; 
}

int Edge::from() {
	return v;
}

int Edge::weight() {
	return _weight;
}

int Edge::to() {
	return w; 
}

class EdgeGraph {

	public:
		EdgeGraph(int V); 
		void addEdge(int v, int w, int weight);
		int DjikstraSP(int s, int d); 
		int BFPath(int s, int d); 
		void prim(int s); 

	private:
		int V;
		list<Edge> *adj;
		void relax(Edge &e, int *dist, IndexMinPQ<int>* pq, int *prev); 
		list<Edge> edges;
};

EdgeGraph::EdgeGraph(int V) {
	
	this->V = V; 
	adj = new list<Edge>[V];
}

void EdgeGraph::addEdge(int v, int w, int weight) { 

	Edge e(v, w, weight);
	Edge e1(w, v, weight);
	adj[v].push_back(e);
	adj[w].push_back(e1);
	edges.push_back(e); 

}

int EdgeGraph::DjikstraSP(int s, int d) {

	int *dist = new int[V]; 
	int *prev = new int[V];

	for(int j = 0; j < V; j++) {
		dist[j] = INT_MAX; 
		prev[j] = -1; 
	}


	dist[s] = 0;
	IndexMinPQ<int> *pq = new IndexMinPQ<int>(V); 
	pq->insert(s, dist[s]); 
	while(!pq->empty()) {

		int n = pq->delMin();
		list<Edge>::iterator i; 
		for(i = adj[n].begin(); i != adj[n].end(); ++i)
			relax(*i, dist, pq, prev); 
	}
	
	int e;
	stack<int> path; 
	path.push(d); 

	for(e = prev[d]; e != -1 ; e = prev[e])
		path.push(e); 
	
	cout << "Path" << std::endl; 
	while(!path.empty()) {
		cout << path.top() << " "; 
		path.pop(); 
	}
	cout << endl;

	return dist[d]; 
}

void EdgeGraph::relax(Edge &e, int *dist, IndexMinPQ<int>* pq, int *prev) {
	
	int v = e.from(); 
	int w = e.to(); 

	if ( dist[v] != INT_MAX && dist[w] > dist[v] + e.weight()) {
		dist[w] = dist[v] + e.weight();
		prev[w] = v;
		if (pq->contains(w))
			pq->decreaseKey(w, dist[w]); 
		else 
			pq->insert(w, dist[w]); 
	}
}

int EdgeGraph::BFPath(int s, int d) { 

	int *dist = new int[V]; 
	int *prev = new int[V];

	for(int j = 0; j < V; j++) {
		dist[j] = INT_MAX; 
		prev[j] = -1; 
	}
	
	dist[s] = 0; 

	for(int j = 0; j < V -1; j++) {

		list<Edge>::iterator i; 
		for(i = edges.begin(); i != edges.end(); ++i) {
			Edge e = *i; 
			int v = e.from(); 
			int w = e.to(); 
			
			if (dist[v] != INT_MAX && dist[w] > dist[v] + e.weight()) {
				dist[w] = dist[v] + e.weight(); 
				prev[w] = v;
			}

		}

	}


        list<Edge>::iterator i;
        for(i = edges.begin(); i != edges.end(); ++i) {
        	Edge e = *i;
                int v = e.from();
                int w = e.to();

                if (dist[v] != INT_MAX && dist[w] > dist[v] + e.weight()) {
			cout << "Graph has a negative cycle" << endl;
			return INT_MAX; 
		}
		
	}
	
        int e;
        stack<int> path;
        path.push(d);

        for(e = prev[d]; e != -1 ; e = prev[e])
                path.push(e);

        cout << "Path" << std::endl;
        while(!path.empty()) {
                cout << path.top() << " ";
                path.pop();
        }
        cout << endl;
	return dist[d];
}


//Find the best cut
//Which means find the least weighted vertex with the smallest distance from any 
//vertex that is part of the tree
void EdgeGraph::prim(int s) { 

	int *dist = new int[V]; 
	bool *marked = new bool[V];
	Edge **edgeTo = new Edge*[V];
	
	for(int j = 0; j < V; j++) {
		dist[j] = INT_MAX; 
		marked[j] = false;
		edgeTo[j] = NULL; 
	}
		
	IndexMinPQ<int> *pq = new IndexMinPQ<int>(V); 
	pq->insert(s, dist[s]); 
	dist[s] = 0; 
	
	while(!pq->empty()) {
		
		int v = pq->delMin(); 
		list<Edge>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); i++) {
			Edge e = *i; 
			marked[v] = true; 
			int w = e.to(); 
			if (marked[w]) continue; 
			if (e.weight() < dist[w]) {
				edgeTo[w] = new Edge(e); 
				cout << e.to() << " " << e.from() << endl;
				dist[w] = e.weight(); 
	
				if (pq->contains(w))
					pq->decreaseKey(w, dist[w]);
				else 
					pq->insert(w, dist[w]); 
			}
		}
	}

	for(int j = 0; j < V; j++) {
		cout << marked[j] << " ";
		cout << endl; 
		if(edgeTo[j] != NULL)
			cout << edgeTo[j]->to() << "--" << edgeTo[j]->from() << endl; 
	}
}
	




#endif
