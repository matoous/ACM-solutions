#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string key, s;
    while(cin >> key && key.compare("THEEND")){
        cin >> s;
        vector<vector<char> > dec;
        dec.resize(key.size(), vector<char>(s.size()/key.size()));
        int offset = 0;
        for(char i = 'A'; i <= 'Z'; i++){
            for(int u = 0; u < key.size(); u++){
                if(key[u] == i){
                    for(int j = 0; j < s.size()/key.size(); j++){
                        dec[u][j] = s[j + offset];
                    }
                    offset += s.size()/key.size();
                }
            }
        }
        for(int i = 0; i < s.size()/key.size(); i++){
            for(int u = 0; u < key.size(); u++){
                cout << dec[u][i];
            }
        }
        cout << endl;
    }
    return 0;
}