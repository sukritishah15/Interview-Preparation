/*
    Print different components in new line. 
    And each component should be printed in increasing order (separated by space). 
    Order of different components doesn't matter.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int **edges, int n, int sv, bool *visited, vector<int> &v)
{
    v.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;

        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            dfs(edges, n, i, visited, v);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    int flag = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            vector<int> v;
            dfs(edges, V, i, visited, v);
            sort(v.begin(), v.end());
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }

    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
