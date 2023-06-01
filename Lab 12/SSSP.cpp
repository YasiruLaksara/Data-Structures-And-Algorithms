#include<bits/stdc++.h>
using namespace std;

#define V 6 // Number of cities in the graph

// Function to find the city with minimum time tacken
int shortestTime(int dist[], bool visited[]) {
    int minTime = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)

        // If the vertex is not visited and its distance is less than minDist
        if (!visited[v] && dist[v] <= minTime)
            // Update minDist and minIndex
            minTime = dist[v], minIndex = v;
    return minIndex;
}

// Function to find the shortest paths from the source vertex
void dijkstra(int graph[V][V], int start) {

    int time[V];   // Array to store the time tacken
    int parent[V];     // Array to store the parent city for each city
    bool visited[V];   //Array to mark all city as unvisited

    for (int i = 0; i < V; i++) {
        time[i] = INT_MAX;
        visited[i] = false;
    }

    time[start] = 0;  // Initialize the time taken for  source city to 0
    parent[start] = -1;   // source city has no parent

    for (int count = 0; count < V - 1; count++) {
        int u = shortestTime(time, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && time[u] != INT_MAX
                && time[u] + graph[u][v] < time[v]) {
                time[v] = time[u] + graph[u][v];
                parent[v] = u;   // update the parent city
            }
        }
    }
    
    // Print the shortest time taken from the source city
    cout << "Shortest times taken from source city " << start << ":-" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Time taken for city " << i << " = " << time[i] << "\t" <<"Shortest path"<<":- ";
        int j = i;
        while (parent[j] != -1) {
            cout << j << " <- ";
            j = parent[j];
        }
        cout << start << endl;
    }
}

int main() {
    int graph[V][V] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};


    int start = 0;  // Start from relavent city as user wish
    dijkstra(graph, start);
    return 0;
}
