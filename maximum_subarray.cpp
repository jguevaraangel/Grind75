#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> current_maximum(nums.size());
        current_maximum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            current_maximum[i] = max(nums[i], current_maximum[i-1] + nums[i]);
        }
        return *max_element(current_maximum.begin(), current_maximum.end());
    }
};

int main () {
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << "Input vector: -2,1,-3,4,-1,2,1,-5,4" << endl;
  Solution sol;
  int output = sol.maxSubArray(nums);
  cout << "Sum of the subarray with the largest sum: " << output << endl;
  return 0;
}
