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
  void dfs(TreeNode *node, vector<int> *numbers) {
    (*numbers).push_back(node->val);

    if (node->left)
      dfs(node->left, numbers);
    if (node->right)
      dfs(node->right, numbers);
  }
  int getMinimumDifference(TreeNode *root) {
    vector<int> numbers;
    dfs(root, &numbers);

    int minimum = abs(numbers[0] - numbers[1]);
    for (int i = 0; i < numbers.size() - 1; i++) {
      for (int j = i + 1; j < numbers.size(); j++) {
        minimum = min(minimum, abs(numbers[i] - numbers[j]));
      }
    }

    return minimum;
  }
};

int main(int argc, char *argv[]) {
  auto sol = new Solution();

  auto root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                           new TreeNode(6));

  auto rs = sol->getMinimumDifference(root);

  return 0;
}
