#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string rs = "";

    int idxa = a.length() - 1;
    int idxb = b.length() - 1;
    int carry = 0;

    while (idxa > -1 || idxb > -1 || carry) {
      if (idxa > -1) {
        carry += a[idxa--] - '0';
      }
      if (idxb > -1) {
        carry += b[idxb--] - '0';
      }
      char ch = carry % 2 + '0';
      carry /= 2;
      rs = ch + rs;
    }

    return rs;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  auto rs = sol->addBinary("11", "1");

  cout << rs;

  return 0;
}
