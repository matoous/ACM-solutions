#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

#define FROM .first.first
#define TO .first.second
#define COST .second

using namespace std;

typedef pair<int, int> pii;

bool loops(vector<pair<pii, int>> edges, int V){
    vector<int> dist(V, numeric_limits<int>::max());
    dist[0] = 0;
    for (int i = 0; i < V -1; i++){
        for (int u = 0; u < edges.size(); u++){
            if (dist[edges[u]FROM] + edges[u]COST < dist[edges[u]TO]) {
                dist[edges[u]TO] = dist[edges[u]FROM] + edges[u]COST;
            }
        }
    }
    for (int i= 0; i < edges.size(); i++){
        if (dist[edges[i]FROM] + edges[i]COST < dist[edges[i]TO]){
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
