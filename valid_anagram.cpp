#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
    }
};

int main() {
  string s = "anagram";
  string t = "nagaram";
  cout << "Input strings: " << endl;
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;

  Solution sol;
  bool output = sol.isAnagram(s, t);
  cout << "Output: " << output << endl;
  return 0;
}
