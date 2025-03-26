package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getMinimumDifference(root *TreeNode) int {
	minimum := 100000
	var prev *int

	var helper func(node *TreeNode) int
	helper = func(node *TreeNode) int {
		if node == nil {
			return minimum
		}

		helper(node.Left)

		if prev != nil {
			minimum = min(minimum, node.Val-*prev)
		}
		prev = &node.Val

		helper(node.Right)

		return minimum
	}

	minimum = helper(root)

	return minimum
}
