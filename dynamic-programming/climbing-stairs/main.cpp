#include <unordered_map>
using namespace std;

class Solution {
  unordered_map<int, int> cache = {{1, 1}, {2, 2}};

public:
  int climbStairs(int n) {
    if (cache.find(n) != cache.end()) {
      return cache[n];
    }
    auto rs = climbStairs(n - 1) + climbStairs(n - 2);
    cache[n] = rs;
    return rs;
  }
};
