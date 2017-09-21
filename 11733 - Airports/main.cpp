#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define From second.first
#define To second.second
#define Cost first
#define pii pair<int,int>
#define edge pair<int, pii>

vector<edge> edges;
vector<int> parent;
int testCases, cities, paths, airportCost, from, to, cost;

int root(int x) { return parent[x] == -1 ? x : root(parent[x]);}
bool find(int u, int v) { return root(u) == root(v);}
void unite(int x, int y) { parent[root(x)] = root(y);}
void reset(int cnt){
    edges.clear();
    parent.resize(cnt);
    fill(parent.begin(), parent.end(), -1);
}

int main() {
    cin >> testCases;
    for (int testcase = 1; testcase <= testCases; testcase++){
        cin >> cities >> paths >> airportCost;
        reset(cities);
        for(int i = 0; i < paths; i++){
            cin >> from >> to >> cost;
            if(cost < airportCost) edges.push_back(edge(cost, pii(--from, --to)));
        }
        sort(edges.begin(), edges.end());
        int total = airportCost * cities, airportCount = cities;
        for(auto e : edges){
            if(!find(e.From, e.To)){
                unite(e.From, e.To);
                total = total - airportCost + e.Cost;
                airportCount--;
            }
        }
        cout << "Case #" << testcase << ": " << total << " " << airportCount << endl;
    }
    return 0;
}