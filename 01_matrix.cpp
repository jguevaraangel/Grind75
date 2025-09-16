#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return mat;
        }
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                if (mat[i][j] == 0) {q.push({i, j});}
                else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            // Check all 4 neighbors
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                // Check bounds and if we found a shorter path
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    mat[newRow][newCol] > mat[row][col] + 1) {
                    
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return mat;
    }
};

int main () {
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << "Input: mat = [[0,0,0],[0,1,0],[0,0,0]]" << endl;
  Solution sol;
  vector<vector<int>> output = sol.updateMatrix(mat);
  cout << "Output: mat = [[" + to_string(output[0][0]) + "," + to_string(output[0][1]) + "," + to_string(output[0][2]) + "],[" + to_string(output[1][0]) + "," + to_string(output[1][1]) + "," + to_string(output[1][2]) + "],[" + to_string(output[2][0]) + "," + to_string(output[2][1]) + "," + to_string(output[2][2]) + "]]" << endl;
  return 0;
}
