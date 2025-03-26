package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}

	target := targetSum - root.Val
	if target == 0 && root.Left == nil && root.Right == nil {
		return true
	}

	return hasPathSum(root.Left, target) || hasPathSum(root.Right, target)
}
