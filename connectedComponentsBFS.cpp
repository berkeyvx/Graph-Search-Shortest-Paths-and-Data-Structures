#include <iostream>
#include <vector>
#include <queue>
#include <list>

// This algorithms finds every connected components
// No way to miss a node, for loops walk through every node

// Usage: 
// Check if network disconnected
// Graph visualisation
// Clustering

// Space complexity Linear Time O(N)


void addEdge(std::vector<int> g[], int u, int v);
void printGraph(std::vector<int> g[], int size);
void BFS(std::vector<int> graph[], int size, int startVertex, std::vector<bool> &visited);
void connectedComponentsBFS(std::vector<int> g[], int size);

int main(int argc, char const *argv[])
{
	int graph_size = 11;

	// Graph representation
	std::vector<int> g[graph_size]; 
	addEdge(g, 1, 3);
	addEdge(g, 1, 5);
	addEdge(g, 3, 5);
	addEdge(g, 5, 7);
	addEdge(g, 5, 9);

	addEdge(g, 2, 4);

	addEdge(g, 6, 8);
	addEdge(g, 6, 10);
	addEdge(g, 8, 10);

	connectedComponentsBFS(g, 11);
	//printGraph(g, graph_size);
	return 0;
}



void BFS(std::vector<int> graph[], int size, int startVertex, std::vector<bool> &visited){

	//std::vector<bool> visited(size, false); // set all nodes unvisited
	std::queue<int> q;						// queue for BFS


	q.push(startVertex);
	visited.at(startVertex) = true;

	std::vector<int>::iterator itr;
	while(!q.empty()){
		// Take front item of the queue and add it to the visited list
		int currVertex = q.front();
		std::cout << "Visited: " << currVertex << "\n";
		q.pop();

		// Add nodes in queue and mark them as visited
		for(itr = graph[currVertex].begin(); itr != graph[currVertex].end(); ++itr){
			int i = *itr;
			if(visited[i] != true){
				visited[i] = true;
				q.push(i);
			}
		}
	}	
}


 void connectedComponentsBFS(std::vector<int> g[], int size){
 	std::vector<bool> visited(size, false);
 	for (int i = 1; i < size; ++i)
 	{
 		if(!visited.at(i))
 			// std::vector<bool> visited -> pass by reference
 			BFS(g, size, i, visited);
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