#include <cstdint>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;

    for (int i = 0; i < 32; i++) {
      ans <<= 1;   // Dịch sang trái 1 bit
      if (n & 1) { // Kiểm tra bit cuối có bằng 1
        ans |= 1;  // Gán bit cuối là 1
      }
      n >>= 1; // Dịch sang phải 1 bit
    }

    return ans;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  return 0;
}
