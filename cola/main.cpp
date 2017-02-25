#include <iostream>
#include <algorithm>

int main(){
    int arr[201];
    arr[1]= 1;
    for(int i = 2; i < 201; i++){
        arr[i] = arr[i-1] + ((i % 2 == 1) ? 1 : 2);
    }
    while(std::cin>>arr[0]){
        std::cout << arr[arr[0]] << std::endl;
    }
    return 0;
}