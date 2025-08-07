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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root->val < p->val) && (root->val < q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if ((root->val > p->val) && (root->val > q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return root;
        }
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
  TreeNode* root = new TreeNode(6);
  root->left = new TreeNode(2, new TreeNode(0), nullptr);
  root->right = new TreeNode(8, new TreeNode(7), new TreeNode(9));
  root->left->right = new TreeNode(4, new TreeNode(3), new TreeNode(5));

  TreeNode* p = root->left; 
  TreeNode* q = root->right; 

  cout << "Input tree (level-order traversal):" << endl;
  printTree(root);


  Solution sol;
  TreeNode* output = sol.lowestCommonAncestor(root, p, q);

  cout << "Output node:" << endl;
  cout << output->val << endl;
  return 0;
}
