#include <iostream>
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return 1 + max(left_height, right_height);
    }
};

int main() {
  TreeNode* root = new TreeNode(3, new TreeNode(9, nullptr, nullptr), new TreeNode(20, new TreeNode(15, nullptr, nullptr), new TreeNode(7, nullptr, nullptr)));
  cout << "Input tree: [3,9,20,null,null,15,7]" << endl;
  Solution sol;
  int output = sol.maxDepth(root);
  cout << "Max depth: " << output << endl;
  return 0;
}
