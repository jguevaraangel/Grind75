#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while ((fast != nullptr) && (fast->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

// Creates a linked list from `values` and
// creates a cycle starting at index `pos` (0-based).
// If pos == -1, no cycle is created.
ListNode* createList(const vector<int>& values, int pos) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;

    if (pos == 0) cycleNode = head;

    for (size_t i = 1; i < values.size(); i++) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
        if ((int)i == pos) cycleNode = curr;
    }

    if (pos != -1) {
        curr->next = cycleNode; // create cycle
    }

    return head;
}

void printList(ListNode* head, int maxNodes = 20) {
    ListNode* curr = head;
    int count = 0;

    while (curr != nullptr && count < maxNodes) {
        cout << curr->val;
        curr = curr->next;
        count++;
        if (curr != nullptr && count < maxNodes) cout << " -> ";
    }

    if (curr != nullptr) {
        cout << " -> ... (cycle detected while printing)";
    }

    cout << endl;
}


int main() {
  ListNode* head = createList({3, 2, 0, -4}, 1);
  Solution sol;
  cout << "Input linked list: " << endl; 
  printList(head);
  cout << "Output: ";
  cout << (sol.hasCycle(head) ? "Cycle" : "No Cycle") << endl; 
  return 0;
}
