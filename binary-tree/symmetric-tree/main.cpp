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
  bool isMirror(TreeNode *left, TreeNode *right) {
    int sum = !!right + !!left;
    if (sum == 0) {
      return true;
    }
    if (sum == 1) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
  }

  bool isSymmetric(TreeNode *root) { return isMirror(root->left, root->right); }
};

int main(int argc, char *argv[]) { return 0; }
