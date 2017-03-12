#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

long outPut(vector<char> number){
    long result = 0;
    int position = 0;
    for(int i = number.size() - 1; i >= 0; i--) result += (number[i]-48) * pow(9, position++);
    return result;
}

int main(){
    char c;
    vector<char> num, orig;
    while(scanf("%c", &c) && (c-48) != 0) {
        orig.push_back(c);
        num.push_back((c-48 > 4)?(c-1):c);
        while(scanf("%c", &c) && c != '\n'){
            orig.push_back(c);
            num.push_back((c-48 > 4)?(c-1):c);
        }
        for(int i = 0; i < orig.size(); i++) cout << orig[i];
        cout << ": " << outPut(num) << endl;
        orig.clear();
        num.clear();
    }
    return 0;
}
