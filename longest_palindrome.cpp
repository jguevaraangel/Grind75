#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.length() == 1) {
            return 1;
        }         
        unordered_map<char, int> letter_count;
        for (char c: s) {
            if (letter_count.count(c)) {
                letter_count[c]++;
            }
            else {
                letter_count[c] = 1;
            }
        }
        int palindrome_length = 0;    
        int middle_letter_count = 0;

        for (auto i : letter_count) {
            if (i.second % 2 == 1) {
                palindrome_length = palindrome_length + i.second - 1;
                middle_letter_count = 1;
            }
            else {
                palindrome_length = palindrome_length + i.second;
            }
        }
        return palindrome_length + middle_letter_count;
    }
};

int main() {
  string s = "bananas";
  cout << "Input string: " << s << endl;
  Solution sol;
  int output = sol.longestPalindrome(s);
  cout << "Longest palindrome: " << output << endl;
  return 0;
}
