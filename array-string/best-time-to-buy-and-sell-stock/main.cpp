#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) {
      return 0;
    }
    int minPrice = prices[0];
    int profit = 0;
    for (int i = 1; i < n; i++) {
      if (prices[i - 1] < minPrice) {
        minPrice = prices[i - 1];
      }
      int tmpProfit = prices[i] - minPrice;
      if (tmpProfit > profit) {
        profit = tmpProfit;
      }
    }
    return profit;
  }
};
