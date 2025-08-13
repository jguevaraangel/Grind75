#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letter_count; // Create HashMap as a frequency table
        for (char c: magazine) {
            if (letter_count.count(c)) {
                letter_count[c]++; 
            }
            else {
                letter_count[c] = 1;
            }
        }

        for (char c: ransomNote) {
            if (letter_count[c] > 0) {
                letter_count[c]--; 
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {
  string ransomNote = "aa";
  string magazine = "aab";
  cout << "Input strings: " << endl;
  cout << "ransomNote: " << ransomNote << endl;
  cout << "magazine: " << magazine << endl;
  Solution sol;
  bool output = sol.canConstruct(ransomNote, magazine);
  cout << "Output: " << output << endl;
  return 0;
}
