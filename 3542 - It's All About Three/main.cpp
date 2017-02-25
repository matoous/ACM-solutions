#include <iostream>
#include <algorithm>
using namespace std;
bool fnc(int m){
    for(int i = 2;m != 1;i++){
        if(m%i == 0){
            if(i%10 != 3) return false;
            while(m%i == 0) m/=i;
        }
    }
    return true;
}
int main(){
    int num;
    while(cin>>num && num != -1) cout << num << (fnc(num) ? " YES" : " NO") << endl;
    return 0;
}