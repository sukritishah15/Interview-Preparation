/*
    BFS Application
    Adjacency List representation using vector of vectors. Note : Size being considered while declaration

    Problem:
    Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. 
    Some pairs of islands are connected to each other by Bidirectional bridges running over water.
    Monk hates to cross these bridges as they require a lot of efforts. 
    He is standing at Island #1 and wants to reach the Island #N. 
    Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

    Input:
    First line contains T. T testcases follow.
    First line of each test case contains two space-separated integers N, M.
    Each of the next M lines contains two space-separated integers X and Y , 
    denoting that there is a bridge between Island X and Island Y.

    Output:
    Print the answer to each test case in a new line.

    Constraints:
    1 ≤ T ≤ 10
    1 ≤ N ≤ 10^4
    1 ≤ M ≤ 10^5
    1 ≤ X, Y ≤ N

    Sample I/P:
    2
    3 2
    1 2
    2 3
    4 4
    1 2
    2 3
    3 4
    4 2

    Sample O/P:
    2
    2
    
*/

#include <bits/stdc++.h>
using namespace std;

void minBridges(vector<vector<int>> graph, int islands){
    queue<int> pendingIslands;
    bool *visited = new bool[islands + 1];
    for (int i = 0; i <= islands; i++){
        visited[i] = false;
    }
    int *level = new int[islands + 1];
    for (int i = 0; i <= islands; i++){
        level[i] = 0;
    }
    pendingIslands.push(1);
    visited[1] = true;

    while (!pendingIslands.empty()){
        int currIsland = pendingIslands.front();
        pendingIslands.pop();
        for (int i = 0; i < graph[currIsland].size(); i++){
            int newIsland = graph[currIsland][i];
            if (!visited[newIsland]){
                visited[newIsland] = true;
                pendingIslands.push(newIsland);
                level[newIsland] = level[currIsland] + 1;
                if (newIsland == islands){
                    cout << level[newIsland] << endl;
                    return;
                }
            }
        }
    }
    delete[] visited;
    delete[] level;
}

int main(){
    int tc;
    cin >> tc;
    while (tc--){
        int islands, bridges;
        cin >> islands >> bridges;

        // Note this step
        vector<vector<int>> graph(islands + 1);
        
        for (int i = 0; i < bridges; i++){
            int first, second;
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        minBridges(graph, islands);
    }
    return 0;
}
