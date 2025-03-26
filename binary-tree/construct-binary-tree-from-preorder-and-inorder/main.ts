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

let preorderIdx: number;
let myMap: Record<number, number>;

function build(
  preorder: number[],
  start: number,
  end: number,
): TreeNode | null {
  if (start > end) return null;

  const val = preorder[preorderIdx++];
  const root = new TreeNode(val);
  const mid = myMap[val];

  root.left = build(preorder, start, mid - 1);
  root.right = build(preorder, mid + 1, end);

  return root;
}

function buildTree(preorder: number[], inorder: number[]): TreeNode | null {
  preorderIdx = 0;
  myMap = {};

  for (let i = 0; i < inorder.length; i++) {
    myMap[inorder[i]] = i;
  }

  return build(preorder, 0, preorder.length - 1);
}
