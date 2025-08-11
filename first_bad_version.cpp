#include <iostream>
using namespace std;

bool isBadVersion(int version) {
  if (version >= 3) {
    return true;
  }
  return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid) == true) {
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }return low;
    }
};

int main() {
  int n = 9000;
  Solution sol;
  int output = sol.firstBadVersion(n);
  cout << "Input: " << n << endl; 
  cout << "Output: " << output << endl; 
}
