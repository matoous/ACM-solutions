#include <cstdio>
#include <deque>
#include <map>
#include <queue>
#include <iostream>

using namespace std;


int T, w, t;

char field[4][4];
string s;
int sz;
int cx[] = {-1,-1,-1,1,1,1,0,0};
int cy[] = {-1,0,1,-1,0,1,1,-1};

int score(string s){
    int sz = s.size();
    if(sz == 3 || sz == 4) return 1;
    if(sz == 5) return 2;
    if(sz == 6) return 3;
    if(sz == 7) return 5;
    if(sz >= 8) return 11;
    return 0;
}

bool isOnField(int x, int y)
    return (x < 0 || x >= 4 || y < 0 || y >= 4) ? false : true;

bool findLetter(int pos, int x, int y, vector<vector<bool> > visited){
    bool fl = false;
    for(int i = 0; i < 8; i++){
        int newx = x + cx[i];
        int newy = y + cy[i];
        if(isOnField(newx, newy) && field[newx][newy] == s[pos] && !visited[newx][newy]){
            visited[newx][newy] = true;
            if(pos != sz - 1 && findLetter(pos+1, newx, newy, visited)){
                fl = true;
                break;
            }
            else if(pos == sz - 1) return true;
            visited[newx][newy] = false;
        }
    }
    return fl;
}

int find(string s){
    bool df = false;
    vector< vector<bool> > visited(4,vector<bool>(4,false));
    for(int i = 0; i < 4 && !df; i++){
        for(int u = 0; u < 4; u++){
            if(field[i][u] == s[0]){
                visited[i][u] = true;
                if(findLetter(1, i, u, visited)){
                    df = true;
                    break;
                }
                visited[i][u] = false;
            }
        }
    }
    return df ? score(s) : 0;
}

int main(){
    cin >> T;
    for(int tt = 0; tt < T; tt++){
        t = 0;
        for(int i = 0; i < 4; i++){
            for(int u = 0; u < 4; u++){
                cin >> field[i][u];
            }
        }
        cin >> w;
        for(int i = 0; i < w; i++){
            cin >> s;
            sz = s.size();
            t += find(s);
        }
        cout << "Score for Boggle game #" << tt + 1 << ": " << t << endl;
    }
    return 0;
}
