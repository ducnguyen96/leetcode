using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    long reverse = 0;
    int xcopy = x;

    while (xcopy > 0) {
      reverse = (reverse * 10) + (xcopy % 10);
      xcopy /= 10;
    }

    return reverse == x;
  }
};
