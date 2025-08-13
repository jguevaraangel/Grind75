#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int diff = abs((int)a.length() - (int)b.length());
        string z(diff, '0');
        
        if (a.length() > b.length()) {
            b = z + b;
        } else {
            a = z + a;
        }

        int carry = 0;
        string sum = ""; // Will be reversed
        for (int i = a.length() - 1; i >= 0; i--) {
            int bitA = a[i] - '0';
            int bitB = b[i] - '0';
            int currentSum = bitA + bitB + carry;
            carry = currentSum / 2;
            sum += (currentSum % 2) + '0';
        }
        if (carry) sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};


int main() {
  string a = "1010";
  string b = "1011";
  cout << "Input string a: " << a << endl;
  cout << "Input string b: " << b << endl;
  Solution sol;
  string output = sol.addBinary(a, b);
  cout << "Sum string: " << output << endl;
  return 0;
}

