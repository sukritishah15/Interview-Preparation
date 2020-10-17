/*
    0-1 BFS (Shortest Path in a Binary Weight Graph)

    This type of BFS is used to find the shortest distance between two nodes in a graph 
    provided that the edges in the graph have the weights 0 or 1. 
    If you apply the BFS, you will get an incorrect result for the optimal distance between 2 nodes.

    In this approach, a boolean array is not used to mark the node because the condition of the optimal distance 
    will be checked when you visit each node. A double-ended queue is used to store the node. 
    In 0-1 BFS, if the weight of the edge = 0, then the node is pushed to the front of the dequeue. 
    If the weight of the edge = 1, then the node is pushed to the back of the dequeue.

    Implementation
    Here, edges[ v ] [ i ] is an adjacency list that exists in the form of pairs i.e. 
    edges[ v ][ i ].first will contain the node to which v is connected and 
    edges[ v ][ i ].second will contain the distance between v and edges[ v ][ i ].first.
    Q is a double-ended queue. The distance is an array where, distance[ v ] will contain 
    the distance from the start node to v node. 
    Initially the distance defined from the source node to each node is infinity.

    The adjacency list of the graph will be as follows:
    Here 's' is considered to be 0 or source node.

    0 -> 1 -> 3 -> 2
    edges[ 0 ][ 0 ].first = 1 , edges[ 0 ][ 0 ].second = 1
    edges[ 0 ][ 1 ].first = 3 , edges[ 0 ][ 1 ].second = 0
    edges[ 0 ][ 2 ].first = 2 , edges[ 0 ][ 2 ].second = 1

    1 -> 0 -> 4
    edges[ 1 ][ 0 ].first = 0 , edges[ 1 ][ 0 ].second = 1
    edges[ 1 ][ 1 ].first = 4 , edges[ 1 ][ 1 ].second = 0

    2 -> 0 -> 3
    edges[ 2 ][ 0 ].first = 0 , edges[ 2 ][ 0 ].second = 0
    edges[ 2 ][ 1 ].first = 3 , edges[ 2 ][ 1 ].second = 0

    3 -> 0 -> 2 -> 4
    edges[ 3 ][ 0 ].first = 0 , edges[ 3 ][ 0 ].second = 0
    edges[ 3 ][ 2 ].first = 2 , edges[ 3 ][ 2 ].second = 0
    edges[ 3 ][ 3 ].first = 4 , edges[ 3 ][ 3 ].second = 0

    4 -> 1 -> 3
    edges[ 4 ][ 0 ].first = 1 , edges[ 4 ][ 0 ].second = 0
    edges[ 4 ][ 1 ].first = 3 , edges[ 4 ][ 1 ].second = 0

    If you use the BFS algorithm, the result will be incorrect 
    because it will show you the optimal distance between s and node 1 and s and node 2 as 1 respectively. 
    This is because it visits the children of s and calculates the distance between s and its children, which is 1. 
    The actual optimal distance is 0 in both cases.

    Processing-
    Starting from the source node, i.e 0, it will move towards 1, 2, and 3. 
    Since the edge weight between 0 and 1 and 0 and 2 is 1 respectively, 1 and 2 will be pushed to the back of the queue. 
    However, since the edge weight between 0 and 3 is 0, 3 will pushed to the front of the queue. 
    The distance will be maintained in distance array accordingly.
    3 will then be popped from the queue and the same process will be applied to its neighbours, and so on.

    (https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/)
*/

#include <bits/stdc++.h>
using namespace std;

void zeroOneBfs(vector<vector<pair<int, int>>> &graph, int vertices, int *dist, int startingVertex){
    deque<int> Q;
    Q.push_back(startingVertex);
    dist[startingVertex] = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop_front();
        for(int i=0; i<graph[v].size(); i++){
            /* if distance of neighbour of v from start node is greater than 
            sum of distance of v from start node and edge weight between v and its neighbour, 
            then change it */
            if(dist[graph[v][i].first] > dist[v] + graph[v][i].second){
                dist[graph[v][i].first] = dist[v] + graph[v][i].second;
                /*if edge weight between v and its neighbour is 0 then push it to front of
                double ended queue else push it to back*/
                if(graph[v][i].second==0)
                    Q.push_front(graph[v][i].first);
                else 
                    Q.push_back(graph[v][i].first);
            }
        }
    }
    for(int i=0; i<vertices; i++){
        cout << dist[i] << " ";
    }
}

int main(){
    int vertices, edges;
    cout << "Enter no. of vertices and edges: ";
    cin >> vertices >> edges;
    vector<vector<pair<int,int>>> graph(vertices+1);
    cout << "Enter edges along with their weights: " << endl;
    for(int i=0; i<edges; i++){
        int first, second, weight;
        cin >> first >> second >> weight;
        graph[first].push_back({second,weight});
        graph[second].push_back({first,weight});
    }
    int *dist = new int[vertices];
    for(int i=0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
    int startingVertex = 0;
    cout << "0-1 BFS traversal for the graph is: " << endl;
    zeroOneBfs(graph, vertices, dist, startingVertex);
    delete[] dist;
    return 0;
}
