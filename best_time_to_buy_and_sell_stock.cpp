#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1000000; // Very large value
        int max_profit = 0;
        for (int i=0; i<prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            
            int profit = prices[i] - min_price;
            
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};

int main() {
  vector<int> prices = {7,1,5,3,6,4};
  Solution solution;
  int output = solution.maxProfit(prices);
  cout << "Input vector: ";
  for (int price : prices) {
      cout << price << " ";
  }
  cout << endl;
  cout << "Output: " << output << endl;
  return 0;
}

