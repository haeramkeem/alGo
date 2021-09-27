/**
 * Leetcode 1
 * 
 * Two Sum
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapTemp;
        for(int i = 0; i < nums.size(); i++) {
            if(mapTemp.find(nums[i]) != mapTemp.end() && mapTemp[nums[i]] != i) {
                return {mapTemp[nums[i]], i};
            }
            mapTemp[target - nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> vecRes = s.twoSum(nums, target);
    for(auto el : vecRes) {
        cout << el << ' ';
    }
    cout << endl;
}