#include <vector>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      int tmp = digits[i];
      digits[i] = (digits[i] + carry) % 10;
      carry = (tmp + carry) / 10;
    }
    if (carry == 0) {
      return digits;
    }
    vector<int> newDigits = {1};
    newDigits.insert(newDigits.end(), digits.begin(), digits.end());
    return newDigits;
  }
};
