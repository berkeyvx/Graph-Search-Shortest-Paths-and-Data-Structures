/*
    Your task is to run Dijkstra's shortest-path algorithm on this graph, using 1 (the first vertex) as the source vertex,
     and to compute the shortest-path distances between 1 and every other vertex of the graph. If there is no path between a vertex
     v and vertex 1, we'll define the shortest-path distance between 1 and v to be 1000000.

You should report the shortest-path distances to the following ten vertices, in order: 7,37,59,82,99,115,133,165,188,197.
You should encode the distances as a comma-separated string of integers. So if you find that all ten of these vertices except 115
 are at distance 1000 away from vertex 1 and 115 is 2000 distance away, then your answer should be 1000,1000,1000,1000,1000,2000,
 1000,1000,1000,1000. Remember the order of reporting DOES MATTER, and the string should be in the same order in which the above
 ten vertices are given. The string should not contain any spaces. Please type your answer in the space provided.

IMPLEMENTATION NOTES: This graph is small enough that the straightforward
O(mn) time implementation of Dijkstra's algorithm should work fine.
OPTIONAL: For those of you seeking an additional challenge, try implementing the heap-based version.
Note this requires a heap that supports deletions, and you'll probably need to maintain some kind of mapping between
 vertices and their positions in the heap.

*/


#include <iostream>
#include <list>
#include <fstream>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>

class Graph;
void printGraph(Graph &g);



class Graph
{
    // pair<dest,cost>
    std::list<std::pair<int, int>> *g; // adjaceny list
    int totalVertexNumber;
    std::vector<bool> visited;
    
public:

    
    Graph(int vertexNum):totalVertexNumber(vertexNum){
        // pair<dest, cost>
        g = new std::list<std::pair<int, int>>[vertexNum];
        //totalVertexNumber = vertexNum;
        
        visited.reserve(vertexNum);
        setVisitedListFalse();
    }

    

    void initGraphFromFile(){
        std::string line;
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
            //std::cout << "Vertex: " << vertex << ":" << "\n";
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

                //std::cout << dest << " " << cost << "\n";

                // insert node in graph
                // undirected graph
                g[vertex].push_back(std::make_pair(dest, cost));
                g[dest].push_back(std::make_pair(vertex, cost));
                
                
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
    
    

    // GETTERS
    
    std::list<std::pair<int, int>>* getGraph(){
        return g;
    }
    
    int getSize(){
        return totalVertexNumber;
    }

    
    
    int dijkstraSP(int vertex,int end=0){
        // g = new std::list<std::pair<int, int>>[vertexNum];
        std::vector<int> dist(totalVertexNumber, INT_MAX);
        dist[vertex] = 0;
        typedef std::pair<int,int> iPair;
        
        // pair<cost, vertex>
        std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> p;
        
        p.push(std::make_pair(0, vertex));

        while (!p.empty()) {
            // v.first -> cost, v.second -> vertex
            auto v = p.top();
            p.pop();
            
            for (auto itr = g[v.second].begin(); itr != g[v.second].end(); ++itr) {
                // (*itr).first -> vertex, (*itr).second -> cost
                int alt = dist[v.second] + (*itr).second;

                if(alt < dist[(*itr).first]){
                    dist[(*itr).first] = alt;
                    p.push(std::make_pair(alt, (*itr).first));
                }
            }
        }


        return dist[end];
    }


    
    void setVisitedListFalse(){
        for (int i = 0; i < visited.size(); ++i) {
            visited[i] = false;
        }
    }


};



int main(int argc, char const *argv[])
{
    // 1 -> 7,37,59,82,99,115,133,165,188,197
    //   -> 2599,2610,2947,2052,2367,2399,2029,2442,2505,3068
    Graph g(201); // 875715
    g.initGraphFromFile();
    std::cout << g.dijkstraSP(1,7) << "\n";
    std::cout << g.dijkstraSP(1,37) << "\n";
    std::cout << g.dijkstraSP(1,59) << "\n";
    std::cout << g.dijkstraSP(1,82) << "\n";
    std::cout << g.dijkstraSP(1,99) << "\n";
    std::cout << g.dijkstraSP(1,115) << "\n";
    std::cout << g.dijkstraSP(1,133) << "\n";
    std::cout << g.dijkstraSP(1,165) << "\n";
    std::cout << g.dijkstraSP(1,188) << "\n";
    std::cout << g.dijkstraSP(1,197) << "\n";
    //std::cout << "Graph:\n";
    //printGraph(g);
    return 0;
}



void printGraph(Graph &g){
    for (int i = 0; i < g.getSize(); i++) {
        for (auto &ik : g.getGraph()[i]) {
            std::cout << "Vertex: "<< i ;
            std::cout << " Dest-Cost: ";
            std::cout <<  ik.first << " - " << ik.second;
            std::cout << "\n";
        }
    }
}


