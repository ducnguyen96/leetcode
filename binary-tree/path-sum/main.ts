class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function hasPathSum(root: TreeNode | null, targetSum: number): boolean {
  if (!root) return false;

  const target = targetSum - root.val;
  if (target === 0 && !root.left && !root.right) return true;

  return hasPathSum(root.left, target) && hasPathSum(root.right, target);
}
