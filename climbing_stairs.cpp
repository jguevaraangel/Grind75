#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int n_0 = 1;
        int n_1 = 2;

        for (int i = 3; i <= n; i++) {
            int n_temp = n_0 + n_1;
            n_0 = n_1;
            n_1 = n_temp;
        }
        return n_1;
    }
};

int main() {
  int n = 8;
  cout << "Input n: " << n << endl;
  Solution sol;
  int output = sol.climbStairs(n);
  cout << "Output: " << output << endl;
  return 0;
}
