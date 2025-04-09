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

function rightSideView(root: TreeNode | null): number[] {
  if (!root) return [];

  let queue: TreeNode[] = [root];
  const ans: number[] = [];

  while (queue.length) {
    const breadth = queue.length;

    for (let i = 0; i < breadth; i++) {
      const node = queue[0];
      queue = queue.slice(1);
      if (i == 0) ans.push(node.val);
      if (node.right) queue.push(node.right);
      if (node.left) queue.push(node.left);
    }
  }

  return ans;
}
