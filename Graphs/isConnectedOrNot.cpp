#include <bits/stdc++.h>
using namespace std;

void dfs(int **edges, int n, int sv, bool *visited)
{
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
            dfs(edges, n, i, visited);
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

    dfs(edges, V, 0, visited);
    int flag = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            cout << "false" << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "true" << endl;
    }

    delete[] visited;
    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}

/*

Sample I/0

Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true

Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other 
but there isn’t any path from vertices 0,1,3 to vertex 2. 

*/