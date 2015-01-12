#include "Graph.h"

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    cout << g.hasCycle() << std::endl;

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
