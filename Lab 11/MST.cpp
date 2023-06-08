#include <iostream>     
#include <vector>       
#include <limits>       

using namespace std;

// Function to find the MST of a given graph
vector<vector<int>> findMST(vector<vector<int>>& graph, int noOfVertices, int startVertex) {
    
    vector<vector<int>> minSpanTree;    // Vector Array to store the edges of the MST
    bool visited[noOfVertices];         // Array to store which vertices have been visited

    for (int i = 0; i < noOfVertices; i++) {  // Initializing all vertices as unvisited
        visited[i] = false;
    }
    
    visited[startVertex] = true;        // Mark the starting vertex as visited
    int numVisitedVertices = 0;         // Counter to store how many vertices have been visited so far
    int vertex1, vertex2, Weight;    // Variables to store the two vertices and the weight of the edge being processed

    // Loop until all vertices have been visited or added to the MST
    while (numVisitedVertices < noOfVertices - 1) {

        // Finding the minimum weight edge that connects a visited vertex to an unvisited vertex
        int minimum = numeric_limits<int>::max();
        
        for (int i = 0; i < noOfVertices; i++) {
            if (visited[i]) {
                for (int j = 0; j < noOfVertices; j++) {
                    if (graph[i][j] != 0 && !visited[j]) {
                        if (minimum > graph[i][j]) {
                            minimum = graph[i][j];
                            vertex1 = i;
                            vertex2 = j;
                            Weight = minimum;
                        }
                    }
                }
            }
        }

        // Mark the second vertex (unvisited vertex) as visited and add the edge to the MST
        visited[vertex2] = true;
        numVisitedVertices++;
        minSpanTree.push_back({vertex1, vertex2, Weight});
    }

    return minSpanTree;     
}

int main() {
    vector<vector<int>> graph = {{0,3,0,0,0,1},
                                {3,0,2,1,10,0},
                                {0,2,0,3,0,5},
                                {0,1,3,0,5,0},
                                {0,10,0,5,0,4},
                                {1,0,5,0,4,0}};

    vector<vector<int>> mst = findMST(graph, 6, 0);   // Computing the MST of the given adjacent matrix starting from vertex 0

    cout<<"Minimum Spanning Tree"<<endl;
    cout << "Edge \tWeight\n";

    // Printing the edges of the MST
    for (auto edge : mst) {
        cout << edge[0] << "--" << edge[1] <<"\t"<<edge[2] << endl;
    }

    return 0; 
}
