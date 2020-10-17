/*
    BFS Application
    Adjacency List representation using vector of vectors.

    Problem:
    In a social networking site, people are connected with other people. 
    The whole system appears as a giant connected graph. 
    In this question, you are required to answer the total number of people connected at t nodes away from each other 
    (t distance connectivity). 
    For example: Two persons directly connected are at 1 distance connectivity. 
    While the two persons having a common contact without having direct connectivity, are at 2 distance connectivity.

    First line of input line contains, two integers n and e, where n is the nodes and e are the edges. 
    Next e line will contain two integers u and v meaning that node u and node v are connected to each other 
    in undirected fashion. Next line contains single integer, m, which is number of queries. 
    Next m lines, each have two inputs, one as source node and other as a required t distance connectivity 
    which should be used to process query.

    Sample I/P:
    9 10
    1 2
    2 3
    1 7
    2 4
    3 4
    4 7
    7 8
    9 7
    7 6
    5 6
    3
    4 2
    5 3
    2 1

    Sample O/P:
    4
    4
    3
 
*/

#include <bits/stdc++.h>
using namespace std;

int tDistancedNodes(vector<vector<int>> graph, int startingNode, int t, int nodes){
    queue<int> pendingNodes;
    bool *visited = new bool[nodes + 1];
    for (int i = 0; i <= nodes; i++){
        visited[i] = false;
    }
    int *level = new int[nodes + 1];
    // memset(level,0,sizeof(level)); - Didn't work - WA
    // fill(level,level+nodes+1,0); - Didn't work - WA
    for (int i = 0; i <= nodes; i++){
        level[i] = 0;
    }

    pendingNodes.push(startingNode);
    visited[startingNode] = true;
    while (!pendingNodes.empty()){
        int currNode = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < graph[currNode].size(); i++){
            int newNode = graph[currNode][i];
            if (!visited[newNode]){
                visited[newNode] = true;
                level[newNode] = level[currNode] + 1;
                pendingNodes.push(newNode);
            }
        }
    }
    int count = 0;
    for (int i = 0; i <= nodes; i++){
        if (level[i] == t)
            count++;
    }

    delete[] visited;
    delete[] level;
    return count;
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes + 1);
    for (int i = 0; i < edges; i++){
        int first, second;
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    int queries;
    cin >> queries;
    while (queries--){
        int startingNode, t_dist;
        cin >> startingNode >> t_dist;
        cout << tDistancedNodes(graph, startingNode, t_dist, nodes) << endl;
    }
    return 0;
}
