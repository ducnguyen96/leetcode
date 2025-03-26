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

function getMinimumDifference(root: TreeNode | null): number {
  let minimum = 100000;
  let prev: number;

  const recursive = (node: TreeNode | null): number => {
    if (!node) return minimum;

    recursive(node.left);

    if (prev != null) minimum = Math.min(minimum, node.val - prev);
    prev = node.val;

    recursive(node.right);
    return minimum;
  };

  return recursive(root);
}
