#include <vector>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size();

    int start = 0;
    int end = n - 1;
    int area = 0;

    while (start < end) {
      area = max(area, (end - start) * min(height[start], height[end]));
      if (height[end] > height[start]) {
        start++;
      } else {
        end--;
      }
    }

    return area;
  }
};
