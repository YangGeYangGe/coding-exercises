// test for printNodes()

#include "Graph.h"

int main() {

	// make a graph
	gdwg::Graph<unsigned int,int> g;

	g.addNode(1);
	g.addNode(2);
	g.addNode(3);
	g.addNode(4);

	g.addEdge(1,2,12);
	g.addEdge(1,3,13);
	g.addEdge(1,4,14);//1 outdegree3
	g.addEdge(2,1,21);
	g.addEdge(2,3,23);//2			2
	g.addEdge(3,1,31);
	g.addEdge(3,4,34);//3			2

	g.printNodes();
}
