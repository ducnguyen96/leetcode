#include <climits>
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
  int minimum = INT_MAX;
  int *prev;

public:
  int getMinimumDifference(TreeNode *root) {
    if (!root) {
      return minimum;
    }

    getMinimumDifference(root->left);

    if (prev != nullptr) {
      minimum = min(minimum, root->val - *prev);
    }
    prev = &root->val;

    getMinimumDifference(root->right);

    return minimum;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  auto root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                           new TreeNode(6));

  auto rs = sol->getMinimumDifference(root);
  cout << rs;

  return 0;
}
