#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int x, int y) return (x > y) ? 1 : ((x < y) ? -1 : 0);

int main() {
    int iter, houses, num, dist, med;
    scanf("%d", &iter);
    while(iter-- > 0){
        float sum = 0;
        vector<int> nums;
        scanf("%d", &houses);
        for(int i = 0; i < houses; i++){
            scanf("%d", &num);
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end(), compare);
        med = nums[houses/2];
        dist = 0;
        for(int i = 0; i < nums.size(); i++) dist += (med > nums[i]) ? (med - nums[i]) : (nums[i] - med); 
        cout << dist << endl;
    }
    return 0;
}
