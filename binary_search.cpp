#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = right - 1;
            }
        }
        return -1;
    }
};

int main() {
  vector<int> nums = {-1,0,3,5,9,12};
  int target = 9;

  Solution sol;
  int output = sol.search(nums, target);
  cout << "Input vector: ";
  for (int num : nums) {
      cout << num << " ";
  }
  cout << endl;
  cout << "Input target: " << target << endl;

  cout << "Output: " << output << endl;
}
