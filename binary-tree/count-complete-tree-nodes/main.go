package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func countNodes(root *TreeNode) int {
	total := 0

	var count func(node *TreeNode)
	count = func(node *TreeNode) {
		if node == nil {
			return
		}
		total++
		count(node.Left)
		count(node.Right)
	}
	count(root)

	return total
}
