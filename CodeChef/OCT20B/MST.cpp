#include <bits/stdc++.h>
using namespace std; 

class Edge 
{ 
	public: 
	int src, dest, weight; 
}; 

class Graph 
{ 
	public: 
	int V, E; 

	Edge* edge; 
}; 

Graph* create_graph(int V, int E) 
{ 
	Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 

class subset 
{ 
	public: 
	int parent; 
	int rank; 
}; 

// A utility function to find set of an element i 
// (uses path compression technique) 
int find(subset subsets[], int i) 
{ 
	// find root and make root as parent of i 
	// (path compression) 
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

	// Attach smaller rank tree under root of high 
	// rank tree (Union by Rank) 
	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	// If ranks are same, then make one as root and 
	// increment its rank by one 
	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
int foo(const void* a, const void* b)
{ 
	Edge* a1 = (Edge*)a; 
	Edge* b1 = (Edge*)b; 
	return a1->weight > b1->weight; 
} 

// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(Graph* graph) 
{ 
	int V = graph->V; 
	Edge result[V]; // Tnis will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), foo);

	subset *subsets = new subset[( V * sizeof(subset) )];

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
 
	while (e < V - 1 && i < graph->E)
	{
		Edge next_edge = graph->edge[i++];
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}
	int sum = 0;
	for (i = 0; i < e; ++i)
	{
		// cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<-result[i].weight<<endl; 
		sum += result[i].weight;
	}
	cout << -sum << '\n';
}

int main() {
	int n, m, d, i, j, k = 0, w;
	cin >> n >> d;
	m = ((n - 1) * n) / 2;

	int coor[n][d];
	for (i = 0; i < n; ++i)
		for (j = 0; j < d; ++j)
			cin >> coor[i][j];

	Graph* graph = create_graph(n, m);
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n and k < m; ++j)
		{
			// if (i == j)
			// 	continue;
			graph->edge[k].src = i;
			graph->edge[k].dest = j;
			w = 0;
			for (int l = 0; l < d; ++l)
				w += abs(coor[i][l] - coor[j][l]);
			graph->edge[k].weight = -w;
			++k;
		}
	}

	KruskalMST(graph);
	return 0;
}