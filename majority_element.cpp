#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        
        unordered_map<int, int> count;
        for (int i=0; i<nums.size(); i++) {
            if (count.count(nums[i])) {
                count[nums[i]]++;
            }
            else {
                count[nums[i]] = 1;
            }
        }

        for (auto i: count) {
            if (i.second > mid) {
                return i.first;
            }
        }
        return -1;
    }
};

int main() {
  vector<int> nums = {2,2,1,1,1,2,2};
  cout << "Input vector: 2,2,1,1,1,2,2" << endl;
  Solution sol;
  int output = sol.majorityElement(nums);
  cout << "Majority element: " << output << endl;
  return 0;
}
