#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> new_vectors;
        int i = 0;
        while ((i < intervals.size()) && (intervals[i][1] < newInterval[0])) {
            new_vectors.push_back(intervals[i]);
            i++;
        }

        while ((i < intervals.size()) && (intervals[i][0] <= newInterval[1])) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        new_vectors.push_back(newInterval);

        while (i < intervals.size()) {
            new_vectors.push_back(intervals[i]);
            i++;
        }
        return new_vectors;
    }
};

int main () {
  vector<vector<int>> intervals;
  vector<int> newInterval = {2, 5};
  vector<int> first_object = {1, 3};
  vector<int> second_object = {6, 9};
  intervals.push_back(first_object);
  intervals.push_back(second_object);
  cout << "intervals = [[1,3],[6,9]]" << endl;
  Solution sol;
  vector<vector<int>> output = sol.insert(intervals, newInterval);
  cout << "output = [[" + to_string(output[0][0]) + " , " + to_string(output[0][1]) + "], [" + to_string(output[1][0]) + " , " + to_string(output[1][1]) + "]]" << endl;
  return 0;
}
