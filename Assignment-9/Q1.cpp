/*Write a program to implement the following graph algorithms:
1.Breadth First Search (BFS)
2.Depth First Search (DFS)
3.Minimum Spanning Tree (Kruskal and Prim)
4.Dijkstra's Shortest Path Algorithm
*/
#include <iostream>
using namespace std;

#define MAXV 100
#define MAXE 1000
#define INF 999999

class Graph
{
public:
    int V;
    int adj[MAXV][MAXV];

    Graph(int v)
    {
        V = v;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v, int w = 1, bool undirected = true)
    {
        adj[u][v] = w;
        if (undirected)
            adj[v][u] = w;
    }

    void BFS(int start)
    {
        bool visited[MAXV] = {false};
        int q[MAXV], front = 0, rear = 0;

        q[rear++] = start;
        visited[start] = true;

        cout << "\nBFS Traversal: ";

        while (front < rear)
        {
            int node = q[front++];
            cout << node << " ";

            for (int i = 0; i < V; i++)
            {
                if (adj[node][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, bool visited[])
    {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < V; i++)
        {
            if (adj[node][i] != 0 && !visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFS(int start)
    {
        bool visited[MAXV] = {false};
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    struct Edge
    {
        int u, v, w;
    };

    Edge edges[MAXE];
    int edgeCount = 0;

    void collectEdges()
    {
        edgeCount = 0;
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (adj[i][j] != 0)
                {
                    edges[edgeCount].u = i;
                    edges[edgeCount].v = j;
                    edges[edgeCount].w = adj[i][j];
                    edgeCount++;
                }
            }
        }
    }

    void sortEdges()
    {
        for (int i = 0; i < edgeCount - 1; i++)
        {
            for (int j = 0; j < edgeCount - i - 1; j++)
            {
                if (edges[j].w > edges[j + 1].w)
                {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    int findParent(int node, int parent[])
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void kruskalMST()
    {
        collectEdges();
        sortEdges();

        int parent[MAXV];
        for (int i = 0; i < V; i++)
            parent[i] = i;

        cout << "\nKruskal MST edges:\n";
        int cost = 0;

        for (int i = 0; i < edgeCount; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu != pv)
            {
                cout << u << " -- " << v << " (Weight: " << w << ")\n";
                cost += w;
                parent[pu] = pv;
            }
        }

        cout << "Total MST Cost: " << cost << endl;
    }

    void primMST(int start = 0)
    {
        bool inMST[MAXV] = {false};
        int key[MAXV];
        int parent[MAXV];

        for (int i = 0; i < V; i++)
            key[i] = INF;

        key[start] = 0;
        parent[start] = -1;

        cout << "\nPrim MST edges:\n";

        for (int cnt = 0; cnt < V; cnt++)
        {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!inMST[i] && (u == -1 || key[i] < key[u]))
                    u = i;

            inMST[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] != 0 && !inMST[v] && adj[u][v] < key[v])
                {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        int cost = 0;
        for (int i = 1; i < V; i++)
        {
            cout << parent[i] << " -- " << i << " (Weight: " << key[i] << ")\n";
            cost += key[i];
        }

        cout << "Total MST Cost: " << cost << endl;
    }

    void dijkstra(int start)
    {
        int dist[MAXV];
        bool visited[MAXV] = {false};

        for (int i = 0; i < V; i++)
            dist[i] = INF;
        dist[start] = 0;

        cout << "\nDijkstra Shortest Paths:\n";

        for (int i = 0; i < V; i++)
        {
            int u = -1;
            for (int j = 0; j < V; j++)
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;

            visited[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] != 0 && dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        for (int i = 0; i < V; i++)
            cout << "Node " << i << " Distance from " << start << " = " << dist[i] << endl;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);

    g.BFS(0);
    g.DFS(0);
    g.kruskalMST();
    g.primMST();
    g.dijkstra(0);

    return 0;
}
