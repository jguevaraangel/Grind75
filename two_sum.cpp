#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexValueMap; // Create a HashMap to store indices
        vector<int> indices;
        for (int i=0; i<nums.size(); ++i){
            if (indexValueMap.count(target - nums[i])) {
                // Complement is in the HashMap
                indices.push_back(indexValueMap[target - nums[i]]);
                indices.push_back(i);
                return indices;
            }
            else {
                // Complement is not in the HashMap, so add it
                indexValueMap[nums[i]] = i;
            }
        }
        return {};
        }
    };

int main() {
  vector<int> nums = {2,7,11,15};
  int target = 9;
  Solution solution;
  vector<int> output = solution.twoSum(nums, target);
  cout << "Input vector: ";
  for (int num : nums) {
      cout << num << " ";
  }
  cout << endl;
  cout << "Target: " << target << endl;
  cout << "Indices of the two numbers are: [" << output[0] << ", " << output[1] << "]" << endl;
  cout << "The corresponding values are: " << nums[output[0]] << " and " << nums[output[1]] << endl;
  return 0;
}
