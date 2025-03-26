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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans = {};

    vector<TreeNode *> level = {root};

    while (!level.empty()) {
      vector<TreeNode *> tmp = {};
      double sum = 0;
      for (auto node : level) {
        sum += node->val;
        if (node->left) {
          tmp.push_back(node->left);
        }
        if (node->right) {
          tmp.push_back(node->right);
        }
      }
      ans.push_back(sum / level.size());
      level = tmp;
    }

    return ans;
  }
};
