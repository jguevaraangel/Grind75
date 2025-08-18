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
private:
    int dfs(TreeNode* root, int &max_diameter) {
        if (!root) return 0;

        int left_height = dfs(root->left, max_diameter); // Left
        int right_height = dfs(root->right, max_diameter); // Right

        max_diameter = max(max_diameter, left_height + right_height);

        return max(left_height, right_height) + 1;
    } 

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        dfs(root, max_diameter);
        return max_diameter;        
    }
};

int main () {
  TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4, nullptr, nullptr), new TreeNode(5, nullptr, nullptr)), new TreeNode(3, nullptr, nullptr));
  cout << "Binary tree: " << "[1,2,3,4,5]" << endl;
  Solution sol;
  int output = sol.diameterOfBinaryTree(root);
  cout << "Diameter of tree: " << output << endl; 
  return 0;
}
