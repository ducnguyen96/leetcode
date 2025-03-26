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

function countNodes(root: TreeNode | null): number {
  let total = 0;

  const count = (node: TreeNode | null) => {
    if (!node) return;
    total++;
    count(node.left);
    count(node.right);
  };

  count(root);
  return total;
}
