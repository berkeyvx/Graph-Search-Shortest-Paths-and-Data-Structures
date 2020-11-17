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

class Graph;
void printG(Graph g);



class Graph
{
    
    std::list<long> *g;
    long totalVertexNumber;
    bool *visited;
    
    
public:

    
    Graph(long vertexNum){
        g = new std::list<long>[vertexNum];
        totalVertexNumber = vertexNum;
        
        visited = new bool[totalVertexNumber];
        for (long i = 0; i < totalVertexNumber; i++) {
            visited[i] = false;
        }
        
    }

    ~Graph(){
        delete [] g;
        delete [] visited;
    }

    

    void initGraphFromFile(){
        std::string line;
        int i = 0;
        std::string edge[2];
        std::ifstream gTxt("graph.txt");
        while(getline(gTxt, line, ' ')) {
            edge[i] = line;
            ++i;
            if (i > 1){
                addEdge(std::stoi(edge[0]), std::stoi(edge[1]));
                i = 0;
            }
        }
    }
    
    
    
    
    void addEdge(long src, long dst){
        g[src].push_back(dst);
    }

    
    
    std::list<long>* getGraph(){
        return g;
    }
    
    long getSize(){
        return totalVertexNumber;
    }

    
    
    void DFS(long vertex, int &i){
        visited[vertex] = true;
        i++;
        for (auto& x : g[vertex])
        {
            if(!visited[x]){
                DFS(x, i);
            }
        }
    }
    
    
    
    // ordering of nodes
    void DFS2(Graph &g, long vertex, std::stack<long> &Stack){
        g.visited[vertex] = true;
        for (auto& x : g.getGraph()[vertex]) {
            if(!g.visited[x])
                DFS2(g, x, Stack);
        }
        Stack.push(vertex);
    }
    
    
    
    void SCC(){
        std::stack<long> Stack;
        Graph gRev = reverseGraph(this);
        
        for (long i = totalVertexNumber - 1 ; i > -1 ; --i) {
            if(!gRev.visited[i])
                gRev.DFS2(gRev, i, Stack);
        }
        
        setVisitedListFalse();
        int i = 0;
        
        while (!Stack.empty()) {
            long v = Stack.top();
            Stack.pop();
            
            if (!visited[v]) {
                DFS(v, i);
                if(i > 100)
                    std::cout << i << "\n";
                i = 0;
            }
        }
    }

    
    
    Graph reverseGraph(Graph *g){
        Graph reversedGraph(totalVertexNumber);
        std::list<long>::iterator itr;
        for(long i = 0; i < totalVertexNumber; i++){
            for(itr = g->getGraph()[i].begin(); itr != g->getGraph()[i].end(); ++itr){
                reversedGraph.g[(*itr)].push_back(i);
            }
        }
        return reversedGraph;
    }
    
    
    
    void setVisitedListFalse(){
        for (long i = 0; i < totalVertexNumber; ++i) {
            visited[i] = false;
        }
    }
};



int main(int argc, char const *argv[])
{
    Graph g(875715); // 875715
    g.initGraphFromFile();

    g.SCC();
    //std::cout << "Graph:\n";
    //printG(g);
    //std::cout << "\nArcs Reversed Graph:\n";
    //printG(g.reverseGraph(g));
    return 0;
}





void printG(Graph g){
    std::list<long> *v = g.getGraph();
    long size = g.getSize();
    for (long i = 0; i < size; ++i)
    {
        std::cout << i << " -> ";
        for (std::list<long>::iterator itr = v[i].begin(); itr != v[i].end(); ++itr)
        {
            std::cout << *itr << " ";
        }
        std::cout << std::endl;
    }
}
