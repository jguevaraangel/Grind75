#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        string filtered_string;
        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                filtered_string += tolower(static_cast<unsigned char>(c));
            }
        }
        string reversed_string;
        for (int i=filtered_string.length()-1; i>=0; i--) {
            reversed_string += filtered_string[i];
        }
        if (reversed_string == filtered_string) {
            return true;
        }
        return false;
    }
};

int main() {
  string s = "A man, a plan, a canal: Panama"; 
  Solution solution; 
  bool output = solution.isPalindrome(s); 
  cout << "Input string: " << s << endl;  
  cout << "Output: " << output << endl;
  return 0;
}

