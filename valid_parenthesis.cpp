#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stck; // Stack to store the chars
            for (int i=0; i<s.length(); i++) {
                char current_char = s[i];
                
                if (current_char == '(' || current_char == '[' || current_char == '{') {
                    stck.push(current_char); // Add open paranthesis
                }
                    
                else {
                    if (stck.empty()) {
                        return false;
                    }
                    char top_char = stck.top();
                    if (current_char == ')' && top_char == '(') {
                        stck.pop();
                    } else if (current_char == '}' && top_char == '{') {
                        stck.pop();
                    } else if (current_char == ']' && top_char == '[') {
                        stck.pop();
                    } else {
                        return false; // Invalid sequence
                    }
                }
            }
        return stck.empty();
    }
};

int main() {
  string s = "()[]{}";
  Solution sol;
  bool output = sol.isValid(s); 
  cout << "Input: " << s << endl;
  cout << "Output: " << output << endl;
  return 0;
}

