#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int last = 0;
    int length = 0;

    for (auto ch : s) {
      if (ch == ' ') {
        last = length == 0 ? last : length;
        length = 0;
      } else {
        length++;
      }
    }
    last = length > 0 ? length : last;

    return last;
  }
};
