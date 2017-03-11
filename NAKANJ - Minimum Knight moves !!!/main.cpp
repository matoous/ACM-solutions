#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

pair<char, char> changes[] = {
        pair<char,char>(-2, -1),
        pair<char,char>(-1, -2),
        pair<char,char>(2, -1),
        pair<char,char>(1, -2),
        pair<char,char>(-2, 1),
        pair<char,char>(-1, 2),
        pair<char,char>(2, 1),
        pair<char,char>(1, 2),
};

bool isOnBoard(pair<char, char> a){
    return (a.first < 0 || a.first > 7 || a.second < 0 || a.second > 7) ? false : true;
}

int DFS(pair<char, char> a, pair<char, char> ziel){

    queue< pair<char, char> > q;
    vector< vector<bool> > fresh(8, vector<bool>(8, true));
    vector< vector<int> > dist(8, vector<int>(8, 1000));

    q.push( a );
    fresh[a.first][a.second] = false;
    dist[a.first][a.second] = 0;

    pair<char, char> currn, neigh;

    while( !q.empty() ){
        currn = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            neigh = pair<char, char>(currn.first + changes[i].first, currn.second + changes[i].second);
            if(!isOnBoard(neigh)) continue;
            dist[neigh.first][neigh.second] = min(dist[currn.first][currn.second]+1, dist[neigh.first][neigh.second]);
            if(neigh == ziel) return dist[ziel.first][ziel.second];
            if(fresh[neigh.first][neigh.second]){
                fresh[neigh.first][neigh.second] = false;
                q.push(neigh);
            }
        }
    }
    return -1;
}

int main(){
    pair<char, char> start, ziel;
    int iter;
    cin >> iter;
    while(iter-- > 0){
        cin >> start.first >> start.second >> ziel.first >> ziel.second;
        start.first -= 97;
        start.second -= 49;
        ziel.first -= 97;
        ziel.second -= 49;
        cout << DFS(start, ziel) << endl;
    }
    return 0;
}
