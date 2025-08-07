#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int starting_color = image[sr][sc];

        if (starting_color == color) {
            return image;
        }

        function<void(int, int)> dfs = 
            [&](int r, int c) {
                int rows = image.size();
                int cols = image[0].size();

                if (r < 0 || r >= rows || c < 0 || c >= cols) {
                    return;
                }

                if (image[r][c] != starting_color) {
                    return;
                }
                
                image[r][c] = color;
                
                dfs(r + 1, c); // Down
                dfs(r - 1, c); // Up
                dfs(r, c + 1); // Right
                dfs(r, c - 1); // Left
            };

        dfs(sr, sc);
        return image;
    }
};

int main() {
  vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
  int sr = 1;
  int sc = 1;
  int color = 2;
  cout << "Input: " << endl;
  for (const auto& row : image) {
      for (const auto& pixel : row) {
          cout << pixel << " ";
      }
      cout << endl;
  }

  cout << "Output: " << endl;
  Solution sol;
  vector<vector<int>> output = sol.floodFill(image, sr, sc, color);
  for (const auto& row : output) {
      for (const auto& pixel : row) {
          cout << pixel << " ";
      }
      cout << endl;
  }
  
}
