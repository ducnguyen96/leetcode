#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *build(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }
    int mid = ceil(double((end - start)) / 2);
    mid += start;
    auto val = nums[mid];
    auto root = new TreeNode(val);

    root->left = build(nums, start, mid - 1);
    root->right = build(nums, mid + 1, end);
    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return build(nums, 0, nums.size() - 1);
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  vector<int> nums = {10, -3, 0, 5, 9};

  auto ans = sol->sortedArrayToBST(nums);

  return 0;
}
