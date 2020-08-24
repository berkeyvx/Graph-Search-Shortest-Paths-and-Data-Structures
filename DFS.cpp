#include <iostream>
#include <vector>

/*
	DFS: Explore agressively, only backtrack when necessary

	-> computes a topological ordering of directed acyclic graph
	-> connected components of directed graph

	Run Time O(m+n)

	DFS Algorithm Applications
	->For finding the path
	->To test if the graph is bipartite
	->For finding the strongly connected components of a graph
	->For detecting cycles in a graph
*/


class Graph
{
	std::vector<int> *g;
	int totalVertexNumber;
	bool *visited;
public:

	Graph(int vertexNumber){
		g = new std::vector<int>[vertexNumber];
		totalVertexNumber = vertexNumber;
		visited = new bool[vertexNumber];
	}


	void addEdge(int src, int dst){
		g[src].push_back(dst);
		g[dst].push_back(src);
	}


	void DFS(int vertex){
		visited[vertex] = true;
		std::cout << vertex << " ";
		for (auto& x : g[vertex])
		{
			if(!visited[x]){
				DFS(x);
			}
		}
	}
};

int main(int argc, char const *argv[])
{	
	
	/*
	Node _0(0);
	Node _1(1);
	Node _2(2);
	Node _3(3);
	_0.addEdge(&_1);
	_1.addEdge(&_0);

	_0.addEdge(&_2);
	_2.addEdge(&_0);

	_1.addEdge(&_2);
	_2.addEdge(&_1);

	_2.addEdge(&_3);
	_3.addEdge(&_2);

	std::vector<Node*> v;
	v.push_back(&_0);
	v.push_back(&_1);
	v.push_back(&_2);
	v.push_back(&_3);
	Graph g(v);

	g.DFS(&_2);

	*/

	Graph g(4);
  	g.addEdge(0, 1);
  	g.addEdge(0, 2);
  	g.addEdge(1, 2);
  	g.addEdge(2, 3);

  	g.DFS(2);
	return 0;
}



// Implementation from scratch

/*
class Node;

class Edge
{
	Node* m_dest;
public:
	Edge(Node* dest):m_dest(dest){
	}

	Node* getDest(){
		return m_dest;
	}
};





class Node
{
	int vertex;
	std::vector<Edge*> m_neighbours;
public:
	Node(int vertex){
		this->vertex = vertex;
	}

	void addEdge(Node* dest){
		m_neighbours.push_back(new Edge(dest));
	}
	
	int getVertex(){
		return this->vertex;
	}

	std::vector<Edge*> getNeighbours(){
		return m_neighbours;
	}
};




class Graph
{
	std::vector<Node*> m_vertices;
	bool *m_visited;
	int m_size;
public:
	Graph(std::vector<Node*> vertices){
		for (int i = 0; i < vertices.size(); ++i)
		{
			m_vertices.push_back(vertices[i]);
		}
		m_visited = new bool[vertices.size()];
		for (int i = 0; i < vertices.size(); ++i)
		{
			m_visited[i] = false;
		}
		m_size = vertices.size();
	}

	void DFS(Node* vertex){
		int v = vertex->getVertex();
		m_visited[v] = true;
		std::cout << vertex->getVertex() << " ";
		for (auto i = vertex->getNeighbours().begin(); i != vertex->getNeighbours().end(); i++)
		{
			if(!m_visited[(*i)->getDest()->getVertex()])
				DFS((*i)->getDest());
		}
	}
	
};
*/