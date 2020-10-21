/*
    Breadth First Search(BFS) for an undirected and connected graph using adjacency matrix representation.
    In BFS, we print the entire level i.e. all nodes at equal distance from the starting node, and then move to next level.
    We have used iterative approach here.
*/

#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(int **graph, int startingVertex, int vertices){
    queue<int> pendingVertices;
    bool *visited = new bool[vertices];
    for(int i=0; i<vertices; i++){
        visited[i] = false;
    }
    pendingVertices.push(startingVertex);
    visited[startingVertex] = true;
    while(!pendingVertices.empty()){
        int currVertex = pendingVertices.front();
        cout << currVertex << " ";
        pendingVertices.pop();
        for(int i=0; i<vertices; i++){
            if(i==currVertex)
                continue;
            if(graph[currVertex][i]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

int main()
{
    cout << "Enter no. of vertices: ";
    int vertices;
    cin >> vertices;
    cout << "Enter no. of edges: ";
    int edges;
    cin >> edges;

    // Adjacency Matrix representation of a graph - 2D Dynamic array
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++){
        graph[i] = new int[vertices];
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges for the graph: " <<endl;
    // Taking input for - Undirected Graph
    for(int i=0; i<edges; i++){
        int first, second;
        cin >> first >> second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    int startingVertex = 0;

    cout << "BFS Traversal for the graph is: " <<endl;
    // BFS Traversal function call
    bfsTraversal(graph, startingVertex, vertices);

    // Deleting memory occupied on heap
    for (int i = 0; i < vertices; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

/*

Sample I/O

Enter no. of vertices: 7
Enter no. of edges: 8
Enter edges for the graph: 
0 1
0 2
1 3
1 4
2 6
3 5
4 5
5 6
BFS Traversal for the graph is: 
0 1 2 3 4 6 5

-------------------------------------

Time Complexity : O(V^2)
Space Complexity : O(V^2)

*/