#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numsCount;
        for (int i=0; i<nums.size(); i++) {
            if (numsCount.count(nums[i])) {
                return true;
            }
            else {
                numsCount[nums[i]] = 1;
            }
        }
        return false;
    }
};

int main () {
  vector<int> nums = {1,2,3,1};
  cout << "Input vector: [1,2,3,1]" << endl;
  Solution sol;
  bool output = sol.containsDuplicate(nums);
  cout << "Contains duplicate?: " << output << endl;
  return 0;
}
