#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = calculateHeight(root->left);
        if (left_height == -1) {
            return -1;
        }
        int right_height = calculateHeight(root->right);
        if (right_height == -1) {
            return -1;
        }

        int height_difference = abs(left_height - right_height);
        if (height_difference > 1) {
            return -1;
        }
        return 1 + max(left_height, right_height);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return calculateHeight(root) != -1;
    }
};

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            cout << current->val << ", ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null, ";
        }
    }
    cout << endl;
}

int main() {
  TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  cout << "Input: " << endl;
  printTree(root);

  Solution sol;
  bool output = sol.isBalanced(root);
  cout << "Output: " << output << endl;
  return 0;
}
