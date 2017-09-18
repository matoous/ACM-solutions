#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

bool loops(vector<pair<pii, int>> edges, int V){
    vector<int> dist(V, numeric_limits<int>::max());
    dist[0] = 0;
    for (int i = 0; i < V -1; i++){
        for (int u = 0; u < edges.size(); u++){
            int b = edges[u].first.first;
            int e = edges[u].first.second;
            if (dist[b] + edges[u].second < dist[e]) {
                dist[e] = dist[b] + edges[u].second;
            }
        }
    }

    for (int i= 0; i < edges.size(); i++){
        int b = edges[i].first.first;
        int e = edges[i].first.second;
        if (dist[b] + edges[i].second < dist[e]){
            return true;
        }
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while(tc-->0) {
        int n, m, s1, s2, y;
        cin >> n >> m;
        vector<pair<pii, int>> edges(n, pair<pii, int>());
        for (int i = 0; i < m; ++i) {
            cin >> s1 >> s2 >> y;
            edges.push_back(pair<pii, int>(pii(s1, s2), y));
        }
        cout << (loops(edges, n) ? "possible" : "not possible") << endl;
    }
    return 0;
}