#include<bits/stdc++.h>
using namespace std;

void dfs(int** graph, int v, int sv){
    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }
    stack<int> s;
    s.push(sv);
    visited[sv] = true;
    while(!s.empty()){
        int currVertex = s.top();
        cout << currVertex << " ";
        s.pop();
        for(int i=0; i<v; i++){
            if(graph[currVertex][i] && !visited[i]){
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

int main(){
    int v,e;
    cin >> v >> e;
    int** graph = new int*[v];
    for(int i=0; i<v; i++){
        graph[i] = new int[v];
        for(int j=0; j<v; j++){
            graph[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    int sv = 0;
    dfs(graph, v, sv);
    return 0;
}

/*

Sample I/O 
5 4
0 1
0 2
1 3
1 4

0 2 1 4 3 

*/