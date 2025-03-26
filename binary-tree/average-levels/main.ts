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

function averageOfLevels(root: TreeNode | null): number[] {
  const ans: number[] = [];

  let level: (TreeNode | null)[] = [root];
  while (level.length > 0) {
    const tmp: (TreeNode | null)[] = [];
    let sum = 0;
    for (const node of level) {
      sum += node!.val;
      if (node!.left) tmp.push(node!.left);
      if (node!.right) tmp.push(node!.right);
    }
    ans.push(sum / level.length);
    level = tmp;
  }

  return ans;
}
