/*
    Breadth First Search(BFS) for an undirected and disconnected graph using adjacency matrix representation.
    In BFS, we print the entire level i.e. all nodes at equal distance from the starting node, and then move to next level.
    We have used iterative approach here.
*/

#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(int **graph, int startingVertex, int vertices, bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(startingVertex);
    visited[startingVertex] = true;
    while (!pendingVertices.empty()){
        int currVertex = pendingVertices.front();
        cout << currVertex << " ";
        pendingVertices.pop();
        for (int i = 0; i < vertices; i++){
            if (i == currVertex)
                continue;
            if (graph[currVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    cout << "Enter no. of vertices: ";
    int vertices;
    cin >> vertices;
    cout << "Enter no. of edges: ";
    int edges;
    cin >> edges;

    // Adjacency Matrix representation of a graph - 2D Dynamic array
    int **graph = new int *[vertices];
    for (int i = 0; i < vertices; i++){
        graph[i] = new int[vertices];
        for (int j = 0; j < vertices; j++){
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges for the graph: " << endl;
    // Taking input for - Undirected Graph
    for (int i = 0; i < edges; i++){
        int first, second;
        cin >> first >> second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++){
        visited[i] = false;
    }

    cout << "BFS Traversal for the graph is: " << endl;
    // BFS Traversal function call
    for(int i=0; i<vertices; i++){
        if(!visited[i])
            bfsTraversal(graph, i, vertices, visited);
    }

    // Deleting memory occupied on heap
    for (int i = 0; i < vertices; i++){
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;

    return 0;
}

/*

Sample I/O

Enter no. of vertices: 8
Enter no. of edges: 6
Enter edges for the graph: 
0 1
1 2
0 2
1 3
4 5
6 7
BFS Traversal for the graph is: 
0 1 2 3 4 5 6 7

-------------------------------------

Time Complexity : O(V^2)
Space Complexity : O(V^2)

*/