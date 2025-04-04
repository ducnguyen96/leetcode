#include <algorithm>
#include <iostream>

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
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};

int main(int argc, char *argv[]) {
  auto solution = new Solution();

  auto root = new TreeNode(0);
  auto rs = solution->maxDepth(root);
  cout << rs << endl;

  return 0;
}
