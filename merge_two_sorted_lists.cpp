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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* current = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }
        return dummy.next;
    }
};

int main() {
  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(4);
  
  ListNode* list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(4);

  cout << "Input List 1: " << endl;
  ListNode* temp1 = list1;
  while (temp1 != nullptr) {
    cout << temp1->val << " -> ";
    temp1 = temp1->next;
  }
  cout << "nullptr" << endl;

  cout << "Input List 2: " << endl;

  ListNode* temp2 = list2;
  while (temp2 != nullptr) {
    cout << temp2->val << " -> ";
    temp2 = temp2->next;
  }
  cout << "nullptr" << endl;

  Solution sol;
  ListNode* output = sol.mergeTwoLists(list1, list2);
  cout << "Output List" << endl;
  ListNode* temp3 = output;
  while (temp3 != nullptr) {
    cout << temp3->val << " -> ";
    temp3 = temp3->next;
  }
  cout << "nullptr" << endl;
  return 0;
}

