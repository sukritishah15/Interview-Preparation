/*
    Depth First Search(DFS) for an undirected and connected graph using adjacency matrix representation.
    In DFS, once we pick a direction, we keep going in that direction, till we can go in that direction.
    We have used recursive approach here.
*/

#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int **graph, int currVertex, int vertices, bool *visited){
    cout << currVertex << " ";
    visited[currVertex] = true;
    for(int i=0; i<vertices; i++){
        if(i==currVertex){
            continue;
        }
        if(graph[currVertex][i]==1 && !visited[i]){
            dfsTraversal(graph, i, vertices, visited);
        }
    }
}

int main()
{
    int vertices;
    cout << "Enter no. of vertices in the graph: ";
    cin >> vertices;
    int edges;
    cout << "Enter no. of edges in the graph: ";
    cin >> edges;

    // Adjacency Matrix representation of a graph - Dynamic 2D array
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++){
        graph[i] = new int[vertices];
        for(int j=0; j<vertices; j++){
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges for graph: " << endl;
    // Taking input for an - Undirected graph
    for(int i=0; i<edges; i++){
        int first, second;
        cin >> first >> second;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }

    // Maintaing a visited array to avoid infinite loop
    bool *visited = new bool[vertices];
    for(int i=0; i<vertices; i++)
        visited[i] = false;

    int startingVertex = 0;

    cout << "DFS Traversal for the graph is: " << endl;
    // DFS Traversal function call
    dfsTraversal(graph, startingVertex, vertices, visited);

    // Deleting memory occupied on heap
    for(int i=0; i<vertices; i++){
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;

    return 0;
}

/*

Sample I/O -

Enter no. of vertices in the graph: 7
Enter no. of edges in the graph: 8
Enter edges for graph: 
0 1 
0 2
1 3
1 4
3 5
4 5
5 6
2 6
DFS Traversal for the graph is: 
0 1 3 5 4 6 2

-------------------------------------------

Time Complexity : O(V^2)
Space Complexity : O(V^2)

*/