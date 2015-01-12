#include "EdgeGraph.h"
#include "IndexMinPQ.h"

int main(void) {

	EdgeGraph *g = new EdgeGraph(8);
	g->addEdge(4, 5, 35);
	g->addEdge(4, 7, 37);
	g->addEdge(5, 7, 28);
	g->addEdge(0, 7, 16);
	g->addEdge(1, 5, 32);
	g->addEdge(0, 4, 38);
	g->addEdge(2, 3, 17);
	g->addEdge(1, 7, 19);
	g->addEdge(0, 2, 26);
	g->addEdge(1, 2, 36);
	g->addEdge(1, 3, 29);
	g->addEdge(2, 7, 34);
	g->addEdge(6, 2, 40);
	g->addEdge(3, 6, 52);
	g->addEdge(6, 0, 58);
	g->addEdge(6, 4, 93);
	g->prim(0);
	return 0;
}
