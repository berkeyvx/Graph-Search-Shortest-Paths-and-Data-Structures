#include <iostream>
#include <vector>
#include <queue>
#include <list>

// BFS
// Explore nodes in "layers"
// can compute shortest paths
// compute the connected components of an undirected graphs

// Time Complexity O(m+n) where m = number of edges, n = number of nodes
// Space Complexity O(V) where V = number of nodes


void addEdge(std::vector<int> g[], int u, int v);
void printGraph(std::vector<int> g[], int size);
void BFS(std::vector<int> graph[], int size, int startVertex, int endVertex);

int main(int argc, char const *argv[])
{
	int graph_size = 6;

	// Graph representation
	std::vector<int> g[graph_size]; 
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 1, 3);
	addEdge(g, 2, 3);
	addEdge(g, 2, 4);
	addEdge(g, 3, 4);
	addEdge(g, 3, 5);
	addEdge(g, 4, 5);
	BFS(g,6,2,5);
	//printGraph(g, graph_size);
	return 0;
}



/*
	BFS algorithm
A standard BFS implementation puts each vertex of the graph into one of two categories:
	-Visited
	-Not Visited

The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

The algorithm works as follows:

Step 1 -> Start by putting any one of the graph's vertices at the back of a queue.
Step 2 -> Take the front item of the queue and add it to the visited list.
Step 3 -> Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
Step 4 -> Keep repeating steps 2 and 3 until the queue is empty.

The graph might have two different disconnected parts so to make sure that we cover every vertex, 
we can also run the BFS algorithm on every node
*/

void BFS(std::vector<int> graph[], int size, int startVertex, int endVertex){

	std::vector<bool> visited(size, false); // set all nodes unvisited
	std::queue<int> q;						// queue for BFS
	std::vector<int> layers(size, -1);		// to see layers, layers: initial node is layer 0, its direct neighbour is layer 1 etc.
											// basically it just keeps track of what layer each node belongs to
	std::vector<int> predecessor(size,-1);	// vector holds predecessor of each node

	// set initial node layer to 0
	layers.at(startVertex) += 1;
	// Step 1
	// Put starting vertex at the back of a queue and mark as visited
	q.push(startVertex);
	visited.at(startVertex) = true;

	std::vector<int>::iterator itr;
	while(!q.empty()){
		// Step 2
		// Take front item of the queue and add it to the visited list
		int currVertex = q.front();
		std::cout << "Visited: " << currVertex << "\n";
		q.pop();

		// Step 3
		// Add nodes in queue and mark them as visited
		for(itr = graph[currVertex].begin(); itr != graph[currVertex].end(); ++itr){
			int i = *itr;
			if(visited[i] != true){
				visited[i] = true;
				q.push(i);

				// Update layers for each node
				layers.at(*itr) = layers.at(currVertex) + 1;

				// update predecessor for each node
				predecessor.at(*itr) = currVertex;
			}
		}
	}


	// to create path
	std::vector<int> path;
	for (int i = endVertex; i != -1; i = predecessor[i])
	{
		path.push_back(i);
	}

	std::reverse(path.begin(), path.end());
	std::cout << std::endl;

	// to print path
	for (std::vector<int>::iterator i = path.begin(); i != path.end(); ++i)
	{
		std::cout << *i << " ";	
	}
	
}




void addEdge(std::vector<int> g[], int u, int v){
	g[u].push_back(v);
	g[v].push_back(u);
}


void printGraph(std::vector<int> g[], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < g[i].size(); j++){
			std::cout << i << "->" << g[i][j] << "\n";
		}
		std::cout << std::endl;
	}
}