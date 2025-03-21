#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = s.length();
    if (len < 2)
      return len;

    int left = 0, right = 0;
    int longest = 0;
    unordered_map<char, bool> map = {};
    while (right < len) {
      if (!map[s[right]]) {
        map[s[right]] = true;
        longest = max(longest, right - left + 1);
      } else {
        while (s[left] != s[right]) {
          map[s[left]] = false;
          left++;
        }
        left++;
      }
      right++;
    }

    return longest;
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  string s = "tmmzuxt";
  auto result = solution->lengthOfLongestSubstring(s);
  cout << result << endl;

  return 0;
}
