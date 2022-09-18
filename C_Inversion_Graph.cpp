// C++ program to prlol connected components in
// an undirected graph
#include <bits/stdc++.h>
#define lol long long

#include <iostream>
#include <list>
using namespace std;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph
{
    lol V; // No. of vertices

    // Pololer to an array containing adjacency lists
    list<lol> *adj;

    // A function used by DFS
    void DFSUtil(lol v, bool visited[]);

public:
    Graph(lol V); // Constructor
    ~Graph();
    void addEdge(lol v, lol w);
    lol connectedComponents();
};

// Method to prlol connected components in an
// undirected graph
lol Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (lol v = 0; v < V; v++)
        visited[v] = false;
    lol c = 0;
    for (lol v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            // prlol all reachable vertices
            // from v
            DFSUtil(v, visited);

            c++;
        }
    }
    delete[] visited;
    return c;
}

void Graph::DFSUtil(lol v, bool visited[])
{
    // Mark the current node as visited and prlol it
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    list<lol>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(lol V)
{
    this->V = V;
    adj = new list<lol>[V];
}

Graph::~Graph() { delete[] adj; }

// method to add an undirected edge
void Graph::addEdge(lol v, lol w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Driver code
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        Graph g(n);
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol t;
            cin >> t;
            mp[t] = i;
        }
        unordered_set<lol> x;
        for (auto i = mp.rbegin(); i != mp.rend(); i++)
        {
            lol k = (*i).second;
            lol j = k + 1;
            while (j < n)
            {
                if (!x.count(j))
                    g.addEdge(j, k);
                j++;
            }
            x.insert(k);
        }

        cout << g.connectedComponents() << endl;
    }

    return 0;
}
