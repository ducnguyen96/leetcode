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

function build(nums: number[], start: number, end: number): TreeNode | null {
  if (start > end) return null;

  let mid = Math.round((end - start) / 2);
  mid += start;
  const val = nums[mid];
  const node = new TreeNode(val);

  node.left = build(nums, start, mid - 1);
  node.right = build(nums, mid + 1, end);

  return node;
}

function sortedArrayToBST(nums: number[]): TreeNode | null {
  return build(nums, 0, nums.length - 1);
}
