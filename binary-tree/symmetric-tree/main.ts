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

function isMirror(left: TreeNode | null, right: TreeNode | null): boolean {
  if (!left && !right) return true;
  if ((!left && right) || (left && !right)) return false;
  if (left?.val != right?.val) return false;
  return (
    isMirror(left?.left, right?.right) && isMirror(left?.right, right?.left)
  );
}

function isSymmetric(root: TreeNode | null): boolean {
  return isMirror(root?.left, root?.right);
}
