#include <iostream>
#include <stdio.h>
using namespace std;

#include "vector"
#include "algorithm"

int compare(int x, int y){
    if(x > y) {
        return 1;
    } else if(x < y) {
        return -1;
    } else{
        return 0;
    }
}

int main() {
    int iter;
    scanf("%d", &iter);
    for(int x = 0; x < iter; x++){
        int houses, num;
        float sum = 0;
        vector<int> nums;
        scanf("%d", &houses);
        for(int i = 0; i < houses; i++){
            scanf("%d", &num);
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end(), compare);
        int med = nums[houses/2];
        int dist = 0;
        for(int i = 0; i < nums.size(); i++){
            if(med > nums[i]){
                dist += med - nums[i];
            } else{
                dist += nums[i] - med;
            }
        }
        cout << dist << endl;
    }
    return 0;
}