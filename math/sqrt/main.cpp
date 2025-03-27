#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int start = 1;
    int end = x;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (mid == x / mid) {
        return mid;
      } else if (mid > x / mid) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return end;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();
  for (int i = 0; i < 17; i++) {
    cout << i << ": " << sol->mySqrt(i) << endl;
  }
  return 0;
}
