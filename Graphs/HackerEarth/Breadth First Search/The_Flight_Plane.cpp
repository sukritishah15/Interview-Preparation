/*
    BFS Application.
    
    ----------------------------------------------------------------------------------------------------------------

    Explanation:
    Flight Time and waiting time is useless from optimisation point of view, since the weights of the edges are same, 
    even if you have to wait at an airport for it to turn to running state from loading state, 
    the net waiting time would be same for every path that has the same number of nodes, 
    so our goal should be minimize the number of nodes that we have to encounter from src to dst, 
    and disregard time taken.

    To minimise the number of nodes, all we have to do is use bfs untill we encounter the dst node.
    Since in bfs, we travel layer by layer, and we would exit the program once we see the dst node, 
    this way we don't travel any deeper than is absolutely necessary.

    Now how to get the path/directions from src to dst.

    Just keep a map, map[i] = j, where j is the parent node of i.
    Since we need to print the path which is lexicographically smallest 
    (as in if 1 3 5 and 14 5 are two paths from 1 to 5, we need 1 3 5). 
    So we sort the adjacency list for each node, and we visit the neighbours of each node in lexicographical order. 
    As soon as we visit a node, we mark it visited and add an entry to our map (map[neigh] = parent). 
    We can be sure that this entry won't be re-edited/updated by other nodes, 
    since this is the first time we are visiting the node, and we have marked it visited now, 
    so no other node can visit it.

    Combining two facts
    - bfs traverses layer by layer (no more depth traversed than required)
    - we are not assigning the parent of each visited node more than once (this ensures lexicographical order)

    we get the path by traversing back the chain (map where we stored parent of each node) from dst to src.
    start from node = dst, get it's parent from map, then the parent of that node....so on untill you reach src.
    There you have it - your path.

    ---------------------------------------------------------------------------------------------------------------
    
    Problem:
    You are given flights route map of a country consisting of N cities and M undirected flight routes. 
    Each city has an airport and each airport can work as layover. 
    The airport will be in two states, Loading and Running. 
    In loading state, luggage is loaded into the planes. 
    In the running state, planes will leave the airport for the next city. 
    All the airports will switch their states from Loading to Running and vice versa after every T minutes. 
    You can cross a city if its airport state is running. Initially, all the airports are in running state. 
    At an airport, if its state is loading, you have to wait for it to switch its state to running. 
    The time taken to travel through any flight route is C minutes. 
    Find the lexicographically smallest path which will take the minimum amount of time (in minutes) 
    required to move from city X to city Y.

    It is guaranteed that the given flight route map will be connected. 
    Graph won't contain multiple edges and self loops. A self loop is an edge that connects a vertex to itself.

    Input Format:
    The first line contains 4 space separated integers, N, M, T and C. 
    Next M lines contains two space separated integers each, U and V denoting that there is a bidirectional road 
    between city U and city V. Next line contains two space separated integers, X and Y.

    Output Format:
    In the first line print an integer K, denoting the number of city you need to go through to reach city Y 
    from the city X. In next line, print K space separated integers denoting the path which will take 
    the minimum amount of time (in minutes) required by to move from city X to city Y. There can be multiple paths. 
    Print the lexicographically smallest one.

    Constraints:
    1 <= N,C,T <= 10^3
    N-1 <= M <= (N*(N-1))/2
    1 <= U,V,X,Y <= N

    Sample I/P:
    5 5 3 5
    1 2
    1 3
    2 4
    1 4
    2 5
    1 5

    Sample O/P:
    3
    1 2 5 
*/

#include <bits/stdc++.h>
using namespace std;

void smallestPath(vector<vector<int>> graph, int source, int destination, int vertices){
    queue<int> pendingVertices;
    bool *visited = new bool[vertices + 1];
    int *parent = new int[vertices + 1];
    for (int i = 0; i <= vertices; i++){
        visited[i] = false;
    }
    pendingVertices.push(source);
    visited[source] = true;
    parent[source] = 0;
    bool flag = false;
    while (!pendingVertices.empty()){
        if (flag)
            break;
        int currVertex = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < graph[currVertex].size(); i++){
            int newVertex = graph[currVertex][i];
            if (!visited[newVertex]){
                parent[newVertex] = currVertex;
                visited[newVertex] = true;
                if (newVertex == destination){
                    flag = true;
                    break;
                }
                pendingVertices.push(newVertex);
            }
        }
    }

    delete[] visited;

    stack<int> ans;
    while (destination){
        ans.push(destination);
        destination = parent[destination];
    }
    cout << ans.size() << endl;
    while (!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    delete[] parent;
}

int main(){
    int vertices, edges, stateChangeTime, cityChangeTime;
    cin >> vertices >> edges >> stateChangeTime >> cityChangeTime;
    vector<vector<int>> graph(vertices + 1);
    for (int i = 0; i < edges; i++){
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    for (int i = 1; i <= vertices; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    int source, destination;
    cin >> source >> destination;
    smallestPath(graph, source, destination, vertices);
    return 0;
}
