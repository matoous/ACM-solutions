#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector< char> > map;
vector<char> top_win;

void scan(int i, int u){
    char target = map[i][u];
    map[i][u] = '.';
    int x_max = i;
    int y_max = u;
    int x2_max = i;
    int y2_max = u;
    // down
    for(int x = i+1; x < n; x++){
        if(map[x][u] == target){
            map[x][u] = '.';
            x_max++;
        }
        else{
            break;
        }
    }
    // right
    for(int y = u+1; y < m; y++){
        if(map[i][y] == target){
            map[i][y] = '.';
            y_max++;
        }
        else{
            break;
        }
    }
    for(int x = i+1; x < n; x++){
        if(map[x][y_max] == target){
            map[x][y_max] = '.';
            x2_max++;
        }
        else{
            break;
        }
    }
    for(int y = u+1; y < m; y++){
        if(map[x_max][y] == target){
            map[x_max][y] = '.';
            y2_max++;
        }
        else{
            break;
        }
    }
    if(x_max == x2_max && y_max == y2_max+1 && !(x_max == y2_max == y_max == x2_max)){
        bool good = true;
        for(int q = i; q < x_max; q++){
            for(int r = u; r < y_max; r++){
                if(map[q][r] != '.'){
                    good = false;
                    break;
                }
            }
            if(!good) break;
        }
        if(good) top_win.push_back(target);
    }
}

int main() {
    while((cin >> n >> m) && (n != 0 && m != 0)){
        map.resize(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int u = 0; u < m; u++){
                cin >> map[i][u];
            }
        }
        for(int i = 0; i < n; i++){
            for(int u = 0; u < m; u++){
                if(map[i][u] == '.') continue;
                else{
                    scan(i, u);
                }
            }
        }
        sort(top_win.begin(), top_win.end());
        for(int i = 0; i < top_win.size(); i++){
            cout << top_win[i];
        }
        map.clear();
        top_win.clear();
        cout << endl;
    }
    return 0;
}