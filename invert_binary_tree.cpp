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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr; 
        }
        
        TreeNode* left_tree = root->left;
        TreeNode* right_tree = root->right;
        root->left = right_tree;
        root->right = left_tree;

        invertTree(root->left);
        invertTree(root->right);

        return root;
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
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    cout << "Input tree (level-order traversal):" << endl;
    printTree(root);

    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    cout << "Inverted tree (level-order traversal):" << endl;
    printTree(invertedRoot);
  return 0;
}


