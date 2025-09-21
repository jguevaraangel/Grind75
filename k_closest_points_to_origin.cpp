#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, vector<int>> distances;
        for (int i=0; i < points.size(); i++) {
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distances.insert({d, points[i]});
        }
        vector<vector<int>> result;
        auto it = distances.begin();
        for (int count = 0; count < k; count++, it++) {
            result.push_back(it->second);
        }
        return result;
        

    }
};

int main () {
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  int k = 2;
  Solution sol;
  vector<vector<int>> output = sol.kClosest(points, k);
  cout << "[[" + to_string(output[0][0]) + "," + to_string(output[0][1]) + "]]" + "," + "[[" + to_string(output[1][0]) + "," + to_string(output[1][1]) + "]]" << endl;
  return 0;
}
