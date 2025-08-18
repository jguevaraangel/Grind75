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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        int middle_id = count / 2;
        while (middle_id != 0) {
            head = head->next;
            middle_id--;
        }
        return head;
    }
};

int main() {
  ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
  cout << "Input linked list: [1, 2, 3, 4, 5]" << endl;
  Solution sol;
  ListNode* output = sol.middleNode(head);
  cout << "Middle node: " << output->val << endl;
  return 0;
}
