#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int left = 0;
        int maxLength = 0;
        map<char, int> charIndexMap;
        for (int right=0; right < s.size(); right++) {
            char currentChar = s[right];
            if (charIndexMap.count(currentChar) && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;
            }
            charIndexMap[currentChar] = right;
            int currentLength = right - left + 1;
            maxLength = max(maxLength, currentLength);
        }
        return maxLength;
    }
};

int main() {
  string s = "abcabcbb";
  Solution sol;
  int output = sol.lengthOfLongestSubstring(s);
  cout << "Input: abcabcbb" << endl;
  cout << "Output: " << output << endl;
  return 0;
}
