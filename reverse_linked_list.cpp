#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head;
        ListNode* next_node = nullptr;
        while (curr_node != nullptr) {
            next_node = curr_node->next;    
            curr_node->next = prev_node;    
            prev_node = curr_node;         
            curr_node = next_node;         
        }
        return prev_node;
    }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
  cout << "Input linked list: " << "1 -> 2 -> 3 -> 4 -> 5" << endl; 
  Solution sol;
  ListNode* output = sol.reverseList(head);
  cout << "Output linked list: ";
  while (output != nullptr) {
    cout << output->val << " -> ";
    output = output->next;
  }
  cout << "nullptr" << endl;
  return 0;
}
