#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

class Graph
{
    int V;
    list<pii> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    string shortestPath(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pii>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

string Graph::shortestPath(int src, int dst)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> dist(V, numeric_limits<int>::max());

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second; pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[dst] != INT32_MAX ? to_string(dist[dst]) : "unreachable";
}

int main() {
    int tc;
    cin >> tc;
    for (int tcn = 1; tcn < tc + 1; tcn++) {
        int n, m, s, t, n1, n2, cost;
        cin >> n >> m >> s >> t;
        Graph g = Graph(n);
        for (int i = 0; i < m; ++i) {
            cin >> n1 >> n2 >> cost;
            g.addEdge(n1, n2, cost);
        }
        cout << "Case #" << tcn << ": " << g.shortestPath(s, t) << endl;
    }
    return 0;
}
