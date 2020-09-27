/*
    Kosaraju's two-pass Algorithms for finding strongly connected components

    Step 1: Reverse Graph Arcs
    Step 2: DFS on reversed Graph, put vertices in stack
    Step 3: While not stack is empty pop vertex and DFS on the vertex.
    
    Time Complexity: 0(m+n)

*/



#include <iostream>
#include <list>
#include <fstream>
#include <cmath>

class Graph;
void printG(Graph g);



class Graph
{
    
    std::list<std::pair<int, int>> *g;
    int totalVertexNumber;
    bool *visited;
    
    
public:

    
    Graph(int vertexNum){
        g = new std::list<std::pair<int, int>>[vertexNum];
        totalVertexNumber = vertexNum;
        
        visited = new bool[totalVertexNumber];
        for (int i = 0; i < totalVertexNumber; i++) {
            visited[i] = false;
        }
        
    }

    

    void initGraphFromFile(){
        std::string line;
        int i = 0;
        std::ifstream gTxt("/Users/berkeyavas/Desktop/code/GraphSearch-ShortestPath-DataStructures/Week2/dijkstraData.txt");
        int vertex = 0;
        int dest = 0;
        int cost = 0;

        // for setting destination vertex
        int helper = 0;
        int helper2 = 2;
        while(getline(gTxt, line, '\n')) {
            int itr = 0;
            while(line[itr] >= '0' && line[itr] <= '9')
            	itr++;

            // set vertex
            for (int i = 0; i < itr; ++i)
            {
            	vertex += (std::pow(10, itr-i-1) * ((line[i]) - '0'));
            }
            std::cout << vertex << ":" << "\n";
            // move cursor to next integer
	        while(line[itr] < '0' || line[itr] > '9')
	           	itr++;


            while(line[itr] != line.back()){

	            // move cursor to before cost and set destination vertex
	            while(line[itr] != ','){
	            	dest += (std::pow(10, helper2--) * ((line[itr]) - '0'));
	            	helper++;
	            	itr++;            
	            }

	            while (3-helper > 0){
	            	dest /= 10;
	            	helper++;
	            }


	            // move cursor once to pass ','
	            itr++;

	            int temp = itr;
	            // get cost
	            while(line[itr] != '\t'){
	            	itr++;
	            }

	            for (int i = itr - 1; i > temp-1; --i)
	            {	
	            	cost += (std::pow(10, itr - i - 1) * ((line[i]) - '0'));
	            }

	            std::cout << dest << " " << cost << "\n";

            	// move cursor to next integer
                while(line[itr] == '\t'){
                       itr++;
                }

				helper = 0;
            	dest = 0;
            	helper2 = 2;
            	cost = 0;
	        }





            vertex = 0;
            itr = 0;
        }
    }
    
    
    
    
    void addEdge(int src, int dst){
        g[src].push_back(dst);
    }

    
    
    std::list<std::pair<int, int>>* getGraph(){
        return g;
    }
    
    int getSize(){
        return totalVertexNumber;
    }

    
    
    
    
    void setVisitedListFalse(){
        for (int i = 0; i < totalVertexNumber; ++i) {
            visited[i] = false;
        }
    }
};



int main(int argc, char const *argv[])
{
    Graph g(201); // 875715
    g.initGraphFromFile();
    //std::cout << "Graph:\n";
    //printG(g);
    return 0;
}





void printG(Graph g){
    std::list<std::pair<int, int>> *v = g.getGraph();
    int size = g.getSize();
    for (int i = 0; i < size; ++i)
    {
        std::cout << i << " -> ";
        for (std::list<long>::iterator itr = v[i].begin(); itr != v[i].end(); ++itr)
        {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;
    }
}
